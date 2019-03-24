
#include "pch.h"

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <vector>
#include <GL/freeglut.h>

#include "functions.h"
using namespace std;



double rotx = 100;
double roty = 50;
double rotz = -30;

int loc = 220;

short is = 17;

double sss = 0.5;

struct point {
	short dataX;
	short dataY;
	short dataZ;
	short dataV;
	short dataI;

   point(short xx, short yy, short zz, short vv,short ii) {
	   dataX = xx;
	   dataY = yy;
	   dataZ = zz;
	   dataV = vv;
	   dataI = ii;


   }
};


vector <point> points;

string inputFile ;
string outputFile;
string finalFile;

int choice;
int triangulationType;
int colouredChoice;

bool triangulationTypeFlag;

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, 640 / 480, 0.001, 10000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, loc, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void setupLights() {


	GLfloat lmodel_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	GLfloat l0Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat l0Spec[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat l0Ambient[] = { 0.1f, 0.0f, 0.0f, 1.0f };
	GLfloat l0Position[] = { 255.0f, 0.0f, 0.0f, 1 };
	GLfloat l0Direction[] = { -1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, l0Position);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, l0Direction);

	GLfloat l1Diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	GLfloat l1Ambient[] = { 0.0f, 0.1f, 0.0f, 1.0f };
	GLfloat l1Position[] = { 0.0f, 255.0f, 0.0f, 1 };
	GLfloat l1Direction[] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, l1Ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l1Direction);

	GLfloat l2Diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat l2Ambient[] = { 0.0f, 0.0f, 0.1f, 1.0f };
	GLfloat l2Position[] = { 0.0f, 0.0f, 255, 1 };
	GLfloat l2Direction[] = { 0.0, 0.0, -1.0 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, l2Diffuse);
	glLightfv(GL_LIGHT2, GL_AMBIENT, l2Ambient);
	glLightfv(GL_LIGHT2, GL_POSITION, l2Position);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l2Direction);

	GLfloat l3Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat l3Ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat l3Position[] = { 0.0f, 0.0f, loc + 10, 1 };
	GLfloat l3Direction[] = { 0.0, 0.0, -1.0 };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, l2Diffuse);
	glLightfv(GL_LIGHT3, GL_AMBIENT, l2Ambient);
	glLightfv(GL_LIGHT3, GL_POSITION, l2Position);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 90.0);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l2Direction);


}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	setupCamera();




	glPushMatrix();

	glRotated(rotx - 90, 1, 0, 0);
	glRotated(roty + 90, 0, 1, 0);
	glRotated(rotz, 0, 0, 1);
	setupLights();
	glTranslated(-133, -133, -87);




	glBegin(GL_TRIANGLES);
	glPushMatrix();

	//glColor3f(0.5, 0, 0);
	int i;
	for (i = 0; i < points.size()-2; i+=3)
	{
		if(colouredChoice == 2 )
		if (points[i].dataI < is)
			continue;


			glColor3f(points[i].dataV/255 , points[i].dataV/255 , points[i].dataV /255);
     		glVertex3f(points[i].dataX, points[i].dataY, points[i].dataZ);
	
			glColor3f(points[i+1].dataV / 255.0, points[i+1].dataV / 255.0, points[i+1].dataV / 255.0);
			glVertex3f(points[i+1].dataX, points[i + 1].dataY, points[i + 1].dataZ);

			glColor3f(points[i+2].dataV / 255.0, points[i+2].dataV / 255.0, points[i+2].dataV / 255.0);
			glVertex3f(points[i + 2].dataX, points[i + 2].dataY, points[i + 2].dataZ);



		}
	glEnd();

	glPopMatrix();

	cout << "done" << endl;

	glFlush();
}

void key(unsigned char k, int x, int y)
{

	if (k == 'a')
		rotx += 10;
	if (k == 's')
		rotx -= 10;
	if (k == 'd')
		roty += 10;
	if (k == 'f')
		roty -= 10;
	if (k == 'g')
		rotz += 10;
	if (k == 'h')
		rotz -= 10;

	if (k == 'q')
		is++;
	if (k == 'w')
		is--;

	if (k == 'e')
		sss /= 2;
	if (k == 'r')
		sss *= 2;

	if (k == 'z')
		loc -= 10;
	if (k == 'x')
		loc += 10;

	cout << rotx << " " << roty << " " << rotz << " " << is << " " << sss << " " << loc << endl;

	glutPostRedisplay();

}

void readFile5Points(string fileName) {
	int count = 0;


	short xx, yy, zz, vv, ii;
	ifstream myfile;
	myfile.open(fileName);
	//	myfile.open("DeluanyOutputWithColours.txt");

	while (myfile >> xx >> yy >> zz >> vv >> ii)
	{
		//		cout << xx;
		points.push_back({ xx, yy, zz, vv, ii });
		count++;
	}
	myfile.close();

	cout << "Finished reading " << count << " points." << endl;
}

void readFile4Points(string fileName) {
	int count = 0;

	short xx, yy, zz, vv;
	ifstream myfile;
	myfile.open(fileName);
	//	myfile.open("DeluanyOutputWithColours.txt");

	while (myfile >> xx >> yy >> zz >> vv )
	{
		//		cout << xx;
		points.push_back({ xx, yy, zz, vv, 0 });
		count++;
	}
	myfile.close();

	cout << "Finished reading " << count << " points." << endl;
}


void readFile3Points(string fileName) {
	int count = 0;


	short xx, yy, zz;
	ifstream myfile;
	myfile.open(fileName);
	//	myfile.open("DeluanyOutputWithColours.txt");

	while (myfile >> xx >> yy >> zz )
	{
		//		cout << xx;
		points.push_back({ xx, yy, zz, 255, 0 });
		count++;
	}
	myfile.close();

	cout << "Finished reading " << count << " points." << endl;
}

