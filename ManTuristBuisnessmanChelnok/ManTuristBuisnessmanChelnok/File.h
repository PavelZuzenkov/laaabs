#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
 
using namespace std;

class File
{
protected:
	char filename[20];
	fstream f;
public:
	File() {}
	File(char* nameoffile)
	{
		strcpy(filename, nameoffile);
	}
	~File()
	{ 
		f.close();
	}

	void Remote()
	{
		f.seekg(0, ios_base::beg);//����� ��������� �� get �� ������ �����
		f.seekp(0, ios_base::beg);//����� ��������� �� put
		f.clear();
	}

	void closeFile()
	{
		f.close();
	}
};

//////////////////////////////////////////////////////

template <class T>
class txtFile :  public File
{
public:
	txtFile() : File(){}
	txtFile(char* nameoffile) : File(nameoffile){}
	~txtFile()
	{ 
		f.close(); 
	}

	int TXTopenREAD()
	{
		int state;

		f.open(filename, ios::in);//��������� ����� ��� �����
		
		state = in.rdstate();
		if (state)
		{
			if (state&ios::badbit)
				cout << "������ �������� �����" << endl;
			return 0;
		}
		return 1;
	}

	int TXTopenWRITE()
	{
		int state;

		f.open(filename, ios_base::out | ios::trunc);//��������� ������������ �(���) ��������� ��� ������

		state = out.rdstate();
		if (state)
		{
			if (state&ios::badbit)
				cout << "������ �������� �����" << endl;
			return 0;
		}
		return 1;//���������
	}

	int readTextFile(T &ob)
	{
		if (!f.eof() && f >> ob)
			return 1;
	    return 0;
	}

	void writeTextFile(T &ob)
	{
		int state;
		
		state = in.rdstate();
		if (state)
		{
			if (state&ios::badbit) 
				cout << "������ �������� �����" << endl;
			  else 
			    if (state&ios::eofbit) 
					cout << "� ����� ������ ��� ������" << endl;
			return;
		}
		f << ob <<endl ;
	}
};
/////// ------------------------------------------------------------------------------------------////////////////////////////////////////////////////

template <class T>
class BinaryFile : public File
{
public:
	BinaryFile(char* filename) : File(filename){}

	int BINARYopenREAD()
	{
		f.open(filename, ios::binary | ios::in);
		if (f) 
			return 1;
	    return 0;
	}

	int BINARYopenWRITE()
	{
		int state;

		f.open(filename, ios::binary | ios::out | ios::trunc);

		state = out.rdstate();
		if (state)
		{
			if (state&ios::badbit)
				cout << "������ �������� �����" << endl;
			return 0;
		} 
		return 1;
	}

	int readBinaryFile(T &obj)
	{
		if (!f.eof() && f.read(reinterpret_cast<char*>(&obj), sizeof(T)))
			return 1;
		f.clear();
		return 0;
	}
	void writeBinaryFile(T& obj)
	{
		int state;

		state = out.rdstate();
		if (state)
		{
			if (state&ios::badbit)
				cout << "������ �������� �����" << endl;
			else
			if (state&ios::eofbit)
				cout << "� ����� ������ ��� ������" << endl;
			return;
		}
		f.seekp(0, ios::end);
		f.write(reinterpret_cast<const char*>(&obj), sizeof(T));
		f.clear(ios::badbit | ios::failbit);
		f.flush();
	}

void zamena(int a, int b)
	{
		int perv = a, vtor = b;
		int kolvo = 0;
		long bit = 0;
		int size = sizeof(T);
		T t1, t2;

		f.open(filename, ios::binary | ios::in | ios::out);
		f.seekp(0, ios_base::end);//������������� ������� �� ����� �����
		bit = f.tellp();//���������� ������� �������
		kolvo = bit / size;
		perv--;
		vtor--;
		f.seekg(perv*size, ios::beg);
		f.read(reinterpret_cast<char*>(&t1), size);  		//��������� perv �������

		f.seekg(vtor*size, ios::beg);    		//���������� �� vtor ������� 

		f.read(reinterpret_cast<char*>(&t2), size);  		//�������� vtor �������

		f.seekp(perv*razmer, ios::beg);  		//���������� �� perv �������(������)

		f.write(reinterpret_cast<char*>(&t2), size);
		f.flush();

		f.seekp(vtor*size, ios::beg);   		//���������� �� vtor ������� (������)

		f.write(reinterpret_cast<char*>(&t1), size);

		f.flush();
		f.close();
	}
};