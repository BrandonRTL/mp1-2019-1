#include "Deposit.h"
    Deposit::Deposit(ProcessingCtr Centr)
	{

	}
	void Deposit::Log_In(int _Number, string _password) //1)
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
	void Deposit::Show_AvailableDeposits() //2)
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
	bool Deposit::DepositOpenCheck() //3)
	{
		if (IsLoggedIn == true)
		{
			return PC.GetOpenCheck(CurrentAccount);
		}
		//	else throw 123;
	}
	void Deposit::OpenDeposit(int time, int money)//4)
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
	int Deposit::DepositStatus()  //5)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == false)
			throw 321;
		return PC.GetDeposit(CurrentAccount);
	}
	void Deposit::WithDraw()//6)
	{
		if (IsLoggedIn == false)
			throw 123;
		if (DepositOpenCheck() == false)
			throw 321;
		PC.SetPay(CurrentAccount, PC.GetPercent(CurrentAccount) + PC.GetPay(CurrentAccount));
		PC.SetPercent(CurrentAccount, 0);
	}
	void Deposit::DepositClose(int CurrentTime)//7)
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
	void Deposit::TimeMachine(int months)
	{
		PC.SetPercent(CurrentAccount, PC.GetPercent(CurrentAccount) + months / 12 * CurrentPercent*PC.GetDeposit(CurrentAccount));
	}
