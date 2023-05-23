#include<iostream>
#include<string>
#include<fstream>//dosya islemleri icin gerekli olan kutuphane
#include<iomanip>//setw() kullanmak icin gerekli olan kutuphane
#include <ctime>//rastgele rezervasyon no icin
#include"admin.h"
#include"ekran.h"
#include"etkinlik.h"

using namespace std;
int ekran::sayac = 0;
etkinlik etkinlik::etkinlikler[10];


ostream& operator<<(ostream& output, etkinlik& etkinlik) {
output	<< "Etkinlik ID: " << etkinlik.getetkinlikID() << endl
		<< "Etkinlik Isim: " << etkinlik.getetkinlikAd() << endl
		<< "Etkinlik Tarih: " << etkinlik.getetkinlikTarih() << endl
		<< "Etkinlik Koltuk Sayisi: " << etkinlik.getkoltuksayisi() << endl;
	return output;
	}
	
istream& operator>>(istream& input, etkinlik& etkinlik) {
	int id,koltuk;
	string ad,tarih;
    cout << "Etkinlik ID girin: ";
    input >> id;
	etkinlik.setetkinlikID(id);
    cout << "Etkinlik Isim girin: ";
    input >> ad;
	etkinlik.setetkinlikAd(ad);
    cout << "Etkinlik Tarih girin: ";
    input >> tarih;
	etkinlik.setetkinlikTarih(tarih);
    cout << "Etkinlik Koltuk Sayisi girin: ";
    input >> koltuk;
	etkinlik.setkoltuksayisi(koltuk);
    return input;
    
}


void ekran::dosyadancek(){
	
	int koltuksayi;
    int etkinlikID;
    string etkinlikAd;
    string etkinlikTarih;
	int i=1;
	
	ifstream Etkinlikcek;
    Etkinlikcek.open("EtkinlikKayitlari.txt");
    while(!(Etkinlikcek.eof()))
	{
    Etkinlikcek>>etkinlikID>>etkinlikAd>>etkinlikTarih>>koltuksayi;
    etkinlikler[i].setetkinlikID(etkinlikID);
 	etkinlikler[i].setetkinlikAd(etkinlikAd);
 	etkinlikler[i].setetkinlikTarih(etkinlikTarih);
 	etkinlikler[i].setkoltuksayisi(koltuksayi);
 	etkinlikler[i].nesneekle(etkinlikID,etkinlikAd,etkinlikTarih,koltuksayi);
	i++;
	}
}

void ekran::haziretkinlik(){
	etkinlik etkinlik1(1,"Mesir Macunu Festivali Manisa","24 nisan 2023",800);
	etkinlik etkinlik2(2,"Tiyatro Festivali Bursa","28 nisan 2023",100);
	etkinlik etkinlik3(3,"Magic Break Antalya","02 haziran 2023",500);
	etkinlik etkinlik4(4,"Holifest","14 nisan 2023",1000);
	etkinlik etkinlik5(5,"Cappadox","24 nisan 2023",2000);
	cout<<etkinlik1<<endl<<endl;
	cout<<etkinlik2<<endl<<endl;
	cout<<etkinlik3<<endl<<endl;
	cout<<etkinlik4<<endl<<endl;
	cout<<etkinlik5<<endl<<endl;
}



