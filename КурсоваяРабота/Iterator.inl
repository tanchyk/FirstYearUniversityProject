#include "Iterator.h"

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	++m_current;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	--m_current;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++(int)
{
	m_current++;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--(int)
{
	m_current--;
	return *this;
}

template <typename T>
T& Iterator<T>::operator*()
{
	return (*m_current);
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(T* ptr)
{
	m_current = ptr;
	return *this;
}