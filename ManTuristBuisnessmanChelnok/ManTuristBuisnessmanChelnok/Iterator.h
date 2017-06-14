//#ifndef ITERATOR_H
//#define ITERATOR_H
////#include "NODE.h"
//#include "Konteiner.h"
//#include <iostream>
//using namespace std;
//
//
//template <class T>
//class Iterator
//{
//private:
//	NODE <T> *Ptr;
//public:
//	Iterator(NODE<T> *Ptr)
//	{
//		this->Ptr = Ptr;
//	}
//
//	Iterator()
//	{
//		Ptr = NULL;
//	}
//
//	Iterator(Iterator &ITob)
//	{
//		Ptr = ITob.Ptr;
//	}
//
//	Iterator& operator=(Iterator &it)
//	{
//		if (*this != it) this->Ptr = it.Ptr;
//		return *this;
//	}
//
//	bool operator==(Iterator &ITob)
//	{
//		if (Ptr == ITob.Ptr) return true;
//		else return false;
//	}
//
//	bool operator!=(Iterator &ITob)
//	{
//		if (Ptr != ITob.Ptr) return true;
//		else return false;
//	}
//
//	Iterator& operator++()
//	{
//		if (!proverkaPTR()) Ptr = Ptr->next;
//		return *this;
//	}
//
//	Iterator& operator++(int some)
//	{
//		Iterator<T> tempIterator(*this);
//		if (!proverkaPTR()) Ptr = Ptr->next;
//		return tempIterator;
//	}
//
//	bool proverkaPTR()
//	{
//		if (Ptr == NULL) return true;
//		else return false;
//	}
//
//	T& operator*()
//	{
//		if (!proverkaPTR()) 
//			return Ptr->data;
//	}
//};
//#endif