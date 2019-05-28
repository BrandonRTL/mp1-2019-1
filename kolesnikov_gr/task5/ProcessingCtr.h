#pragma once
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
	ProcessingCtr();
	void Registration(int _nmb, string _name, long int _pay, string _password);
	int GetSize();
	int GetPay(int i);
	int GetDeposit(int i);
	int GetPercent(int i);
	bool GetOpenCheck(int i);
	string GetPassword(int i);
	string GetName(int i);
	void SetPassWord(int i, string _password);
	void SetPay(int i, int _pay);
	void SetDeposit(int i, int _deposit);
	void SetPercent(int i, int _percent);
	void SetDepositOpen(int i, bool truth);
};