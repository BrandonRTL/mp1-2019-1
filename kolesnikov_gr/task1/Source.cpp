#include  <iostream>
class MeterConvertor
{
	float meters;
	double Ar[10] = { 1, 0.9144, 0.3048, 1609.34,0.7112, 2.1337 };
	char names[6][15] = { " meter(s)", " YARD(s)!!!!"," foot(s)"," mile(s)", " arshin(s)", " sazhen(s)" };
public:
	void SetMeters(float meters1)
	{
		meters = meters1;
	}
	void PrintNames(int choice)
	{
		std::cout << names[choice];
	}
	float GetMeters(float meters1)
	{
		meters = meters1;
	}
	float MetersToYards()
	{
		float meters1;
		meters1 = meters / Ar[1];
		return meters1;
	}
	float MetersToFoots()
	{
		float meters1;
		meters1 = meters / Ar[2];
		return meters1;
	}
	float MetersToMiles()
	{
		float meters1;
		meters1 = meters / Ar[3];
		return meters1;
	}
	float MetersToArshins()
	{
		float meters1;
		meters1 = meters / Ar[4];
		return meters1;
	}
	float MetersToSazhens()
	{
		float meters1;
		meters1 = meters / Ar[5];
		return meters1;
	}
	MeterConvertor()
	{
		meters = 0;
	}
	MeterConvertor(float n)
	{
		meters = n;
	}
};
int main()
{
	using namespace std;
	int choice2 = 0;
	char choice1,choice3;
	bool flag1 = 1;
	float x, y;
	cout << "Enter the length\n";
	cin >> x;
	MeterConvertor Metr(x);
	while(flag1)
	{ 
	cout << "Press 1 to reset length\n"  << "Press 2 to dispay length in meters\n" << "Press 3 to convert unit\n" << "Press 4 to exit\n";
	cin >> choice1;
	y = x;
	switch (choice1)
	{
	case '1':
	{
		cout << "Enter the length\n";
		cin >> x;
		cout << endl;
		Metr.SetMeters(x);
		y = x;
		break;
	}
	case '2':
	{
		cout << x << " meter(s)" << endl;
		break;
	}
	case '3':
	{
		std::cout << "1 - Yard\n2 - Foot\n3 - Mile\n4 - Arshin\n5 - Sazhen\n";
		std::cin >> choice3;
		switch (choice3)
		{
		case '1':
			{
			y = Metr.MetersToYards();
			break;
			}
		case '2':
		{
			y = Metr.MetersToFoots();
			break;
		}
		case '3':
		{
			y = Metr.MetersToMiles();
			break;
		}
		case '4':
		{
			y = Metr.MetersToArshins();
			break;
		}
		case '5':
		{
			y = Metr.MetersToSazhens();
			break;
		}
		}
		cout << y;
		choice2 = int(choice3)-48;
		Metr.PrintNames(choice2);
		cout << endl;
		break;
	}
	case '4':
	{
		flag1 = 0;
		break;
	}
	}
	}
	return 0;
}