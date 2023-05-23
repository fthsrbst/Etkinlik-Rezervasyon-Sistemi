#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"admin.h"
#include"ekran.h"
#include"etkinlik.h"

using namespace std;
int admin::sayac=0;

admin::admin(string username,string password)
{
		setusername(username);
		setpassword(password);
}

admin::~admin(){
}


void admin::setusername(string _username){
	username=_username;
}
void admin::setpassword(string _password){
	password=_password;
}
/*void admin::setpassword(int password){
	if(password>6){
		cout<<endl<<"fazla karakter girdiniz tekrar deneyiniz"<<endl;
	}
	else{
		this->password=password;
		cout<<"basariyla olustu";
	}
}*/



string admin::getusername()const
{
	return username;
}

string admin::getpassword()const
{
	return username;
}








