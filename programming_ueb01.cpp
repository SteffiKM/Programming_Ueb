// programming_ueb01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reader.h"
#include "AlgorithmSimpleSearch.h"
#include "AlgorithmBoyerMooreHorspool.h"
#include "SuperString.h"
#include <iostream>
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	Reader *reader = new Reader();

	OccurrenceList *occList = NULL;

	SuperString *genom = reader->getGenom();
	SuperString *dummygenom0 = reader->getDummyGenom(0);
	SuperString *dummygenom1 = reader->getDummyGenom(1);
	SuperString *dummygenom2 = reader->getDummyGenom(2);

	SuperString *pattern0 = reader->getPattern(0);
	SuperString *pattern1 = reader->getPattern(1);
	SuperString *pattern2 = reader->getPattern(2);
	
	AlgorithmSearch *searchAlgo = new AlgorithmSimpleSearch();
	cout << endl << "--AlgorithmSimpleSearch--" << endl;
	cout << "res: " << searchAlgo->search(genom, pattern0) << endl;
	cout << "res: " << searchAlgo->search(genom, pattern1) << endl;
	cout << "res: " << searchAlgo->search(genom, pattern2) << endl;

	searchAlgo = new AlgorithmBoyerMooreHorspool();
	cout << endl << "--AlgorithmBoyerMooreHorspool--" << endl;
	cout << "res: " << searchAlgo->search(genom, pattern0) << endl;
	cout << "res: " << searchAlgo->search(genom, pattern1) << endl;
	cout << "res: " << searchAlgo->search(genom, pattern2) << endl;

	searchAlgo = new AlgorithmSimpleSearch();
	cout << endl << "--AlgorithmSimpleSearch--dummygenom--" << endl;
	cout << "res: " << searchAlgo->search(dummygenom1, pattern0) << endl;
	cout << "res: " << searchAlgo->search(dummygenom1, pattern1) << endl;
	cout << "res: " << searchAlgo->search(dummygenom1, pattern2) << endl;

	cout << endl << "--AlgorithmSimpleSearch--dummygenom--"  << endl;
	occList = searchAlgo->searchAll(dummygenom0, pattern2);
	if (occList != NULL){
		occList->print();
	} else {
		cout << "Nothing found."  << endl;
	}

	occList = searchAlgo->searchAll(dummygenom1, pattern2);
	if (occList != NULL){
		occList->print();
	} else {
		cout << "Nothing found."  << endl;
	}

	occList = searchAlgo->searchAll(dummygenom2, pattern2);
	if (occList != NULL){
		occList->print();
	} else {
		cout << "Nothing found."  << endl;
	}

	/*searchAlgo = new AlgorithmBoyerMooreHorspool();
	cout << "--AlgorithmBoyerMooreHorspool--dummygenom--" << endl << endl;
	cout << "res: " << searchAlgo->search(dummygenom, pattern1) << endl;
	cout << "res: " << searchAlgo->search(dummygenom, pattern2) << endl;
	cout << "res: " << searchAlgo->search(dummygenom, pattern3) << endl;*/



	int dummy;
	cin >> dummy;

	reader->~Reader();
	delete genom;
	delete pattern0;
	delete pattern1;
	delete pattern2;

	return 0;
}

