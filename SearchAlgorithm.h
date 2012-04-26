#pragma once
class SearchAlgorithm
{
public:
	SearchAlgorithm(void) {};
	~SearchAlgorithm(void) {};

	virtual int search(char *haystack, char *needle) = 0;
};

