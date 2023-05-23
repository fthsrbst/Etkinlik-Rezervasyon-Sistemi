#include<iostream>
#include<string>
#include"ekran.h"
#include"admin.h"
#include"etkinlik.h"

using namespace std;

int main(){
	
	
	etkinlik(1,"Mesir Macunu","23 ocak 2023",30);
	admin admin("fatih","1234");
	ekran ekran;
	ekran.KarsilamaMesajYaz();
	cout<<endl;
	return 0;
}
