#include "SuperString.h"

#pragma once
class Reader
{
public:
	Reader(void);
	~Reader(void);

	SuperString* getGenom();
	SuperString* getPattern(int index);

private:
	SuperString* readFile(char* filePath);
};

