#pragma once
#include "ProcessingCtr.h"
class Deposit
{
	static ProcessingCtr &PC;
	bool IsLoggedIn;
	double Percent100K[5] = { 1.2, 1.4, 1.7, 2.1 , 2.2 };
	double Percent100_500K[5] = { 1.8, 2.3,2.5, 2.7 , 3.0 };
	double Percent500_1000K[5] = { 2.9, 3.1, 3.4,3.7 , 3.8 };
	double Percent1KK[5] = { 4.1, 4.5, 4.9,5.1 ,5.5 };
	double CurrentPercent;
	int CurrentAccount;
	int DepositOpenTime;
public:
	static void ConnectPrCtr(ProcessingCtr _PC)
	{
		Deposit::PC = _PC;
	}
	void Log_In(int _Number, string _password);
	void Show_AvailableDeposits();
	bool DepositOpenCheck();
	void OpenDeposit(int time, int money);
	int DepositStatus();
	void WithDraw();
	void DepositClose(int CurrentTime);
	void TimeMachine(int months);
};

