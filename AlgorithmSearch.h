#include "SuperString.h"
#include "OccurrenceList.h"

#pragma once
class AlgorithmSearch
{
public:
	AlgorithmSearch(void) {};
	~AlgorithmSearch(void) {};

	virtual int search(SuperString *haystack, SuperString *needle) = 0;
	virtual OccurrenceList* searchAll(SuperString *haystack, SuperString *needle) = 0;

	const static int minMatchLength = 1;
};

