#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

#include"admin.h"
#include"ekran.h"
#include"etkinlik.h"

using namespace std;



int etkinlik::sayac=0;



etkinlik::etkinlik(int etkinlikID, string etkinlikAd, string etkinlikTarih, int koltuksayi) {
    this->etkinlikID = etkinlikID;
    this->etkinlikAd = etkinlikAd;
    this->etkinlikTarih = etkinlikTarih;
    this->koltuksayi = koltuksayi;
}
etkinlik::~etkinlik(){
	//empty body
	etkinlik::sayac--;

}

void etkinlik::setetkinlikID(int id) {
    etkinlikID = id;
}

void etkinlik::setetkinlikAd(string ad) {
    etkinlikAd = ad;
}

void etkinlik::setetkinlikTarih(string tarih) {
    etkinlikTarih = tarih;
}

void etkinlik::setkoltuksayisi(int koltuk) {
    koltuksayi = koltuk;
}

int etkinlik::getetkinlikID() const {
    return etkinlikID;
}

string etkinlik::getetkinlikAd() const {
    return etkinlikAd;
}

string etkinlik::getetkinlikTarih() const {
    return etkinlikTarih;
}

int etkinlik::getkoltuksayisi() const {
    return koltuksayi;
}


void etkinlik::etkinlikIDKayit(){
/*
	ifstream file("IDsayac.txt");
    int karakter;
    file >> karakter;
    file.close();
		
    ofstream gecici("geciciIDsayac.txt");
    gecici<<sayac2++;
    gecici.close();
	
    ofstream sayac("IDsayac.txt");
    sayac<<karakter;
	sayac<<sayac1<<endl;
	sayac1++;
	sayac.close();
	remove("IDsayac.txt");
	rename("geciciIDsayac.txt","IDsayac.txt");
	
	ifstream Id("IDsayac.txt");
    int ID;
    Id >> ID;
    Id.close();
    setetkinlikID(ID);
    
    
    	ifstream file("sayac.txt");
    int sayac ;
    file >> sayac;
    file.close();

    int etkinlikID = sayac;
    setetkinlikID(sayac);
    
    
    
     ofstream outFile("sayac.txt");
    outFile << sayac + 1;
    outFile.close();
*/

	}
	

void etkinlik::EtkinlikEkle(int sayac, string etkinlikAd,string etkinlikTarih,int koltuksayi) {

    ofstream EtkinlikEkle;
    EtkinlikEkle.open("EtkinlikKayitlari.txt", ios::app);
    	etkinlikler[sayac].setetkinlikID(sayac);
  		etkinlikler[sayac].setetkinlikAd(etkinlikAd);
 		etkinlikler[sayac].setetkinlikTarih(etkinlikTarih);
 		etkinlikler[sayac].setkoltuksayisi(koltuksayi);

    EtkinlikEkle << endl
                << etkinlikler[sayac].getetkinlikID() << setw(20) << etkinlikler[sayac].getetkinlikAd() << setw(20)
                << etkinlikler[sayac].getetkinlikTarih() << setw(20) << setw(20) 
                << setw(20) << etkinlikler[sayac].getkoltuksayisi();

    EtkinlikEkle.close();

    ofstream etkinlikNesneleri("etkinlikNesneleri.txt", ios::app);
    if (!etkinlikNesneleri) {
        cout << "Dosya açilamadi" << endl;
        return;
    }
    etkinlikNesneleri << endl << sayac << " numarali nesneniz = " << etkinlikler[sayac].getetkinlikAd();

    etkinlikNesneleri.close();

    cout << endl << "Etkinlik basariyla olusturuldu." << endl;
}

void etkinlik::nesneekle(int sayac, string etkinlikAd,string etkinlikTarih,int koltuksayi){
		etkinlikler[sayac].setetkinlikID(sayac);
  		etkinlikler[sayac].setetkinlikAd(etkinlikAd);
 		etkinlikler[sayac].setetkinlikTarih(etkinlikTarih);
 		etkinlikler[sayac].setkoltuksayisi(koltuksayi);
}



void etkinlik::EtkinlikDuzenle() {
    ifstream EtkinlikGoster("EtkinlikKayitlari.txt", ios::app);
    string line;
    cout<<endl<<"===ID===      ===ISIM===      ===TARIH===      ===KOLTUK==="<<endl;
    while (getline(EtkinlikGoster, line)) {
        cout << line << endl;
    }
    EtkinlikGoster.close();

    int IDkontrol;
    cout << "Degistirmek istediginiz etkinlik ID'sini girin: ";
    cin >> IDkontrol;
    cout << endl;

    ifstream EtkinlikOku("EtkinlikKayitlari.txt");
    ofstream Gecici("gecici.txt");

    int etkinlikID;
    string etkinlikAd;
    string etkinlikTarih;
    string etkinlikAdres;
    string etkinlikIcerik;

    while (EtkinlikOku >> etkinlikID >> etkinlikAd >> etkinlikTarih >> etkinlikAdres >> etkinlikIcerik) {
        if (IDkontrol == etkinlikID) {
            cout << "Yeni Etkinlik ID'sini girin: ";
            cin >> etkinlikID;
            cout << "Yeni Etkinlik adini girin: ";
            cin >> etkinlikAd;
            cout << "Yeni Etkinlik tarihini girin: ";
            cin >> etkinlikTarih;
            cout << "Yeni Etkinlik adresini girin: ";
            cin >> etkinlikAdres;
            cout << "Yeni Etkinlik içerigini girin: ";
            cin >> etkinlikIcerik;
        }

        Gecici << etkinlikID << " " << etkinlikAd << " " << etkinlikTarih << " " << etkinlikAdres << " " << etkinlikIcerik << endl;
    }

    EtkinlikOku.close();
    Gecici.close();

    remove("EtkinlikKayitlari.txt");
    rename("gecici.txt", "EtkinlikKayitlari.txt");
}


/*void etkinlik::etkinlikgoster(){
		ifstream EtkinlikGoster;
		string line ;
		EtkinlikGoster.open("EtkinlikKayitlari.txt");
		while(!EtkinlikGoster.eof())
		{
		getline(EtkinlikGoster,line);
		if(EtkinlikGoster.fail())
		{
			continue;;
		}
		cout<<line<<endl;
		}
		EtkinlikGoster.close();
}*/


