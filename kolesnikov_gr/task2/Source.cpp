#include  <iostream>
class DympMass
{
	int N;
	double *Array;
public:
	DympMass(int n=13)
	{
		N = n;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = 13;
	}
	DympMass(const DympMass &Arr)
	{
		N = Arr.N;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = Arr.Array[i];
	}
	DympMass& operator=(const DympMass &Arr)
	{
		N = Arr.N;
		delete[] Array;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = Arr.Array[i];
		return *this;
	}
	void SetN(int n)
	{
		delete[] Array;
		N = n;
	}
	int GetN (int n)
	{
		N = n;
	}
	void FullArrayIn()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << "Enter the "<< i <<"st/nd/rd/th element"<< std::endl;
			std::cin >> Array[i];
		}
	}
	void ArrayInByNumber(int n)
	{
		double a;
		std::cout << "Enter the " << n << "st/nd/rd/th element" << std::endl;
		std::cin >> a;
		Array[n] = a;
	}
	double GetArrayElement(int n)
	{
		return Array[n];
	}
	void FindingMinMax()
	{
		int a;
		double MinMax;
		std::cout << "1 to find minimum\n2 to find maximum\n";
		std::cin >> a;
		switch (a)
		{
			case 1:
			{
				MinMax = Array[0];
				for (int i = 0; i < N; i++)
				{
					if (Array[i] <= MinMax)
						MinMax = Array[i];
				}
				std::cout << "The minimum is " << MinMax << "\n";
				break;
			}
			case 2:
			{
				MinMax = Array[0];
				for (int i = 0; i < N; i++)
				{
					if (Array[i] >= MinMax)
						MinMax = Array[i];
				}
				std::cout << "The maximum is " << MinMax << "\n";
				break;
			}
		}
	}
	void SortedCheck()
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				std::cout << "Array is not sorted" <<std::endl;
				return;
			}
		}
		std::cout << "Array is  sorted" << std::endl;
		for (int i = 0; i < N - 1; i++)
		{
			if (Array[i] < Array[i + 1])
			{
				std::cout << "Array is not sorted" << std::endl;
				return;
			}
		}
		std::cout << "Array is sorted" << std::endl;
	}
	void SubMassive()
	{

	}
};
int main()
{
	using namespace std;
	int a,b,c,d,e,f;
	DympMass TheGood;
	DympMass TheBad;
	DympMass TheUnsorted;
	cin >> b;
	TheGood.SetN(b); 
	TheGood.FullArrayIn();
	cout << "Position to change element\n";
	cin >> c;
	TheGood.ArrayInByNumber(c);
	TheGood.FindingMinMax();
	TheGood.SortedCheck();
	cin >> a;
	return 0;
}