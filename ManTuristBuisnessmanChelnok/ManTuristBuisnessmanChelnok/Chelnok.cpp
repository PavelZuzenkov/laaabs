//#include <iostream>
//#include"Human.h"
//#include"Tourist.h"
//#include"Businessman.h"
//#include"Chelnok.h"
//using namespace std;
//#pragma once;
//
//
//Chelnok::Chelnok() :Businessman(), Tourist()
//{
//	for (int i = 0; i<3; i++)
//	{
//	adr[i] = NULL;
//	}
//}
//Chelnok::Chelnok(char *surname, char *name, int year_of_birth, char *passport, char* outboard, char * inboard, int license, char * address, char *adr[]) :Tourist(surname, name, year_of_birth, passport, outboard, inboard), Businessman(surname, name, year_of_birth, license, address)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		this->adr[i] = new char[strlen(adr[i]) + 1];
//		strcpy(this->adr[i], adr[i]);
//	}
//}
//Chelnok::Chelnok(const Chelnok & obj) :Businessman(obj), Tourist(obj)
//{
//
//	k = obj.k;
//	for (int i = 0; i<3; i++)
//	{
//		adr[i] = obj.adr[i];
//	}
//}
//Chelnok::~Chelnok()
//{
//	for (int i = 0; i<3; i++)
//	{
//		delete[] adr[i];
//	}
//}
//
//
//
//void Chelnok::set_adr(char *adr, int i)
//{
//	if (i<3)
//	{
//		if (adr[i])
//		{
//			delete[] this->adr[i];
//		}
//		this->adr[i] = new char[strlen(adr) + 1];
//		strcpy(this->adr[i], adr);
//	}
//	else cout << " �� ������ ����� ������!!!!" << endl;
//
//}
//char * Chelnok::get_adr(int i)
//{
//	if (i<3)
//	{
//		return adr[i];
//	}
//	else cout << " �� ������ ����� ������!!!" << endl;
//}
//int Chelnok::print_adr()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (adr[i])
//		{
//			cout << adr[i];
//		}
//		else cout << "iopta" << endl;
//	}
//	cout << endl;
//	return 0;
//}
//
//
//Chelnok &Chelnok::operator = (const Chelnok &ob)
//{
//	if (this != &ob)
//	{
//		delete name;
//		name = new char[strlen(ob.name) + 1];
//		strcpy(this->name, ob.name);
//		delete surname;
//		surname = new char[strlen(ob.surname) + 1];
//		strcpy(this->surname, ob.surname);
//
//		delete address;
//		address = new char[strlen(ob.address) + 1];
//		strcpy(this->address, ob.address);
//
//		delete passport;
//		passport = new char[strlen(ob.passport) + 1];
//		strcpy(this->passport, ob.passport);
//		for (int i = 0; i < 2; i++)
//		{
//			delete b[i].inborder;
//			b[i].inborder = new char[strlen(ob.b[i].inborder) + 1];
//			strcpy(this->b[i].inborder, ob.b[i].inborder);
//
//			delete b[i].outborder;
//			b[i].outborder = new char[strlen(ob.b[i].outborder) + 1];
//			strcpy(this->b[i].outborder, ob.b[i].outborder);
//		}
//		license = ob.license;
//		year_of_birth = ob.year_of_birth;
//		for (int i = 0; i < 3; i++)
//		{
//			delete adr[i];
//			adr[i] = new char[strlen(ob.adr[i]) + 1];
//			strcpy(this->adr[i], ob.adr[i]);
//		}
//	}
//	return *this;
//}
//
//
//ostream& operator<<(ostream& s, Chelnok & d)
//{
//	s << setw(11) << d.get_surname() << "|";
//	s << setw(11) << d.get_name() << "|";
//	s << setw(14) << d.get_year() << "|";
//	s << setw(14) << d.get_license() << "|";
//	s << setw(17) << d.get_address() << "|";
//	s << setw(16) << d.passport << "|";
//	for (int i = 0; i < 2; i++)
//	{
//		s << setw(17) << d.b[i].outborder << "|";
//		s << setw(18) << d.b[i].inborder << "|";
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		s << setw(16) << d.adr[i] << "|";
//	}
//	cout << endl;
//	for (int i = 0; i < 218; i++)
//	{
//		cout << "-";
//	}
//	//cout << endl;
//	return s;
//}
//
//
//
//istream& operator>>(istream &s, Chelnok & d)
//{
//	if (d.surname)
//	{
//		delete[] d.surname;
//	}
//	d.surname = new char[20];
//	cout << "������� ������� �������:" << endl;
//	s >> d.surname;
//	cout << "������� ��� �������:" << endl;
//	if (d.name)
//	{
//		delete[] d.name;
//	}
//	d.name = new char[25];
//	s >> d.name;
//
//	
//	cout << "������� ��� �������� �������:" << endl;
//	while (!(s >> d.year_of_birth))
//	{
//		cout << "������!!������� �����!!!" << endl;
//		cin.clear();
//		cin.sync();
//
//	}
//	cout << "������� �����  �������� �������:" << endl;
//	while (!(s >> d.license))
//	{
//		cout << "������!!������� �����!!!" << endl;
//		cin.clear();
//		cin.sync();
//
//	}
//
//	cout << "������� ����� �����������:" << endl;
//	if (d.address)
//	{
//		delete[] d.address;
//	}
//	d.address = new char[20];
//	s >> d.address;
//
//
//	
//	cout << "������� ������ �������� �������:" << endl;
//	if (d.passport)
//	{
//		delete[] d.passport;
//	}
//	d.passport = new char[20];
//	s >> d.passport;
//	cout << "������� ������ � ����������� ������:" << endl;
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "������� ������ �� ������� ������:" << endl;
//		if (d.b[i].outborder)
//		{
//			delete[] d.b[i].outborder;
//		}
//		d.b[i].outborder = new char[20];
//		s >> d.b[i].outborder;
//		cout << "������� ������ � ������� ������:" << endl;
//		if (d.b[i].inborder)
//		{
//			delete[] d.b[i].inborder;
//		}
//		d.b[i].inborder = new char[20];
//		s >> d.b[i].inborder;
//	}
//	cout << "������� �����, ��� ��������� �����:" << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		/*if (d.adr[i])
//		{
//			delete[] d.adr[i];
//		}*/
//	/*}
//	for (int i = 0; i < 3; i++)
//	{*/
//		cout <<i+1<< ")";
//		d.adr[i]= new char[20];
//		s >>  d.adr[i];
//	}
//	return s;
//}
//
//
//fstream &operator >>(fstream &fs, Chelnok& d)
//{
//	return fs;
//}
//fstream &operator <<(fstream &fs, Chelnok& d)
//{
//	return fs;
//}
//
//
//bool Chelnok::operator ==(Chelnok &obj)
//{
//	if (!strcmp(this->surname, obj.surname))
//		return true;
//	else
//		return false;
//}
//
//void Chelnok::redact()
//{
//	int vib = 0, k=0, i=0;
//	//Chelnok ob;
//	while (vib != 9)
//	{
//	system("cls");
//	cout << "��������:" << endl;
//	cout << "1.�������� ������� �������." << endl;
//	cout << "2.�������� ��� �������. " << endl;
//	cout << "3.�������� ��� �������� �������." << endl;
//	cout << "4.�������� ����� ��������� �������" << endl;
//	cout << "5.�������� ���������� � ����������� ������" << endl;
//	cout << "6.�������� ����� �������� �������" << endl;
//	cout << "7.�������� ����� ����������� �������" << endl;
//	cout << "8.�������� ����� �������" << endl;
//
//	cout << "9.�����" << endl;
//	while (!(cin >> vib) || vib<1 || vib>9)
//	{
//		cout << "������!!! ������� ����� �� 1 �� 9!" << endl;
//		cin.clear();
//		cin.sync();
//	}
//		switch (vib)
//		{
//		case 1:
//			char *Surname;
//			Surname = new char[20];
//			cout << "������� ����� �������:" << endl;
//			cin >> Surname;
//			set_surname(Surname);
//			cout << "��������� ���������" << endl;
//			break;
//		case 2:
//			char *Name;
//			Name = new char[30];
//			cout << "������� ����� ���:" << endl;
//			cin >> Name;
//			set_name(Name);
//			cout << "��������� ���������" << endl;
//			break;
//		case 3:
//			int Year;
//			cout << "������� ����� ��� ��������:" << endl;
//			while (!(cin >> Year))
//			{
//				cout << "������!!������� �����!!!" << endl;
//				cin.clear();
//				cin.sync();
//
//			}
//			set_year(Year);
//			break;
//		case 4:
//			char * pasp;
//			pasp = new char[30];
//			cout << "������� ����� ����������� ������:" << endl;
//			cin >> pasp;
//			set_passport(pasp);
//			cout << "��������� ���������" << endl;
//			break;
//		case 5:
//			while (k != 3){
//			cout << "��������� ���������� � ����������� ������" << endl;
//			cout << "1.�������� ���������� � ������, ������� ������� ������" << endl;
//			cout << "2.�������� ���������� � ������, � ������� ������ ������" << endl;
//			cout << "3.�����" << endl;
//			while (!(cin >> k) || k<1 || k>3)
//			{
//				cout << "������!!! ������� ����� �� 1 �� 3!" << endl;
//				cin.clear();
//				cin.sync();
//			}
//			
//				switch (k)
//				{
//				case 1:
//					char *outb;
//					outb = new char[20];
//					/*int i = 0;*/
//					cout << "������� ����� ���������� ������: " << endl;
//					while (!(cin >> i) || i<0 || i>2)
//					{
//						cout << "������!!! ������� ����� �� 0 �� 2!" << endl;
//						cin.clear();
//						cin.sync();
//					}
//					cout << "������� ����� �������� ������: " << endl;
//					cin >> outb;
//					set_OUTborder(outb, i);
//					cout << "��������� ���������" << endl;
//					break;
//				case 2:
//					char *inb;
//					inb = new char[20];
//					int q = 0;
//					cout << "������� ����� ���������� ������: " << endl;
//					while (!(cin >> q) || q<0 || q>2)
//					{
//						cout << "������!!! ������� ����� �� 0 �� 2!" << endl;
//						cin.clear();
//						cin.sync();
//					}
//					cout << "������� ����� �������� ������: " << endl;
//					cin >> inb;
//					set_INborder(inb, q);
//					cout << "��������� ���������" << endl;
//					break;
//					/*case 3:break;*/
//				}
//			}
//		case 6:
//			int nom;
//			cout << "������� ����� ����� ��������:" << endl;
//			cin >> nom;
//			set_license(nom);
//			break;
//		case 7:
//			char * adrreg;
//			adrreg = new char[30];
//			cout << "������� ����� ����� �����������:" << endl;
//			cin >> adrreg;
//			set_address(adrreg);
//			break;
//		case 8:
//			char * adrpok;
//			adrpok = new char[30];
//			int nomer;
//			cout << "������� ����� ����������� ������ ������: " << endl;
//			while (!(cin >> nomer) || nomer<0 || nomer>2)
//			{
//				cout << "������!!! ������� ����� �� 0 �� 2!" << endl;
//				cin.clear();
//				cin.sync();
//			}
//			cout << "������� ����� ����� �����������:" << endl;
//			cin >> adrpok;
//			//set_adr(adrpok, nomer);
//			break;
//		case 9: break;
//		}
//	}
//}
//
//void Chelnok::shapka()
//{
//	for (int i = 0; i < 218; i++)
//	{
//		cout << "_";
//	}
//	cout << endl;
//	cout << setw(12) << "�������|" << setw(12) << "���|" << setw(15) << "��� ��������|" << setw(15) << "����� ��������|" << setw(17) << "����� �����������|" << setw(16) << "������ ���c�����|" << setw(17) << "(1)������� ������|" << setw(17) << "(1)������ � ������|" << setw(17) << "(2)������� ������|" << setw(17) << "(2)������ � ������|" << setw(17) << "(1)����� �������|" << setw(17) << "(2)����� �������|" << setw(17) << "(3)����� �������|" << endl;
//	for (int i = 0; i < 218; i++)
//	{
//		cout << "_";
//	}
//	cout << endl;
//}