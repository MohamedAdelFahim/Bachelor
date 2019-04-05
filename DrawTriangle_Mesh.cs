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
       System.DateTime start = System.DateTime.Now;


        int size = 0;
        string line;
        

System.IO.StreamReader file =   
    new System.IO.StreamReader("Assets/Input/out1_DeluanyTriangulation_Coloured.txt");  
while((line = file.ReadLine()) != null)  
{  
    if(line != "")
    size++;  
}   
file.Close();  
    Debug.Log(size);

 StreamReader reader = new StreamReader("Assets/Input/out1_DeluanyTriangulation_Coloured.txt");

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
    
    
  Color32 currentColor = new Color32();
     Color32[] colors = new Color32[triangles.Length];
 reader = new StreamReader("Assets/Input/out1_NormalTriangulation_Coloured.txt");

    int meshCount = 0;
    int currentMesh =0;
   //    Mesh [] mesh = GetComponent<MeshFilter>().mesh[numberOfMeshes];

         GameObject [] listOfObjects =new GameObject [numberOfMeshes] ;
    
     for(int i =0; i< numberOfMeshes; i++){
            listOfObjects[i] = new GameObject("MeshObject" + i);
     }
     Mesh mesh = new Mesh();
     using (reader)
      {
          
          line = reader.ReadLine();
                
          if(line != null){
                  // While there's lines left in the text file, do this:
                  do
                  {
                       
                         string[] entries = line.Split(' ');
                         if (entries.Length > 0){
                                
                             vertices [meshCount]  = new Vector3 ((float) System.Convert.ToDouble(entries[0]),(float) System.Convert.ToDouble(entries[1]),(float) System.Convert.ToDouble(entries[2]));
                             triangles [meshCount] = index;
                            index ++;
                            meshCount ++;
                                  if(meshCount == maxVectorSize){
                                      mesh.Clear();
                                   listOfObjects[currentMesh].AddComponent<MeshFilter>();
                                   listOfObjects[currentMesh].AddComponent<MeshRenderer>();
                                   listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.vertices = vertices ; 
                                   listOfObjects[currentMesh].GetComponent<MeshFilter>().mesh.triangles = triangles ; 
                                 
                               //   mesh.vertices = vertices;
                                 // mesh.triangles = triangles;
                                

                                    currentMesh++;
                                    meshCount =0;
                                    index = 0;
                                  
                                }
                         
                         }
                         
                         
                         line = reader.ReadLine();
                  }
                  while (line != null );
                    mesh.Clear();
                    listOfObjects[currentMesh].AddComponent<MeshFilter>();
                    listOfObjects[currentMesh].AddComponent<MeshRenderer>();
                    mesh  = GetComponent<MeshFilter>().mesh; 
                                 
                    mesh.vertices = vertices;
                    mesh.triangles = triangles;
          
          } 
          
          // Done reading, close the reader and return true to broadcast success    
          reader.Close();
          }

          
/*
          for(int i=0; i<numberOfMeshes;i++){
              mesh[i].vertices = vertices[i];
              mesh[i].triangles = triangles[i];

          }
*/

          System.DateTime after = System.DateTime.Now; 
          System.TimeSpan duration = after.Subtract(start);
Debug.Log("Duration in seconds: " + duration.Seconds);
        // make changes to the Mesh by creating arrays which contain the new values
        //mesh.vertices = vertices;
//        mesh.uv = new Vector2[] {new Vector2(0, 0), new Vector2(0, 1), new Vector2(1, 1)};
        //mesh.triangles = triangles; 
        int count = 0;
 /*
            for(int i = maxSize; i>0;i--)
        {
            trianglesFlip[i] = i;
            count ++;
        }
        Debug.Log(vertices.Length);
        */
        //meshFlipped.vertices = vertices;
        //meshFlipped.triangles = trianglesFlip;
          System.DateTime end = System.DateTime.Now; 
        System.TimeSpan durationEnd = end.Subtract(start);
        Debug.Log("Duration in seconds: " + durationEnd.Seconds);

    }

}
