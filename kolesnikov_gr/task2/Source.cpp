#include  <iostream>
class DynamArr
{
	int N;
	double *Array;
public:
	DynamArr()
	{
		N = 13;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = 13;
	}
	DynamArr (const int n)
	{
		N = n;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = 13;
	}
	DynamArr(const DynamArr &Arr)
	{
		N = Arr.N;
		Array = new double[N];
		for (int i = 0; i < N; i++)
			Array[i] = Arr.Array[i];
	}
	DynamArr& operator=(const DynamArr &Arr)
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
	void ArrayInByIndex(int n)
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
	void FindingMin()
	{
		int a;
		int i = 0;
		double Min = Array[0];
		for (i = 0; i <N; i++)
			{
				if (Min>Array[i])
				Min = Array[i];
			}
		std::cout << "And the minimum is " << Min << std::endl;

	}
	void AscendingSortedCheck()
	{
		int i;
		for (i = 0; i < N - 1; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				std::cout << "Array is not sorted" <<std::endl;
				return;
			} 
		}
		if (i == N - 1)
		{
			std::cout << "Array is sorted" << std::endl;
			return;
		}
	}
	void DescendingSortedCheck()
	{
		int i;
		for (i = 0; i < N - 1; i++)
		{
			if (Array[i] < Array[i + 1])
			{
				std::cout << "Array is not sorted" << std::endl;
				return;
			}
		}
		if (i == N - 1)
		{
			std::cout << "Array is sorted";
			return;
		}
	}
	void OddSubArray()
	{
		double *SubAr;
		SubAr = new double[N / 2 + 1];
		int i;
		for (i = 0; i < N/2;i++)
			SubAr[i] = Array[2*i + 1];
		for (i = 0; i < N/2; i++)
			std::cout << SubAr[i] << " ";
		delete[] SubAr;
	}
	~DynamArr()
	{
		delete[] Array;
	}
};
int main()
{
	using namespace std;
	int a,b,c,d,e,f;
	DynamArr TheGood;
	cout << "Number of elements";
	cin >> b;
	TheGood.SetN(b); 
	TheGood.FullArrayIn();
	cout << "Position of the element to set/change(count starts with zero)\n";
	cin >> c;
	TheGood.ArrayInByIndex(c);
	TheGood.AscendingSortedCheck();
	TheGood.FindingMin();
	cout << "SUB ARRAY: ";
	TheGood.OddSubArray();
	cin >> a;
	return 0;
}