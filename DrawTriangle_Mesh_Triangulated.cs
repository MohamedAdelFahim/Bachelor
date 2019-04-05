using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
//using System.DateTime;
[RequireComponent (typeof(MeshFilter)) ]
public class DrawTriangle_Mesh_Triangulated : MonoBehaviour
{
// Use this for initialization
        void Start()
    {
       System.DateTime start = System.DateTime.Now;

        gameObject.AddComponent<MeshFilter>();
        gameObject.AddComponent<MeshRenderer>();
        Mesh mesh = GetComponent<MeshFilter>().mesh;

        mesh.Clear();
        int size = 0;
        int maxSize = 0;
         Mesh meshFlipped  = GetComponent<MeshFilter>().mesh; 

 StreamReader reader = new StreamReader("Assets/Input/out1_DeluanyTriangulation.txt");
 string line;

 line = reader.ReadLine();
 line = reader.ReadLine();
 size = System.Convert.ToInt32(line);
 maxSize = size;   
/*
     using (reader)
      {
          
          line = reader.ReadLine();
                
          if(line != null){
                  // While there's lines left in the text file, do this:
                  do
                  {
                    size++;
                    

                    }
                  while (line != null && size < 1947917 );
          } 
          // Done reading, close the reader and return true to broadcast success    
          reader.Close();
          }
*/

    if(! (size%3 == 0)){
    int quotient = size /3;
    size = 3*(quotient+1);
    }
    Debug.Log(size);
    Vector3[] vertices = new Vector3[size];
    int [] triangles = new int [size] ;
    int [] trianglesFlip = new int [size] ;

    int index = 0;
    int count = 0;
    Debug.Log("done 1");
    
// reader = new StreamReader("Assets/Input/OutputWithColours.txt");

     using (reader)
      {
          
          line = reader.ReadLine();
                
          if(line != null){
                  // While there's lines left in the text file, do this:
                  do
                  {
                       
                         string[] entries = line.Split(' ');
                         if (entries.Length > 0){
                             vertices[index] = new Vector3 ((float) System.Convert.ToDouble(entries[0]),(float) System.Convert.ToDouble(entries[1]),(float) System.Convert.ToDouble(entries[2]));
                             triangles[index] = index;
                            index ++;
     
                         }
                         
                         
                         line = reader.ReadLine();
                  }
                  while (line != null && index <  maxSize );
          } 
          // Done reading, close the reader and return true to broadcast success    
          reader.Close();
          }
          System.DateTime after = System.DateTime.Now; 
          System.TimeSpan duration = after.Subtract(start);
Debug.Log("Duration in seconds: " + duration.Seconds);
    Debug.Log(vertices[1000]);

        // make changes to the Mesh by creating arrays which contain the new values
        mesh.vertices = vertices;
//        mesh.uv = new Vector2[] {new Vector2(0, 0), new Vector2(0, 1), new Vector2(1, 1)};
        mesh.triangles = triangles; 

                    for(int i = maxSize; i>0;i--)
        {
            trianglesFlip[i] = i;
            count ++;
        }
        meshFlipped.vertices = vertices;
        meshFlipped.triangles = trianglesFlip;

          System.DateTime end = System.DateTime.Now; 
        System.TimeSpan durationEnd = end.Subtract(start);
        Debug.Log("Duration in seconds: " + durationEnd.Seconds);

    }

}
