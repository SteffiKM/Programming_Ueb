#include "StdAfx.h"
#include "Reader.h"

#include "SuperString.h"

#include <iostream>
#include <fstream>
using namespace std;


char* genomFilePath = "E:/htw/programming/ueb1/GenomProbe.txt";


Reader::Reader(void)
{
}


Reader::~Reader(void)
{
}



SuperString* Reader::readFile(char* filePath){
	FILE *fp;
	long len;
	char *res;
	fp=fopen(filePath,"rb");
	fseek(fp,0,SEEK_END); //go to end
	len = ftell(fp); //get position at end (length)
	fseek(fp,0,SEEK_SET); //go to beg.
	res = (char *)malloc(len); //malloc buffer
	fread(res,len,1,fp); //read into buffer
	fclose(fp);

	SuperString *result = new SuperString(res, len);

	return result;
}


SuperString* Reader::getGenom(){
	return readFile(genomFilePath);
}

SuperString* Reader::getDummyGenom(int index){
	SuperString *result = NULL;
	if (index == 0)
		result = new SuperString("qwertzuiopasdfghjklyxcvbnmqwtzui", 32);
	else if (index == 1)
		result = new SuperString("GGGGGGAGTGGGGGGGAGTAAGGGTTTTAGTT", 32);
	else if (index == 2)
		result = new SuperString("AGTAGTAGTAGTAGTAGTAGTAGTAGTAGTAGT", 33);

	return result;
}

SuperString* Reader::getPattern(int index){
	SuperString *result = NULL;
	if (index == 0)
		result = new SuperString("FOO", 3);
	else if (index == 1)
		result = new SuperString("BAR", 3);
	else if (index == 2)
		result = new SuperString("AGT", 3);

	return result;
}