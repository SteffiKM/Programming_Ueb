#pragma once
#include "AlgorithmSearch.h"
class AlgorithmSimpleSearch :
	public AlgorithmSearch
{
public:
	AlgorithmSimpleSearch(void);
	~AlgorithmSimpleSearch(void);

	int search(SuperString *haystack, SuperString *needle);
	OccurrenceList* searchAll(SuperString *haystack, SuperString *needle);

private:
	bool haystackStartsWith(char *haystack, char *needle);
	void incArraySize(int* intArray, int newLength);
};

