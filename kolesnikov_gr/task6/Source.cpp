#include <iostream> 
#include <string> 
#include <clocale> 
#include <fstream> 
#include <vector> 
#include <fstream>
#include <time.h>
using namespace std;
class NonRepeatingDigits
{
public:
	static vector<int> Generate(int length)
	{
		vector<int> Digits(length);
		int Numeral;
		Digits[0] = rand() % 9 + 1;
		for (int i = 1; i < length; i++)
		{
			Numeral = rand() % 10;
			for (int j = 0; j < i; j++)
			{
				while (Numeral == Digits[j])
				{
					j = 0;
					Numeral = rand() % 10;
				}
				Digits[i] = Numeral;
			}
		}
		return Digits;
	}
};
class BnC
{
	int cows;
	int bools;
public:
	void Guessing()
	{
		cows = 0;
		bools = 0;
		int Number;
		vector<int> TrueDigits(length);
		cout << "Number" << endl;
		//	for (int i = 0; i < length; i++)
		//		cout << Digits[i] << endl;
		cin >> Number;
		for (int i = 0; i < length; i++)
		{
			TrueDigits[i] = (Number) % 10;
			Number /= 10;
		}
		for (int i = 0; i < length; i++)
		{
			if (Digits[i] == TrueDigits[length - i - 1])
				bools = bools + 1;
			else
			{
				for (int j = 0; j < length; j++)
				{
					if (Digits[i] == TrueDigits[length - j - 1])
						cows = cows + 1;
				}
			}
		}

	}
	void SetLenght(int _lenght)
	{
		length = _lenght;
	}
	void SetNumber()
	{
		vector<int>_Digits = NonRepeatingDigits::Generate(length);
		Digits = _Digits;
	}
	bool WinCheck()
	{
		bool WinCheck = 0;
		if (cows == 0)
			if (bools != length)
				printf("Cows.net\n");
		if (bools == 0)
			if (bools != length)
				printf("Bools.net\n");
		if (cows > 0)
			if (bools != length)
				printf("Cows %d\n", cows);
		if (bools > 0)
			if (bools != length)
				printf("Bools %d\n", bools);
		if (bools == length)
		{
			printf("You win!\n");
			WinCheck = 1;
		}
		return WinCheck;
	}
private:
	int length;
	vector<int>Digits;
	int count;
};
void main()
{
	srand(time(NULL));
	BnC Game;
	bool win = 0;
	int length = 5;
	cout << "Enter the Lenght";
	cin >> length;
	Game.SetLenght(length);
	Game.SetNumber();
	while (!win)
	{
		Game.Guessing();
		win = Game.WinCheck();
	}
	cout << endl;
	cin >> win;
}
