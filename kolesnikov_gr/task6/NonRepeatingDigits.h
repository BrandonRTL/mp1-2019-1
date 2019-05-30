#pragma once
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