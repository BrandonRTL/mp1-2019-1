#include <iostream> 
#include <string> 
#include <clocale> 
#include <fstream> 
#include <vector> 
#include <fstream>
using namespace std;
class Thermometr
{
	vector<int> Year;
	vector<int> Month;
	vector<int> Day;
	vector<int> Hour;
	vector<double> Temperature;
	int InitialYear;
	int InitialMonth;
	int InitialDay;
	int InitialHour;
public:
	Thermometr(int _year = 2012, int _month = 11, int _day = 21, int _hour = 13)
	{
		InitialYear = _year;
		InitialMonth = _month;
		InitialDay = _day;
		InitialHour = _hour;
	}
	void SetInitialDate(int _year, int _month, int _day, int _hour); // 1)
	void GetInitialDate(int &_Year, int &_Month, int &_Day, int &_Hour); //2)
	bool SetObservation(int _year, int _month, int _day, int _hour, double _temperature); //3)
	double GetTemperature(int _year, int _month, int _day, int _hour); //4) 
	void SerialObservation(int _year, int _month, int _day, double TempArr[]); // 5)
	double DailyAverageTemp(int _year, int _month, int _day); //6.1)
	double MouthlyAverageTemp(int _year, int _month); //6.2)
	double AllTimeAverageTemp(); //6.3)
	double AverageDay≈imeTemp(int _year, int _month); //7.1)
	double AverageNight≈imeTemp(int _year, int _month); //7.2)
	void SaveFile(string FileName);
	Thermometr ReadFromFile(string FileName)
	{
		ifstream File;
		int i = 0;
		File.open(FileName + ".txt");
		Thermometr FromFile;
		int _year;
		int _month;
		int _day;
		int _hour;
		int _temperature;
		while (!File.eof())
		{
			File >> _year >> _month >> _day >> _hour >> _temperature;
			Year.push_back(_year);
			Month.push_back(_month);
			Day.push_back(_day);
			Hour.push_back(_hour);
			Temperature.push_back(_temperature);
			i++;
		}
		File.close();
		return FromFile;
	}
	void Print(); // 4 testing
	void  PrintSize(); // I SAID IT IS FOR TESTING !!!!!
};