void ekran::rezervasyon() {
    int secim;
    system("cls");
    cout << "Rezervasyon paneline hos geldiniz" << endl;

    string line;

    ifstream EtkinlikGoster;
    EtkinlikGoster.open("EtkinlikKayitlari.txt", ios::app);
    cout<<endl<<"===ID===      ===ISIM===      ===TARIH===      ===KOLTUK==="<<endl;
    while (!EtkinlikGoster.eof()) {
        getline(EtkinlikGoster, line);
        if (EtkinlikGoster.fail()) {
            continue;
        }
        cout << line << endl;
    }
    EtkinlikGoster.close();

    int etkinlikID;
    string adSoyad;
    int koltukNo;
    int j;


    cout << "Etkinlik ID'sini girin: ";
    cin >> etkinlikID;

    bool etkinlikBulundu;
    for (int i = 0; i <= 10; i++) 
	{
        if (etkinlikler[i].getetkinlikID() == etkinlikID) 
		{
			cout<<endl<<"Kalan koltuk sayisi ="<<etkinlikler[i].getkoltuksayisi()<<endl;
            etkinlikBulundu = true;
            if (etkinlikler[i].getkoltuksayisi() > 0) 
			{
                cout << "Adiniz ve soyadinizi girin: ";
                cin.ignore();
                getline(cin, adSoyad);

                cout << "Koltuk numarasini girin: ";
                cin >> koltukNo;

                int rezervasyonNo = 0;
                srand(time(0));
                rezervasyonNo = rand() % 1000 + 1;

                cout << "Rezervasyon basariyla yapildi. Rezervasyon No: " << rezervasyonNo << endl;
                cout << "Rezervasyon Bilgileri:" << endl;
                cout << "Etkinlik ID: " << etkinlikID << endl;
                cout << "Etkinlik Ad: " << etkinlikler[i].getetkinlikAd() << endl;
                cout << "Etkinlik Tarih: " << etkinlikler[i].getetkinlikTarih() << endl;
                cout << "Ad Soyad: " << adSoyad << endl;
                cout << "Koltuk No: " << koltukNo << endl;

                etkinlikler[i].setkoltuksayisi(etkinlikler[i].getkoltuksayisi() - 1);

                ofstream rezervasyonDosyasi;
                rezervasyonDosyasi.open("rezervasyonlar.txt", ios::app);
                if (!rezervasyonDosyasi) {
                    cout << "Hata: Rezervasyon dosyasina erisilemedi!" << endl;
                    return;
                }

                rezervasyonDosyasi <<endl<<endl<< "Rezervasyon No: " << rezervasyonNo << endl;
                rezervasyonDosyasi << "Etkinlik ID: " << etkinlikID << endl;
                rezervasyonDosyasi << "Etkinlik Ad: " << etkinlikler[i].getetkinlikAd() << endl;
				rezervasyonDosyasi << "Etkinlik Tarih: " << etkinlikler[i].getetkinlikTarih() << endl;
                rezervasyonDosyasi << "Ad Soyad: " << adSoyad << endl;
                rezervasyonDosyasi << "Koltuk No: " << koltukNo << endl;
                rezervasyonDosyasi << "-----------------------" << endl;
				
                rezervasyonDosyasi.close();

            } 
			else {
                cout << "Seçilen etkinlik için bos koltuk bulunmamaktadir." << endl;
            }
        }
    }

    if (!etkinlikBulundu) {
        cout << "Girilen ID'ye sahip bir etkinlik bulunamadi." << endl;
    }

    cout << "Ana menuye donmek icin 0'a, baska bir islem yapmak icin 1'e basin: ";
    cin >> secim;

    if (secim == 0) {
        KarsilamaMesajYaz();
    } else if (secim == 1) {
        rezervasyon();
    } else {
        cout << "Geçersiz seçim. Ana menüye dönülüyor." << endl;
       KarsilamaMesajYaz();
    }
}


int ekran::secimYap(){

	int secim;
		cout<<"1-Bilet-Satis"<<endl<<"2-Admin-giris"<<endl<<"3-Rezervasyon"<<endl<<"4-Cikis"<<endl;
    cout<<"Yapmak istediginiz islemin numarasini giriniz :";
    cin>>secim;
	
    
    if (secim!=1 && secim!=2 && secim!=3 && secim!=4){
    cout<<endl<<"!!!  Yanlis giris yaptiniz lutfen tekrardan giriniz  !!!"<<endl<<endl;
    secimYap();
		}

	switch(secim){
		case 1:
			etkinliklerpaneli();
			break;
		case 2:
			AdminGirispaneli();
			break;
		case 3:
			rezervasyon();
			break;
		case 4:
			system("cls");
			return 0;
			break;
	}
	}
	
	
void ekran::KarsilamaMesajYaz(){
  dosyadancek();
  cout<<"|-------------------------------------------|"<<endl;
  cout<<"|-------|Bilet Sistemine Hosgeldiniz|-------|"<<endl;
  cout<<"|-------------------------------------------|"<<endl<<endl;
  secimYap();
  }


