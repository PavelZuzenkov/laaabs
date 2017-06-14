#pragma once
#include<iostream>
#include "Human.h"

using namespace std;

class Businessman : public Human
{
protected:
	int license;
	char *address;
public:
	Businessman();
	Businessman(const char*, const char*, const int, const int, const char*);
	Businessman(const Businessman&);
	~Businessman();
	
	void Set_license(const int);
	void Set_address(const char*);
	
	int  Get_license();
	char* Get_address();
	
	void Redact();
	void Shapka();
	
	Businessman &operator=(const Businessman&);
	bool operator ==(Businessman&);
	friend ostream& operator<<(ostream&, Businessman&);
	friend istream& operator>>(istream&, Businessman&);
	friend fstream &operator >>(fstream&, Businessman&);
	friend fstream &operator <<(fstream&, Businessman&);
};