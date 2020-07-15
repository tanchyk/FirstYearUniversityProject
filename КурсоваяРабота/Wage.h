#pragma once
#include "Group.h"
#include "Iterator.h"
#include "Employee.h"

class Wage
{
private:
	Group<Employee> group_employee;
	double* m_wage;

public:
	Wage()
		:m_wage{ nullptr }
	{
	}

	Wage(Group<Employee>& g)
	{
		group_employee = g;
		m_wage = new double[g.get_length()];
		count_wage();
	}

	Wage(string name)
	{
		group_employee.read_file(name);
		m_wage = new double[group_employee.get_length()];
		count_wage();
	}

	void count_wage();
	void add_employee(Employee& employee);
	void print_wage();
	void wage_in_file(string file_name);

	Wage& operator=(Group<Employee>& group);
	friend ostream& operator<<(ostream& out, Wage& wage);
};