void ekran::etkinliklerpaneli(){
	system("cls");
	string line;
	cout<<"Etkinlikler Ekranina Hosgeldiniz!"<<endl<<endl;
	ifstream EtkinlikGoster;
	EtkinlikGoster.open("EtkinlikKayitlari.txt",ios::app);

cout<<endl<<"===ID===      ===ISIM===      ===TARIH===      ===KOLTUK==="<<endl;
	while(!EtkinlikGoster.eof())
	{
		
		getline(EtkinlikGoster,line);

		if(EtkinlikGoster.fail())
		{
			continue;
		}
	
		cout<<line<<endl;
	}
	EtkinlikGoster.close();
	int tercih;
	cout<<endl<<endl;
	cout<<"cikis icin 1 e basin :";
	cin>>tercih;
	if(tercih==1){
		system("cls");
		KarsilamaMesajYaz();
	}
}

void ekran::AdminGirispaneli(){
	system("cls");
	string username,password;
   	cout << "Kullanici adi: ";
   	cin >> username;
   	cout <<endl<< "Sifre: ";
   	cin >> password;

   	if (username == "admin" && password == "1234") 
	   {
      	cout << "Giris basarili, Hosgeldin admin" << endl;
      	Adminpaneli();
   		} 
		else 
		{
		system("cls");
      	cout << "Kullanici adi veya sifre yanlis, erisim reddedildi" <<endl<<endl;
				KarsilamaMesajYaz();
   		}
}

void ekran::etkinlikekle(){
	static int sayac=1;
	string etkinlikAd,etkinlikTarih;
	int koltuksayi;

	if (sayac < 10) {
        
        cout << "Etkinlik adini girin: ";
        cin.ignore();
        getline(cin, etkinlikAd);

        cout << "Etkinlik tarihini girin: ";
        getline(cin, etkinlikTarih);

        cout << "Koltuk sayisini girin: ";
        cin >> koltuksayi;
		etkinlikler[sayac].setetkinlikID(sayac);
 		etkinlikler[sayac].setetkinlikAd(etkinlikAd);
 		etkinlikler[sayac].setetkinlikTarih(etkinlikTarih);
 		etkinlikler[sayac].setkoltuksayisi(koltuksayi);
 		etkinlikler[sayac].EtkinlikEkle(sayac,etkinlikAd,etkinlikTarih,koltuksayi);
 		
 		sayac++;
        cout << "Etkinlik basariyla eklendi." << endl;
    } else {
        cout << "Maksimum etkinlik sayisina ulasildi." << endl;
    }
}

void ekran::Adminpaneli() {
    sayac = 0;
    system("cls");
    int secim;

    cout << endl << "ADMIN PANELINE ERISIM KABUL EDILDI!" << endl;
    cout << "HOSGELDIN FATIH SERBEST" << endl << endl;
    cout << "1-Etkinlik Ekle" << endl;
    cout << "2-Etkinliklere Bak" << endl;
    cout << "3-Etkinlik Duzenle" << endl;
    cout << "4-Anasayfa" << endl;
    cout << "5-Rezervasyonlari Gor" << endl;
    cout << "Lütfen yapmak istediginiz islemi giriniz: ";
    cin >> secim;

    if (secim == 1) {
        etkinlikekle();
        	Adminpaneli();
        	
        	
    } else if (secim == 2) {
        etkinliklerpaneli();
    } else if (secim == 3) {
        etkinlikler[sayac].EtkinlikDuzenle();
    } else if (secim == 4) {
        system("cls");
        KarsilamaMesajYaz();
    } else if (secim == 5) {

        system("cls");
        cout << "Rezervasyon Kayitlari" << endl << endl;
        string line;
        ifstream rezervasyonDosyasi("rezervasyonlar.txt");
        if (rezervasyonDosyasi.is_open()) {
            while (getline(rezervasyonDosyasi, line)) {
                cout << line << endl;
            }
            
            rezervasyonDosyasi.close();
            int tercih;
            cout<<endl<<endl<<"Admin paneline donus icin 1 e basin :";
            cin>>tercih;
            if (tercih==1){
            	Adminpaneli();
			}
        } else {
            cout << "Hata: Rezervasyon dosyasina erisilemedi!" << endl;
        }
        cout << endl;
    } else {
        cout << "Yanlis tusladiniz, lütfen tekrar deneyiniz" << endl;
    }
    sayac++;
}




