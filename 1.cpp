#include <iostream>
#include <string>
#include <sstream>
using namespace std;
double div(double a, double b);
int main()
{
	setlocale(LC_ALL, "Russian");
	double a{};
	double b{};
	string tmp;
	cout << "Введите делимое: ";
	cin.clear();
	while (getline(cin, tmp))
	{
		stringstream ss(tmp);
		if (ss >> a)
		{
			if (a)
			{
				if (ss.eof())
				{
					break;
				}
			}
		}
		cout << "Введите делимое: ";
	}
	cout << "Введите делитель: ";
	cin.clear();
	while (getline(cin, tmp))
	{
		stringstream ss(tmp);
		if (ss >> b)
		{
			if (b)
			{
				if (ss.eof())
				{
					break;
				}
			}
		}
		cout << "Введите делитель: ";
	}
	try
	{
		cout << div(a, b);
	}
	catch (const char* DivisionByZero)
	{
		cerr << "Ошибка: " << DivisionByZero << endl;
	}
	return 0;
}
double div(double a, double b)
{
	if (b == 0)
	{
		throw "Деление на ноль невозможно";
	}
	return (a / b);
}