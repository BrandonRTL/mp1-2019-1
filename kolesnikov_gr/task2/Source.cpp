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
	DynamArr(int n)
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
		if (this != &Arr)
		{
			N = Arr.N;
			delete[] Array;
			Array = new double[N];
			for (int i = 0; i < N; i++)
				Array[i] = Arr.Array[i];
		}
		return *this;
	}
	DynamArr OddSubArray()
	{
		DynamArr C;
		C.N = N / 2 + 1;
		C.Array = new double[N / 2 + 1];
		int i;
		for (i = 0; i < N / 2; i++)
			C.Array[i] = Array[2 * i + 1];
		return C;
	}
	void SetN(int n)
	{
		delete[] Array;
		N = n;
		Array = new double[N];
	}
	int GetN(int n)
	{
		N = n;
	}
	void ArrayInByIndex(int n, double a)
	{
		Array[n] = a;
	}
	double GetArrayElement(int n)
	{
		return Array[n];
	}
	double FindingMin()
	{
		int a;
		int i = 0;
		double Min = Array[0];
		for (i = 0; i <N; i++)
		{
			if (Min>Array[i])
				Min = Array[i];
		}
		return Min;
	}
	bool AscendingSortedCheck()
	{
		int i;
		bool SortCheck = 0;;
		for (i = 0; i < N - 1; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				return SortCheck;
			}
		}
		if (i == N - 1)
		{
			SortCheck = 1;
			return SortCheck;
		}
	}
	int DescendingSortedCheck()
	{
		int i;
		bool SortCheck = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (Array[i] < Array[i + 1])
			{
				return SortCheck;
			}
		}
		if (i == N - 1)
		{
			SortCheck = 1;
			return SortCheck;
		}
	}
	~DynamArr()
	{
		delete[] Array;
	}
};
int main()
{
	using namespace std;
	int a, b, c, d, e, f;
	double N = 1, Minimum;
	DynamArr TheGood, TheSubArray;
	cout << "Number of elements";
	cin >> b;
	TheGood.SetN(b);
    cout << "Position of the element to set/change(count starts with zero)\n";
    cin >> c;
	TheGood.ArrayInByIndex(c, N);
	e = TheGood.AscendingSortedCheck();
	Minimum = TheGood.FindingMin();
	cout << Minimum;
	cout << "SUB ARRAY: ";
	TheSubArray = TheGood.OddSubArray();
	cin >> a;
	return 0;
}