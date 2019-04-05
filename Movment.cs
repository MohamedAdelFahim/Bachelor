using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movment : MonoBehaviour
{
  float sensitivity = 10f;
  float x;
  float y;
    Vector3 rotateValue;

 
	// Update is called once per frame
	void Update()
    {

         y = Input.GetAxis("Mouse X");
         x = Input.GetAxis("Mouse Y");
         rotateValue = new Vector3(x, y * -1, 0);
         transform.eulerAngles = transform.eulerAngles - rotateValue;
 
    float fov  = Camera.main.fieldOfView;
    fov -= Input.GetAxis("Mouse ScrollWheel") * sensitivity;
    Camera.main.fieldOfView = fov;
    int speed = 75;
    

    if(Input.GetKey(KeyCode.Z)){
    Camera.main.fieldOfView += 2;
    }

    if(Input.GetKey(KeyCode.X)){
    Camera.main.fieldOfView -= 2;
    }

if(Input.GetKey(KeyCode.D))
     {
        transform.Translate(new Vector3(speed * Time.deltaTime,0,0));
     }
     if(Input.GetKey(KeyCode.A))
     {
         transform.Translate(new Vector3(-speed * Time.deltaTime,0,0));
     }
     if(Input.GetKey(KeyCode.S))
     {
         transform.Translate(new Vector3(0,-speed * Time.deltaTime,0));
     }
     if(Input.GetKey(KeyCode.W))
     {
         transform.Translate(new Vector3(0,speed * Time.deltaTime,0));
     }
   
    }
   

}
