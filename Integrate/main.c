#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double simpson(double,double);
double rectangle(double,double);
double trapezoid(double,double);
double midpoint(double,double);
double fonksiyonK(double);
bool rakammi(char); 
bool fonksiyonKontrol(char*);
double usAl(double taban, double us);
char *fonksiyon;
int main(int argc,char*argv[])
{
    double sonuc;
    double a,b;
    fonksiyon = argv[1];
    int aralikSayisi = atof(argv[4]);
    a = atof(argv[2]);
    b = atof(argv[3]);
    double aralik = (b-a)/aralikSayisi;
    int k;
    if(argc != 6)
    {
        printf("Eksik Arguman Girildi !!!\n");
        exit(1);
    }
    if(fonksiyonKontrol(argv[1]) == false)
    {
        printf("Fonksiyon Hatali\n");
        exit(1);
    }


    switch(argv[5][0])
    {
    case 's':case 'S':
        for(k=0;k < aralikSayisi ;k++)
        {
            sonuc += simpson(a,a+aralik);
            a+=aralik;
        }
        break;
    case 'r':case 'R':
        for(k=0;k < aralikSayisi ;k++)
        {
            sonuc += rectangle(a,a+aralik);
            a+=aralik;
        }
        break;
    case 't':case 'T':
        for(k=0;k < aralikSayisi ;k++)
        {
            sonuc += trapezoid(a,a+aralik);
            a+=aralik;
        }
        break;
    case 'm':case 'M':
        for(k=0;k < aralikSayisi ;k++)
        {
            sonuc += midpoint(a,a+aralik);
            a+=aralik;
        }
        break;
    default:
        printf("fonksiyon tipini yanlis girdiniz\n");
        exit(1);
        break;

    }
    printf("sonuc : %.2f",sonuc);
    return 0;
}
double simpson(double a ,double b)
{
    double sonuc = ((b-a)/6)*(fonksiyonK(a)+4*fonksiyonK((a+b)/2)+fonksiyonK(b));
    return sonuc;
}
double rectangle(double a,double b)
{
    double sonuc = fonksiyonK(a)*(b-a);
    return sonuc;
}
double trapezoid(double a,double b)
{
    double sonuc = ((fonksiyonK(a) + fonksiyonK(b))/2)*(b-a);
    return sonuc;
}
double midpoint(double a,double b)
{
    double sonuc = fonksiyonK((a+b)/2)*(b-a);
    return sonuc;
}

