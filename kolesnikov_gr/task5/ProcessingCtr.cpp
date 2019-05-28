#include "ProcessingCtr.h"

ProcessingCtr::ProcessingCtr()
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
void ProcessingCtr::Registration(int _nmb, string _name, long int _pay, string _password)
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
int ProcessingCtr::GetSize()
{
	return Name.size();
}
int ProcessingCtr::GetPay(int i)
{
	return PayRollAmount[i];
}
int ProcessingCtr::GetDeposit(int i)
{
	return DepositAmount[i];
}
int ProcessingCtr::GetPercent(int i)
{
	return IncreasedAmount[i];
}
bool ProcessingCtr::GetOpenCheck(int i)
{
	return HasDeposit[i];
}
string ProcessingCtr::GetPassword(int i)
{
	return Password[i];
}
string ProcessingCtr::GetName(int i)
{
	return Name[i];
}
void ProcessingCtr::SetPassWord(int i, string _password)
{
	if (_password.length() < 3)
		throw 123;
	Password[i] = _password;
}
void ProcessingCtr::SetPay(int i, int _pay)
{
	PayRollAmount[i] = _pay;
}
void ProcessingCtr::SetDeposit(int i, int _deposit)
{
	DepositAmount[i] = _deposit;
}
void ProcessingCtr::SetPercent(int i, int _percent)
{
	IncreasedAmount[i] = _percent;
}
void ProcessingCtr::SetDepositOpen(int i, bool truth)
{
	HasDeposit[i] = truth;
}