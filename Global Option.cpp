#include "Creators.h"

void Menu(Accounter& obj)
{
	cout << "1.Create Account\n";
	if (obj.GetAccountSize() != 0)
	{
		cout << "2.Login\n";
	}
	cout << "0.Exit\n\n";
	cout << "Select:";
}
void Choice(Accounter & obj)
{
	string choice;
	cin >> choice;
	
	for (char c : choice)
		if (!isdigit(c))
		{
			cin.clear();
			cin.ignore(numeric_limits<size_t>::max(), '\n');
			cout << "Error! Incorrected input";
			millis(500);
			cls;
			obj.Start();
		}
		
	switch (atoi(choice.c_str()))
	{
	case 1:
		cls;
		cin.ignore();
		obj.CreateAccount();
		break;
	case 2:
		if (obj.GetAccountSize() == 0)
		{
			cls;
			cin.clear();
			cin.ignore(numeric_limits<size_t>::max(), '\n');
			obj.Start();
		}
		cls;
		cin.ignore();
		obj.LogIn();
		break;
	case 0:
		exit(0);
		break;
	default:
		cin.clear();
		cin.ignore(numeric_limits<size_t>::max(), '\n');
		cout << "Error! Incorrected input";
		millis(500);
		cls;
		obj.Start();
		break;
	}
}



void LoginMenu()
{
	cout << "1.Profile\n"
		<< "2.Search\n"
		<< "3.Message\n"
		<< "4.Settings\n"
		<< "5.Get All Index\n\n"
		<< "Select:";
}

void LoginMain(Accounter& account)
{
	int choice;
	LoginMenu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		cls;
		account.MProfile();
		break;
	case 2:
		cls;
		account.MSearch();
		break;
	case 3:
		cls;
		account.MMessage();
		break;
	case 4:
		cls;
		account.MSettings();
		break;
	case 5:
		cls;
		account.GetAllIndex();
		LoginMain(account);
		break;
	default:
		cls;
		LoginMain(account);
		break;
	}
	cls;
}

void SystemColor(color x)
{
	switch (x)
	{
	case red:
		system("color E4");
		break;
	case blue:
		system("color E1");
		break;
	case green:
		system("color E2");
		break;
	case black:
		system("color B0");
		break;
	case yellow:
		system("color 2E");
		break;
	default:
		system("color F");
		break;
	}
}