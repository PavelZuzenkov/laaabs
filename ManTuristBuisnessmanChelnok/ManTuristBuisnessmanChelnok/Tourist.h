#pragma once
#include <iostream>
#include "Human.h"

using namespace std;

class Tourist : public Human
{
protected:
	char passport[20];
	struct board
	{
		char outborder[20];
		char inborder[20];
	}b[2];

public:
	Tourist();
	Tourist(const char*, const char*, const int, const char*, const char*, const char*);
	~Tourist();
	Tourist(const Tourist&);

	void Set_passport(const char*);
	void Set_OUTborder(const char*, const int);
	void Set_INborder(const char*, const int);

	char* Get_passport();
	char* Get_outborder(const int);
	char* Get_inborder(const int);
	
	bool operator ==(const Tourist&);
	Tourist &operator=(const Tourist&);
	friend ostream& operator<<(ostream&, Tourist&);
	friend istream& operator>>(istream&, Tourist&);
	friend fstream &operator >>(fstream&, Tourist&);
	friend fstream &operator <<(fstream&, Tourist&);

	void Redact();
	void Shapka();
};
