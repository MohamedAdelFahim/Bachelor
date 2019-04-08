using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
//using System.DateTime;
[RequireComponent (typeof(MeshFilter)) ]
public class DrawTriangle_Mesh : MonoBehaviour
{
// Use this for initialization
        void Start()
    {

    string fileName = "Assets/Input/out1_DeluanyTriangulation_Coloured.txt";


       System.DateTime start = System.DateTime.Now;
                Material mat;
             var shader = Shader.Find("Particles/Standard Surface");
            mat = new Material(shader);
        
         int size = 0;
        string line;
        
//string fileName = "Assets/Input/out1_DeluanyTriangulation_Coloured_RemovedFrontPart.txt";
System.IO.StreamReader file =   
    new System.IO.StreamReader(fileName);  
while((line = file.ReadLine()) != null)  
{  
    if(line != "")
    size++;  
}   
file.Close();  
    Debug.Log(size);

 file =   
    new System.IO.StreamReader(fileName);  


    int maxSize = size;
    if(! (size%3 == 0)){
    int quotient = size /3;
    size = 3*(quotient+1);
    }
    Debug.Log(size);
    int maxVectorSize = 65535;
    int numberOfMeshes = System.Convert.ToInt32(System.Math.Ceiling(  (( double ) size) / (( double ) maxVectorSize))) ;
 
    Vector3 [] vertices = new Vector3[maxVectorSize];
    int [] triangles = new int [maxVectorSize];
    int [] trianglesFlip = new int [maxVectorSize];
    
    int index = 0;
    
    
    Color[] colors = new Color[65535];

 StreamReader reader = new StreamReader(fileName);

    int meshCount = 0;
    int currentMesh =0;
   //    Mesh [] mesh = GetComponent<MeshFilter>().mesh[numberOfMeshes];

         GameObject [] listOfObjects =new GameObject [numberOfMeshes] ;
    
     for(int i =0; i< numberOfMeshes; i++){
            listOfObjects[i] = new GameObject("MeshObject" + (i+1));
     }
  string[] entries ;
     using (reader)
      {
          
          line = reader.ReadLine();
                
          if(line != null){
                  // While there's lines left in the text file, do this:
                  do
                  {
                       
                         entries = line.Split(' ');
                         if (entries.Length > 0){

                            if(entries.Length  < 5){    

                             vertices [meshCount]  = new Vector3 ((float) System.Convert.ToDouble(entries[0]),(float) System.Convert.ToDouble(entries[1]),(float) System.Convert.ToDouble(entries[2]));
                             triangles [meshCount] = index;
                            
                            if(entries.Length == 4 )    
                                colors [meshCount] = new Color ((float) System.Convert.ToDouble(entries[3])/255, (float) System.Convert.ToDouble(entries[3])/255,(float) System.Convert.ToDouble(entries[3])/255, 0); 
                                index ++;
                                meshCount ++;
                            }
                            else{

                                if(System.Convert.ToInt32(entries[4]) < 17){
                                line = reader.ReadLine();
                                line = reader.ReadLine();
                                }

                                else{
                                       vertices [meshCount]  = new Vector3 ((float) System.Convert.ToDouble(entries[0]),(float) System.Convert.ToDouble(entries[1]),(float) System.Convert.ToDouble(entries[2]));
                                       triangles [meshCount] = index;                            
                                       colors [meshCount] = new Color ((float) System.Convert.ToDouble(entries[3])/255, (float) System.Convert.ToDouble(entries[3])/255,(float) System.Convert.ToDouble(entries[3])/255, 0);
                            
                                        index ++;
                                        meshCount ++;
                          
                                }

                            }
                                  if(meshCount == maxVectorSize){
                                   listOfObjects[currentMesh].AddComponent<MeshFilter>();
                                   listOfObjects[currentMesh].AddComponent<MeshRenderer>();

                                   listOfObjects[currentMesh].GetComponent<MeshRenderer>().material = mat;
                                   listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.vertices = vertices ; 
                                   listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.triangles = triangles ; 
       
                                  if(entries.Length == 4 || entries.Length == 5)
                                   listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.colors = colors ; 
                                                                
                                    currentMesh++;
                                    meshCount =0;
                                    index = 0;
                                  
                                }
                         
                         }
                         
                         
                         line = reader.ReadLine();
                  }
                  while (line != null );

                  for(int i = currentMesh ; i< numberOfMeshes ; i++){
                             vertices [i]  = new Vector3(0, 0, 0);
                             triangles [i] = 0;
                      
                  } 

                    listOfObjects[currentMesh].AddComponent<MeshFilter>();
                    listOfObjects[currentMesh].AddComponent<MeshRenderer>();
                    listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.vertices = vertices ; 
                    listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.triangles = triangles ; 
                    listOfObjects[currentMesh].GetComponent<MeshRenderer>().material = mat;
                    
                    if(entries.Length == 4 || entries.Length == 5)
                       listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.colors = colors ; 

          } 
          
          // Done reading, close the reader and return true to broadcast success    
          reader.Close();
          }
          System.DateTime after = System.DateTime.Now; 
          System.TimeSpan duration = after.Subtract(start);
Debug.Log("Duration in seconds: " + duration.Seconds);

        int count = 0;
          System.DateTime end = System.DateTime.Now; 
        System.TimeSpan durationEnd = end.Subtract(start);
        Debug.Log("Duration in seconds: " + durationEnd.Seconds);

    }

}
