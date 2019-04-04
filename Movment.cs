using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movment : MonoBehaviour
{
  float sensitivity = 10f;
 
	// Update is called once per frame
	void Update()
    {
 
         float fov  = Camera.main.fieldOfView;
                 float oldFov= fov;

   fov += Input.GetAxis("Mouse ScrollWheel") * sensitivity;
   Camera.main.fieldOfView = fov;
        float newFov = fov;
        if((newFov-oldFov) != 0)
        Debug.Log("zoom works");
    int speed = 10;
if(Input.GetKey(KeyCode.RightArrow))
     {
        transform.Translate(new Vector3(speed * Time.deltaTime,0,0));
     }
     if(Input.GetKey(KeyCode.LeftArrow))
     {
         transform.Translate(new Vector3(-speed * Time.deltaTime,0,0));
     }
     if(Input.GetKey(KeyCode.DownArrow))
     {
         transform.Translate(new Vector3(0,-speed * Time.deltaTime,0));
     }
     if(Input.GetKey(KeyCode.UpArrow))
     {
         transform.Translate(new Vector3(0,speed * Time.deltaTime,0));
     }
          Shader shader = Shader.Find("Hidden/Internal-Colored");
Material mat = new Material(shader);
/*
          GL.PushMatrix();
        GL.Begin(GL.TRIANGLES);
for(int i=0; i <10000-2 ;i+=3){    
//           for(int i=0; i <arrayOfX.Count-2 ;i+=3){
    //    transform.localScale -= new Vector3((float) 1500000,0,0);
          //  GameObject sphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
       // sphere.transform.position = new Vector3((float) arrayOfX[i],(float) arrayOfY[i],(float) arrayOfZ[i]);
    // Start is called before the first frame update

  //    Debug.Log(i);
        mat.SetPass(0);
        GL.LoadOrtho();
        GL.Vertex3((float) arrayOfX[i], (float) arrayOfY[i], (float) arrayOfZ[i]);
        GL.Vertex3((float) arrayOfX[i+1], (float) arrayOfY[i+1],  (float) arrayOfZ[i+1]);
        GL.Vertex3((float) arrayOfX[i+2], (float) arrayOfY[i+2],  (float) arrayOfZ[i+2]);
         }
         
     GL.PopMatrix();
//     GL.LoadIdentity followed by GL.MultMatrix 
     
     */
    }
   

}
