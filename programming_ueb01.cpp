// programming_ueb01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reader.h"
#include "SearchAlgorithm.h"
#include "SimpleSearch.h"
#include <iostream>
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	Reader *reader = new Reader();
	SearchAlgorithm *searchAlgo = new SimpleSearch();
	char *genom = reader->getGenom();
	char *pattern1 = reader->getPattern(0);
	char *pattern2 = reader->getPattern(1);
	
	cout << "genom: " << genom << " - pattern1: " << pattern1 << " - pattern2: " << pattern2 << endl;
	
	cout << "res: " << searchAlgo->search(genom, pattern1) << endl;
	cout << "res: " << searchAlgo->search(genom, pattern2) << endl;


	int dummy;
	cin >> dummy;

	cout << "destruct" << endl;
	cout << "genom: " << genom << " - pattern1: " << pattern1 << " - pattern2: " << pattern2 << endl;

	reader->~Reader();
	delete genom;
	delete pattern1;
	delete pattern2;

	return 0;
}

