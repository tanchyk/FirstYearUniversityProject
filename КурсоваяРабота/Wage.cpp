#include "Wage.h"

void Wage::count_wage()
{
	for (int i = 0; i < group_employee.get_length(); ++i)
	{
		m_wage[i] = group_employee[i].get_hours_worked() * group_employee[i].get_hour_salary();
	}
}

void Wage::add_employee(Employee& employee)
{
	group_employee.add_back(employee);
	delete[] m_wage;
	m_wage = new double[group_employee.get_length()];
	count_wage();
}

void Wage::print_wage()
{
	cout << *this;
}

void Wage::wage_in_file(string file_name)
{
	ofstream in;
	in.open(file_name);
	if (!in.is_open())
		cout << "Немжливо відкрити файл!" << endl;
	else
	{
		in << *this;
	}
}

Wage& Wage::operator=(Group<Employee>& group)
{
	group_employee = group;
	m_wage = new double[group.get_length()];
	count_wage();

	return *this;
}

ostream& operator<<(ostream& out,Wage& wage)
{
	for (int i = 0; i < wage.group_employee.get_length(); ++i)
	{
		out <<"#" << i+1 << " " << wage.group_employee[i].get_surname() << " ";
		out << wage.group_employee[i].get_name() << " ";
		out << wage.group_employee[i].get_middle_name() << endl;
		out << "Заробітня плата: " << wage.m_wage[i] << endl;
	}
	return out;
}