#include "Creators.h"

void Accounter::CreateAccount()
{
	Account newAccount;
	int choice;
	string* iset[]{ &newAccount.username,  &newAccount.password,  &newAccount.Info.name,  &newAccount.Info.surname,  &newAccount.Info.age,  &newAccount.Info.tellNumber };
	for (int i = 0; i < 6; i++)
	{
		
		printList(newAccount);
		if (iset[i]->empty())
		{
			cout << "\n\tSet:";
			if (i == 1)
			{
				getline(cin, *iset[i]);
				//cin >> *iset[i];
				while (!isValidPassword(*iset[i]))
				{
					cout << "\n\tError! Incorrected input or password was be less than 8 words\n\tSet:";
					getline(cin, *iset[i]);

				}

				cls;
				continue;
			
			}
			else if(i == 0)
			{
				getline(cin, *iset[i]);
				//cin >> *iset[i];
				while (!isValidUsername(*iset[i]))
				{
					cout << "\n\tError! This Username is taked or incorrected input\n\tPls Create anymore:";
					getline(cin, *iset[i]);

				}
				cls;
				continue;
			}
			
			else if (i == 5)
			{
				getline(cin, *iset[i]);
				//cin >> *iset[i];
				while (!isValidPhoneNumber(*iset[i]))
				{
					cout << "\tError! Incorrect number entry:";
					getline(cin, *iset[i]);

				}
				cls;
				continue;
			}
			else if(i == 4)
			{
				getline(cin, *iset[i]);
				//cin >> *iset[i];
				while(!isValidAge(*iset[i]))
				{
					cout << "\tError! Incorrected age:";
					getline(cin, *iset[i]);
				}
				cls;
				continue;
			}
			//cin >> *iset[i];
			getline(cin, *iset[i]);
			while (!isvalidWord(*iset[i])) 
			{
				cout << "\tError! Incorrected Input:";
				getline(cin, *iset[i]);
			}
		}
		cls;
	}
	again:
	printList(newAccount);
	cout << "\n1.Yes\n2.No\n";
	cout << "All Right?:";
	cin >> choice;
	if (choice == 1)
	{
		push_account(newAccount);
	}
	else if (choice == 2)
	{
		cls;
		Start();
	}
	else
	{
		cls;
		goto again;
	}
	cls;
}

void Accounter::Start()
{
	Menu(*this);
	Choice(*this);
}

void Accounter::FriendList()
{
	for (int frnd : accounts.at(AccountIndex).friends)
	{
		cout << accounts.at(accounts.at(frnd).index).username << ' '
			 << accounts.at(accounts.at(frnd).index).Info.surname << endl;
	}
}



void Accounter::GetAllIndex()
{
	if (accounts.empty())
		return;
	cout << "All Index:";
	for (Account i : accounts)
	{
		if (accounts.size() == 1)
			cout << i.index + 1;
		else
			cout << i.index + 1 << ',';
	}
	cout << endl;
}


bool Accounter::CheckUser(string& username, string& password)
{

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].username == username && accounts[i].password == password) 
		{
			AccountIndex = i;
			return true;
		}
	}
	return false;
}

void Accounter::ProfileMenu()
{
	cout << "Username:" << accounts.at(AccountIndex).username << endl;
	cout << "ID:" << "@" << AccountIndex + 1 << endl;
	cout << "Description:" << accounts.at(AccountIndex).descreption << endl << endl;
	cout << "Name:" << accounts.at(AccountIndex).Info.name << ' ' << accounts.at(AccountIndex).Info.surname << endl;
	cout << "Age:" << accounts.at(AccountIndex).Info.age << endl;
	cout << "TellNumber:" << accounts.at(AccountIndex).Info.tellNumber << endl;
	cout << "Friends:" << accounts.at(AccountIndex).friends.size() << endl;
	cout << "Post's:" << accounts.at(AccountIndex).posts.size() << endl;
	
	cout << setw(PostTab) << "Post's\n";
	if (!accounts.at(AccountIndex).posts.empty())
		for (string post : accounts.at(AccountIndex).posts)
		{
			cout << post << endl;
		}
	else
		cout << setw(PostTab - 1) << "NULL\n";
	cout << "\n\n1.Edit Profile\n";
	cout << "2.Friend's\n";
	cout << "3.Post's\n";
	cout << "4.Back\n\n";
	cout << "Select:";
}

