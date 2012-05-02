#include "StdAfx.h"
#include "AlgorithmSimpleSearch.h"
#include <iostream>

AlgorithmSimpleSearch::AlgorithmSimpleSearch(void)
{
}


AlgorithmSimpleSearch::~AlgorithmSimpleSearch(void)
{
}


int AlgorithmSimpleSearch::search(SuperString *haystack, SuperString *needle){
	int i = 0;
	char *haystackString = haystack->getString();
	char *needleString = needle->getString();

	//std::cout << "SimpleSearch::search genom: " << haystack << " - needle: " << needle << std::endl;
	//std::cout <<  "Size Haystack: " << lengthHaystack << " Size Needle: " << lengthNeedle << std::endl;

	while(haystackString[i] != '\0'){
		//std::cout << "c: " << haystack[i] << " n: " << needle[0] << std::endl;
		if ((haystackString[i] == needleString[0]) && (haystackStartsWith(&haystackString[i], needleString)))
			return i;
		i++;
	}

	return -1;
}

OccurrenceList* AlgorithmSimpleSearch::searchAll(SuperString *haystack, SuperString *needle){
	int i = 0;
	char *haystackString = haystack->getString();
	char *needleString = needle->getString();
	SuperString *currNeedle = new SuperString(needleString, needle->getLength());
	OccurrenceList *occList = NULL;

	while(haystackString[i] != '\0'){
		if ((haystackString[i] == needleString[0]) && (haystackStartsWith(&haystackString[i], needleString))){
			Occurrence *occ = new Occurrence(currNeedle, i);
			if (occList == NULL){
				occList = new OccurrenceList(occ);
				//cout << "first occ found." << endl;
			} else {
				occList->addOccurrenceListAfter(new OccurrenceList(occ));
				//cout << "occ found." << endl;
			}
		}
		i++;
	}

	return occList;
}

bool AlgorithmSimpleSearch::haystackStartsWith(char *haystack, char *needle){
	int i = 0;

	//std::cout << "SimpleSearch::haystackStartsWith genom: " << haystack << " - needle: " << needle << std::endl;

	while(haystack[i] != '\0'){
		//std::cout << "HSW  c: " << haystack[i] << " n: " << needle[i] << std::endl;
		if (haystack[i] != needle[i]){
			if (needle[i] == '\0')
				return true;
			else 
				return false;
		}
		i++;
	}
	return needle[i] == '\0';
}


void AlgorithmSimpleSearch::incArraySize(int* intArray, int newLength){
	void *temp; 
	temp = realloc ( intArray, newLength * sizeof(*intArray) ); 
	if ( temp != NULL ) { 
		//intArray = temp; 
	}

}
