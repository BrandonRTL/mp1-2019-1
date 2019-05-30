#include <BnC.h>
void BnC::Guessing()
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
void  BnC::SetLenght(int _length)
{
	length = _length;
}
void  BnC::SetNumber()
{
	vector<int>_Digits = NonRepeatingDigits::Generate(length);
	Digits = _Digits;
}
bool  BnC::WinCheck()
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