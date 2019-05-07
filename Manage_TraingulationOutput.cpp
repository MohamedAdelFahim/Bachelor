#include "pch.h"

#include <string>
#include <iostream>
#include <fstream>	
#include <vector>
#include <chrono>

using namespace std;


int length = 0;

std::vector <short> dataX;
std::vector <short> dataY;
std::vector <short> dataZ;
std::vector <short> dataV;
std::vector <short> dataI;


std::vector <short> dataXTri;
std::vector <short> dataYTri;
std::vector <short> dataZTri;
std::vector <short> dataVTri;
std::vector <short> dataITri;


int Manage_TraingulationOutput(string originalFile, string newFile, bool coloured, bool remove)
{


	short xx, yy, zz, vv, jj;
	ifstream myfile;

	myfile.open(newFile + ".txt");
	myfile.ignore(10000, '\n');
	
	string str;
	std::getline(myfile, str);
	length = std::stoi(str);

	dataX.reserve(length);
	dataY.reserve(length);
	dataZ.reserve(length);
	dataV.reserve(length);
	dataI.reserve(length);

	dataXTri.reserve(length);
	dataYTri.reserve(length);
	dataZTri.reserve(length);
	dataVTri.reserve(length);
	dataITri.reserve(length);

	while (myfile >> xx >> yy >> zz)
	{
		dataXTri.push_back(xx);
		dataYTri.push_back(yy);
		dataZTri.push_back(zz);

	}
	myfile.close();

	

	
	int count = 0;
	
	
	if(coloured)
		myfile.open(originalFile + ".txt");

	while (myfile >> xx >> yy >> zz >> vv >> jj)
	{
		dataX.push_back(xx);
		dataY.push_back(yy);
		dataZ.push_back(zz);
		dataV.push_back(vv);
		dataI.push_back(jj);
	}
	
	myfile.close();

	short *dataXPTri = &dataXTri[0];
	short *dataYPTri = &dataYTri[0];
	short *dataZPTri = &dataZTri[0];
	
	auto start = std::chrono::high_resolution_clock::now();
	if (coloured) {
		short *dataXP = &dataX[0];
		short *dataYP = &dataY[0];
		short *dataZP = &dataZ[0];
		short *dataVP = &dataV[0];
		short *dataIP = &dataI[0];


		for (int i = 0; i < length; i++) {
			if (i == 1000000 || i == 1500000 || i == 500000) {

				std::cout << "Finished " << i << " points." << endl;

				auto finish1 = chrono::high_resolution_clock::now();
				chrono::duration<double> endTime = finish1 - start;

				std::cout << "Elapsed time: " << endTime.count() / 60 << " minutes.\n";

			}

			for (int j = 0; j < length; j++) {

				if (*(dataXPTri + i) == *(dataXP + j) && *(dataYPTri + i) == *(dataYP + j) && *(dataZPTri + i) == *(dataZP + j)) {
					dataVTri.push_back(*(dataVP + j));
					if (remove)
						dataITri.push_back(*(dataIP + j));
					break;
				}

			}
		}
	}


		std::cout << "done creating desired output." << endl;
		string fileName;
	
		if (coloured && remove) {
			fileName = newFile + "_Coloured_RemovedFrontPart.txt";
		}
		else if (coloured && !remove) {
			fileName = newFile + "_Coloured.txt";
		}
		else {
			fileName = newFile + "_NoColours.txt";
		}
		ofstream outData;
		ofstream outfile(fileName);
		outData.open(fileName);
		count = 0;
		for (int i = 0; i < length; i++) {

			outData << dataXTri[i]<< " ";
			outData << dataYTri[i]<< " ";

			if (coloured && remove) {
				outData << dataZTri[i] << " ";
				outData << dataVTri[i] << " ";
				outData << dataITri[i] << endl;

			}
			else if (coloured && !remove) {
				outData << dataZTri[i] << " ";
				outData << dataVTri[i] << endl;

			}
			else {
				outData << dataZTri[i] << endl;
			}

			count++;
		}
		std::cout << "writing " << count << " points." << endl;
	

	auto finish2 = chrono::high_resolution_clock::now();
	chrono::duration<double> endTime = finish2 - start;




	std::cout << "Operation Sucessful, Elapsed time: " << endTime.count() / 60 << " minutes.\n";
	
	return EXIT_SUCCESS;
}
