#pragma once
#include "Person.h"

class Employee : public Person
{
private:
	int m_personel_number;
	double m_min_salary;
	double m_hour_salary;
	int m_work_exp;
	int m_hours_worked;

public:

	//Конструктори
	Employee()
		: Person(), m_personel_number{ 0 }, m_min_salary{ 0.0 }, m_hour_salary{ 0.0 }, m_work_exp{ 0 }, m_hours_worked{ 0 }
	{
	}

	Employee(string name, string surname, string middle_name, int day, int month, int year, string sex, \
		int personel_number, double min_salary, double hour_salary, int work_exp, int hours_worked)
		:Person(name, surname, middle_name, day, month, year, sex), m_personel_number{ personel_number }, \
		m_min_salary{ min_salary }, m_hour_salary{ hour_salary }, m_work_exp{ work_exp }, m_hours_worked{ hours_worked }
	{
		check_data();
	}

	Employee(string file)
	{
		from_file(file);
	}

	Employee(Employee& employee) : Person(employee) //Конструктор копіювання
	{
		m_personel_number = employee.m_personel_number;
		m_min_salary = employee.m_min_salary;
		m_hour_salary = employee.m_hour_salary;
		m_work_exp = employee.m_work_exp;
		m_hours_worked = employee.m_hours_worked;
	}

	virtual void check_data() override;
	virtual void print_fio() override;

	//Геттеры
	int get_personel_number() { return m_personel_number; }
	double get_min_salary() { return m_min_salary; }
	double get_hour_salary() { return m_hour_salary; }
	int get_work_exp() { return m_work_exp; }
	int get_hours_worked() { return m_hours_worked; }

	//Сеттеры
	void set_personel_number(int personel_number);
	void set_min_salary(double min_salary);
	void set_hour_salary(double hour_salary);
	void set_work_exp(int work_exp);
	void set_hours_worked(int hours_worked);

	//Методи для роботи з файлом
	void in_file(string name);
	void from_file(string name);
	void from_file_f(ifstream& out);

	//Перевантаження
	friend ostream& operator<<(ostream& out, Employee& person); //Перевантаження оператора<< для ввиводу данних на консоль
	friend istream& operator>> (istream& in, Employee& person); //Перевантаження оператора>> для введення данних з консолі

	void operator()(string name, string surname, string middle_name, int day, int month, int year, string sex, \
		int personel_number, double min_salary, double hour_salary, int work_exp, int hours_worked);
	void operator()(int personel_number, double min_salary, double hour_salary, int work_exp, int hours_worked);

	Employee operator=(Employee& employee);
	friend bool operator== (Employee& p1, Employee& p2);
	friend bool operator!= (Employee& p1, Employee& p2);

	~Employee()
	{
	}
};