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
					throw Stroka(01, "\n� ������ ���� ����� ���� ������ ����� ����������� �������� � ������ ���� !!!\n");
			
			if (!((str[0] >= 65 && str[0] <= 90)))
				throw Stroka(02, "\n������ ���� ������ ���������� � ��������� �����!!!\n");
			
			return str;
		}
		catch (Stroka ob)
		{
			ob.mess();
		}
		catch (...)
		{	
			cout << "\n���������� ����������" << endl;
		}
	}
}

void my_term()
{
	cout << "\n�������������� ����������, ���������� ���������" << endl;
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

				throw Chislo(11, "\n������ �����!!������� ���!\n");
			}
			if (ch < -5)
				throw invalid_argument("\n��������� ��� ��� ������, ��������� �������\n");
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
				throw Chislo(11, "\n������ �����!\n");
			
			if (year < nach || year>end)
				throw Chislo(12, "\n��������� ��� �� ������ � ��������!\n");
			return year;
			if (year <= 0)
				throw invalid_argument("\n����� ��� �� ����������!\n");
			if (year > end)
				throw invalid_argument("\n�� ��� �� ��������!\n");
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
				throw Size(44, "\n������� ����� ��������, ������� �� ����� 10!!!\n");//�������� �� �����!*/
			}
			for (i = 0; i < strlen(str); i++)
			{
				if (str[i] == 32)
					throw NumLett(22, "\n���� ������ �������������� ��� �������!!!\n");
				if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)))
					throw NumLett(21, "\n� ������ ���� ����� ���� ������ ����� ����������� �������� � �����!!!\n");
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
