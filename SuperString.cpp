#include "StdAfx.h"
#include "SuperString.h"
#include "AlgorithmSearch.h"


SuperString::SuperString(char *string, int length)
{
	this->string = string;
	this->length = length;

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

void SuperString::print(){
	cout << this->string;
}