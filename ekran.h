#ifndef EKRAN_H
#define EKRAN_H

#include<iostream>
#include<string>
#include"admin.h"
#include"etkinlik.h"

using namespace std;

class ekran{
	private:
		etkinlik etkinlikler[10];
		static int sayac;
		admin admin;
	
	public:
		void KarsilamaMesajYaz();
		int secimYap();
		friend ostream &operator>>(ostream&input,etkinlik &etkinlik);
		friend ostream &operator<<(ostream &output,etkinlik &etkinlik);
		void Adminpaneli();
		void AdminGirispaneli();
		void etkinliklerpaneli();
		void rezervasyon();
		static void haziretkinlik();
		void etkinlikekle();
		void dosyadancek();
	
		
		
};
#endif

