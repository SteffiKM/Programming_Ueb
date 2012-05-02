#include "SuperString.h"
#include "algorithmsearch.h"

#pragma once
class AlgorithmBoyerMooreHorspool : public AlgorithmSearch {
public:
	AlgorithmBoyerMooreHorspool(void);
	~AlgorithmBoyerMooreHorspool(void);

	int search(SuperString *haystack, SuperString *needle);
	OccurrenceList* searchAll(SuperString *haystack, SuperString *needle);
};

