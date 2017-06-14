#pragma once
#include <iostream>
#include <iomanip>

#include "File.h"

template <class T> class queue;
template <class T>
struct Node
{
	T data;
	Node <T> *next;
};

template <class T>
class queue
{
protected:
	Node <T> *begin, *end;
	int size;
public:
	queue();
	queue(const queue<T> &ob)
	{
		this->begin = this->end = NULL;
		this->size = 0;

		Node <T> *ptr = ob.begin;
		for (int i = 0; i < ob.size; i++)
		{
			input(ptr->data);
			ptr = ptr->next;
		}
	}

	~queue();

	void input(const T&);
	T getob(int);
	void del_first();
	void show();
	void del_queue();

	int get_dlina()
	{
		return size;
	}

	int find(T &);
	void change(int);
	
	void TXTwrite(txtFile<T> &);
	void BINARYwrite(BinaryFile <T> &);
};

template <class T>
void queue<T>::TXTwrite(txtFile<T> &write)
{
	while (begin)
	{
		write.writeTextFile(begin->data);
		begin = begin->next;
	}
}


template <class T>
queue <T>::queue()
{
	begin = end = NULL;
	size = 0;
}

template <class T>
queue <T>::~queue()
{
	while (begin)
	{
		Node <T> *Ptr = begin;

		begin = begin->next;
		delete Ptr;
	}
	size = 0;
}

template <class T>
T queue<T>::getob(int index) // получение данных для эл-та с индексом index
{
	Node <T> *Ptr = begin;

	for (int i = 0; i < index; i++)
		Ptr = Ptr->next;
	
	return Ptr->data;
}

template <class T>
void queue <T>::input(const T& data)
{
	Node <T> *ptr = new Node<T>;

	ptr->data = data;
	if (!begin)
	{
		begin = end = ptr;
		end->next = NULL;
	}
	else
	{
		end->next = ptr;
		end = ptr;
		end->next = NULL;
	}
	size++;
}

template <class T>
void queue <T>::del_first()
{
	if (begin)
	{
		Node<T> *ptr = begin;

		begin = begin->next;
		delete ptr;
		size--;
	}
}

template <class T>
void queue <T>::show()
{
	Node <T> *ptr = begin;

	while (ptr)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
	}
}

template <class T>
void queue <T>::del_queue()
{
	Node<T> *ptr;

	while (begin)
	{
		ptr = begin;
		begin = begin->next;
		delete ptr;
	}
	size = 0;
}

template <class T>
int queue <T>::find(T &obj)
{
	int proverka = 0;
	Node<T> *ptr;

	if (begin)
	{
		ptr = begin;
		for (int i = 0; i < size; i++)
		{
			if (ptr->data == obj)
			{
				cout << ptr->data << endl;
				proverka++;
			}
			ptr = ptr->next;
		}
	}
	if (!proverka)
	{
		system("cls");
		cout << "Человек с такой фамилией не найден!\n";
	}
	return proverka;
}

template <class T>
void queue <T>::change(int num)
{
	if (begin)
	{
		Node<T> *ptr = begin;

		num--;
		for (int i = 0; i < size; i++)
		{
			if (i==num)
				ptr->data.redact();
			
			ptr = ptr->next;
		}
	}
}
