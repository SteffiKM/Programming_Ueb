#include "StdAfx.h"
#include "SuperString.h"
#include "SearchAlgorithm.h"



SuperString::SuperString(char *string, int length)
{
	this->string = string;
	this->length = length;

	SearchAlgorithm *searchAlgo = new SimpleSearch();
}


SuperString::~SuperString(void)
{
}

char* SuperString::getString(void) {
	return this->string;
}

int SuperString::getLength(void) {
	return this->length;
}

int SuperString::find(SuperString *needle) {
	return searchAlgo->search(this->string, needle->string);
}