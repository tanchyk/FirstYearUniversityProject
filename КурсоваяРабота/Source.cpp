#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Group.h"
#include "Iterator.h"
#include "Wage.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Group<Employee> group;

	bool program = true;
	while (program == true)
	{
		cout << "<Меню>" << endl;
		cout << "Для заповнення данних введіть  <1>" << endl;
		cout << "Для виведення данних введіть   <2>" << endl;
		cout << "Для редагування данних введіть <3>" << endl;
		cout << "Для розрахунку З.П. введіть    <4>" << endl;
		cout << "Для виходу з програми введіть  <5>" << endl << endl;

		int menu; cin >> menu;
		switch (menu)
		{
			case 1:
			{
				cout << "<Меню> для заповнення данних:" << endl;
				cout << "Для заповнення данних з консолі введіть <1>" << endl;
				cout << "Для заповнення данних з файлу введіть   <2>" << endl;
				cout << "Для повернення в головне меню введіть   <3>" << endl << endl;
				int menu_fill; cin >> menu_fill;

				switch (menu_fill)
				{
				case 1:
				{
					cout << "Введіть кількість робітників: ";
					int num; cin >> num;
					group.resize(num);
					cin >> group;
				} break;

				case 2:
				{
					cout << "Введіть назву файлу: ";
					string file_name; cin >> file_name;
					group.read_file(file_name);
				} break;

				case 3: break;
				}
			}break;

			case 2:
			{
				cout << "<Меню> для виведення данних:" << endl;
				cout << "Для виводу данних на консоль введіть <1>" << endl;
				cout << "Для виводу данних у файл введіть     <2>" << endl;
				cout << "Для виходу до головного меню введіть <3>" << endl << endl;
				int menu_out; cin >> menu_out;

				switch (menu_out)
				{
				case 1:
				{
					cout << group << endl;
				} break;
				
				case 2:
				{
					cout << "Введіть назву файла: ";
					string name_file; cin >> name_file;
					group.in_file(name_file);
				}break;

				case 3: break;
				}
			} break;

			case 3:
			{
				cout << "<Меню> для редагування данних:" << endl;
				cout << "Для додавання робітника введіть      <1>" << endl;
				cout << "Для видалення робітника введіть      <2>" << endl;
				cout << "Для виходу до головного меню введіть <3>" << endl << endl;
				int menu_change; cin >> menu_change;

				switch (menu_change)
				{
				case 1:
				{
					cout << "Для додавання робітника з консолі введіть <1>" << endl;
					cout << "Для додавання робітника з файлу введіть   <2>" << endl;
					cout << "Для виходу до головного меню введіть      <3>" << endl << endl;
					int add; cin >> add;

					switch (add)
					{
					case 1:
					{
						Employee tmp; cin >> tmp;
						group.add_back(tmp);
					}break;

					case 2:
					{
						cout << "Введіть назву файла: ";
						string tmp_str; cin >> tmp_str;
						Employee tmp;
						tmp.from_file(tmp_str);
						group.add_back(tmp);
					}

					case 3: break;
					}
				}break;

				case 2:
				{
					cout << "Для видалення робітника з компанії введіть <1>" << endl;
					cout << "Для виходу до головного меню введіть       <2>" << endl << endl;
					int del; cin >> del;

					switch (del)
					{
					case 1:
					{
						int index;
						do
						{
							cout << "Введіть номер звільненого робітника: " << endl;
							cin >> index;
						} while (index < 0 || index > group.get_length());
						group.remove(index);
					}break;

					case 2: break;
					}

				}break;

				case 3: break;

				}break;

			case 4:
			{
				Wage wage(group);

				cout << "<Меню> для розрахунку З.П.:" << endl;
				cout << "Для виводу З.П. на консоль введіть   <1>" << endl;
				cout << "Для виводу З.П. у файл введіть       <2>" << endl;
				cout << "Для виходу до головного меню введіть <3>" << endl << endl;
				int menu_wage; cin >> menu_wage;

				switch (menu_wage)
				{
				case 1:
				{
					cout << wage << endl;
				}break;

				case 2:
				{
					cout << "Введіть назву файла: ";
					string name_file; cin >> name_file;
					wage.wage_in_file(name_file);
				} break;

				case 3: break;
				}
				}
			}break;

			case 5:
			{
				program = false;
				cout << "<Робота програми завершена>" << endl;
			} break;
		}

	}

	return 0;
}