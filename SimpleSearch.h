#pragma once
#include "searchalgorithm.h"
class SimpleSearch :
	public SearchAlgorithm
{
public:
	SimpleSearch(void);
	~SimpleSearch(void);

	int search(char *haystack, char *needle);

private:
	bool haystackStartsWith(char *haystack, char *needle);
};

