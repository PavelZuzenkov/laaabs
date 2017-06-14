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
//	else cout << " НЕ ВЕРНЫЙ НОМЕР АДРЕСА!!!!" << endl;
//
//}
//char * Chelnok::get_adr(int i)
//{
//	if (i<3)
//	{
//		return adr[i];
//	}
//	else cout << " Не верный номер адреса!!!" << endl;
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
//	cout << "Введите фамилию челнока:" << endl;
//	s >> d.surname;
//	cout << "Введите имя челнока:" << endl;
//	if (d.name)
//	{
//		delete[] d.name;
//	}
//	d.name = new char[25];
//	s >> d.name;
//
//	
//	cout << "Введите год рождения челнока:" << endl;
//	while (!(s >> d.year_of_birth))
//	{
//		cout << "Ошибка!!Введите числа!!!" << endl;
//		cin.clear();
//		cin.sync();
//
//	}
//	cout << "Введите номер  лицензии челнока:" << endl;
//	while (!(s >> d.license))
//	{
//		cout << "Ошибка!!Введите числа!!!" << endl;
//		cin.clear();
//		cin.sync();
//
//	}
//
//	cout << "Введите адрес регистрации:" << endl;
//	if (d.address)
//	{
//		delete[] d.address;
//	}
//	d.address = new char[20];
//	s >> d.address;
//
//
//	
//	cout << "Введите данные паспорта челнока:" << endl;
//	if (d.passport)
//	{
//		delete[] d.passport;
//	}
//	d.passport = new char[20];
//	s >> d.passport;
//	cout << "Введите данные о пересечении границ:" << endl;
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "Введите страну из которой выехал:" << endl;
//		if (d.b[i].outborder)
//		{
//			delete[] d.b[i].outborder;
//		}
//		d.b[i].outborder = new char[20];
//		s >> d.b[i].outborder;
//		cout << "Введите страну в которую въехал:" << endl;
//		if (d.b[i].inborder)
//		{
//			delete[] d.b[i].inborder;
//		}
//		d.b[i].inborder = new char[20];
//		s >> d.b[i].inborder;
//	}
//	cout << "Введите адрес, где покупался товар:" << endl;
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
//	cout << "Выберите:" << endl;
//	cout << "1.Изменить фамилию челнока." << endl;
//	cout << "2.Изменить имя челнока. " << endl;
//	cout << "3.Изменить год рождения челнока." << endl;
//	cout << "4.Изменить номер пасспорта челнока" << endl;
//	cout << "5.Изменить информацию о пересечении границ" << endl;
//	cout << "6.Изменить номер лицензии челнока" << endl;
//	cout << "7.Изменить адрес регистрации челнока" << endl;
//	cout << "8.Изменить адрес покупки" << endl;
//
//	cout << "9.Выход" << endl;
//	while (!(cin >> vib) || vib<1 || vib>9)
//	{
//		cout << "Ошибка!!! Введите числа от 1 до 9!" << endl;
//		cin.clear();
//		cin.sync();
//	}
//		switch (vib)
//		{
//		case 1:
//			char *Surname;
//			Surname = new char[20];
//			cout << "Введите новую фамилию:" << endl;
//			cin >> Surname;
//			set_surname(Surname);
//			cout << "Изменения сохранены" << endl;
//			break;
//		case 2:
//			char *Name;
//			Name = new char[30];
//			cout << "Введите новое имя:" << endl;
//			cin >> Name;
//			set_name(Name);
//			cout << "Изменения сохранены" << endl;
//			break;
//		case 3:
//			int Year;
//			cout << "Введите новый год рождения:" << endl;
//			while (!(cin >> Year))
//			{
//				cout << "Ошибка!!Введите числа!!!" << endl;
//				cin.clear();
//				cin.sync();
//
//			}
//			set_year(Year);
//			break;
//		case 4:
//			char * pasp;
//			pasp = new char[30];
//			cout << "Введите новые пасспортные данные:" << endl;
//			cin >> pasp;
//			set_passport(pasp);
//			cout << "Изменения сохранены" << endl;
//			break;
//		case 5:
//			while (k != 3){
//			cout << "Изменение информации о пересечении границ" << endl;
//			cout << "1.Изменить информацию о стране, которую покинул челнок" << endl;
//			cout << "2.Изменить информацию о стране, в которую въехал челнок" << endl;
//			cout << "3.Выход" << endl;
//			while (!(cin >> k) || k<1 || k>3)
//			{
//				cout << "Ошибка!!! Введите числа от 1 до 3!" << endl;
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
//					cout << "Введите номер изменяемой страны: " << endl;
//					while (!(cin >> i) || i<0 || i>2)
//					{
//						cout << "Ошибка!!! Введите числа от 0 до 2!" << endl;
//						cin.clear();
//						cin.sync();
//					}
//					cout << "Введите новое название страны: " << endl;
//					cin >> outb;
//					set_OUTborder(outb, i);
//					cout << "Изменения сохранены" << endl;
//					break;
//				case 2:
//					char *inb;
//					inb = new char[20];
//					int q = 0;
//					cout << "Введите номер изменяемой страны: " << endl;
//					while (!(cin >> q) || q<0 || q>2)
//					{
//						cout << "Ошибка!!! Введите числа от 0 до 2!" << endl;
//						cin.clear();
//						cin.sync();
//					}
//					cout << "Введите новое название страны: " << endl;
//					cin >> inb;
//					set_INborder(inb, q);
//					cout << "Изменения сохранены" << endl;
//					break;
//					/*case 3:break;*/
//				}
//			}
//		case 6:
//			int nom;
//			cout << "Введите новый номер лицензии:" << endl;
//			cin >> nom;
//			set_license(nom);
//			break;
//		case 7:
//			char * adrreg;
//			adrreg = new char[30];
//			cout << "Введите новый адрес регистрации:" << endl;
//			cin >> adrreg;
//			set_address(adrreg);
//			break;
//		case 8:
//			char * adrpok;
//			adrpok = new char[30];
//			int nomer;
//			cout << "Введите номер изменяемого адреса товара: " << endl;
//			while (!(cin >> nomer) || nomer<0 || nomer>2)
//			{
//				cout << "Ошибка!!! Введите числа от 0 до 2!" << endl;
//				cin.clear();
//				cin.sync();
//			}
//			cout << "Введите новый адрес регистрации:" << endl;
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
//	cout << setw(12) << "Фамилия|" << setw(12) << "Имя|" << setw(15) << "Год рождения|" << setw(15) << "Номер лицензии|" << setw(17) << "Адрес регистрации|" << setw(16) << "Данные пасcпорта|" << setw(17) << "(1)Покинул страну|" << setw(17) << "(1)Въехал в страну|" << setw(17) << "(2)Покинул страну|" << setw(17) << "(2)Въехал в страну|" << setw(17) << "(1)Адрес покупки|" << setw(17) << "(2)Адрес покупки|" << setw(17) << "(3)Адрес покупки|" << endl;
//	for (int i = 0; i < 218; i++)
//	{
//		cout << "_";
//	}
//	cout << endl;
//}