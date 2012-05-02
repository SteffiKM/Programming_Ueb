#include "StdAfx.h"
#include "OccurrenceList.h"


OccurrenceList::OccurrenceList(Occurrence *occ)
{
	this->next = this;
	this->prev = this;
	this->occ = occ;
}


OccurrenceList::~OccurrenceList(void)
{
	while (this->next != this){
		this->setNext(this->next->next);
		delete this->next->getPrev();
		this->next->setPrev(this);
	}
	delete this;
}


void OccurrenceList::addOccurrenceListAfter(OccurrenceList *occList){
	this->next->setPrev(occList->getPrev());
	occList->getPrev()->setNext(this->next);
	this->setNext(occList);
	occList->setPrev(this);
}

Occurrence* OccurrenceList::getOccurrence(){
	return this->occ;
}

OccurrenceList* OccurrenceList::getNext(){
	return this->next;
}

OccurrenceList* OccurrenceList::getPrev(){
	return this->prev;
}


void OccurrenceList::setNext(OccurrenceList* next){
	this->next = next;
}

void OccurrenceList::setPrev(OccurrenceList* prev){
	this->prev = prev;
}

void OccurrenceList::setOccurrence(Occurrence *occ){
	this->occ = occ;
}


void OccurrenceList::print(){
	this->occ->print();
	this->next->printUntil(this);
}

void OccurrenceList::printUntil(OccurrenceList *occList){
	if (occList != this){
		this->occ->print();
		this->next->printUntil(occList);
	}
}