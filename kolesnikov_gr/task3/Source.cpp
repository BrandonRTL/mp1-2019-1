#include  <iostream>
#include <string>  
#include <clocale> 
using namespace std;
class TransDict
{
std::string RusWord[100];
std::string EngWord[100];
int WordCount = 0;
public:
	TransDict()
	{
		EngWord[0] = "No";
		EngWord[1] = "Words";
		EngWord[2] = "Here";
		RusWord[0] = "Нет";
		RusWord[1] = "Слова";
		RusWord[2] = "Здесь";
		WordCount = 3;
	}
	void DictPrint()
	{
		for (int i = 0; i < WordCount; i++)
		{
			std::cout << EngWord[i] << "-" << RusWord[i] << endl;
		}
	}
	void WordAdd(string A, string B)
	{
		EngWord[WordCount] =  A;
		RusWord[WordCount] =  B;
		WordCount++;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	TransDict A;
	A.DictPrint();
	int a;
	cin >> a;
	return 0;
}