int main(int argc, char** argv)
{
	cout << "Please select a corrsponding number for one of the following actions." << endl;
	cout << "1) start triangulation." << endl;
	cout << "2) Apply triangulation without adding colours." << endl;
	cout << "3) add colours to the already existing triangulation." << endl;
	cout << "4) add colour and remove the front part of the brain ( only possible with the brain pointcloud dataset)." << endl;
	cout << "5) directly draw." << endl;
	
	cin >> choice;

	while (choice < 1 || choice > 5) {
		cout << "Please select one of the numbers from the list." << endl;
		cin >> choice;
	}


	
	if (choice == 1) {

		cout << "Please input the name of the .txt file you want to preform the triangulation (do not include .txt in the input)." << endl;
		cin >> inputFile;

		cout << "Use Delaunay triangulation or regular triangulation? press 1 for Delaunay triangulation and 2 for regular triangulation." << endl;
		cin >> triangulationType;
		
		while (triangulationType < 1 || triangulationType> 2) {
			cout << "Please choose a correct triangulation type." << endl;
			cin >> triangulationType;

		}
		
		cout << "Only coloured,coloured and remove front part of the brain or with no colours? press 1 for only coloured, 2 for removal  and 3 for no colours." << endl;
		cin >> colouredChoice;		

		while (colouredChoice < 1 || colouredChoice> 3) {
			cout << "Please choose a correct colouring choice." << endl;
			cin >> colouredChoice;

		}

		if (triangulationType == 1) 
			triangulationTypeFlag = true;
		else if (triangulationType == 2)
			triangulationTypeFlag = false;


		triangulation_CGAL(inputFile, triangulationTypeFlag);

		string addition;
		if (triangulationType == 1)
			addition = "_DeluanyTriangulation";
		else
			addition = "_NormalTriangulation";

		if (colouredChoice == 1){


			Manage_TraingulationOutput(inputFile , inputFile + addition,true,false );
			finalFile = inputFile + addition + "_Coloured.txt";
		}
		else if (colouredChoice == 2) {
			Manage_TraingulationOutput(inputFile , inputFile + addition,true,true );
			finalFile = inputFile + addition  + "_Coloured_RemovedFrontPart.txt";	
		}
		else {
			Manage_TraingulationOutput(inputFile, inputFile + addition, false, false);
			finalFile = inputFile +addition+ "_NoColours.txt";
		}
	}

	if (choice == 2) {

		cout << "Please input the name of the .txt file you want to preform the triangulation (do not include .txt in the input)." << endl;
		cin >> inputFile;

		cout << "Use Delaunay triangulation or regular triangulation? press 1 for Delaunay triangulation and 2 for regular triangulation." << endl;
		cin >> triangulationType;

		while (triangulationType < 1 || triangulationType> 2) {
			cout << "Please choose a correct triangulation type." << endl;
			cin >> triangulationType;

		}

		if (triangulationType == 1)
			triangulationTypeFlag = true;
		else if (triangulationType == 2)
			triangulationTypeFlag = false;

		string addition;
		if (triangulationType == 1)
			addition = "_DeluanyTriangulation";
		else
			addition = "_NormalTriangulation";


		triangulation_CGAL(inputFile, triangulationTypeFlag);
		Manage_TraingulationOutput(inputFile, inputFile + addition, false, false);

		finalFile = inputFile + addition + "_NoColours.txt";


	}


	if (choice == 3) {
		colouredChoice = 1;
		cout << "Please input the name of the .txt file you want to colour (do not include .txt in the input)." << endl;
		cin >> inputFile;
		string triangulatedInputFile;
		cout << "Please enter the name of the triangulated input file"<<endl;
		cin >> triangulatedInputFile;
		while (triangulationType < 1 || triangulationType> 2) {
			cout << "Please choose a correct triangulation type." << endl;
			cin >> triangulationType;

		}

		Manage_TraingulationOutput(inputFile, triangulatedInputFile, true, false);
		finalFile = triangulatedInputFile + "_Coloured.txt";

	}


	if (choice == 4) {
		colouredChoice = 2;
		cout << "Please input the name of the .txt file you want to preform the operations on (do not include .txt in the input)." << endl;
		cin >> inputFile;
		string triangulatedInputFile;
		cout << "Please enter the name of the triangulated input file" << endl;
		cin >> triangulatedInputFile;

		while (triangulationType < 1 || triangulationType> 2) {
			cout << "Please choose a correct triangulation type." << endl;
			cin >> triangulationType;

		}

		Manage_TraingulationOutput(inputFile, triangulatedInputFile, true, true);
		finalFile = triangulatedInputFile + "_Coloured_RemovedFrontPart.txt";

	}


	if (choice == 5) {

		cout << "Please input the name of the .txt file you want to draw (do not include .txt in the input)." << endl;
		cin >> inputFile;

		finalFile = inputFile + ".txt";

		cout << "Which one of the following colouring choices does the triangulation file use Only coloured,coloured and remove front    part of the brain or with no colours? press 1 for only coloured, 2 for removal  and 3 for no colours." << endl;
		cin >> colouredChoice;

		while (colouredChoice < 1 || colouredChoice> 3) {
			cout << "Please choose a correct colouring choice." << endl;
			cin >> colouredChoice;

		}


	}

	if(colouredChoice == 1)
	readFile4Points(finalFile);
	else if (colouredChoice == 2)
	readFile5Points(finalFile);
	else
	readFile3Points(finalFile);


	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(550, 50);	

	glutCreateWindow("Triangulated PointCloud");
	glutDisplayFunc(Display);
	glutKeyboardFunc(key);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_LIGHT2);
//	glEnable(GL_LIGHT3);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}
