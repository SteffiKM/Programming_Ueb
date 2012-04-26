#include "StdAfx.h"
#include "Reader.h"


Reader::Reader(void)
{
}


Reader::~Reader(void)
{
}


char* Reader::getGenom(){
	return "qwertzuiopasdfghjklyxcvbnmqwtzui";
}

char* Reader::getPattern(int index){
	if (index == 0)
		return "wer";
	else if (index == 1)
		return "foo";

	return NULL;
}
