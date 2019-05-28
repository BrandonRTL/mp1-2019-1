#include <iostream> 
#include <string> 
#include <clocale> 
#include <fstream> 
#include <vector> 
#include <fstream>
#include "Deposit.h"
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
