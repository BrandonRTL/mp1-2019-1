#include  <iostream>
#include <string>  
#include <clocale> 
#include <fstream>
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
	/*void DictPrint()
	{
	for (int i = 0; i < WordCount; i++)
	{
	std::cout << EngWord[i] << "-" << RusWord[i] << endl;
	}
	}*/
	void AddWord(string A, string B)
	{
		EngWord[WordCount] = A;
		RusWord[WordCount] = B;
		WordCount++;
	}
	void ChangeTranslation(string _EngWord, string _RusWord)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (_EngWord == EngWord[i])
				RusWord[i] = _RusWord;
		}
	}
	string GetTranslation(string A)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				return RusWord[i];
		}
		return "";
	}
	bool TranslationCheck(string A)
	{
		bool TransCheck = false;
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				TransCheck = true;
		}
		return TransCheck;
	}
	int GetWordCount()
	{
		return WordCount;
	}
	void SaveFile(string FileName) //Наверное, расширение файла не нужно, но тут как бы тонкая грань, поэтому пусть будет txt
	{
		ofstream File;
		File.open(FileName + ".txt");
		for (int i = 0; i < WordCount; i++)
		{
			File << EngWord[i] << " " << RusWord[i] << endl;
		}
		File.close();
	}
	TransDict ReadFile(string FileName)
	{
		ifstream File;
		int i = 0;
		File.open(FileName + ".txt");
		TransDict FromFile;
		while (!File.eof())
		{
			File >> FromFile.EngWord[i] >> FromFile.RusWord[i];
			i++;
		}
		FromFile.WordCount = i;
		cout << endl << i << endl;
		File.close();
		return FromFile;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	TransDict A, FromFile;
	int count;
	string b, c, d;
	bool Tr;
	//	A.DictPrint();
	string FileName = "Dictionary";
	count = A.GetWordCount();
	cout << count << endl;
	//A.SaveFile(FileName);
	A.ChangeTranslation("Here", "Тут");
	A.AddWord("Cat", "Кошка");
	//	A.DictPrint();
	b = A.GetTranslation("Here");
	cout << b << endl;;
	FileName = "Dictionary1";
	Tr = A.TranslationCheck("Here");
	cout << Tr << endl;
	count = A.GetWordCount();
	cout << count << endl;
	//  A.SaveFile(FileName);
	FromFile = A.ReadFile(FileName);
	Tr = FromFile.TranslationCheck("Beltalowda");
	b = FromFile.GetTranslation("Beltalowda");
	cout << b;
	cout << Tr;
	int a;
	cin >> a;
	return 0;
}