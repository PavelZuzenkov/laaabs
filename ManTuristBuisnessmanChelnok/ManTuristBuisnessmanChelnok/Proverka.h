#pragma once
#include "iostream"
#include "conio.h"
#include "iomanip"
#include "excepTTioNN.h"

using namespace std;

char* input_string() throw(Stroka)
{
	char *str = new char[40];
	int i;

	while (true)
	{
		try
		{
			flushall();
			cin.getline(str, 40);

			int p = strlen(str);
			for (i = 0; i < p; i++)
				if (!((str[i] >= 65 && str[i] <= 90) ||
					(str[i] >= 97 && str[i] <= 122) || 
					str[i] == 32 || str[i]==45))
					throw Stroka(01, "\nВ данном поле могут быть только буквы английского алфавита и символ тире !!!\n");
			
			if (!((str[0] >= 65 && str[0] <= 90)))
				throw Stroka(02, "\nДанное поле должно начинаться с заглавной буквы!!!\n");
			
			return str;
		}
		catch (Stroka ob)
		{
			ob.mess();
		}
		catch (...)
		{	
			cout << "\nАбсолютный обработчик" << endl;
		}
	}
}

void my_term()
{
	cout << "\nНеобработанное исключение, завершение программы" << endl;
	exit(1);
}

int input_chislo() 
{
	int ch = 0;

	while (true)
	{
		flushall();
		try
		{
			cin >> ch;
			if (!cin.good() || cin.get() != '\n')
			{
				cin.clear();
				cin.sync();

				throw Chislo(11, "\nОшибка ввода!!Введите год!\n");
			}
			if (ch < -5)
				throw invalid_argument("\nВведенный год уже прошел, повторите попытку\n");
			return ch;
		}
		catch (Chislo ob)
		{
			ob.mess();
		}
		catch (invalid_argument &s)
		{
			cerr << s.what() << endl;
		}
	}
}

int input_year(int nach, int end) throw(Chislo)
{
	int year = 0;

	while (true)
	{
		try
		{
			flushall();
			cin >> year;
			if (!cin.good() || cin.peek()!='\n')
				throw Chislo(11, "\nОшибка ввода!\n");
			
			if (year < nach || year>end)
				throw Chislo(12, "\nВведенный год не входит в диапазон!\n");
			return year;
			if (year <= 0)
				throw invalid_argument("\nТакой год не существует!\n");
			if (year > end)
				throw invalid_argument("\nВы еще не родились!\n");
		}
		catch (Chislo ob)
		{
			cin.clear();
			cin.sync();
			ob.mess();
		}
		catch (invalid_argument &s)
		{
			cerr << s.what() << endl;
		}
	}
}

char* input_CHandW() throw(NumLett, Size)
{
	char *str = new char[10];
	int i;

	while (true)
	{
		try
		{
			flushall();
			cin.getline(str, 10);
			if (!cin.good())
			{
				cin.clear();
				cin.sync();
				throw Size(44, "\nСлишком много символов, введите не более 10!!!\n");//проверка на длину!*/
			}
			for (i = 0; i < strlen(str); i++)
			{
				if (str[i] == 32)
					throw NumLett(22, "\nВвод должен осуществляться без пробела!!!\n");
				if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)))
					throw NumLett(21, "\nВ данном поле могут быть только буквы английского алфавита и цифры!!!\n");
			}

			return str;
		}
		catch (Size obj)
		{
			flushall();
			obj.mess();
		}
		catch (NumLett ob)
		{
			ob.mess();
		}
	}
}
