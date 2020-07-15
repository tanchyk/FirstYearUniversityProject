#pragma once
# include "Interface.h"

class Person : public Interface
{
private:
	string m_name;
	string m_surname;
	string m_middle_name;
	struct Birthday
	{
		int m_day;
		int m_month;
		int m_year;
	}m_birthday;
	string m_sex;

public:
	Person()
		: m_name{ "Undefined" }, m_surname{ "Undefined" }, m_middle_name{ "Undefined" }, m_sex{ "Undefined" }
	{
		m_birthday.m_day = 0;
		m_birthday.m_month = 0;
		m_birthday.m_year = 0;
	}

	Person(string name, string surname, string middle_name, int day, int month, int year, string sex)
		: m_name{ name }, m_surname{ surname }, m_middle_name{ middle_name }, m_sex{ sex }
	{
		m_birthday.m_day = day;
		m_birthday.m_month = month;
		m_birthday.m_year = year;

		check_data();
	}

	Person(string file)//Конструктор з параметром для роботи з файлом
	{
		from_file(file);
	}

	Person(Person& person) //Конструктор копіювання
	{
		m_name = person.m_name;
		m_surname = person.m_surname;
		m_middle_name = person.m_middle_name;
		m_birthday = person.m_birthday;
		m_sex = person.m_sex;
	}

	virtual void check_data();
	virtual void print_fio();

	//Гетеры
	string get_name() { return m_name; }
	string get_surname() { return m_surname; }
	string get_middle_name() { return m_middle_name; }
	int get_birthday_day() { return m_birthday.m_day; }
	int get_birthday_month() { return m_birthday.m_month; }
	int get_birthday_year() { return m_birthday.m_year; }
	string get_sex() { return m_sex; }

	//Сеттеры
	void set_name(string name);
	void set_surname(string surname);
	void set_middle_name(string middle_name);
	void set_birthday_day(int day);
	void set_birthday_month(int month);
	void set_birthday_year(int year);
	void set_sex(string sex);

	//Функции для работы с файлом
	void in_file(string name);
	void from_file(string name);

	//Перегрузка
	friend ostream& operator<<(ostream& out, const Person& person);
	friend istream& operator>> (istream& in, Person& person);

	void operator()(string name, string surname, string middle_name, int day, int month, int year, string sex);
	void operator()(string name, string surname, string middle_name);
	void operator()(int day, int month, int year);

	Person operator=(Person& person);
	friend bool operator== (const Person& p1, const Person& p2);
	friend bool operator!= (const Person& p1, const Person& p2);

	~Person()
	{
	}
};