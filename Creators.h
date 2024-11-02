#pragma once
#include "lib.h"

//---------------------------*
//		All Define's
//---------------------------*
#define millis(x)			this_thread::sleep_for(chrono::milliseconds(x))
#define DefaultDescription "Hello! It's my new created Account"
#define PostTab				60

enum color :int { red, blue, green, black, yellow, def = -1 };

//---------------------------*
//		Constexpr
//---------------------------*

constexpr int MaxDescriptionSize = 60; // <------- Max Description Size
constexpr int Empty = -1;			   // <------- If Account Deleted

class Social_Network
{
protected:
	string excp = " .,!-=*/\\'\";:][()"; // <------- Exception

	//---------------------------*
	//	Personal Account Struct
	//---------------------------*
	
	struct PersonalInfo
	{
		string name;
		string surname;
		string age;
		string tellNumber;
	};
	
	//---------------------------*
	//		Account Struct
	//---------------------------*

	struct Account
	{
		int index;
		string username;
		string password;
		string descreption = DefaultDescription;
		PersonalInfo Info;
		vector<string> posts;
		string** msg = new string*;
		vector<int> friends;
	};
	
	vector<Account> accounts; // <------- Account Safe Array

	//-------------------------------*
	// 
	//  Function's for Social Network
	// 
	//-------------------------------*

	void			printList(Account&);
	void			push_account(Account&);
	virtual int		GetAccountSize() = 0;
	virtual void	CreateAccount()	 = 0;
	virtual void	CreatePost()	 = 0;
	virtual void	FriendList()	 = 0;
	virtual void	GetAllIndex()	 = 0;
	bool			isValidUsername(const string&);
	bool			isValidPhoneNumber(const string&);
	bool			isValidAge(const string&);
	bool			isValidPassword(const string&);
	bool			isvalidWord(const string&);
	bool			vFriend(int&);


	//---------------------------*
	//		Admin Contoller
	//---------------------------*


};

class System
{
public:
virtual void Start() = 0;
}


class Accounter : public System, protected Social_Network
{
	bool			CheckUser(string&, string&);
	int				AccountIndex = Empty;
public:

	//---------------------------*
	//		Login and Logout
	//---------------------------*

	void			LogIn();
	void			Logout();

	//---------------------------*
	//			Edit Account
	//---------------------------*

	void			EditProfile();
	void			EditUsername();
	void			EditName();
	void			EditPassword();
	void			EditSurname();
	void			EditAge();
	void			EditDiscreption();
	void			EditTellNumber();
	void			DeleteAccount();

	//---------------------------*
	//			Menus
	//---------------------------*

	void			MPost();
	void			MProfile();
	void			MMessage();
	void			MSearch();	
	void			MFriend();	
	void			MSettings();
	void			MSetStyle();

	//---------------------------*
	//			Creator's
	//---------------------------*

	virtual void	CreatePost()		override;
	virtual void	CreateAccount()		override;

	//---------------------------*
	//			Anymore
	//---------------------------*
	
	void			Start()         override;
	void			ProfileMenu();
	virtual void	FriendList()		override;
	virtual int		GetAccountSize()	override;
	virtual void	GetAllIndex()		override;
};

//---------------------------*
//	  Basic Main Void's
//---------------------------*

void Menu(Accounter&);
void Choice(Accounter&);
void LoginMenu();
void LoginMain(Accounter&);
void SystemColor(color);
