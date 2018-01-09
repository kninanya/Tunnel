#ifndef IO_H
#define IO_H

#include <string>
#include "readfile.h"
#include <fstream>

//public functions - Interface

class ExternFiles : public Readsubtitles
{
public:
	int OpenFile(int, char *[]);
	int ReadFile(void);
	void Exportfile(int, std::ostream&);


};

#endif // !IO_H
