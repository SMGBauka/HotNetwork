#include "Creators.h"

void Social_Network::printList(Account& list)
{
		cout << "Username:" << list.username << endl;
		cout << "Password:" << list.password << endl;
		cout << "Name:" << list.Info.name << endl;
		cout << "Surname:" << list.Info.surname << endl;
		cout << "Age:" << list.Info.age << endl;
		cout << "TellNumber:" << list.Info.tellNumber << endl;
}

void Social_Network::push_account(Account& obj)
{
	accounts.push_back(obj);
	accounts.at(accounts.size() - 1).index = accounts.size() - 1;
	return;
}

bool Social_Network::isValidUsername(const string& obj)
{
	if (obj.empty())
		return false;

	for (int i = 0; i < accounts.size(); i++)
		if (accounts.at(i).username == obj)
			return false;

	for (char c : obj)
		if (excp.find(c) != string::npos)
			return false;

	return true;
}

bool Social_Network::isValidAge(const string& _age)
{
	if (_age.empty())
		return false;

	for (char c : _age)
		if (!isdigit(c))
			return false;

	if (_age[0] == '0')
		return false;

	int age = atoi(_age.c_str());

	if (age > 120)
		return false;

	if (age < 11)
		return false;

	return true;
}

bool Social_Network::isValidPassword(const string& obj)
{
	if (obj.empty())
		return false;

	if (obj.size() < 8)
		return false;

	if (obj.size() > 30)
		return false;

	for (char c : obj)
		if (excp.find(c) != string::npos)
			return false;

	return true;
}

bool Social_Network::isvalidWord(const string& obj)
{
	if (obj.empty())
		return false;

	for (char c : obj)
		if (excp.find(c) != string::npos)
			return false;

	return true;
}

bool Social_Network::vFriend(int& _index)
{
	if (accounts.at(_index).friends.size() != 0)
		return true;

	return false;
}


bool Social_Network::isValidPhoneNumber(const string& phoneNumber)
{
	if (phoneNumber.size() != 11 || phoneNumber[0] != '8' || (phoneNumber[0] != '+' && phoneNumber[1] != '7'))
		return false;

	for (char c : phoneNumber)
		if (!std::isdigit(c))
			return false;

	return true;
}
