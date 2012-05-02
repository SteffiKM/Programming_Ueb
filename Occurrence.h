#include "SuperString.h"
#include <iostream>
using namespace std;

#pragma once
class Occurrence
{
public:
	Occurrence(SuperString *occString, int pos);
	~Occurrence(void);
	void print();

private:
	SuperString *occString;
	int pos;
};

