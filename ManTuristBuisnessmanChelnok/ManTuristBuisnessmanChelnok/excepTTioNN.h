#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Exception
{
public:
	Exception();
	Exception(const int, const char *);
	Exception(const Exception&);
	void mess();
	int getCode()
	{
		return Code;
	}
protected:
	int Code;
	char *MainMess;
};

Exception::Exception()
{
	Code = 0;
	MainMess = NULL;
}

Exception::Exception(const int Kode, const char *mess)
{
	Code = Kode;
	MainMess = new char[strlen(mess) + 1];
	strcpy(MainMess, mess);
}

Exception::Exception(const Exception &ob)
{
	Code = ob.Code;
	MainMess = new char[strlen(ob.MainMess) + 1];
	strcpy(MainMess, ob.MainMess);
}

void Exception::mess()
{
	cout <<"Код ошибки: "<< Code << " - "  << MainMess<<endl<< "Повторите ввод:";
}

class Size : public Exception
{
public:
	Size(){}
	Size(int kod1, char* mes) : Exception(kod1, mes){}
	Size(const Size&ob) :Exception(ob){}
};

class Stroka : public Exception
{
public:
	Stroka(){}
	Stroka(int Kod1, char* mes) :Exception(Kod1, mes){}
	Stroka(const Stroka &ob) :Exception(ob){}
};
/*__________________________________________________________________________*/

class Chislo : public Exception
{
public:
	Chislo() {}
	Chislo(int Kod1, char* mes) :Exception(Kod1, mes){}
	Chislo(const Chislo &ob) :Exception(ob){}
};

class NumLett : public Exception
{
public:
	NumLett(){}
	NumLett(int Kod1, char* mess) :Exception(Kod1, mess){}
	NumLett(const NumLett &ob) :Exception(ob){}
};






















/*--------------------------------------------------------------------------------------------------------------------------------------*/
//
//char* input_string() throw(Stroka)
//{
//	char *str = new char[40];
//	int i;
//	while (true)
//	{
//		try
//		{
//			//cin >> str;
//			fflush(stdin);
//			cin.getline(str, 40);
//			for (i = 0; i < strlen(str); i++)
//			{
//				if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 32))
//					throw Stroka(01,"В данном поле могут быть только буквы английского алфавита!!!");
//			}
//			if (!((str[0] >= 65 && str[0] <= 90)))
//			{
//				throw Stroka(02, "Данное поле должно начинаться с заглавной буквы!!!");
//			}
//			return str;
//		}
//		catch (Stroka ob)
//		{
//			ob.mess();
//		}
//		catch (...)
//		{
//			cout << "Абсолютный обработчик" << endl;
//		}
//	}
//}
//
////void my_unexpected()
////{
////	cout << "Неожиданный обработчик" << endl;
////	throw Chislo();
////}
//
//void my_term()
//{
//	cout << "Необработанное исключение, завершение программы" << endl;
//	exit(1);
//}
//
//int input_year() throw(Chislo)
//{
//	int year = 0;
//	while (true)
//	{
//		set_terminate(my_term);
//		try
//		{
//			cin >> year;
//			if (!cin.good() || year < 1900 || year>2015)
//			{
//				cin.clear();
//				cin.sync();
//				//throw 1;//вызов сеттерминэйта
//				throw Chislo(11, "Данное поле должно состоять из цифр и входить в диапазон [1900;2015]");
//			}
//			return year;
//		}
//		catch (Chislo ob)
//		{
//			ob.mess();
//		}
//	}
//}
//
//
//char* input_CHandW() throw(NumLett)
//{
//	char *str = new char[40];
//	int i;
//	while (true)
//	{
//		try
//		{
//			//cin >> str;
//			fflush(stdin);
//			cin.getline(str, 40);
//			if (strlen(str) > 10)
//				throw NumLett(23, "Слишком много символов, введите не более 10!!!");
//			for (i = 0; i < strlen(str); i++)
//			{
//				if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)))
//					throw NumLett(21, "В данном поле могут быть только буквы английского алфавита и цифры!!!");
//				if (str[i] == 32)
//					throw NumLett(22, "Ввод должен осуществляться без пробела!!!");
//			}
//			
//			return str;
//		}
//		catch (NumLett ob)
//		{
//			ob.mess();
//		}
//	}
//}

