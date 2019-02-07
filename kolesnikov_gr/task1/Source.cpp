#include  <iostream>
class MeterConvertor
{
	float meters;
public:
	void SetMeters(float meters1) 
	{
		meters = meters1;
	}
	float MetersToYards(float meters)
	{
		float meters1; 
		meters1 =  meters/ 0.9144;
		return meters1;
	}
	float MetersToFoot(float meters)
	{
		float meters1;
		meters1 =  meters/0.3048;
		return meters1;
	}
	float MetersToArshin(float meters)
	{
		float meters1;
		meters1 = meters/ 0.7112;
		return meters1;
	}
	float MetersToSazhen(float meters)
	{
		float meters1;
		meters1 = meters/ 2.1337;
		return meters1;
	}
	float MetersToMile(float meters)
	{
		float meters1;
		meters1 = meters/ 1609.34;
		return meters1;
	}
};
int main()
{
	using namespace std;
	int a;
	char choice1;
	float x, y, z, w;
	MeterConvertor Metr;
	cout << "Enter the lehgth";
	cin >> x;
	cout << "Press 1 to reset length\n";
	cout << "Press 2 to dispay lehgth in current unit\n";
	cout << "Press 3 to convert unit\n";
	cin >> choice1;
	switch (choice1)
	{
	case '1':
	{
		cin >> x;
		break;
	}
	case '2':
	{
		cout << x;
		break;
	}
	case '3':
	{
	
	}
	}
	Metr.SetMeters(x);
	y = Metr.MetersToYards(x);
	cout << y;
	cout << " YYAAArds!!!";
	cout << endl;
	y = Metr.MetersToMile(x);
	cout << y;
	cout << " Miles!!!";
	cout << endl;
	y = Metr.MetersToSazhen(x);
	cout << y;
	cout << " Sazhens";
	cout << endl;
	y = Metr.MetersToFoot(x);
	cout << y;
	cout << " Foots";
	cout << endl;
	y = Metr.MetersToArshin(x);
	cout << y;
	cout << " Arshins";
	cout << endl;
	cout << "CONVERTOR";
	cout << endl;
	cin >> a;
	return 0;
}