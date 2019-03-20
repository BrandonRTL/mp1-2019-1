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
		WordCount = 0;
	}
	/*void DictPrint() // Ìåòîä äëÿ òåñòîâ(!)
	{
	for (int i = 0; i < WordCount; i++)
	{
	std::cout << EngWord[i] << "-" << RusWord[i] << endl;
	}
	}*/
	void AddWord(string _EngWord, string _RusWord) //Äîáàâëåíèå  ñëîâà(1)
	{
		EngWord.push_back(_EngWord);
		RusWord.push_back(_RusWord);
		WordCount++;
	}
	void ChangeTranslation(string _EngWord, string _RusWord) //Èçìåíåíèå ïåðåâîäà(2)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (_EngWord == EngWord[i])
				RusWord[i] = _RusWord;
		}
	}
	string GetTranslation(string A) // Óçíàâàíèå ïåðåâîäà(3)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				return RusWord[i];
		}
		return "";
	}
	bool TranslationCheck(string A) //Ïðîâåðêà íàëè÷èÿ ïåðåâîäà(4)
	{
		bool TransCheck = false;
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				TransCheck = true;
		}
		return TransCheck;
	}
	int GetWordCount() //Óçíàòü, ñêîëüêî ñëîâ â  ñëîâàðå(5)
	{
		return WordCount;
	}
	void SaveFile(string FileName) //Íàâåðíîå, ðàñøèðåíèå ôàéëà íå íóæíî, íî òóò êàê áû òîíêàÿ ãðàíü, ïîýòîìó ïóñòü áóäåò txt. Çàïèñü â ôàéë(6)
	{
		ofstream File;
		File.open(FileName + ".txt");
		for (int i = 0; i < WordCount; i++)
		{
			File << EngWord[i] << " " << RusWord[i] << endl;
		}
		File.close();
	}
	TransDict ReadFile(string FileName) //×òåíèå èç ôàéëà(7)
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
	//	A.DictPrint();
	string FileName = "Dictionary1";
	count = A.GetWordCount();
	cout << count << endl;
	A.AddWord("Cat", "Êîøêà");
	//	A.DictPrint();
	A.ChangeTranslation("Cat", "Êîò");
	A.AddWord("Rat", "Êðûñêà");
	A.AddWord("Valentina", "Ïèñàíèíà");
	A.SaveFile(FileName);
	//	A.DictPrint();
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