#pragma once
#include"Human.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

Human::Human()
{
	this->surname[0] = '\0';
	this->name[0] = '\0';
	this->year_of_birth = 0;
}

Human::Human(const char *surname, const char *name, const int year_of_birth)
{
	strcpy(this->surname, surname);
	strcpy(this->name, name);
	this->year_of_birth = year_of_birth;
}

Human::Human(const Human &obj)
{
	strcpy(this->surname, obj.surname);
	strcpy(this->name, obj.name);
	this->year_of_birth = obj.year_of_birth;
}

Human::~Human()
{
	this->surname[0] = '\0';
	this->name[0] = '\0';
	this->year_of_birth = 0;
}

void Human::Set_Surname(const char *surname)
{
	strcpy(this->surname, surname);
}

Human Human::Change_Surname(const char *surname)
{
	strcpy(this->surname, surname);

	return *this;
}

void Human::Set_Name(const char *name)

{
	strcpy(this->name, name);
}

void Human::Set_Year(const int year)
{
	this->year_of_birth = year;
}

char* Human::Get_Surname()
{
	return this->surname;
}

char* Human::Get_Name()
{
	return this->name;
}

int Human::Get_Year()
{
	return this->year_of_birth;
}

istream& operator>>(istream &in, Human &obj)
{
	cout << "¬ведите фамилию:" << endl;
	in >> obj.surname, 20;

	cout << "\n¬ведите им€:" << endl;
	in >> obj.name;

	cout << "\n¬ведите год рождени€:" << endl;
	while (!(in >> obj.year_of_birth))
	{
		cout << "ќшибка!!¬ведите числа!!!" << endl;
		cin.clear();
		cin.sync();
	}

	return in;
}

ostream& operator<<(ostream &out, Human &obj)
{
	out << setw(11) << obj.surname << "|"
	    << setw(11) << obj.name << "|"
	    << setw(14) << obj.year_of_birth << "|" << endl;

	return out;
}