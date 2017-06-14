#pragma once
#include <iostream>
#include"Human.h"
#include"Tourist.h"
#include <conio.h>
#include "excepTTioNN.h"
#include "Proverka.h"

using namespace std;

Tourist::Tourist() :Human()
{
	int i;

	this->passport[0] = NULL;
	for (i = 0; i < 2; i++)
	{
		this->b[i].outborder[0] = NULL;
		this->b[i].inborder[0] = NULL;
	}
}

Tourist::Tourist(const char *surname, const char *name, const int year_of_birth, 
	     const char *passport, const char *outboard, const char *inboard) : Human(surname, name, year_of_birth)
{
	int i;

	strcpy(this->passport, passport);
	for (i = 0; i < 2; i++)
	{
		strcpy(this->b[i].outborder, outboard);
		strcpy(this->b[i].inborder, inboard);
	}
}

Tourist::Tourist(const Tourist &obj) :Human(obj)
{
	int i;

	strcpy(this->passport, obj.passport);
	for (i = 0; i < 2; i++)
	{
		strcpy(this->b[i].outborder, obj.b[i].outborder);
		strcpy(this->b[i].inborder, obj.b[i].inborder);
	}
}

Tourist::~Tourist()
{
}

void Tourist::Set_passport(const char *passport)
{
	strcpy(this->passport, passport);
}

void Tourist::Set_INborder(const char *inboard, const int i)
{
	strcpy(this->b[i].inborder, inboard);
}

void Tourist::Set_OUTborder(const char *outboard, const int i)
{
	strcpy(this->b[i].outborder, outboard);
}

char* Tourist::Get_passport()
{
	return this->passport;
}

char* Tourist::Get_outborder(const int i)
{
	return this->b[i].outborder;
}

char* Tourist::Get_inborder(const int i)
{
	return this->b[i].inborder;
}

Tourist &Tourist::operator = (const Tourist &obj)
{
	int i;

	if (this != &obj)
	{
		strcpy(this->name, obj.name);
		strcpy(this->surname, obj.surname);
		strcpy(this->passport, obj.passport);

		for (i = 0; i < 2; i++)
		{
			strcpy(this->b[i].inborder, obj.b[i].inborder);
			strcpy(this->b[i].outborder, obj.b[i].outborder);
		}
		this->year_of_birth = obj.year_of_birth;
	}

	return *this;
}

istream& operator>>(istream &in, Tourist &obj)
{
	int i;

	cout << "������� ������� �������:" << endl;
	obj.Set_Surname(input_string());
	
	cout << "\n������� ��� �������:" << endl;
	obj.Set_Name(input_string());
	
	cout << "\n������� ������� ���:";
	int tek = input_chislo();
	
	int nach = tek - 120;
	cout << "\n������� ��� �������� �������:" << endl;
	obj.Set_Year(input_year(nach, tek));

	cout << "\n������� ������ �������� �������:" << endl;
	obj.Set_passport(input_CHandW());
	
	cout << "\n������� ������ � ����������� ������:" << endl;
	for (i = 0; i < 2; i++)
	{
		cout << "������� ������ �� ������� ������:" << endl;
		obj.Set_OUTborder(input_string(), i);
		
		cout << "\n������� ������ � ������� ������:" << endl;
		obj.Set_INborder(input_string(), i);
	}
	return in;
}

ostream& operator<<(ostream &out, Tourist &obj)
{
	int i;

	out << setw(11) << obj.Get_Surname() << "|"
	  << setw(11) << obj.Get_Name() << "|"
	  << setw(14) << obj.Get_Year() << "|"
	  << setw(15) << obj.Get_passport() << "|";

	for (i = 0; i < 2; i++)
		out << setw(13) << obj.b[i].outborder << "|"
		  << setw(13) << obj.b[i].inborder << "|";
	cout << endl;
	
	for (i = 0; i < 111; i++)
		cout << "-";
	
	return out;
}

