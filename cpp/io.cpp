#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <fstream>
#include "io.h"
#include "readfile.h"



using namespace std;

static char inputfile[BUFSIZ];
static FILE *_ioData = NULL;




int ExternFiles::OpenFile(int argc, char*argv[])
{
	if (argc>1)
	{
		strcpy(inputfile, argv[1]);
	}
	else
	{
		return 1;
	}

	if ((_ioData = fopen(inputfile, "r")) == NULL)
	{
		return 0;
	}

	return 1;
}

int ExternFiles::ReadFile()
{
	pointerFile(_ioData);
	subtitles();

	return 1;
}

void ExternFiles::Exportfile(int numNodes, std::ostream &os)
{
	int space=10;
	os << "right side" << endl;
	for (int i = 0; i < numNodes; i++)
	{
		os << vectorNodes[i].id << setw(space) << vectorNodes[i].xr << setw(space) << vectorNodes[i].yr << setw(space) << vectorNodes[i].zr << endl;
	}
}
