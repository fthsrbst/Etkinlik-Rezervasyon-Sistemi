#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
#include<string>
#include"etkinlik.h"

using namespace std;

class admin{
	private:
		string username;
		string password;
		etkinlik etkinlikler[10];
	public:
		static int sayac;
		explicit admin(string username="admin",string password="1234");
		~admin();
		
		friend class ekran;
		
		void setusername(string);
		void setpassword(string);
		
		string getusername()const;
		string getpassword()const;
		
	
		
};

#endif
