#include "Employee.h"

void Employee::check_data()
{
	Person::check_data();
	try
	{
		if (m_personel_number < 0)
			throw 0;
		if (m_min_salary < 4723.0) // 4723 мімальний оклад в Україні
			throw 0;
		if (m_hour_salary < 26.23) // 26.23 мінімальний оклад в годину в Україні
			throw 0;
		if (m_work_exp < 0 || m_work_exp > 80)
			throw 0;
		if (m_hours_worked < 0 || m_hours_worked > 180) //Максимальна кількість робочих годин в украйїні за місяць
			throw 0;
	}
	catch (int num)
	{
		cout << "Такиі данні неможливі" << endl;
		m_personel_number = 0;
		m_min_salary = 0.0;
		m_hour_salary = 0.0;
		m_work_exp = 0;
		m_hours_worked = 0;
	}
}

void Employee::print_fio()
{
	cout << get_surname() << ", " << get_name() << ", " << get_middle_name() << ", " << m_personel_number << ". ";
}

void Employee::from_file(string file)
{
	ifstream out;
	out.open(file);
	from_file_f(out);

	out.close();
}

void Employee::from_file_f(ifstream& out)
{
	if (!out.is_open())
		cout << "Неможливо відкрити файл!" << endl;
	else
	{
		char tmp[200];
		out.getline(tmp, 200);
		char* pch;

		pch = strtok(tmp, ",");
		set_name(string(pch));
		pch = strtok(NULL, ",");
		set_surname(string(pch));
		pch = strtok(NULL, ",");
		set_middle_name(string(pch));

		pch = strtok(NULL, ",");
		set_birthday_day(atoi(pch));
		pch = strtok(NULL, ",");
		set_birthday_month(atoi(pch));
		pch = strtok(NULL, ",");
		set_birthday_year(atoi(pch));

		pch = strtok(NULL, ",");
		set_sex(string(pch));

		pch = strtok(NULL, ",");
		m_personel_number = atoi(pch);
		pch = strtok(NULL, ",");
		m_min_salary = atof(pch);
		pch = strtok(NULL, ",");
		m_hour_salary = atof(pch);
		pch = strtok(NULL, ",");
		m_work_exp = atoi(pch);
		pch = strtok(NULL, ",.");
		m_hours_worked = atoi(pch);
	}
	check_data();
}

void Employee::in_file(string name)
{
	ofstream in;
	in.open(name);
	if (!in.is_open())
		cout << "Неможливо відкрити файл!" << endl;
	else
	{
		in << *this << endl;
	}
	in.close();
}

//Перегрузка
ostream& operator<<(ostream& out, Employee& employee)
{
	out << employee.get_surname() << " " << employee.get_name() << " " << employee.get_middle_name();
	out << ", (" << employee.get_birthday_day() << ", " << employee.get_birthday_month() << ", " << employee.get_birthday_year() << "), ";
	out << employee.get_sex() << ", " << employee.get_personel_number() << ", " << employee.get_min_salary() << ", " << employee.get_hour_salary();
	out << ", " << employee.get_work_exp() << ", " << employee.get_hours_worked() << ". ";

	return out;
}

