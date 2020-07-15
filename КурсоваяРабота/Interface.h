#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
#include<string>
#include<cassert>
#include <cctype>
using namespace std;

class Interface
{
public:

	virtual void check_data() = 0;
	virtual void print_fio() = 0;

	virtual ~Interface()
	{
	}
};
