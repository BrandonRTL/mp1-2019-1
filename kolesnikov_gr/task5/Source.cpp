#include <iostream> 
#include <string> 
#include <clocale> 
#include <fstream> 
#include <vector> 
#include <fstream>
using namespace std;
class ProcessingCtr
{
	vector<int> Nmb;
	vector<string> Name;
	vector<long int> PayRollAmount;
	vector<long int> DepositAmount;
	vector<long int> IncreasedAmount;
	vector<string> Password;
	vector<bool> HasDeposit;
public:
	ProcessingCtr()
	{
		Nmb.push_back(0);
		Name.push_back("Johnny Rico");
		PayRollAmount.push_back(100000);
		DepositAmount.push_back(0);
		IncreasedAmount.push_back(0);
		Password.push_back("123");
		HasDeposit.push_back(false);
		Nmb.push_back(1);
		Name.push_back("Andrew Wiggin");
		PayRollAmount.push_back(6000000);
		DepositAmount.push_back(0);
		IncreasedAmount.push_back(0);
		Password.push_back("123");
		HasDeposit.push_back(false);
	}
	void Registration(int _nmb, string _name, long int _pay, string _password)
	{
		for (int i = 0; i < Nmb.size(); i++)
		{
			if (_nmb == Nmb[i])
			{
				cout << "Already registered";
				//return;
			}
		}
		if (_password.length() < 3)
			throw 123;
		Nmb.push_back(_nmb);
		Name.push_back(_name);
		PayRollAmount.push_back(_pay);
		DepositAmount.push_back(0);
		IncreasedAmount.push_back(0);
		Password.push_back(_password);
		HasDeposit.push_back(false);


	}
	int GetSize()
	{
		return Name.size();
	}
	int GetPay(int i)
	{
		return PayRollAmount[i];
	}
	int GetDeposit(int i)
	{
		return DepositAmount[i];
	}
	int GetPercent(int i)
	{
		return IncreasedAmount[i];
	}
	bool GetOpenCheck(int i)
	{
		return HasDeposit[i];
	}
	string GetPassword(int i)
	{
		return Password[i];
	}
	string GetName(int i)
	{
		return Name[i];
	}
	void SetPassWord(int i, string _password)
	{
		if (_password.length() < 3)
			throw 123;
		Password[i] = _password;
	}
	void SetPay(int i, int _pay)
	{
		PayRollAmount[i] = _pay;
	}
	void SetDeposit(int i, int _deposit)
	{
		DepositAmount[i] = _deposit;
	}
	void SetPercent(int i, int _percent)
	{
		IncreasedAmount[i] = _percent;
	}
	void SetDepositOpen(int i, bool truth)
	{
		HasDeposit[i] = truth;
	}
};
class Deposit
{
	ProcessingCtr PC;
	bool IsLoggedIn;
	double Percent100K[5] = { 1.2, 1.4, 1.7, 2.1 , 2.2 };
	double Percent100_500K[5] = { 1.8, 2.3,2.5, 2.7 , 3.0 };
	double Percent500_1000K[5] = { 2.9, 3.1, 3.4,3.7 , 3.8 };
	double Percent1KK[5] = { 4.1, 4.5, 4.9,5.1 ,5.5 };
	double CurrentPercent;
	int CurrentAccount;
	int DepositOpenTime;
public:
	Deposit(ProcessingCtr Centr)
	{
		PC = Centr;
	}
	void Log_In(int _Number, string _password) //1)
	{
		if (_password == PC.GetPassword(_Number))
		{
			IsLoggedIn = true;
			CurrentAccount = _Number;
			cout << "Hello, mr(s) " << PC.GetName(CurrentAccount) << endl;
		}
		else
		{
			cout << "Wrong password" << endl;
		}
	}
	void Show_AvailableDeposits() //2)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (IsLoggedIn == true)
		{
			cout << "Now you have " << PC.GetPay(CurrentAccount) << endl;
			cout << "Avaliable deposits for you:" << endl;
			cout << "Time:        " << "Percent:" << endl;
			if (PC.GetPay(CurrentAccount) < 100000)
				cout << "3 months     " << Percent100K[0] << "%" << endl << "6 months     " << Percent100K[1] << "%" << endl << "12 months    "
				<< Percent100K[2] << "%" << endl << "24 months    " << Percent100K[3] << "%" << endl
				<< "36 months    " << Percent100K[4] << "%";
			else if (PC.GetPay(CurrentAccount) < 500000)
				cout << "3 months     " << Percent100_500K[0] << "%" << endl << "6 months     " << Percent100_500K[1] << "%" << endl << "12 months    "
				<< Percent100_500K[2] << "%" << endl << "24 months    " << Percent100_500K[3] << "%" << endl
				<< "36 months    " << Percent100_500K[4] << "%";
			else if (PC.GetPay(CurrentAccount) < 1000000)
				cout << "3 months     " << Percent500_1000K[0] << "%" << endl << "6 months     " << Percent500_1000K[1] << "%" << endl << "12 months    "
				<< Percent500_1000K[2] << "%" << endl << "24 months    " << Percent500_1000K[3] << "%" << endl
				<< "36 months    " << Percent500_1000K[4] << "%";
			else
				cout << "3 months     " << Percent1KK[0] << "%" << endl << "6 months     " << Percent1KK[1] << "%" << endl << "12 months    "
				<< Percent1KK[2] << "%" << endl << "24 months    " << Percent1KK[3] << "%" << endl
				<< "36 months    " << Percent1KK[4] << "%";
		}
	}
	bool DepositOpenCheck() //3)
	{
		if (IsLoggedIn == true)
		{
			return PC.GetOpenCheck(CurrentAccount);
		}
		//	else throw 123;
	}
	void OpenDeposit(int time, int money)//4)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == true)
			throw 321;
		if ((money < 0) || (money > PC.GetPay(CurrentAccount)))
			throw 213;
		if (time == 3)
		{
			if (PC.GetPay(CurrentAccount) < 100000)
				CurrentPercent = Percent100K[0];
			else if (PC.GetPay(CurrentAccount) < 500000)
				CurrentPercent = Percent100_500K[0];
			else if (PC.GetPay(CurrentAccount) < 1000000)
				CurrentPercent = Percent500_1000K[0];
			else
				CurrentPercent = Percent1KK[0];
		}
		if (time == 6)
		{
			if (PC.GetPay(CurrentAccount) < 100000)
				CurrentPercent = Percent100K[1];
			else if (PC.GetPay(CurrentAccount) < 500000)
				CurrentPercent = Percent100_500K[1];
			else if (PC.GetPay(CurrentAccount) < 1000000)
				CurrentPercent = Percent500_1000K[1];
			else
				CurrentPercent = Percent1KK[1];
		}
		if (time == 12)
		{
			if (PC.GetPay(CurrentAccount) < 100000)
				CurrentPercent = Percent100K[2];
			else if (PC.GetPay(CurrentAccount) < 500000)
				CurrentPercent = Percent100_500K[2];
			else if (PC.GetPay(CurrentAccount) < 1000000)
				CurrentPercent = Percent500_1000K[2];
			else
				CurrentPercent = Percent1KK[2];
		}
		if (time == 24)
		{
			if (PC.GetPay(CurrentAccount) < 100000)
				CurrentPercent = Percent100K[3];
			else if (PC.GetPay(CurrentAccount) < 500000)
				CurrentPercent = Percent100_500K[3];
			else if (PC.GetPay(CurrentAccount) < 1000000)
				CurrentPercent = Percent500_1000K[3];
			else
				CurrentPercent = Percent1KK[3];
		}
		if (time == 36)
		{
			if (PC.GetPay(CurrentAccount) < 100000)
				CurrentPercent = Percent100K[4];
			else if (PC.GetPay(CurrentAccount) < 500000)
				CurrentPercent = Percent100_500K[4];
			else if (PC.GetPay(CurrentAccount) < 1000000)
				CurrentPercent = Percent500_1000K[4];
			else
				CurrentPercent = Percent1KK[4];
		}
		DepositOpenTime = time;
		PC.SetPay(CurrentAccount, PC.GetPay(CurrentAccount) - money);
		PC.SetDeposit(CurrentAccount, money);
		PC.SetDepositOpen(CurrentAccount, true);
	}
	int DepositStatus()  //5)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == false)
			throw 321;
		return PC.GetDeposit(CurrentAccount);
	}
	void WithDraw()//6)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == false)
			throw 321;
		PC.SetPay(CurrentAccount, PC.GetPercent(CurrentAccount) + PC.GetPay(CurrentAccount));
		PC.SetPercent(CurrentAccount, 0);
	}
	void DepositClose(int CurrentTime)//7)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == false)
			throw 321;
		if (CurrentTime < DepositOpenTime)
			throw 4321;
		PC.SetPay(CurrentAccount, PC.GetPercent(CurrentAccount) + PC.GetPay(CurrentAccount) + PC.GetDeposit(CurrentAccount));
		PC.SetDeposit(CurrentAccount, 0);
		PC.SetPercent(CurrentAccount, 0);
		PC.SetDepositOpen(CurrentAccount, false);
	}
	void TimeMachine(int months)
	{
		PC.SetPercent(CurrentAccount, PC.GetPercent(CurrentAccount) + months / 12 * CurrentPercent);
	}
};
int main()
{
	ProcessingCtr ABC;
	Deposit BAC(ABC);
	BAC.Log_In(1, "123");
	BAC.Show_AvailableDeposits();
	bool av = BAC.DepositOpenCheck();
	cout << endl << av;
	BAC.OpenDeposit(6, 1000);
	av = BAC.DepositOpenCheck();
	cout << endl << av;
	int q, w, e, r, t, y;
	e = BAC.DepositStatus();
	BAC.DepositClose(13);
	cout << endl << e;
	double a, b;
	cin >> a;
	return 0;
}