void EditMenu()
{
	cout << "1.Edit Username\n"
		<< "2.Edit Password\n"
		<< "3.Edit Description\n"
		<< "4.Edit Name\n"
		<< "5.Edit Surname\n"
		<< "6.Edit Age\n"
		<< "7.TellNumber\n"
		<< "8.Delete Account\n"
		<< "0.Back\n\n";

	cout << "Select:";
}

void Accounter::EditProfile()
{
	int choice;
	EditMenu();
	cin >> choice;
	switch (choice)
	{
	case 0:
		cls;
		ProfileMenu();
		break;

	case 1:
		cls;
		EditUsername();
		break;
	case 2:
		cls;
		EditPassword();
		break;
	case 3:
		cls;
		EditDiscreption();
		break;
	case 4:
		cls;
		EditName();
		break;
	case 5:
		cls;
		EditSurname();
		break;
	case 6:
		cls;
		EditAge();
		break;
	case 7:
		cls;
		EditTellNumber();
		break;
	case 8:
		cls;
		DeleteAccount();
		break;
	default:
		cls;
		cout << "Invalid Choice!\n";
		EditProfile();
		break;
	}
	cls;
	MProfile();
}

void Accounter::EditUsername()
{
	string NewUsername;
	cout << "Set New Username:";
	cin >> NewUsername;
	cout << "You'r New Username is \"" << NewUsername << "\"";
	accounts.at(AccountIndex).username = NewUsername;
	cls;
}

void Accounter::EditName()
{
	string NewName;
	cout << "Set New Name:";
	cin >> NewName;
	cout << "You'r New Name is \"" << NewName << "\"";
	accounts.at(AccountIndex).Info.name = NewName;
	cls;
}

void Accounter::EditPassword()
{
	string NewPassword;
	cout << "Set New Password:";
	cin >> NewPassword;
	cout << "You'r New Password is \"" << NewPassword << "\"";
	accounts.at(AccountIndex).password = NewPassword;
	cls;
}

void Accounter::EditSurname()
{
	string NewSurname;
	cout << "Set New Surname:";
	cin >> NewSurname;
	cout << "You'r New Surname is \"" << NewSurname << "\"";
	accounts.at(AccountIndex).Info.surname = NewSurname;
	cls;
}

void Accounter::EditAge()
{
	string NewAge;
	cout << "Set New Age:";
	cin >> NewAge;
	for (char i : NewAge)
		if (!isdigit(i)) 
		{
			cls;
			cout << "Invalid Age!";
			EditAge();
		}
	cout << "You'r New Age is \"" << NewAge << "\"";
	accounts.at(AccountIndex).Info.age = NewAge;
	cls;
}

void Accounter::EditDiscreption()
{
	string NewDescription;
	cin.ignore();
	cout << "Set New Description:";
	getline(cin, NewDescription);
	cout << "\nDescription has been set!";
	accounts.at(AccountIndex).descreption = NewDescription;
	cls;
}

void Accounter::EditTellNumber()
{
	string NewTellNumber;
	cout << "Set New TellNumber:";
	getline(cin, NewTellNumber);
	if(!isValidPhoneNumber(NewTellNumber))
	{
		cls;
		cout << "Invalid TellNumber!\n";
		EditTellNumber();
	}
	cout << "You'r New TellNumber is \"" << NewTellNumber << "\"";
	accounts.at(AccountIndex).Info.tellNumber = NewTellNumber;
	cls;
}

