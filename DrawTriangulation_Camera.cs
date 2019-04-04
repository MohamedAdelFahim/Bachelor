using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Text;
using System.IO;


public class DrawTriangulation_Camera : MonoBehaviour
{
     string line;
    ArrayList arrayOfX = new ArrayList();
    ArrayList arrayOfY = new ArrayList();
    ArrayList arrayOfZ = new ArrayList();
    ArrayList arrayOfGray = new ArrayList();
     static int printCount =0 ;
     float maxX=0;
     float maxY=0;
     float maxZ=0;

     
public static void PrintValues( IEnumerable myList )  {
      foreach ( int obj in myList )
        Debug.Log(obj);
        printCount++;
        if(printCount >4)
        return ;
   }

    // Use this for initialization
    
    // Draws a triangle that covers the middle of the screen
    Material mat;

    
  public void OnPostRender()
    {
        if (!mat)
        {
            // Unity has a built-in shader that is useful for drawing
            // simple colored things. In this case, we just want to use
            // a blend mode that inverts destination colors.
            var shader = Shader.Find("Hidden/Internal-Colored");
            mat = new Material(shader);
            mat.hideFlags = HideFlags.HideAndDontSave;
            // Set blend mode to invert destination colors.
            mat.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusDstColor);
            mat.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.Zero);
            // Turn off backface culling, depth writes, depth test.
            mat.SetInt("_Cull", (int)UnityEngine.Rendering.CullMode.Off);
            mat.SetInt("_ZWrite", 0);
            mat.SetInt("_ZTest", (int)UnityEngine.Rendering.CompareFunction.Always);
        }
   
          GL.PushMatrix();
        GL.Begin(GL.TRIANGLES);
        
          for(int i=0; i <arrayOfX.Count-2 ;i+=3){
        mat.SetPass(0);
        GL.LoadOrtho();
        GL.Vertex3(((float) arrayOfX[i])/maxX, ((float) arrayOfY[i])/maxY, ((float) arrayOfZ[i])/maxZ);
        GL.Vertex3(((float) arrayOfX[i+1])/maxX, ((float) arrayOfY[i+2])/maxY, ((float) arrayOfZ[i+1])/maxZ);
        GL.Vertex3(((float) arrayOfX[i+2])/maxX, ((float) arrayOfY[i+2])/maxY, ((float) arrayOfZ[i+2])/maxZ);
         }
         
     GL.PopMatrix();
        
    }
               void Start()
    {
 StreamReader reader = new StreamReader("Assets/Input/OutputWithColours.txt");

     using (reader)
      {
          
          line = reader.ReadLine();
                
          if(line != null){
                  // While there's lines left in the text file, do this:
                  do
                  {
                       
                         string[] entries = line.Split(' ');
                         if (entries.Length > 0)
                         arrayOfX.Add( (float) System.Convert.ToDouble(entries[0]));
                         arrayOfY.Add((float) System.Convert.ToDouble(entries[1]));
                         arrayOfZ.Add((float) System.Convert.ToDouble(entries[2]));
                         arrayOfGray.Add((float) System.Convert.ToDouble(entries[3]));
                         if((float) System.Convert.ToDouble(entries[0])>maxX)
                          maxX = (float) System.Convert.ToDouble(entries[0]);
                          
                         if((float) System.Convert.ToDouble(entries[1])>maxY)
                          maxY = (float) System.Convert.ToDouble(entries[1]);                      
                         if((float) System.Convert.ToDouble(entries[2])>maxZ)
                          maxZ = (float) System.Convert.ToDouble(entries[2]);


                         line = reader.ReadLine();
                  }
                  while (line != null);
          } 
          // Done reading, close the reader and return true to broadcast success    
          reader.Close();
          }
//             Debug.Log(arrayOfX[0]); 
  //                          Debug.Log(arrayOfY[0]); 
    //         Debug.Log(arrayOfZ[0]); 
    	//       GameObject.Find("Main Camera").transform.position = new Vector3(122,123, 70);
      //   Camera.main.fieldOfView = 15;
      //    Debug.Log("Done");
   		
		
    }
	
     
}