bool Tourist::operator ==(const Tourist &obj)
{
	if (!strcmp(this->surname, obj.surname))
		return true;
	return false;
}

fstream &operator <<(fstream &fout, Tourist &obj)
{
	int i;
	
	fout << obj.surname << " "
		<< obj.name << " "
		<< obj.year_of_birth << " "
		<< obj.passport << " ";

	for (i = 0; i < 2; i++)
		fout << obj.b[i].outborder << " "
		     << obj.b[i].inborder << " ";
	
	return fout;
}

fstream& operator >>(fstream &fin, Tourist &obj)
{
	int  i;
	char text[20];
	
	fin >> text;
	obj.Set_Surname(text);
	
	fin >> text;
	obj.Set_Name(text);

	fin >> text;
	obj.Set_Year(atoi(text));
	
	fin >> text;
	obj.Set_passport(text);

	for (i = 0; i < 2; i++)
	{
		fin >> text;
		obj.Set_OUTborder(text, i);

		fin >> text;
		obj.Set_INborder(text, i);
	}

	return fin;
}

void Tourist:: Redact()
{
	Tourist obj;
	char *text;
	int vibor, value;

	text = new char[30];

	cout << "��������:" << endl;
	cout << "1.�������� �������." << endl;
	cout << "2.�������� ���. " << endl;
	cout << "3.�������� ��� ��������." << endl;
	cout << "4.�������� ����� ���������" << endl;
	cout << "5.�������� ���������� � ����������� ������" << endl;
	cin >> vibor;

	system("cls");

	switch (vibor)
	{
	case 1:
		cout << "������� ����� �������: ";
		cin >> text;
		Set_Surname(text);
		break;
	case 2:
		cout << "������� ����� ���:" << endl;
		cin >> text;
		Set_Name(text);
		break;
	case 3:
		cout << "������� ����� ��� ��������:" << endl;
		while (!(cin >> value))
		{
			cout << "������!!������� �����!!!" << endl;
			cin.clear();
			cin.sync();
		}
		Set_Year(value);
		break;
	case 4:
		cout << "������� ����� ����������� ������:" << endl;
		cin >> text;
		Set_passport(text);
		break;
	case 5:
			  cout << "��������� ���������� � ����������� ������" << endl;
			  int k;
			  char *country;

			  country = new char[20];

			  do
			  {
				  system("cls");
				  cout << "1.�������� ���������� � ������, ������� ������� ������" << endl;
				  cout << "2.�������� ���������� � ������, � ������� ������ ������" << endl;
				  cout << "3.�����" << endl;

				  while (!(cin >> k) || k<1 || k>3)
				  {
					  cout << "������!!! ������� ����� �� 1 �� 3!" << endl;
					  cin.clear();
					  cin.sync();
				  }

				  switch (k)
				  {
					  case 1:
						  cout << "������� ����� ���������� ������: " << endl;
						  cin >> value;
					  
						  cout << "������� ����� �������� ������: " << endl;
						  cin >> country;
					  
						  Set_OUTborder(country, value - 1);
						  break;
					  case 2:
						  cout << "������� ����� ���������� ������: " << endl;
						  cin >> value;
					  
						  cout << "������� ����� �������� ������: " << endl;
						  cin >> country;
					  
						  Set_INborder(country, value - 1);
				    }
			  } while (k != 3);
			  
			  cout << "\n��������� ���������" << endl;
			  system("pause");
	}  
}

void Tourist::Shapka()
{
	int i;

	for (i = 0; i < 111; i++)
		cout << "_";
	
	cout << endl;
	cout << setw(12) << "�������|" << 
		    setw(12) << "���|" << 
			setw(15) << "��� ��������|" << 
			setw(15) << "������ ��������|" << 
			setw(13) << "������ ������|" << 
			setw(13) << "������ ������|" << 
			setw(13) << "������ ������|" << 
			setw(13) << "������ ������|" << endl;
	
	for (i = 0; i < 111; i++)
		cout << "_";
	cout << endl;
}