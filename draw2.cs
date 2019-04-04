using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

[RequireComponent (typeof(MeshFilter)) ]
public class draw2 : MonoBehaviour
{
// Use this for initialization
        void Start()
    {
  gameObject.AddComponent<MeshFilter>();
        gameObject.AddComponent<MeshRenderer>();
        Mesh mesh = GetComponent<MeshFilter>().mesh;

        mesh.Clear();

        // make changes to the Mesh by creating arrays which contain the new values
         //79 90.955 44.887
        mesh.vertices = new Vector3[] {new Vector3(75,91,42), new Vector3(79,70,54), new Vector3(90,96,59)};
        mesh.triangles =  new int[] {0, 1, 2};
    } 
       }


