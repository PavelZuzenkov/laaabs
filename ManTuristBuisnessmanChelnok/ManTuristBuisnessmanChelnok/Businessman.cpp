#pragma once
#include<iostream>
#include "Human.h"
#include"Businessman.h"
#include<string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

Businessman::Businessman() :Human()
{
	this->license = 0;
	this->address = nullptr;
}

Businessman::Businessman(const char *surname, const char *name, const int year_of_birth, const int license, const char * address)
: Human(surname, name, year_of_birth)
{
	this->license = license;
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

Businessman::Businessman(const Businessman & obj) :Human(obj)
{
	this->license = obj.license;
	this->address = new char[strlen(obj.address) + 1];
	strcpy(this->address, obj.address);
}

Businessman::~Businessman()
{
	delete[] this->address;
}

void Businessman::Set_license(const int license)
{
	this->license = license;
}

void Businessman::Set_address(const char *address)
{
	if (this->address)
		delete[] this->address;
	
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}


int Businessman::Get_license()
{
	return this->license;
}

char * Businessman::Get_address()
{
	return this->address;
}

istream& operator>>(istream &in, Businessman &obj)
{
	cout << "\n������� ������� ���������������:" << endl;
	in >> obj.surname;

	cout << "\n������� ��� ���������������:" << endl;
	in >> obj.name;

	cout << "\n������� ��� �������� ���������������:" << endl;
	while (!(in >> obj.year_of_birth))
	{
		cout << "\n������!!������� �����!!!" << endl;
		cin.clear();
		cin.sync();
	}

	cout << "\n������� �����  �������� ���������������:" << endl;
	while (!(in >> obj.license))
	{
		cout << "\n������!!������� �����!!!" << endl;
		cin.clear();
		cin.sync();
	}

	cout << "\n������� ����� �����������:" << endl;
	if (obj.address)
		delete[] obj.address;
	
	obj.address = new char[20];
	in >> obj.address;

	return in;
}

ostream& operator<<(ostream &out, Businessman &obj)
{
	out   << setw(11) << obj.Get_Surname() << "|"
		  << setw(11) << obj.Get_Name() << "|"
		  << setw(14) << obj.Get_Year() << "|"
		  << setw(14) << obj.Get_license() << "|"
		  << setw(17) << obj.Get_address() << "|" << endl;
	out << "------------------------------------------------------------------------";
	
	return out;
}

fstream &operator >>(fstream &fin, Businessman &obj)
{
	if (!fin.good())
		cerr<<"\n������ ������� ���� ��� ������\n";
	if (fin.bad())
	{
		cerr << "\n�������� ����� ����������\n";
		fin.clear(ios::badbit);
	}
	if (fin.eof())
	{
		cerr << "\n��������� ����� �����\n";
		fin.clear(ios::eofbit);
	}
	 return fin;
}

fstream &operator <<(fstream &fout, Businessman &obj)
 {
	if (fout.fail())
		cerr << "\n������ ������� ���� ��� ������\n";
	 return fout;
 }

Businessman &Businessman::operator = (const Businessman &obj)
{
	if (this != &obj)
	{
		delete name;
		strcpy(this->name, obj.name);
		
		delete surname;
		strcpy(this->surname, obj.surname);
		
		delete address;
		address = new char[strlen(obj.address) + 1];
		strcpy(this->address, obj.address);
		
		this->license = obj.license;
		this->year_of_birth = obj.year_of_birth;
	}

	return *this;
}

bool Businessman::operator ==(Businessman &obj)
{
	if (!strcmp(this->surname, obj.surname))
		return true;
	return false;
}

void Businessman::Redact()
{
	int vib = 0;
	Businessman obj;

	while (vib != 6)
	{
		system("cls");
		cout << "��������:" << endl;
		cout << "1.�������� ������� �����������." << endl;
		cout << "2.�������� ��� �����������. " << endl;
		cout << "3.�������� ��� �������� �����������." << endl;
		cout << "4.�������� ����� �������� �����������" << endl;
		cout << "5.�������� ����� ����������� ����������" << endl;
		cout << "6.�����" << endl;

		while (!(cin >> vib) || vib<1 || vib>6)
		{
			cout << "\n������!!! ������� ����� �� 1 �� 6!" << endl;
			cin.clear();
			cin.sync();
		}

		switch (vib)
		{
		 case 1:
			char *surnamee;

			surnamee = new char[20];
			cout << "\n������� ����� �������:" << endl;
			cin >> surnamee;
			Set_Surname(surnamee);

			cout << "\n��������� ���������" << endl;
			break;
		 case 2:
			char *name;

			name = new char[30];
			cout << "\n������� ����� ���:" << endl;
			cin >> name;
			Set_Name(name);
			break;
		 case 3:
			int year;

			cout << "\n������� ����� ��� ��������:" << endl;
			while (!(cin >> year))
			{
				cout << "\n������!!������� �����!!!" << endl;
				cin.clear();
				cin.sync();
			}
			Set_Year(year);
			break;
		 case 4:
			int nom;

			cout << "\n������� ����� ����� ��������:" << endl;
			cin >> nom;
			Set_license(nom);
			break;
		 case 5:
			char * adr;

			adr = new char[30];
			cout << "\n������� ����� ����� �����������:" << endl;
			cin >> adr;
			Set_address(adr);
		}
	}
}

void Businessman::Shapka()
{
	int i;

	for (i = 0; i < 72; i++)
		cout << "_";
	cout << endl;

	cout << setw(12) << "�������|" 
		 << setw(12) << "���|" 
		 << setw(15) << "��� ��������|" 
		 << setw(15) << "����� ��������|" 
		 << setw(17) << "����� �����������|" << endl;
	
	for (i = 0; i < 72; i++)
		cout << "_";
	cout << endl;
}