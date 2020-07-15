#include "Person.h"
using namespace std;

void Person::check_data()
{
	try
	{
		for (int i = 0; i < m_name.length(); i++)
		{
			if (!(m_name[i] >= '�' && m_name[i] <= '�' || m_name[i] == '�'\
				|| m_name[i] == '�' || m_name[i] == '�' || m_name[i] == '�'))
				throw 1;
		}
		for (int i = 0; i < m_surname.length(); i++)
		{
			if (!(m_surname[i] >= '�' && m_surname[i] <= '�' || m_surname[i] == '�'\
				|| m_surname[i] == '�' || m_surname[i] == '�' || m_surname[i] == '�'))
				throw 1;
		}
		for (int i = 0; i < m_middle_name.length(); i++)
		{
			if (!(m_middle_name[i] >= '�' && m_middle_name[i] <= '�' || m_middle_name[i] == '�'\
				|| m_middle_name[i] == '�' || m_middle_name[i] == '�' || m_middle_name[i] == '�'))
				throw 1;
		}
		for (int i = 0; i < m_sex.length(); i++)
		{
			if (!(m_sex[i] >= '�' && m_sex[i] <= '�' || m_sex[i] == '�'\
				|| m_sex[i] == '�' || m_sex[i] == '�' || m_sex[i] == '�'))
				throw 1;
		}
	}
	catch (int)
	{
		cout << "�������: ���������� ������." << endl;
		m_name = "Undefined"; m_surname = "Undefined"; m_middle_name = "Undefined"; m_sex = "Undefined";
	}

	try
	{
		if (m_birthday.m_day > 31 || m_birthday.m_day < 1)
			throw 0;
		if (m_birthday.m_month > 12 || m_birthday.m_month < 1)
			throw 0;
		if (m_birthday.m_year > 2020 || m_birthday.m_year < 1920)
			throw 0;
	}
	catch (int)
	{
		cout << "���� ���� ���������" << endl;
		m_birthday.m_day = 0; m_birthday.m_month = 0; m_birthday.m_year = 0;
	}
}

void Person::print_fio()
{
	cout << m_surname << ", " << m_name << ", " << m_middle_name << ". ";
}

void Person::in_file(string name)
{
	ofstream in;
	in.open(name);
	if (!in.is_open())
		cout << "��������� ������� ����!" << endl;
	else
	{
		in << *this << endl;
	}
	in.close();
}

void Person::from_file(string file)
{
	ifstream out;
	out.open(file);
	if (!out.is_open())
		cout << "��������� ������� ����!" << endl;
	else
	{
		char tmp[100];
		out.getline(tmp, 100);
		char* pch;

		pch = strtok(tmp, ",");
		m_name = string(pch);
		pch = strtok(NULL, ",");
		m_surname = string(pch);
		pch = strtok(NULL, ",");
		m_middle_name = string(pch);

		pch = strtok(NULL, ",");
		m_birthday.m_day = atoi(pch);
		pch = strtok(NULL, ",");
		m_birthday.m_month = atoi(pch);
		pch = strtok(NULL, ",");
		m_birthday.m_year = atoi(pch);

		pch = strtok(NULL, ",");
		m_sex = string(pch);

		delete[] pch;
	}

	check_data();
	out.close();
}

//�������������� ���������
ostream& operator<<(ostream& out, const Person& person)
{
	out << person.m_surname << " " << person.m_name << " " << person.m_middle_name << ", ("\
		<< person.m_birthday.m_day << ", " << person.m_birthday.m_month << ", " << person.m_birthday.m_year << "), " << person.m_sex << ". ";

	return out;
}

