#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int Start{ 0 };
const int End{ 10 };

class OffTheField
{
public:
	OffTheField(int offTheField) : o_offTheField(offTheField) {}
	int getRobotDirection() const
	{
		return o_offTheField;
	}

private:
	int o_offTheField;
};

class IllegalCommand
{
public:
	IllegalCommand(int illegalCommand) : i_illegalCommand(illegalCommand) {}
	int getIllegalCommand() const
	{
		return i_illegalCommand;
	}

private:
	int i_illegalCommand;
};

class Robot
{
public:
	Robot() { x = 0; y = 0; }

	void up()
	{
		if (y == End)
		{
			throw OffTheField{ y };
		}
		else y++;
		show();
	}
	void down()
	{
		if (y == Start)
		{
			throw OffTheField{ y };
		}
		else y--;
		show();
	}
	void left()
	{
		if (x == Start)
		{
			throw OffTheField{ x };
		}
		else x--;
		show();
	}
	void right()
	{
		if (x == End)
		{
			throw OffTheField{ x };
		}
		else x++;
		show();
	}
	void show() const
	{
		cout << "Координаты робота: " << x << ", " << y << endl;
	}

protected:
	int x, y;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int command{};
	Robot robot;
	while (true)
	{
		string tmp;
		cout << endl << "Меню управления роботом (5 для выхода):" << endl << "1 - на клетку вверх" << endl
			<< "2 - на клетку вниз" << endl << "3 - на клетку влево" << endl << "4 - на клетку вправо " << endl;
		while (getline(cin, tmp))
		{
			stringstream ss(tmp);
			if (ss >> command)
			{
				if (command)
				{
					if (ss.eof())
					{
						break;
					}
				}
			}
			cout << endl << "Меню управления роботом (5 для выхода):" << endl << "1 - на клетку вверх" << endl
				<< "2 - на клетку вниз" << endl << "3 - на клетку влево" << endl << "4 - на клетку вправо " << endl;
		}
		try
		{
			switch (command)
			{
			case 1:
			{
				robot.up();
				break;
			}
			case 2:
			{
				robot.down();
				break;
			}
			case 3:
			{
				robot.left();
				break;
			}
			case 4:
			{
				robot.right();
				break;
			}
			case 5:
			{
				cout << "Выход из программы." << endl;
				return 0;
			}
			default:
				throw IllegalCommand{ command };
				break;
			}
		}
		catch (OffTheField)
		{
			cerr << "Ошибка. Невозможно выехать за поле" << endl;
			cerr << "Последняя введённая команда: " << command << endl;
			robot.show();
		}
		catch (IllegalCommand)
		{
			cerr << "Последняя введённая команда: " << command << endl;
			cerr << "Ошибка. Подана неверная команда" << endl;
		}
	}
	return 0;
}