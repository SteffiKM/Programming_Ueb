#include "searchalgorithm.h"
#include "SimpleSearch.h"

#pragma once
class SuperString
{
public:
	SuperString(char *res, int length);
	~SuperString(void);
	
	char* getString(void);
	int getLength(void);
	int SuperString::find(SuperString *needle);

private:
	char *string;
	int length;
	SearchAlgorithm *searchAlgo;
};

