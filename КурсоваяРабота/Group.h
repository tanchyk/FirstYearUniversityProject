#pragma once
#include "Person.h"
#include "Employee.h"

template<class T>
class Group
{
private:
	int m_length;
	T* m_group;

public:

	Group()
		:m_length{ 0 }, m_group{ nullptr }
	{
	}

	Group(int length)
		: m_length{ length }
	{
		assert(m_length >= 0);
		m_group = new T[length];
	}

	Group(int length, T& group)
		: Group(length)
	{
		for (int i = 0; i < m_length; ++i)
			m_group[i] = group;
	}

	Group(string name)
	{
		read_file(name);
	}

	Group(Group<T>& group)
	{
		m_length = group.m_length;
		m_group = group.m_group;
	}

	void read_file(string name);
	void in_file(string name);

	T* begin() { return m_group; }
	T* end() { return (m_group + m_length); }

	void erase();
	void resize(int new_length);
	void remade(int new_length);
	void remove(int index);
	bool empty();

	void add(T& group, int index);
	void add_beginning(T& group);
	void add_back(T& group);

	int get_length() { return m_length; }

	T& operator[](int index);

	Group<T>& operator=(const Group<T>& group);
	friend bool operator==(Group<T>& g1, Group<T>& g2)
	{
		bool tmp = true;
		for (int i = 0; i < g1.m_length; ++i)
		{
			if (g1[i] != g2[i])
				tmp == false;
		}

		return (g1.m_length == g2.m_length && tmp == true);
	}
	friend bool operator!=(Group<T>& g1, Group<T>& g2)
	{
		return!(g1 == g2);
	}

	friend ostream& operator<<(ostream& out, Group<T>& person)
	{
		for (int i = 0; i < person.m_length; ++i)
			out << person[i] << endl;
		return out;
	}
	friend istream& operator>> (istream& in, Group<T>& person)
	{
		for (int i = 0; i < person.m_length; ++i)
			in >> person[i];
		return in;
	}

	~Group()
	{
		delete[] m_group;
	}
};

#include "Group.inl"