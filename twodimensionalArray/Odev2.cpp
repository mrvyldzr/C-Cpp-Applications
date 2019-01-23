
#include <iostream>


#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;



void matrisiSirala(char Harf[][10], int);
char Harf[5][10];


int main() {
	srand(time(NULL));
	
	int eleman;
	

	int istenilenHarfSayisi = 0;					
	for (int satir = 0; satir <= 4; satir++) {		
		for (int sutun = 0; sutun <= 9; sutun++) {	

			if (istenilenHarfSayisi % 2 == 0) {		//istenilen eleman çift ise tekli sutunlara atama yapar
				eleman = 65 + rand() % 26;
				//elemanýn tekrarlayýp tekrarlamadýðýný kontrol eder
				//eleman tekrarlýyorsa elemaný atlar
				bool kontrol = true;				
				for (int kontrol_satir = 0; kontrol_satir <= 4; kontrol_satir++) {
					for (int kontrol_sutun = 0; kontrol_sutun <= 9; kontrol_sutun++)
					{
						if (Harf[kontrol_satir][kontrol_sutun] == (char)eleman) {
							kontrol = false;
							break;
						}
					}
				}
				if (kontrol)
					Harf[satir][sutun] = (char)eleman;
				else
				{
					sutun--;		
					continue;
				}
			}
			else  if (istenilenHarfSayisi % 2 == 1) {		

				eleman = 97 + rand() % 26;
				bool kontrol = true;
				for (int kontrol_satir = 0; kontrol_satir <= 4; kontrol_satir++) {
					for (int kontrol_sutun = 0; kontrol_sutun <= 9; kontrol_sutun++)
					{
						if (Harf[kontrol_satir][kontrol_sutun] == (char)eleman) {
							kontrol = false;
							break;
						}
					}
				}
				if (kontrol)
					Harf[satir][sutun] = (char)eleman;
				else
				{
					sutun--;
					continue;
				}

			}
			istenilenHarfSayisi++;		
		}
	}
	cout << "tekrarsiz ve rastgele dizi" << endl;
			for (int satir = 0; satir < 5; satir++) {	
				for (int sutun = 0; sutun < 10; sutun++) {
					cout << (char)Harf[satir][sutun] << '\t';
				}
				cout << endl;
			}
			
			cout << "Siralanmis dizi" << endl;

			matrisiSirala(Harf, istenilenHarfSayisi);
		
			for (int satir = 0; satir < 5; satir++) {
			
				for (int sutun = 0; sutun < 10; sutun++) {
				cout << (char)Harf[satir][sutun]<< '\t';
				}
				cout << endl;
			}
	
	system("pause");
}

void matrisiSirala(char Harf[][10], int istenilenHarfSayisi) { 
																 // asci karþýlýðýna göre kücükten buyuge siralar
	int temp, i, satir, sutun;

	for (i = 1; i < istenilenHarfSayisi + 1; i++)
	{
		for (satir = 0; satir < 5; satir++)
		{
			for (sutun = 0; sutun < 9; sutun++)
			{
				if (Harf[satir][sutun] > Harf[satir][sutun + 1])
				{
					temp = Harf[satir][sutun];
					Harf[satir][sutun] = Harf[satir][sutun + 1];
					Harf[satir][sutun + 1] = temp;
				}
			}
		}
		for (satir= 0; satir < 4; satir++)			
		{											
			if (Harf[satir][9] > Harf[satir + 1][0])
			{
				temp = Harf[satir][9];
				Harf[satir][9] = Harf[satir + 1][0];
				Harf[satir + 1][0] = temp;
			}
		}
	}
}
