#include <iostream>
#include <cstring>
#include <string>
#include <locale.h>

//#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
const int boyut = 2000;
int main()
{

	setlocale(LC_ALL, "Turkish");
	
	char cstr[boyut];

	int aSayisi = 0;
	int eSayisi = 0;
	int iSayisi = 0;
	int �Sayisi = 0;
	int oSayisi = 0;
	int uSayisi = 0;
	int �Sayisi = 0;
	int �Sayisi = 0;
	char karakterOku;
	int max = 0;
	cout << "bir karakter dizisi giriniz;";
	cin.getline(cstr,boyut); 

		for (int i = 0; cstr[i] != '\0'; i++) { 
			
			karakterOku = cstr[i];	

										
			switch (karakterOku) { 
			case 'a': case 'A':
				aSayisi++;						
				if (aSayisi > max)
					max = aSayisi;
				break;
			case 'i': case (char)-104:
				iSayisi++;
				if (iSayisi > max)
					max = iSayisi;
				break;
			case (char)-115: case 'I': //� ve I sayisi
				�Sayisi++;
				if (�Sayisi > max)
					max = �Sayisi;
				break;
			case 'e': case 'E':
				eSayisi++;
				if (eSayisi > max)
					max = eSayisi;
				break;
			
			case 'o': case 'O':	
				oSayisi++;
				if (oSayisi > max)
					max = oSayisi;
				break;
			case (char)-108: case (char)-103:// � ve � sayisi
				�Sayisi++;
				if (�Sayisi > max)
					max = �Sayisi;
				break;
			case 'u': case 'U':
				uSayisi++;
				if (uSayisi > max)
					max = uSayisi;
				break;
			case (char)-127: case (char)-102: //�-� sayisi
				�Sayisi++;
				if (�Sayisi > max)
					max = �Sayisi;
				break;
			default:		
				break;
			}
		}

	cout << endl <<endl;	
	cout << "H" << "\tTS";
	for (int i = 1; i <= max; i++) //girilen stringde eleman say�s� en fazla olan� tutar ve yazd�r�r
		cout << "\t"<< i;
	cout << "\n";
	if (aSayisi > 0)
	{
		cout << "a" << "\t" << aSayisi;
		if (aSayisi > 9)
		{
			for (int i = 1; i <= aSayisi; i++)
				cout << "\ta";
		}
		else
		{
			for (int i = 1; i <= aSayisi; i++)
				cout << "\ta";
		}
		cout << "\n";
	}
		
	if (iSayisi > 0)
	{
		cout << "i" << "\t" << iSayisi;
		if (iSayisi < 10)
		{
			for (int i = 1; i <= iSayisi; i++)
				cout << "\ti";
		}
		else
		{
			for (int i = 1; i <= iSayisi; i++)
				cout << "\ti";
		}
		cout << "\n";
	}
		
	if (eSayisi > 0)
	{
		cout << "e" << "\t" << eSayisi;
		if (eSayisi < 10)
		{
			for (int i = 1; i <= eSayisi; i++)
				cout << "\te";
		}
		else
		{
			for (int i = 1; i <= eSayisi; i++)
				cout << "\te";
		}
		cout << "\n";
	}
		
	if (uSayisi > 0)
	{
		cout << "u" << "\t" << uSayisi;
		if (uSayisi < 10)
		{
			for (int i = 1; i <= uSayisi; i++)
				cout << "\tu";
		}
		else
		{
			for (int i = 1; i <= uSayisi; i++)
				cout << "\tu";
		}
		cout << "\n";

	}
	if (�Sayisi > 0)
	{
		cout << "�" << "\t" << �Sayisi;
		if (�Sayisi < 10)
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		else
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		cout << "\n";

	}

	if (�Sayisi > 0)
	{
		cout << "�" << "\t" << �Sayisi;
		if (�Sayisi < 10)
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		else
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		cout << "\n";

	}
		
	if (oSayisi > 0) 
	{
		cout << "o" << "\t" << oSayisi <<" ";
		if(oSayisi < 10)
		{
			for (int i = 1; i <= oSayisi; i++)
				cout << "\to";
		}
		else
		{
			for (int i = 1; i <= oSayisi; i++)
				cout << "\to";
		}
		cout << "\n";
	}
	if (�Sayisi > 0)
	{
		cout << "�" << "\t" << �Sayisi << " ";
		if (�Sayisi < 10)
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		else
		{
			for (int i = 1; i <= �Sayisi; i++)
				cout << "\t�";
		}
		cout << "\n";
	}
		
	
	system("pause");
}


