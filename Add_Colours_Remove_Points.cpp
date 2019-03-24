#include "pch.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;


short remove_DataXTri[1947917];
short remove_DataYTri[1947917];
short remove_DataZTri[1947917];
short remove_DataVTri[1947917];
short remove_DataITri[1947917];


short remove_DataX[1947917];
short remove_DataY[1947917];
short remove_DataZ[1947917];
short remove_DataV[1947917];
short remove_DataI[1947917];


short remove_Colours[1947917];


int Add_Colours_RemovePoints (string originalFile, string newFile)
{
	short xx, yy, zz, vv, ii;
	ifstream myfile;
	myfile.open(newFile + ".txt");
	myfile.ignore(10000, '\n');
	myfile.ignore(10000, '\n');
	int count = 0;
	while (myfile >> xx >> yy >> zz)
	{
		remove_DataXTri[count] = xx;
		remove_DataYTri[count] = yy;
		remove_DataZTri[count] = zz;
		count++;
	}
	myfile.close();

	myfile.open(originalFile + ".txt");
	count = 0;
	while (myfile >> xx >> yy >> zz >> vv >> ii)
	{
		remove_DataX[count] = xx;
		remove_DataY[count] = yy;
		remove_DataZ[count] = zz;
		remove_DataV[count] = vv;
		remove_DataI[count] = ii;

		count++;
	}
	myfile.close();

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1947917; i++) {
		if (i == 1000000 || i == 1500000 || i == 500000) {
			std::cout <<"Finished " << i << " points."<<endl;
			auto finish1 = chrono::high_resolution_clock::now();
			chrono::duration<double> endTime = finish1 - start;

			std::cout << "Elapsed time: " << endTime.count() / 60 << " minutes.\n";

		}


		for (int j = 0; j < 1947917; j++) {
			if (remove_DataXTri[i] == remove_DataX[j] && remove_DataYTri[i] == remove_DataY[j] 
				&& remove_DataZTri[i] == remove_DataZ[j]) {
				remove_DataVTri[i] = remove_DataV[j];
				remove_DataITri[i] = remove_DataI[j];

				break;
			}

		}
	}
	std::cout << "done creating coloured output." << endl;
	const string fileName = originalFile+"_Triangulated_Coloured_RemovedFrontPart.txt";
	ofstream outData;
	ofstream outfile(fileName);
	outData.open(fileName);
	count = 0;
	for(int i =0 ; i< 1947917;i++){

	outData << remove_DataXTri[i] << " ";
	outData << remove_DataYTri[i] << " ";
	outData << remove_DataZTri[i] << " ";
	outData << remove_DataVTri[i] << " ";
	outData << remove_DataITri[i] << endl;
//	cout << i<< endl;
//	cout << dataXTri[i] << endl;
	count++;
	}
	std::cout << "writing " << count << " points" << endl;

	auto finish2 = chrono::high_resolution_clock::now();
	chrono::duration<double> endTime = finish2 - start;

	std::cout << "Colouring and removing Sucessful, Elapsed time: " << endTime.count() / 60 << " m\n";

	return EXIT_SUCCESS;
}
