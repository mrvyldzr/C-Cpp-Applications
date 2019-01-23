
#include <iostream>
#include <string>
#include "b181210377_1B_odev4.h"

using namespace std;

class Sifre {

public:
	Sifre(char *alfabe, char *sifre);
	Sifre();
	~Sifre();

	char *sifrele(char *);
	char *sifrecoz(char *);
	void sifreKelimesiAta(char *);

private:
	char *alfabe ;
	char *sifreKelimesi;

};
Sifre::Sifre()
{
	alfabe = (char*)"ABCDEFGHJKLMNOPRRSXWYZ";
}
Sifre::Sifre(char *alfabe, char *sifre) 
{	
	this->alfabe = alfabe;
	this->sifreKelimesi = sifre;
}
void Sifre::sifreKelimesiAta(char *sifre) {
	this->sifreKelimesi = sifre;
}
char* Sifre::sifrele(char *sifreli_metin)
{
	char *sifrelenen_metin = new char[1];
	int sifreli_metin_boyut = 1;
	int metin_boyut = strlen(sifreli_metin) ;
	int alfabe_uzunluk = strlen(alfabe);
	int sifre_uzunluk = strlen(sifreKelimesi);


	for (int i = 0 ; i < metin_boyut; i++)
	{
		char c = sifreKelimesi[i % sifre_uzunluk];
		int c_konum = 0;
		int k_konum = 0;
		bool kont1 = true, kont2 = true;
		for (int k = 0; k < alfabe_uzunluk; k++)
		{
			if (c == alfabe[k] && kont1)
			{
				c_konum = k + 1;
				kont1 = false;
			}

			if (sifreli_metin[i] == alfabe[k] && kont2)
			{
				k_konum = k;
				kont2 = false;
			}
		}


		int sifre_konum = (k_konum + c_konum) % (alfabe_uzunluk);
		sifrelenen_metin[sifreli_metin_boyut - 1] = alfabe[sifre_konum];
		sifreli_metin_boyut++;
		char* gecici = sifrelenen_metin;
		sifrelenen_metin = new char[sifreli_metin_boyut];
		for (int p = 0; p < sifreli_metin_boyut - 1; p++)
		{
			sifrelenen_metin[p] = gecici[p];
		}
		sifrelenen_metin[sifreli_metin_boyut - 1] = '\0';
		//delete gecici;
	}
	sifrelenen_metin[sifreli_metin_boyut - 1] = '\0';
	return sifrelenen_metin;
}
char* Sifre::sifrecoz(char *sifreli_metin) {

	char *sifrelenen_metin = new char[1];

	int sifreli_metin_boyut = 1;
	int metin_boyut = strlen(sifreli_metin);
	int alfabe_uzunluk = strlen(alfabe);
	int sifre_uzunluk = strlen(sifreKelimesi);


	for (int i = 0; i < metin_boyut; i++)
	{
		char c = sifreKelimesi[i % sifre_uzunluk];
		int c_konum = 0;
		int k_konum = 0;
		bool kont1 = true, kont2 = true;
		for (int k = 0; k < alfabe_uzunluk; k++)
		{
			if (c == alfabe[k] && kont1)
			{
				c_konum = k;
				kont1 = false;
			}
			if (sifreli_metin[i] == alfabe[k] && kont2)
			{
				k_konum = k;
				kont2 = false;
			}
		}
		int sifre_konum = (k_konum - c_konum);
		if (sifre_konum < 0)
			sifre_konum += alfabe_uzunluk;
		sifrelenen_metin[sifreli_metin_boyut - 1] = alfabe[sifre_konum];
		sifreli_metin_boyut++;
		char* gecici = sifrelenen_metin;
		sifrelenen_metin = new char[sifreli_metin_boyut];
		for (int p = 0; p < sifreli_metin_boyut - 1 ; p++)
		{
			sifrelenen_metin[p] = gecici[p];
		}
		sifrelenen_metin[sifreli_metin_boyut - 1] = '\0';
		//delete gecici;
	}
	sifreli_metin_boyut--;
	char* gecici = sifrelenen_metin;
	sifrelenen_metin = new char[sifreli_metin_boyut];
	for (int p = 0; p < sifreli_metin_boyut; p++)
	{
		sifrelenen_metin[p] = gecici[p];
	}
	return sifrelenen_metin;


}
Sifre::~Sifre() {

	delete alfabe;
	delete sifreKelimesi;

	
}






int main() {

	
		cout << "Sifrelenmesini istediðiniz  bir alfabe giriniz\n";
		std::string line;
		std::getline(std::cin, line);
	    char *girilenAlfabe = (char *)line.data();

		cout << "Alfabe yi kullanarak þifre olustur\n";

		std::string line1;
		std::getline(std::cin, line1);
		char *sifreleyen = (char *)line1.data();

		cout << "Sifre Kelimesi\n";

		std::string line2;
		std::getline(std::cin, line2);
		char *sifre_kelimesi = (char*)line2.data();

	 Sifre a(girilenAlfabe, sifreleyen);
	 char* sifreli_metin = a.sifrele(sifre_kelimesi);
	 cout << "Sifreli Metin : "<<sifreli_metin<<endl;
	 cout << "Desifre Metin : " << a.sifrecoz(sifreli_metin) << endl;


	

}