void Thermometr::SetInitialDate(int _year, int _month, int _day, int _hour)
{
	InitialYear = _year;
	InitialMonth = _month;
	InitialDay = _day;
	InitialHour = _hour;
}
void Thermometr::GetInitialDate(int &_Year, int &_Month, int &_Day, int &_Hour)
{
	_Year = InitialYear;
	_Month = InitialMonth;
	_Day = InitialDay;
	_Hour = InitialHour;
}
bool Thermometr::SetObservation(int _year, int _month, int _day, int _hour, double _temperature)
{
	int i;
	for (i = 0; i < Temperature.size(); i++)
	{
		if ((_year == Year[i]) && (_month == Month[i]) && (_day == Day[i]) && (_hour == Hour[i]))
		{
			Temperature[i] = _temperature;
			return 1;
		}
	}
	Year.push_back(_year);
	Month.push_back(_month);
	Day.push_back(_day);
	Hour.push_back(_hour);
	Temperature.push_back(_temperature);
	return 0;
}
double Thermometr::GetTemperature(int _year, int _month, int _day, int _hour)
{

	for (int i = 0; i < Temperature.size(); i++)
	{
		if ((_year == Year[i]) && (_month == Month[i]) && (_day == Day[i]) && (_hour == Hour[i]))
		{
			return Temperature[i];
		}
	}
	return -1;
}
void Thermometr::SerialObservation(int _year, int _month, int _day, double TempArr[])
{
	for (int i = 0; i < 24; i++)
	{
		SetObservation(_year, _month, _day, i, TempArr[i]);
	}
}
double Thermometr::DailyAverageTemp(int _year, int _month, int _day)
{
	int count = 0;
	double Summ = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((_year == Year[i]) && (_month == Month[i]) && (_day == Day[i]))
		{
			count++;
			Summ += Temperature[i];
		}
	if (count == 0)
		return -123456789;
	Summ /= count;
	return Summ;
}
double Thermometr::MouthlyAverageTemp(int _year, int _month)
{
	int count = 0;
	double Summ = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((_year == Year[i]) && (_month == Month[i]))
		{
			count++;
			Summ += Temperature[i];
		}
	if (count == 0)
		return -123456789;
	Summ /= count;
	return Summ;
}
double Thermometr::AllTimeAverageTemp()
{
	int count = 0;
	double Summ = 0;
	for (int i = 0; i < Temperature.size(); i++)
	{
		count++;
		Summ += Temperature[i];
	}
	if (count == 0)
		return -123456789;
	Summ /= count;
	return Summ;
}
double Thermometr::AverageDay≈imeTemp(int _year, int _month)
{
	int count = 0;
	double Summ = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((_year == Year[i]) && (_month == Month[i]) && (Hour[i]<18) && (Hour[i]>6))
		{
			count++;
			Summ += Temperature[i];
		}
	if (count == 0)
		return -123456789;
	Summ /= count;
	return Summ;
}
double Thermometr::AverageNight≈imeTemp(int _year, int _month)
{
	int count = 0;
	double Summ = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((_year == Year[i]) && (_month == Month[i]) && (Hour[i]<18) && (Hour[i]<6))
		{
			count++;
			Summ += Temperature[i];
		}
	if (count == 0)
		return -123456789;
	Summ /= count;
	return Summ;
}
void Thermometr::Print()
{
	for (int i = 0; i < Temperature.size(); i++)
		cout << Year[i] << " " << Month[i] << " " << Day[i] << " " << Hour[i] << " " << Temperature[i] << "Degrees" << endl;
}
void Thermometr::PrintSize()
{
	cout << endl << Temperature.size() << " Obs count" << endl;
}
void Thermometr::SaveFile(string FileName)
{
	ofstream File;
	File.open(FileName + ".txt");
	for (int i = 0; i < Temperature.size(); i++)
	{
		File << Year[i] << " " << Month[i] << " " << Day[i] << " " << Hour[i] << " " << Temperature[i] << endl;
	}
	File.close();
}
void main()
{
	Thermometr Mayan_Calendar(2019, 03, 22, 1), FromFile;
	int q, w, e, r, t, y;
	double Temper[24] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17, 18, 19, 20, 21, 22, 23 };
	double a, b;
	Mayan_Calendar.GetInitialDate(q, w, e, r);
	cout << q << " " << w << " " << e << " " << r << endl;
	Mayan_Calendar.SetObservation(2000, 0, 0, 0, 13);
	//Mayan_Calendar.PrintSize();
	//	Mayan_Calendar.Print();
	Mayan_Calendar.SetObservation(2000, 0, 0, 1, 14);
	a = Mayan_Calendar.GetTemperature(2000, 0, 0, 0);
	cout << a << endl;
	//a = Mayan_Calendar.GetTemperature(2000, 0, 0, 1);
	//cout << a << endl;
	Mayan_Calendar.SetObservation(2000, 0, 0, 0, 16);
	Mayan_Calendar.SetObservation(2000, 0, 0, 0, 17);
	Mayan_Calendar.SerialObservation(2000, 0, 2, Temper);
	a = Mayan_Calendar.GetTemperature(2000, 0, 0, 1);
	//cout << a << endl;
	//	Mayan_Calendar.PrintSize();
	a = Mayan_Calendar.DailyAverageTemp(2000, 0, 2);
	//cout << a << endl;
	a = Mayan_Calendar.AllTimeAverageTemp();
	//cout << a;
	Mayan_Calendar.SaveFile("Test");
	FromFile.ReadFromFile("Test");
	FromFile.Print();
	//	Mayan_Calendar.Print();
	cin >> a;
}