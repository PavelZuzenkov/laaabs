#pragma once
#include <iostream>

using namespace std;

template <class T> class Queue;
template <class T> class Iterator;
template <class T> class Algorithm;

template <class T>
struct NODE
{
	NODE <T> *next;	
	T data;
};


template <class T>
class Queue
{
	NODE<T> *head, *tail;
	Iterator<T> IterForHead, IterForTail;
public:
	Queue();
	~Queue();
	void print();
	void Add(const T&);
	
	void del_first();
	void del_queue();

	Iterator<T> returnBegin();
	Iterator<T> returnEND();

	bool isEmpty();
};


template<class T>
Queue<T>::Queue()
{
	head = tail = NULL;
	IterForHead = IterForTail = Iterator<T>(NULL); //обнуление итераторов для начала и конца очереди
}

template <class T>

bool Queue<T>::isEmpty()
{
	if (head)
		return true;
	
	return false;
}

template<class T>
void Queue< T>::Add(const T &obj) //добавление осуществляется всегда в конец
{
	NODE<T> *ptr = new NODE<T>;

	ptr->data = obj;
	if (!head)
	{
		head = tail = ptr;
		tail->next = NULL;	
		IterForHead = Iterator<T>(head);
		IterForTail = Iterator<T>(tail);
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
		tail->next = NULL;

		IterForHead = Iterator<T>(head);
		IterForTail = Iterator<T>(tail);
	}
}
//////////////////////
template<class T>
Iterator<T> Queue<T>::returnBegin()
{
	return IterForHead;
}
//////////////////////
template<class T>
Iterator<T> Queue<T>::returnEND()
{
	return IterForTail;
}
//////////////////////
template<class T>
void Queue<T>::del_first()
{
	if (isEmpty()) //если эл-ты есть
	{
		NODE<T> *ptr = head; //поставить указатель на 1 эл-т
		head = head->next; //переставить указатель начала на след
		delete ptr; //удалить 1 эл-т
		IterForHead = Iterator<T>(head); 
	}
}

template<class T>
void  Queue<T>::print()
{
	if (isEmpty())
	{
		Iterator<T> beginIterator = returnBegin();
		Iterator<T> endIterator = returnEND();
		Iterator<T> ITob = beginIterator;

		while (ITob != endIterator)
		{
			cout << *ITob << endl;
			ITob++;
		}
		cout << *ITob << endl;
		Iterator<T> nol = NULL;
	}
}


template<class T>
void Queue<T>::del_queue()
{
	while (isEmpty())
		del_first();
}

template<class T>
Queue< T>::~Queue()
{
	del_queue();
}


template <class T>
class Iterator
{
private:
	NODE <T> *Ptr;
public:
	Iterator()
	{
		this->Ptr = NULL;
	}

	Iterator(NODE<T> *Ptr)
	{
		this->Ptr = Ptr;
	}

	Iterator(Iterator &ITob)
	{
		this->Ptr = ITob.Ptr;
	}

	T& operator*()
	{
		return this->Ptr->data;
	}

	bool operator!=(Iterator &ITob)
	{
		if (this->Ptr != ITob.Ptr)
			return true;
		return false;
	}

	Iterator& operator++()
	{
		this->Ptr = Ptr->next;
		return *this;
	}
};

/////////////////////////////////////////////////////////////////АЛГОРИТМ///////////////////////////////////////////
template<class T>
class Algorithm
{
public:
	int POISK(Iterator<T> &, Iterator<T> &, char*, int);
	void sort(Iterator<T> &, Iterator<T> &,  int);
	void diap(Iterator<T> &, Iterator<T> &,  int, int);
};


template<class T>
void Algorithm<T>::diap(Iterator<T>& begin, Iterator<T>& end, int god, int kol)
{
	int k = 0;
	Iterator<T> *t = new Iterator<T>[kol];
	Iterator<T> temp = begin;

	while (temp != end)
	{
		t[k] = temp;
		k++;
		++temp;
	}
	t[k] = temp;

	int *p = new int[kol];

	for (k = 0; k < kol; k++)
		p[k] = (*t[k]).get_year();
	
	(*temp).Shapka();

	for (k = 0; k < kol; k++)
		if (god >= p[k])
			cout << *t[k] << endl;
	
	system("pause");
}

template<class T>
void Algorithm<T>::sort(Iterator<T>& begin, Iterator<T>& end, int dl)
{
	int kol = dl, k = 0, i, j;
	Iterator<T> *t = new Iterator<T>[kol];
	Iterator<T> temp = begin;
	Iterator<T> tek;
	Iterator<T> lll;

	cout << kol << endl;

	while (temp != end)
	{
		t[k] = temp;
		k++;
		++temp;
	}
	t[k] = temp;

	int *p=new int[kol];
	for (k = 0; k < kol; k++)
	{
		cout << *t[k] << endl;
		p[k] = (*t[k]).get_year();
	}

	for (k = 0; k < kol; k++)
		cout <<  p[t]<< endl;
	cout << endl;

	for (i = 0; i < kol-1; ++i) // i - номер прохода
		for (j = 0; j < kol-1 ; ++j) // внутренний цикл прохода
			if (p[j + 1]<p[j])
			{
				tek = t[j + 1];
				t[j + 1] = t[j];
				t[j] = tek;
			}

	for (k = 0; k < kol; k++)
		cout << *t[k] << endl;
	
	system("pause");
}