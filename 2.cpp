#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Ex
{
public:
	Ex(double x_number) : x(x_number) {}
	double exception() const
	{
		return x;
	}

private:
	double x;
};

class Bar
{
public:
	Bar() : y(0) {}
	void set(double a)
	{
		if ((y + a) > 100)
		{
			throw Ex{ a * y };
		}
		else
		{
			y = a;
		}
	}

private:
	double y;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Bar bar;
	int n{};
	try
	{
		do
		{
			string tmp;
			cout << "Введите целочисленное значение: ";
			cin.clear();
			while (getline(cin, tmp))
			{
				stringstream ss(tmp);
				if (ss >> n)
				{
					if (n)
					{
						if (ss.eof())
						{
							bar.set(n);
							break;
						}
					}
				}
				cout << "Введите целочисленное значение: ";
			}
		}
		while (n != 0);
	}
	catch (const Ex &ex)
	{
		cout << "Ошибка. Сумма превысила 100: " << ex.exception() << endl;
	}
	return 0;
}