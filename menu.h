#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<string>

using namespace std;

class menu{
	private:
		int secim;
	public:
		explicit menu(int secim=0);
		~menu();
		
		void setsecim(int);
		int getsecim()const;
		
		void KarsilamaMesajYaz()const;
		
		void secimYap();
		
};
#endif

