#pragma once
#include<iostream>
using namespace std;

template <class T>
class Iterator
{
private:
	T* m_current;

public:
	Iterator()
		: m_current{ nullptr }
	{
	}

	Iterator(T* first)
		:m_current{ first }
	{
	}

	friend Iterator<T> operator+(int index, Iterator<T> it)
	{
		it.m_current + index;
		return it;
	}
	friend Iterator<T> operator+(Iterator<T> it, int index)
	{
		it.m_current + index;
		return it;
	}

	friend Iterator<T> operator-(int index, Iterator<T> it)
	{
		it.m_current - index;
		return it;
	}
	friend Iterator<T> operator-(Iterator<T> it, int index)
	{
		it.m_current - index;
		return it;
	}

	Iterator<T>& operator++();
	Iterator<T>& operator--();
	Iterator<T>& operator++(int);
	Iterator<T>& operator--(int);

	T& operator*();

	Iterator<T>& operator=(T* ptr);

	friend bool operator== (Iterator<T>& p1, Iterator<T>& p2)
	{
		return (p1.m_current == p2.m_current);
	}
	friend bool operator!= (Iterator<T>& p1, Iterator<T>& p2)
	{
		return (p1.m_current != p2.m_current);
	}

	friend bool operator< (const Iterator<T>& ptr, const T* emp)
	{
		return(ptr.m_current < emp);
	}

	friend ostream& operator<<(ostream& out, Iterator<T>& it)
	{
		out << it.m_current;
		return out;
	}

	~Iterator()
	{
	}
};

#include "Iterator.inl"