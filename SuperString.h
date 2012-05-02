#pragma once
class SuperString
{
public:
	SuperString(char *res, int length);
	~SuperString(void);
	
	char* getString();
	int getLength();
	void print();

private:
	char *string;
	int length;
};