#ifndef ETKINLIK_H
#define ETKINLIK_H

#include <iostream>
#include <string>

using namespace std;

class etkinlik {
public:
	static int sayac;
    explicit etkinlik(int etkinlikID = 0, string etkinlikAd = " ", string etkinlikTarih = " ", int koltuksayi = 0);
    ~etkinlik();
	
	static int sayac1;
	static int sayac2;
    void setetkinlikID(int);
    void setetkinlikAd(string);
    void setetkinlikTarih(string);
    void setkoltuksayisi(int);

    int getetkinlikID() const;
    string getetkinlikAd() const;
    string getetkinlikTarih() const;
    int getkoltuksayisi() const;

    void etkinlikIDKayit();
    void EtkinlikEkle(int,string,string,int);
    void EtkinlikDuzenle();
    
    void nesneekle(int,string,string,int);

private:
    int koltuksayi;
    int etkinlikID;
    string etkinlikAd;
    string etkinlikTarih;
    static etkinlik etkinlikler[10];
};

#endif