istream& operator>> (istream& in, Person& person)
{
	bool check; //����� ��� �������� ����������� ��������

	cout << "<������ ��'� ������>" << endl;
	do
	{
		check = true;
		in >> person.m_name;
		try
		{
			for (int i = 0; i < person.m_name.length(); i++)
			{
				if (!(person.m_name[i] >= '�' && person.m_name[i] <= '�' || person.m_name[i] == '�'\
					|| person.m_name[i] == '�' || person.m_name[i] == '�' || person.m_name[i] == '�'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "������� ���������� ������." << endl;
			check = false;
		}
	} while (check == false);

	cout << "<������ ������� ������>" << endl;
	do
	{
		check = true;
		in >> person.m_surname;
		try
		{
			for (int i = 0; i < person.m_surname.length(); i++)
			{
				if (!(person.m_surname[i] >= '�' && person.m_surname[i] <= '�' || person.m_surname[i] == '�'\
					|| person.m_surname[i] == '�' || person.m_surname[i] == '�' || person.m_surname[i] == '�'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "������� ���������� ������." << endl;
			check = false;
		}
	} while (check == false);

	cout << "<������ ��-������� ������>" << endl;
	do
	{
		check = true;
		in >> person.m_middle_name;
		try
		{
			for (int i = 0; i < person.m_middle_name.length(); i++)
			{
				if (!(person.m_middle_name[i] >= '�' && person.m_middle_name[i] <= '�' || person.m_middle_name[i] == '�'\
					|| person.m_middle_name[i] == '�' || person.m_middle_name[i] == '�' || person.m_middle_name[i] == '�'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "������� ���������� ������." << endl;
			check = false;
		}
	} while (check == false);

	cout << "<������ ���� ���������� ������>" << endl;
	do
	{
		in >> person.m_birthday.m_day; //������� ���� ���������
	} while (person.m_birthday.m_day > 0 && person.m_birthday.m_day <= 31);

	cout << "<������ ����� ���������� ������>" << endl;
	do
	{
		in >> person.m_birthday.m_month; //������� ���� ����������
	} while (person.m_birthday.m_month > 0 && person.m_birthday.m_month <= 12);

	cout << "<������ �� ���������� ������>" << endl;
	do
	{
		in >> person.m_birthday.m_year; //������� �� ���������
	} while (person.m_birthday.m_year > 1920 && person.m_birthday.m_year <= 2029);

	cout << "<������ ����� ������>" << endl;
	do
	{
		check = true;
		in >> person.m_sex; //������� ����� ������
		try
		{
			for (int i = 0; i < person.m_sex.length(); i++)
			{
				if (!(person.m_sex[i] >= '�' && person.m_sex[i] <= '�' || person.m_sex[i] == '�'\
					|| person.m_sex[i] == '�' || person.m_sex[i] == '�' || person.m_sex[i] == '�'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "������� ���������� ������." << endl;
			check = false;
		}
	} while (check == false);

	return in;
}

void Person::operator()(string name, string surname, string middle_name, int day, int month, int year, string sex)
{
	m_name = name;
	m_surname = surname;
	m_middle_name = middle_name;

	m_birthday.m_day = day;
	m_birthday.m_month = month;
	m_birthday.m_year = year;

	m_sex = sex;

	check_data();
}

void Person::operator()(string name, string surname, string middle_name)
{
	try
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] < '�' && name[i] > '�' || name[i] < '�' && name[i] > '�'\
				|| name[i] != 'I' || name[i] != 'i' || name[i] != '�' || name[i] != '�')
				throw "Error";
		}
		for (int i = 0; i < surname.length(); i++)
		{
			if (surname[i] < '�' && surname[i] > '�' || surname[i] < '�' && surname[i] > '�'\
				|| surname[i] != 'I' || surname[i] != 'i' || surname[i] != '�' || surname[i] != '�')
				throw "Error";
		}
		for (int i = 0; i < middle_name.length(); i++)
		{
			if (middle_name[i] < '�' && middle_name[i] > '�' || middle_name[i] < '�' && middle_name[i] > '�'\
				|| middle_name[i] != 'I' || middle_name[i] != 'i' || middle_name[i] != '�' || middle_name[i] != '�')
				throw "Error";
		}
	}
	catch(string error)
	{
		cout << error << " ���������� ������." << endl;
		return;
	}

	m_name = name;
	m_surname = surname;
	m_middle_name = middle_name;
}

void Person::operator()(int day, int month, int year)
{
	try
	{
		if (day > 31 || day < 1)
			throw 0;
		if (month > 12 || month < 1)
			throw 0;
		if (year > 2020 || year < 1920)
			throw 0;
	}
	catch (int num)
	{
		cout << "���� ���� ���������" << endl;
		return;
	}

	m_birthday.m_day = day;
	m_birthday.m_month = month;
	m_birthday.m_year = year;
}

Person Person::operator=(Person& person)
{
	m_name = person.m_name;
	m_surname = person.m_surname;
	m_middle_name = person.m_middle_name;
	m_birthday = person.m_birthday;
	m_sex = person.m_sex;

	return *this;
}

bool operator==(const Person& p1, const Person& p2) // ���������
{
	return (p1.m_name == p2.m_name && p1.m_surname == p2.m_surname && p1.m_middle_name == p2.m_middle_name && \
		p1.m_birthday.m_day == p2.m_birthday.m_day && p1.m_birthday.m_month == p2.m_birthday.m_month && \
		p1.m_birthday.m_year == p2.m_birthday.m_year && p1.m_sex == p2.m_sex);
}

bool operator!= (const Person& p1, const Person& p2)
{
	return!(p1 == p2);
}

//�������
void Person::set_name(string name)
{
	try
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (!(name[i] >= '�' && name[i] <= '�' || name[i] == '�'\
				|| name[i] == '�' || name[i] == '�' || name[i] == '�'))
				throw 1;
		}
	}
	catch (int)
	{
		cout << "������� ���������� ������." << endl;
		return;
	}
	m_name = name;
}

void Person::set_surname(string surname)
{
	try
	{
		for (int i = 0; i < surname.length(); i++)
		{
			if (!(surname[i] >= '�' && surname[i] <= '�' || surname[i] == '�'\
				|| surname[i] == '�' || surname[i] == '�' || surname[i] == '�'))
				throw 1;
		}
	}
	catch (int)
	{
		cout << "������� ���������� ������." << endl;
		return;
	}
	m_surname = surname;
}

void Person::set_middle_name(string middle_name)
{
	try
	{
		for (int i = 0; i < middle_name.length(); i++)
		{
			if (!(middle_name[i] >= '�' && middle_name[i] <= '�' || middle_name[i] == '�'\
				|| middle_name[i] == '�' || middle_name[i] == '�' || middle_name[i] == '�'))
				throw 1;
		}
	}
	catch (int)
	{
		cout << "������� ���������� ������." << endl;
		return;
	}
	m_middle_name = middle_name;
}

void Person::set_birthday_day(int day)
{
	try
	{
		if (day > 31 || day < 1)
			throw 0;
	}
	catch (int)
	{
		cout << "���� ���� ���������" << endl;
		return;
	}
	m_birthday.m_day = day;
}

void Person::set_birthday_month(int month)
{
	try
	{
		if (month > 12 || month < 1)
			throw 0;
	}
	catch (int)
	{
		cout << "���� ���� ���������" << endl;
		return;
	}
	m_birthday.m_month = month;
}

void Person::set_birthday_year(int year)
{
	try
	{
		if (year > 2020 || year < 1920)
			throw 0;
	}
	catch (int)
	{
		cout << "���� ���� ���������" << endl;
		return;
	}
	m_birthday.m_year = year;
}

void Person::set_sex(string sex)
{
	try
	{
		for (int i = 0; i < sex.length(); i++)
		{
			if (!(sex[i] >= '�' && sex[i] <= '�' || sex[i] == '�'\
				|| sex[i] == '�' || sex[i] == '�' || sex[i] == '�'))
				throw 1;
		}
	}
	catch (int)
	{
		cout << "������� ���������� ������." << endl;
		return;
	}
	m_sex = sex;
}