void Accounter::DeleteAccount()
{
	int choice;
	cout << "You't sure?\n 1.Yes \n 2.No\n\nSelect:";
	cin >> choice;
	if (choice == 1)
	{
		cls;
		accounts.erase(accounts.cbegin() + AccountIndex);
		Start();
	}
	else if (choice == 2)
		EditProfile();
	else
	{
		cls;
		DeleteAccount();
	}
}
void Accounter::MPost()
{
	cls;
	MProfile();
}

void Accounter::MProfile()
{
	int choice;
	ProfileMenu();
	cin >> choice;
	switch(choice)
	{
	case 1:
		cls;
		EditProfile();
			break;		
	case 2:
		cls;
		MFriend();
			break;		
	case 3:
		cls;
		MPost();
			break;
	case 4:
		cls;
		LoginMain(*this);
		break;
	default:
		cls;
		MProfile();
		break;
	}
}

/// <Empty Void's>
/// Create Him New Func
/// </Empty Void's>

void SettingMenu()
{
	cout<< "1.Policy\n"
		<< "2.Account Setting\n"
		<< "3.Style\n"
		<< "4.About Creator\n"
		<< "5.Logout\n\n";

	cout << "Select:";
}

void Accounter::Logout()
{
	int choice;
	cout << "You'r Sure?\n"
		<< "\t1.Yes\n"
		<< "\t2.No\n\n";
	cout << "Select:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cls;
		AccountIndex = Empty;
		Start();
		break;
	case 2:
		cls;
		MSettings();
		break;
	default:
		cls;
		cout << "Invalit Select!\n";
		Logout();
		break;
	}

}

void Accounter::MSettings()
{
	short int choice;
	SettingMenu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		cls;
		MSettings();
		break;
	
	case 2:
		cls;
		MSettings();
		break;
	
	case 3:
		cls;
		MSetStyle();
		break;
	
	case 4:
		cls;
		MSettings();
		break;
	
	case 5:
		cls;
		Logout();
		break;
	
	
	default:
		cls;
		cout << "Invalid Select!\n";
		MSettings();
		break;
	}
	cls;
	LoginMain(*this);
}

void Accounter::MSetStyle()
{
	int choice;
	cout << "1.Black\n"
		<< "2.Blue\n"
		<< "3.Green\n"
		<< "4.Red\n"
		<< "5.Yellow\n"
		<< "6.Default\n\n";

	cout << "Select:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		SystemColor(color::black);
		cls;
		MSettings();
		break;
	
	case 2:
		SystemColor(color::blue);
		cls;
		MSettings();
		break;
	
	case 3:
		SystemColor(color::green);
		cls;
		MSettings();
		break;
	
	case 4:
		SystemColor(color::red);
		cls;
		MSettings();
		break;
	
	case 5:
		SystemColor(color::yellow); 
		cls;
		MSettings();
		break;
	
	case 6:
		SystemColor(color::def);
		cls;
		MSettings();
		break;
	
	
	default:
		cls;
		MSetStyle();
		break;
	}
}

void Accounter::MMessage()
{
	if (vFriend(AccountIndex))
		FriendList();
	else
		cout << "You haven't frined's" << endl;
	

	cls;
	LoginMain(*this);
}

void Accounter::MSearch()
{
	cls;
	LoginMain(*this);
}

void Accounter::MFriend()
{
	cls;
	MProfile();
}


void Accounter::CreatePost()
{
}

void Accounter::LogIn()
{
	string username, password;
	cout << "Username:";
	cin >> username;
	cout << "Password:";
	cin >> password;
	if (CheckUser(username, password))
	{
		cls;
		LoginMain(*this);
	}
	else
	{
		cout << "Incorrected input!";
		millis(500);
	}
	cls;
}

int Accounter::GetAccountSize()
{
	if (accounts.empty())
		return 0;
	return accounts.size();
}

