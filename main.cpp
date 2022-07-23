#include <iostream>
#include <random>

void Seperator(int a);
int RandomNumber();
void BallCount(int a, int b, int c, int d, int e, int f);
void AlarmRecord(int array[3]);

int main()
{
	int number1;
	std::cout << "세자리 숫자를 입력하세요.";
	std::cin >> number1;
	Seperator(number1);
}

void Seperator(int number2)
{
	int a, b, c;
	static int d, e, f, rdn{ 100 };
	a = number2 / 100;
	b = (number2 - (100 * a)) / 10;
	c = (number2 - (100 * a) - (10 * b));

	if (rdn != (100 * d) + (10 * e) + f)
	{
		rdn = RandomNumber();
		d = rdn / 100;
		e = (rdn - (100 * d)) / 10;
		f = (rdn - (100 * d) - (10 * e));
	}

	BallCount(a, b, c, d, e, f);
}

int RandomNumber()
{
	int x{ 0 }, y{ 0 }, z{ 0 }, rdnum{ 0 };

	while (x == y || x == z || y == z)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(100, 999);

		rdnum = dis(gen);
		x = rdnum / 100;
		y = (rdnum - (100 * x)) / 10;
		z = (rdnum - (100 * x) - (10 * y));
	}
	return rdnum;
}

void BallCount(int a, int b, int c, int d, int e, int f)
{
	int count[3]{0, 0, 0};

	if (a != d && a != e && a != f)
	{
		count[2]++;
	}
	if (b != d && b != e && b != f)
	{
		count[2]++;
	}
	if (c != d && c != e && c != f)
	{
		count[2]++;
	}

	if (a == e || a == f)
	{
		count[1]++;
	}
	if (b == d || b == f)
	{
		count[1]++;
	}
	if (c == d || c == e)
	{
		count[1]++;
	}

	if (a == d)
	{
		count[0]++;
	}
	if (b == e)
	{
		count[0]++;
	}
	if (c == f)
	{
		count[0]++;
	}

	AlarmRecord(count);
}

void AlarmRecord(int answer[3])
{
	int number3{};

	if (answer[0] == 3)
	{
		std::cout << "정답입니다!" << std::endl;
	}

	if (answer[0] == 2)
	{
		if (answer[1] == 1)
		{
			std::cout << "2 Strike, 1 Ball" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}

		else if (answer[2] == 1)
		{
			std::cout << "2 Strike, 1 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
	}

	if (answer[0] == 1)
	{
		if (answer[1] == 2)
		{
			std::cout << "1 Strike, 2 Ball" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
		else if (answer[1] == 1) 
 		{
			std::cout << "1 Strike, 1 Ball, 1 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
		else if (answer[2] == 2)
		{
			std::cout << "1 Strike, 2 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
	}

	if (answer[0] == 0)
	{
		if (answer[1] == 1)
		{
			std::cout << "1 Ball, 2 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
		else if (answer[1] == 2)
		{
			std::cout << "2 Ball, 1 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
		else if (answer[1] == 3)
		{
			std::cout << "3 Ball" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
		else if (answer[2] == 3)
		{
			std::cout << "3 Out" << std::endl;
			std::cin >> number3;
			Seperator(number3);
		}
	}
}





