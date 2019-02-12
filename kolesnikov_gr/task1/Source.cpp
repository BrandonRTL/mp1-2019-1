#include  <iostream>
class MeterConvertor
{
	float meters;
public:
	double Ar[10] = { 1, 0.9144, 0.3048, 1609.34,0.7112, 2.1337 };
	char names[6][15] ={ " meter(s)", " YARD(s)!!!!"," foot(s)"," mile(s)", " arshin(s)", " sazhen(s)"};
	void SetMeters(float meters1) 
	{
		meters = meters1;
	}
	float GetMeters(float meters1)
	{
		meters1 = meters;
	}
	void SetNames(int choice)
	{
		std::cout << names[choice];
	}
	int ChooseUnit ()
	{
		int choice;
		std :: cout << "1 - Yards\n2 - Foot\n3 - Mile\n4 - Arshin\n5 - Sazhen\n";
		std :: cin >> choice;
		return choice;
	}
	float MetersToSOMETHING(int choice)
	{
		float meters1; 
		meters1 =  meters/ Ar[choice];
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
	int a;
	int choice2 = 0;
	char choice1;
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
		break;
	}
	case '2':
	{
		cout << x << " meter(s)" << endl;
		break;
	}
	case '3':
	{
		choice2 = Metr.ChooseUnit();
		y = Metr.MetersToSOMETHING(choice2);
		cout << y;
		Metr.SetNames(choice2);
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
	cin >> a;
	return 0;
}