istream& operator>> (istream& in, Employee& person)
{
	bool check; //Змінна для перевірки правильності введення
	string stmp;
	int itmp;
	double dtmp;

	cout << "<Введіть ім'я людини>" << endl;
	do
	{
		check = true;
		in >> stmp;
		try
		{
			for (int i = 0; i < stmp.length(); i++)
			{
				if (!(stmp[i] >= 'А' && stmp[i] <= 'я' || stmp[i] == 'І'\
					|| stmp[i] == 'і' || stmp[i] == 'є' || stmp[i] == 'є'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "Помилка неможливий символ." << endl;
			check = false;
		}
	} while (check == false); person.set_name(stmp);

	cout << "<Введіть прізвище людини>" << endl;
	do
	{
		check = true;
		in >> stmp;
		try
		{
			for (int i = 0; i < stmp.length(); i++)
			{
				if (!(stmp[i] >= 'А' && stmp[i] <= 'я' || stmp[i] == 'І'\
					|| stmp[i] == 'і' || stmp[i] == 'є' || stmp[i] == 'є'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "Помилка неможливий символ." << endl;
			check = false;
		}
	} while (check == false); person.set_surname(stmp);

	cout << "<Введіть по-батькові людини>" << endl;
	do
	{
		check = true;
		in >> stmp;
		try
		{
			for (int i = 0; i < stmp.length(); i++)
			{
				if (!(stmp[i] >= 'А' && stmp[i] <= 'я' || stmp[i] == 'І'\
					|| stmp[i] == 'і' || stmp[i] == 'є' || stmp[i] == 'є'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "Помилка неможливий символ." << endl;
			check = false;
		}
	} while (check == false); person.set_middle_name(stmp);

	cout << "<Введіть день народження людини>" << endl;
	do
	{
		in >> itmp;

	} while (itmp < 0 || itmp > 31); person.set_birthday_day(itmp);

	cout << "<Введіть місяць народження людини>" << endl;
	do
	{
		in >> itmp;
	} while (itmp < 0 || itmp > 12); person.set_birthday_month(itmp);

	cout << "<Введіть рік народження людини>" << endl;
	do
	{
		in >> itmp;
	} while (itmp < 1920 || itmp > 2004); person.set_birthday_year(itmp);

	cout << "<Введіть стать людини>" << endl;
	do
	{
		check = true;
		in >> stmp; //Вводимо стать людини
		try
		{
			for (int i = 0; i < stmp.length(); i++)
			{
				if (!(stmp[i] >= 'А' && stmp[i] <= 'я' || stmp[i] == 'І'\
					|| stmp[i] == 'і' || stmp[i] == 'є' || stmp[i] == 'є'))
					throw 1;
			}
		}
		catch (int)
		{
			cout << "Помилка неможливий символ." << endl;
			check = false;
		}
	} while (check == false); person.set_sex(stmp);

	cout << "<Введіть табельний номер людини>" << endl;
	do
	{
		in >> itmp;
	} while (itmp < 0); person.set_personel_number(itmp);

	cout << "<Введіть оклад людини>" << endl;
	do
	{
		in >> dtmp;
	} while (dtmp < 4723); person.set_min_salary(dtmp);

	cout << "<Введіть зарплату за годину людини>" << endl;
	do
	{
		in >> dtmp;
	} while (dtmp < 26.23); person.set_hour_salary(dtmp);

	cout << "<Введіть стаж роботи людини>" << endl;
	do
	{
		in >> itmp;
	} while (itmp < 0 || itmp > 80); person.set_work_exp(itmp);

	cout << "<Введіть кількість відпрацьованих годин людини>" << endl;
	do
	{
		in >> itmp;
	} while (itmp < 0 || itmp > 180); person.set_hours_worked(itmp);

	return in;
}

void Employee::operator()(string name, string surname, string middle_name, int day, int month, int year, string sex, \
	int personel_number, double min_salary, double hour_salary, int work_exp, int hours_worked)
{
	Person::operator()(name, surname, middle_name, day, month, year, sex);
	Employee::operator()(personel_number, min_salary, hour_salary, work_exp, hours_worked);
}

void Employee::operator()(int personel_number, double min_salary, double hour_salary, int work_exp, int hours_worked)
{
	try
	{
		if (personel_number < 0)
			throw 0;
		if (min_salary < 4723.0)
			throw 0;
		if (hour_salary < 26.23)
			throw 0;
		if (work_exp < 0 || work_exp > 80)
			throw 0;
		if (hours_worked < 0 || hours_worked > 180)
			throw 0;
	}
	catch (int)
	{
		cout << "Такиі данні неможливі" << endl;
		return;
	}
	m_personel_number = personel_number;
	m_min_salary = min_salary;
	m_hour_salary = hour_salary;
	m_work_exp = work_exp;
	m_hours_worked = hours_worked;
}

Employee Employee::operator=(Employee& employee)
{
	Person::operator=(employee);
	m_personel_number = employee.m_personel_number;
	m_min_salary = employee.m_min_salary;
	m_hour_salary = employee.m_hour_salary;
	m_work_exp = employee.m_work_exp;
	m_hours_worked = employee.m_hours_worked;

	return *this;
}

bool operator== (Employee& p1, Employee& p2)
{
	return (p1.get_name() == p2.get_name() && p1.get_surname() == p2.get_surname() && p1.get_middle_name() == p2.get_middle_name() && \
		p1.get_birthday_day() == p2.get_birthday_day() && p1.get_birthday_month() == p2.get_birthday_month() && \
		p1.get_birthday_year() == p2.get_birthday_year() && p1.get_sex() == p2.get_sex() && p1.get_personel_number() == p2.get_personel_number() && \
		p1.get_min_salary() == p2.get_min_salary() && p1.get_hour_salary() == p2.get_hour_salary() && p1.get_work_exp() == p2.get_work_exp() && \
		p1.get_hours_worked() == p2.get_hours_worked());
}

bool operator!= (Employee& p1, Employee& p2)
{
	return!(p1 == p2);
}

//Сеттери
void Employee::set_personel_number(int personel_number)
{
	try
	{
		if (personel_number < 0)
			throw 0;
	}
	catch (int)
	{
		cout << "Такий табельний номер неможливий" << endl;
		return;
	}
	m_personel_number = personel_number;
}

void Employee::set_min_salary(double min_salary)
{
	try
	{
		if (min_salary < 4723.0)
			throw 0;
	}
	catch (int num)
	{
		cout << "Така заробітня плата неможлива" << endl;
		return;
	}
	m_min_salary = min_salary;
}

void Employee::set_hour_salary(double hour_salary)
{
	try
	{
		if (hour_salary < 26.23)
			throw 0;
	}
	catch (int)
	{
		cout << "Така заробітня плата в годину неможлива" << endl;
		return;
	}
	m_hour_salary = hour_salary;
}

void Employee::set_work_exp(int work_exp)
{
	try
	{
		if (work_exp < 0 || work_exp > 80)
			throw 0;
	}
	catch (int)
	{
		cout << "Такий досвід праці неможливий" << endl;
		return;
	}
	m_work_exp = work_exp;
}

void Employee::set_hours_worked(int hours_worked)
{
	try
	{
		if (hours_worked < 0 || hours_worked > 180)
			throw 0;
	}
	catch (int)
	{
		cout << "Така кількість робочих годин неможлива" << endl;
		return;
	}
	m_hours_worked = hours_worked;
}
