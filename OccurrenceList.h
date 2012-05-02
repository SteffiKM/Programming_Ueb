#include "Occurrence.h"

#pragma once
class OccurrenceList
{
public:
	OccurrenceList(Occurrence *occ);
	~OccurrenceList(void);

	void addOccurrenceListAfter(OccurrenceList *occList);

	Occurrence* getOccurrence();
	OccurrenceList* getNext();
	OccurrenceList* getPrev();
	void setNext(OccurrenceList* next);
	void setPrev(OccurrenceList* prev);
	void setOccurrence(Occurrence *occ);

	void print();

private :
	Occurrence* occ;
	OccurrenceList *next;
	OccurrenceList *prev;
	void printUntil(OccurrenceList *occList);
};

