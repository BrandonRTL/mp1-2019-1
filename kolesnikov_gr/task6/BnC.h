#include <iostream> 
#include <string> 
#include <clocale> 
#include <fstream> 
#include <vector> 
#include <fstream>
#include <time.h>
#include <NonRepeatingDigits.h>
using namespace std;
class BnC
{
	int cows;
	int bools;
	int length;
	vector<int>Digits;
public:
	static int count;
	void Guessing();
	void SetLenght(int _length);
	void SetNumber();
	bool WinCheck();
};