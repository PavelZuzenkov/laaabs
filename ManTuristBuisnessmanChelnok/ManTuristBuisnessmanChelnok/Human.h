#pragma once
#include <iostream>
#include <iomanip>
#include "File.h"

using namespace std;

class Human
{
protected:
	char surname[20];
	char name[20];
	int year_of_birth;
public:
	Human();
	Human(const char *, const char*, const int);
	Human(const Human&);
	~Human();
	void Set_Surname(const char*);
	void Set_Name(const char*);
	void Set_Year(const int);

	Human Change_Surname(const char*);

	char* Get_Surname();
	char* Get_Name();
	int Get_Year();
	friend ostream& operator<<(ostream&, Human &);
	friend istream& operator>>(istream&, Human&);
};