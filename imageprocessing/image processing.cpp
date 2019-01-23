#include <iostream>

using namespace std;
bool Kontrol(int, int, int);
struct Islem {
	int girisBoyutu;   
	int giris[5][5] = { 1,2,5,1,4,
					   1,2,1,0,7,
					   3,0,0,2,0,
					   1,1,3,2,2,
					   0,3,1,0,0};

	int cikisBoyutu;
	int kaymaMiktari;
	int *cikis;			//matrisin yeni halini tutar
	int cekirdekBoyutu;
	int *cekirdek;			//cekirdek matrisini tutar
};


int main() {

	
	struct Islem* mystr = new struct Islem();

	int a = sizeof(mystr->giris[0])/sizeof(int); 
	mystr->girisBoyutu = a;

	
	
	int cekirdek_boyut;
	int kayma_miktari;
	cout << "Cekirdek Boyutu = ";
	cin >> cekirdek_boyut;
	cout << "\nKayma Miktari = ";
	cin >> kayma_miktari;


	int tut = mystr->girisBoyutu;
	
	//Kayma miktari ve cekirdek Boyutunda taþma olup olmadýðýný kontrol ediyor.
	//Kontrol fonksiyonu false donerse iþleme devam edilemez.
	if (!Kontrol(cekirdek_boyut, kayma_miktari, tut)) {
		system("pause");
		return -1;
	}
	else { // true ise dogrudan devam eder.


		mystr->girisBoyutu = tut;
		mystr->cekirdekBoyutu = cekirdek_boyut;						
		
		mystr->cekirdek = new int[cekirdek_boyut * cekirdek_boyut]; // cekirdek matrisi iki boyutlu olduðu için karesi kadar elemana sahip
		



		///////////////////////////////////////////////////////////////////////////////////////////////////

																	
		//SATIRLARI GEZ
		for (int i = 0; i < cekirdek_boyut; i++)  
		{	
			//SUTUNLARI GEZ
			for (int j = 0; j < cekirdek_boyut; j++)  
			{
				cout << "Cekirdek[" << i << "]" << "[" << j << "]" << " = ";

				//cekirdek elemanlarýný alýyoruz.Ýki Boyutlu matris þeklinde
				cin >> mystr->cekirdek[i*cekirdek_boyut + j]; 
			}
			//cýkýs matrisinin sutun sayisi
			mystr->cikisBoyutu = (mystr->girisBoyutu - mystr->cekirdekBoyutu) / kayma_miktari + 1;

			//cikis matrisi icin yeni dinamik bir bellek alanýmýz oluyor.
			mystr->cikis = new int[mystr->cikisBoyutu*mystr->cikisBoyutu];

			for (int i = 0; i < mystr->cikisBoyutu; i++)
			{
				for (int j = 0; j < mystr->cikisBoyutu; j++)
				{
					mystr->cikis[i*mystr->cikisBoyutu + j] = 0;
				}
			}



			///////////////////////////////////////////////////////////////////////////////////////////////////////////

			int cikis_satir = -1, cikis_sutun = -1;

		
			//Kayma miktari kadar satirda ilerliyoruz.
			
			for (int i = 0; i <= mystr->girisBoyutu - cekirdek_boyut; i += kayma_miktari)
			{
				cikis_satir++;
				//Kayma miktari kadar sutunda ilerliyoruz.
				for (int j = 0; j <= mystr->girisBoyutu - cekirdek_boyut; j += kayma_miktari) //cikis tek boyutlu dinamik dizinin satir sayisini artýrýyoruz
				{
					cikis_sutun++;																//cikis  tek sutun sayisini artýrýyoruz.
					{
					for (int k = 0; k < cekirdek_boyut; k++)										
						for (int p = 0; p < cekirdek_boyut; p++)
						{
							mystr->cikis[cikis_satir*mystr->cikisBoyutu + cikis_sutun]
								+= mystr->giris[i + k][j + p] * mystr->cekirdek[k*cekirdek_boyut + p];   // Matris elemanlarýmýzla cekirdek dizi 
						}																				//elemanlarýnýn carpimi ve toplanmasý
					}
				}
				cikis_sutun = -1;
			}
		}




		////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//cikis matrisinin yazdirilmasi
		for (int i = 0; i < mystr->cikisBoyutu; i++)
		{
			for (int j = 0; j < mystr->cikisBoyutu; j++)
			{
				cout << mystr->cikis[i*mystr->cikisBoyutu + j];
				cout << "\t";
			}
			cout << "\n";
		}

	}


	system("pause");
	return 0;
}




//Kayma miktari ve cekirdek Boyutunda taþma olup olmadýðýný kontrol ediyor.

bool Kontrol(int cekirdek_boyut, int kayma_miktari, int tut) {
	bool kontrol = false;

	//mystr->girisBoyutu = tut

	for (int i = 0; i < tut; i++)
	{
		if (cekirdek_boyut + i * kayma_miktari == tut)
		{
			kontrol = true;
			break;
		}
	}
	if (!kontrol)
	{
		cout << "Bu kayma gerceklestirilemez.Cekirdek boyutu ve kayma miktari matris boyutunu asiyor" << endl;
		return false;
	}
	return true;

}
