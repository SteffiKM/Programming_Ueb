#include "StdAfx.h"
#include "SimpleSearch.h"
#include <iostream>

SimpleSearch::SimpleSearch(void)
{
}


SimpleSearch::~SimpleSearch(void)
{
}


int SimpleSearch::search(char *haystack, char *needle){
	int i = 0;

	std::cout << "SimpleSearch::search genom: " << haystack << " - needle: " << needle << std::endl;
	//std::cout <<  "Size Haystack: " << lengthHaystack << " Size Needle: " << lengthNeedle << std::endl;

	while(haystack[i] != '\0'){
		std::cout << "c: " << haystack[i] << " n: " << needle[0] << std::endl;
		if ((haystack[i] == needle[0]) && (haystackStartsWith(&haystack[i], needle)))
			return i;
		i++;
	}

	return -1;
}

bool SimpleSearch::haystackStartsWith(char *haystack, char *needle){
	int i = 0;

	std::cout << "SimpleSearch::haystackStartsWith genom: " << haystack << " - needle: " << needle << std::endl;

	while(haystack[i] != '\0'){
		std::cout << "HSW  c: " << haystack[i] << " n: " << needle[i] << std::endl;
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
