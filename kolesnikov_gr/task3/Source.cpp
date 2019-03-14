#include  <iostream>
#include <string>  
#include <clocale> 
#include <fstream>
#include <vector>
using namespace std;
class TransDict
{
	vector<string> RusWord;
	vector<string> EngWord;
	int WordCount;
public:
	TransDict()
	{
		WordCount= 0;
	}
	/*void DictPrint() // Метод для тестов(!)
	{ 
		for (int i = 0; i < WordCount; i++)
		{
			std::cout << EngWord[i] << "-" << RusWord[i] << endl;
		}
	}*/
	void AddWord(string A, string B) //Добавление  слова(1)
	{
		EngWord.push_back(A);
		RusWord.push_back(B);
		WordCount++;
	}
	void ChangeTranslation(string A, string B) //Изменение перевода(2)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				RusWord[i] = B;
		}
	}
	string GetTranslation(string A) // Узнавание перевода(3)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				return RusWord[i];
		}
		return 0;
	}
	bool TranslationCheck(string A) //Проверка наличия перевода(4)
	{
		bool TransCheck = 0;
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				TransCheck = 1;
		}
		return TransCheck;
	}
	int GetWordCount() //Узнать, сколько слов в  словаре(5)
	{
		return WordCount;
	}
	void SaveFile(string FileName) //Наверное, расширение файла не нужно, но тут как бы тонкая грань, поэтому пусть будет txt. Запись в файл(6)
	{
		ofstream File;
		File.open(FileName + ".txt");
		for (int i = 0; i < WordCount; i++)
		{
			File << EngWord[i] << " " << RusWord[i] << endl;
		}
		File.close();
	}
	TransDict ReadFile(string FileName) //Чтение из файла (7)
	{
		ifstream File;
		int i = 0;
		File.open(FileName + ".txt");
		TransDict FromFile;
		string RusWords;
		string EngWords;
		while (!File.eof()) 
		{
				File >> EngWords >> RusWords;
				FromFile.EngWord.push_back(EngWords);
				FromFile.RusWord.push_back(RusWords);
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
	//A.DictPrint();
	string FileName = "Dictionary1";
	count = A.GetWordCount();
	cout << count << endl;
	A.AddWord("Cat", "Кошка");
//	A.DictPrint();
	A.ChangeTranslation("Cat", "Кот");
	A.AddWord("Rat", "Крыска");
	A.AddWord("Valentina", "Писанина");
	A.SaveFile(FileName);
	//A.DictPrint();
	b = A.GetTranslation("Cat");
	cout << b << endl;
	count = A.GetWordCount();
	cout << count << endl;
	FileName = "Dictionary12";
	Tr = A.TranslationCheck("Cat");
	cout << Tr << endl;
//	count = A.GetWordCount();
//	cout << count << endl;
	//  A.SaveFile(FileName);
    FromFile = A.ReadFile(FileName);
	Tr = FromFile.TranslationCheck("Beltalowda");
    b = FromFile.GetTranslation("Dog");
    cout << b;
	cout << Tr;
	cout << FromFile.GetWordCount() << endl;
	int a;
	cin >> a;
	return 0;
}