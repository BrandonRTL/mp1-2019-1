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
	/*void DictPrint() // ����� ��� ������(!)
	{ 
		for (int i = 0; i < WordCount; i++)
		{
			std::cout << EngWord[i] << "-" << RusWord[i] << endl;
		}
	}*/
	void AddWord(string A, string B) //����������  �����(1)
	{
		EngWord.push_back(A);
		RusWord.push_back(B);
		WordCount++;
	}
	void ChangeTranslation(string A, string B) //��������� ��������(2)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				RusWord[i] = B;
		}
	}
	string GetTranslation(string A) // ��������� ��������(3)
	{
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				return RusWord[i];
		}
		return 0;
	}
	bool TranslationCheck(string A) //�������� ������� ��������(4)
	{
		bool TransCheck = 0;
		for (int i = 0; i < WordCount; i++)
		{
			if (A == EngWord[i])
				TransCheck = 1;
		}
		return TransCheck;
	}
	int GetWordCount() //������, ������� ���� �  �������(5)
	{
		return WordCount;
	}
	void SaveFile(string FileName) //��������, ���������� ����� �� �����, �� ��� ��� �� ������ �����, ������� ����� ����� txt. ������ � ����(6)
	{
		ofstream File;
		File.open(FileName + ".txt");
		for (int i = 0; i < WordCount; i++)
		{
			File << EngWord[i] << " " << RusWord[i] << endl;
		}
		File.close();
	}
	TransDict ReadFile(string FileName) //������ �� ����� (7)
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
	A.AddWord("Cat", "�����");
//	A.DictPrint();
	A.ChangeTranslation("Cat", "���");
	A.AddWord("Rat", "������");
	A.AddWord("Valentina", "��������");
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