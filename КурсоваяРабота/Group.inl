#include "Group.h"

template <typename T>
void Group<T>::read_file(string name)
{
	erase();
	m_length = 0;
	m_group = new T[m_length];
	ifstream out;
	out.open(name);
	if (!out.is_open())
		cout << "Неможливо відкрити файл!" << endl;
	else
	{
		while (!out.eof())
		{
			Employee tmp;
			tmp.from_file_f(out);
			add_back(tmp);
		}
	}
}

template <typename T>
void Group<T>::in_file(string name)
{
	ofstream in;
	in.open(name);
	if (!in.is_open())
		cout << "Неможливо відкрити файл!" << endl;
	else
	{
		for (int i = 0; i < m_length; ++i)
		{
			in << m_group[i];
		}
	}
	in.close();
}

template <typename T>
void Group<T>::erase()
{
	delete[] m_group;
	m_group = nullptr;
	m_length = 0;
}

template <typename T>
void Group<T>::resize(int new_length)
{
	if (new_length == m_length)
		return;

	if (new_length <= 0)
	{
		erase();
		return;
	}

	T* group = new T[new_length];
	int elements;
	if (new_length > m_length)
		elements = m_length;
	else
		elements = new_length;

	for (int i = 0; i < elements; ++i)
		group[i] = m_group[i];

	delete[] m_group;

	m_group = group;
	m_length = new_length;
}

template <typename T>
void Group<T>::remade(int newLength)
{
	erase();

	if (newLength <= 0)
		return;

	m_group = new T[newLength];
	m_length = newLength;
}

template <typename T>
void Group<T>::remove(int index)
{
	assert(index >= 0 || index <= m_length);

	if (m_length == 1)
	{
		erase();
		return;
	}
	else if (index == m_length)
	{
		T* group = new T[m_length - 1];
		for (int i = 0; i < (index - 1); ++i)
			group[i] = m_group[i];

		delete[] m_group;
		m_group = group;
		--m_length;
		return;
	}
	else if (index == 0)
	{
		T* group = new T[m_length - 1];
		for (int i = 0; i > (index - 1); --i)
			group[i] = m_group[i+1];

		delete[] m_group;
		m_group = group;
		--m_length;
		return;
	}
	else
	{
		T* group = new T[m_length - 1];

		for (int i_before = 0; i_before < index; ++i_before)
			group[i_before] = m_group[i_before];

		for (int i_after = index + 1; i_after < m_length; ++i_after)
			group[i_after - 1] = m_group[i_after];

		delete[] m_group;
		m_group = group;
		--m_length;
	}
}

template <typename T>
bool Group<T>::empty()
{
	if (m_length == 0)
		return true;
}

template <typename T>
void Group<T>::add(T& group, int index)
{
	assert(index >= 0 && index <= m_length);

	T* ary_group = new T[m_length + 1];

	for (int i_before = 0; i_before < index; ++i_before)
		ary_group[i_before] = m_group[i_before];

	ary_group[index] = group;

	for (int i_after = index; i_after < m_length; ++i_after)
		ary_group[i_after + 1] = m_group[i_after];

	delete[] m_group;
	m_group = ary_group;
	++m_length;
}

template <typename T>
void Group<T>::add_beginning(T& group)
{
	add(group, 0);
}

template<typename T>
void Group<T>::add_back(T& group)
{
	add(group, m_length);
}

//Перегрузка
template <typename T>
T& Group<T>::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_group[index];
}

template <typename T>
Group<T>& Group<T>::operator=(const Group<T>& group)
{
	erase();
	m_length = group.m_length;
	m_group = new T[m_length];
	for (int i = 0; i < m_length; ++i)
		m_group[i] = group.m_group[i];

	return *this;
}