double fonksiyonK(double x)
{
    int i=0;
    double sonuc = 0;
    double KatsayiSonucu = 1;
    double katsayi = 1;
    double usSonucu = 0;
    int k=0;
    while (fonksiyon[k] != '\0') 
    {
        i=k;
        while (fonksiyon[i] != 'x' && fonksiyon[i] != '\0') 
    {
        if( i == 0) 
        {
            char str[1] = {fonksiyon[i]}; //FONKSIYONUN i'NCI DEGERINI strtod() FONKSIYONUYLA DOUBLEYE CEVIRIYOR
            char *ptr;
            double ret;
            ret = strtod(str, &ptr);
            KatsayiSonucu = ret;
        }
        else if(rakammi(fonksiyon[i]) == true)//SIRADAKI KARAKTER RAKAMSA ONU DOUBLE DEGERE CEVIR
        {
            char str[1] = {fonksiyon[i]};
            char *ptr;
            double ret;
            ret = strtod(str, &ptr);
            KatsayiSonucu*=katsayi; 
            KatsayiSonucu+=ret; //YENI RAKAMI EKLE
        }
        else if(fonksiyon[i] == '+' || fonksiyon[i] == '-') // + VEYA - GELMIS ISE DONGUDEN CIK
            break;
        else
        {
            fprintf(stderr,"Beklenmedik hata\n");
            exit(1);
        }
        katsayi=10;
        i++;
    }
    if(fonksiyon[i] == 'x') //YUKARDAKI WHILE DEN X E GELDIGIMIZ ICIN CIKMISSAK USSONUCUNU 1'E SETLEYIP INDISI 1 ARTIRIYORUZ
    {
        usSonucu = 1.0;
        i++;
    }
    else if(fonksiyon[i] == '+' || fonksiyon[i] == '-') //+ VEYA - YE GELDIGIMIZ ICIN CIKMISSAK US SONUCUMUZU 0 YAPIYORUZ
    {
        usSonucu = 0.0;
    }
    else if(fonksiyon[i] == '\0') //NULL IFADEYE GELDIGIMIZ ICIN CIKMISSAK FONKSIYONUN SONUNA GELMISIZDIR INDISI ARTIRMIYORUZ US SONUCUNU 0 YAPIYORUZ
    {
        usSonucu = 0.0;
    }
    katsayi = 1; 

    if(fonksiyon[i]=='^') // US ISARETI OKURSAK
    {
        while(fonksiyon[i] != '+' && fonksiyon[i] != '-' && fonksiyon[i] != '\0')//FONKSIYONDAN + ,-,NULL OKUYANA KADAR OKUDUGUMUZ US DEGERININ DOUBLEYE CEVIRECEZ
        {
            if( fonksiyon[i]=='^') //WHILENIN ICINE ILK DEFA GIRIYORSA
            {
                if(rakammi(fonksiyon[i+1]) == false) // EGER ^ SEMBOLUNDEN SONRA RAKAM GELMIYORSA FONKSIYON YANLIS GIRILMISTIR EXIT
                {
                    fprintf(stderr,"Ussu '^' isaretinden sonra sayi yok\n");
                    exit(1);
                }
                char *str = &fonksiyon[i+1]; // ^ SEMBOLUNDEN SONRAKI RAKAMI strtod() FONKSIYONUYLA ret DEGISKENINE ATIYORUZ SONRA usSonucu NA ATIYORUZ
                char *ptr;
                double ret;
                ret = strtod(str, &ptr);
                usSonucu *= ret;
                i+=2; 
            }
            else //WHILENIN ICINE ILK GIRISI DEGILSE
            {
                char str[1] = {fonksiyon[i]}; 
                char *ptr;
                double ret;
                ret = strtod(str, &ptr);
                usSonucu*=katsayi; 
                usSonucu +=ret; 
                i++;
            }
            katsayi=10; 
        }
    }
    if(fonksiyon[i] == '+')
    {
       sonuc += usAl(x,usSonucu)*KatsayiSonucu;
       i++;
    }
    else if(fonksiyon[i] == '-')
    {
        sonuc -= usAl(x,usSonucu)*KatsayiSonucu;
        i++;
    }
    else if(fonksiyon[i] == '\0')
    {
        sonuc += usAl(x,usSonucu)*KatsayiSonucu;
    }
    katsayi = 1.0;
    KatsayiSonucu = 0.0;
    usSonucu = 0.0;
    k=i;
    }
    return sonuc;
}
double usAl(double taban, double us)
{
    double sonuc=1;
    if(us == 0)
    {
        return sonuc;
    }

    else
    {
        int i ;
        for(i=0;i<us;i++)
            sonuc *=taban;
    }
    return sonuc;
}
bool rakammi(char a)
{
    switch(a)
    {
    case'0':
    case'1':
    case'2':
    case'3':
    case'4':
    case'5':
    case'6':
    case'7':
    case'8':
    case'9':
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}
bool fonksiyonKontrol(char*p)
{


    int j=0;
    while(p[j] != '\0')//FONKSIYONDAKI DEGISKENIN X OLMASINI GARANTI EDIYOR
    {
        if(p[j] != '^' && p[j] != 'x' && rakammi(p[j]) != true && p[j] != '+' && p[j] != '-'  )
        {

            if(p[j] == '/' || p[j] == '*')
            {
               fprintf(stderr,"/ veya * ifadesi kullanilamaz\n");
               exit(1);
       	    }
            fprintf(stderr,"fonksiyon degiskenini x olarak girin \n");
            exit(1);
        }
        if(p[j] == 'x' && rakammi(p[j+1]) == true ) //x in katsayisinin x in solunda oldugunu kontrol ediyor
        {
            fprintf(stderr,"x lerin katsayilari x in solunda olmak zorunda !!!\n");
            exit(1);
        }
        j++;
    }
    return true;
}

