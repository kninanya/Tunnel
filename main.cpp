#define _CRT_SECURE_NO_WARNINGS


//Here all classes are definde
#include <iostream> //Output
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <string>
#include <chrono>
//---
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>

#include  "io.h"
#include  "readfile.h"

//--

//Most populares -Testando!!1132165498461768!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//int main is the main function ALLWAYS!!!!

using namespace std;
using namespace std::chrono;

ExternFiles openfile;
ExternFiles readfile;
//-------------------------------------------------

int main(int argc, char *argv[])
{
	//--
	std::cout << "Tunnel Section" << endl;
	std::cout << "Date		:";
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	cout << " " << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
	std::cout << "__________________________________________________________________" << endl;
	std::cout << endl;



	//INPUT FILE
	char *Files_[2] = {NULL, NULL };
	Files_[1] = (char*)calloc(BUFSIZ, sizeof(char));

	if (argc < 2)
	{
		printf("Enter the input file with its extension : ");
		scanf("%s", Files_[1]);
	}
	else
	{
		strcpy(Files_[1], argv[1]);
	}

	if (!openfile.OpenFile(2, Files_))
	{
		return 0;
	}

	//READ FILE

	readfile.ReadFile();
	//----
	cout << "Axes" << endl;

	double width, height;
	double varx, a;
	int numvarx;
	double hypotenuse, sen, cos, hypotenuse0, sen0, cos0;

	cout << "Enter a width" << endl;
	cin >> width;

	cout << "Enter a height" << endl;
	cin >> height;

	hypotenuse0 = pow(pow(vectorNodes[1].y - vectorNodes[0].y, 2) + pow(vectorNodes[1].x - vectorNodes[0].x, 2), 0.5);
	sen0 = (vectorNodes[1].x - vectorNodes[0].x) / hypotenuse0;
	cos0 = (vectorNodes[1].y - vectorNodes[0].y) / hypotenuse0;
	vectorNodes[0].xl = vectorNodes[0].x - width * cos0;
	vectorNodes[0].yl = vectorNodes[0].y + width * sen0;
	vectorNodes[0].zl = vectorNodes[0].z;
	vectorNodes[0].xr = vectorNodes[0].x + width * cos0;
	vectorNodes[0].yr = vectorNodes[0].y - width * sen0;
	vectorNodes[0].zr = vectorNodes[0].z;
	for (int i = 1; i < numNodes; i++)
	{
		vectorNodes[i].hypotenuse = pow(pow(vectorNodes[i].y - vectorNodes[i-1].y, 2) + pow(vectorNodes[i].x - vectorNodes[i-1].x, 2), 0.5);
		vectorNodes[i].sen = (vectorNodes[i].x - vectorNodes[i-1].x) / vectorNodes[i].hypotenuse;
		vectorNodes[i].cos = (vectorNodes[i].y - vectorNodes[i-1].y) / vectorNodes[i].hypotenuse;
		vectorNodes[i].xl = vectorNodes[i].x - width * vectorNodes[i].cos;
		vectorNodes[i].yl = vectorNodes[i].y + width * vectorNodes[i].sen;
		vectorNodes[i].zl = vectorNodes[i].z;
		vectorNodes[i].xr = vectorNodes[i].x + width * vectorNodes[i].cos;
		vectorNodes[i].yr = vectorNodes[i].y - width * vectorNodes[i].sen;
		vectorNodes[i].zr = vectorNodes[i].z;
	}

	cout << "left side" << endl;

	for (int i = 0; i < numNodes; i++)
	{
		cout << vectorNodes[i].id << " " << vectorNodes[i].xl << " " << vectorNodes[i].yl << " " << vectorNodes[i].zl << " " << endl;
	}

	cout << "right side" << endl;
	for (int i = 0; i < numNodes; i++)
	{
		cout << vectorNodes[i].id << " " << vectorNodes[i].xr << " " << vectorNodes[i].yr << " " << vectorNodes[i].zr << " " << endl;

	}

	//Parabola section
	varx = width / 10;
	
	cout << "Enter the amount of points for parabola section" << endl;
	cin >> numvarx;

	a = -(0 - height) / pow(width, 2);

	for (int i = 0; i < numNodes; i++)
	{
		for (int k = 0; k < numvarx; k++)
		{
		    vectorNodes[i].x3d[k] = vectorNodes[i].xl + varx * k;
			vectorNodes[i].z3D[k] = -a * pow(vectorNodes[i].x3d[k] - (vectorNodes[i].xl + width), 2) + height;
		}

		vectorNodes[i].cos3D = 1 - ((pow(vectorNodes[i].xr- vectorNodes[i].x3d[numvarx - 1], 2) + pow(vectorNodes[i].yr - vectorNodes[i].yl, 2)) / (2 * pow(2 * width, 2)));
		vectorNodes[i].sen3D = pow(1 - pow(vectorNodes[i].cos3D, 2), 0.5);
				
			for (int k = 0; k < numvarx; k++)
		{
		vectorNodes[i].x3D[k] = vectorNodes[i].xl + varx *k*vectorNodes[i].cos3D;
		
			if (vectorNodes[i].yl>vectorNodes[i].yr)
				{
				vectorNodes[i].y3D[k] = vectorNodes[i].yl + varx * k*vectorNodes[i].sen3D;
				}
			else
				{
				vectorNodes[i].y3D[k] = vectorNodes[i].yl - varx * k*vectorNodes[i].sen3D;
				}
 		}
	}

	cout << "3d" << endl;
	for (int i = 0; i < numNodes; i++)
	{
		for (int k = 0; k < numvarx; k++)
		{
			cout << vectorNodes[i].x3d[k] << " " << endl;
		}
	}

	cout << "3D" << endl;
	for (int i = 0; i < numNodes; i++)
	{
		for (int k = 0; k < numvarx; k++)
		{
			cout << vectorNodes[i].x3D[k] << " " << vectorNodes[i].z3D[k] << " " << endl;
		}
	}

	//id, x, y, z, description

	char *Exported[2] = {NULL, NULL };

	Exported[0] = (char *)calloc(BUFSIZ, sizeof(char));
	Exported[1] = (char *)calloc(BUFSIZ, sizeof(char));


	for (int i = 0; i < 2; i++)
	{
		printf("Enter the name for the surface  ");
		cout << i+1 << endl;
		scanf("%s", Exported[i]);		
	}
	

	strcat(Exported[0],".txt");
	strcat(Exported[1], ".txt");
	ofstream Upper(Exported[0]);
	ofstream Lower(Exported[1]);


	ExternFiles exported;

	exported.Exportfile(numNodes, Upper);
	exported.Exportfile(numNodes, Lower);



	//Enter the exported file name
	//filename.txt


	//for compiling press F5


	system("pause"); //trick

	//return 0; //return beacause the main fucntion is "int", unlike void-> here is not necessary to define a return
}