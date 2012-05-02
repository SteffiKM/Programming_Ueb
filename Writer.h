#include "OccurrenceList.h"
#include <fstream>
using namespace std;

#pragma once
class Writer
{
public:
	Writer(void);
	~Writer(void);

	void writeToFile(OccurrenceList *occList, char* comment);

private:
	char* filePath;
};

