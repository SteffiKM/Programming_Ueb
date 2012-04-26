#pragma once
class Reader
{
public:
	Reader(void);
	~Reader(void);

	char* getGenom();
	char* getPattern(int index);
};

