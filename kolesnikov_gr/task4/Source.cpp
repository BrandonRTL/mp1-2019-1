#include  <iostream>
#include <string>  
#include <clocale> 
#include <fstream>
#include <vector>
using namespace std;
class Observation
{
	int Year;
	int Month;
	int Day;
	int Hour;
	double Temperature;
public:
	void SetDate(int _Year, int _Mount, int _Day, int _Hour)
	{

	}
	void GetDate(int *_Year, int *_Mount, int *_Day, int *_Hour)
	{

	}
	void SetTemp(double _Temperature)
	{

	}
	double GetTemp()
	{

	}
};
class ObsevrCalendar
{
	vector<Observation> ObsCalendar;
public:

};