#include "StdAfx.h"
#include "Occurrence.h"


Occurrence::Occurrence(SuperString *occString, int pos){
	this->occString = occString;
	this->pos = pos;
}


Occurrence::~Occurrence(void)
{
}

void Occurrence::print(void)
{	
	cout << "OccString: " << occString->getString() << " @ " << pos << endl;
}