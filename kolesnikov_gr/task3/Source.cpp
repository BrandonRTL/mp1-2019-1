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
	void TranslationChange(string A, string B)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				RusWord[i] = B;
		}
	}
	string GetTranslation(string A)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				return RusWord[i];
		}
		return 0;
	}
	bool TranslationCheck(string A)
	{
		bool TransCheck = 0;
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				TransCheck = 1;
		}
		return TransCheck;
	}
	int GetWordCount()
	{
		return WordCount;
	}
	void FileSave()
	{

	}
	TransDict FileRead()
	{

	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	TransDict A;
	int count;
	string b, c, d;
	bool Tr;
	A.DictPrint();
	count = A.GetWordCount();
	cout << count << endl;
	A.TranslationChange("Here", "Тут");
	A.WordAdd("Cat", "Кошка");
	A.DictPrint();
	b = A.GetTranslation("Here");
	cout << b << endl;;
	Tr = A.TranslationCheck("Here");
	cout << Tr << endl;
	count = A.GetWordCount();
	cout << count << endl;
	int a;
	cin >> a;
	return 0;
}