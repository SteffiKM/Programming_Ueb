#include "StdAfx.h"
#include "Writer.h"


Writer::Writer(void)
{
	this->filePath = "output.txt";
	ofstream file (filePath, ios::trunc);
	if (file.is_open()) file.close();
}


Writer::~Writer(void)
{
}


void Writer::writeToFile(OccurrenceList *occList, char* comment){
	occList != NULL ? occList->print() : cout << "Nothing found."  << endl;
	ofstream file (filePath, ios::app);
	if (file && file.is_open()){
		if (comment != NULL) file << comment << endl;
		if (occList != NULL){
			occList->printToFile(&file);
		} else {
			file << "Nothing found.\n";
		}
		file.close();
	}
}
