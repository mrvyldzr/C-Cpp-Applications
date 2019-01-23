#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool kontrol(char*satir,int x);
bool icindemi(char*satir);
char* forToWhile(char*,FILE *fp);

struct yigin
{
    char *C;
    struct yigin *ptr;
};
int main(int argc,char**argv)
{
    char *giris = argv[1];
    char *cikis = argv[2];
    FILE * fp=fopen(giris,"r");
    FILE * fp1=fopen(cikis,"w");
    struct yigin *head = '\0';
    char okuyucu[256];
    char *gecici;
    int i;
    for(i = 0;i<=255;i++)
        okuyucu[i] = '\0';
    i=0;
    while(fgets(okuyucu, sizeof okuyucu, fp) != '\0') //fgets() dosyadan satir satir okuma yapar
    {
        i++;
        if(icindemi(okuyucu) && kontrol(okuyucu,i))
        {
            gecici = forToWhile(okuyucu,fp1);
            struct yigin *nptr = (struct yigin*)malloc(sizeof(struct yigin));
            nptr->C = gecici;
            if(head == '\0')
            {
                nptr->ptr = '\0';
                head = nptr;
            }
            else
            {
                struct yigin *gecici2 = head;
                nptr->ptr = gecici2;
                head = nptr;
            }
        }
        else if(okuyucu[0] == '}')
        {
            if(head != '\0')
            {
                struct yigin *gecici4 = (struct yigin*)malloc(sizeof(struct yigin));
                gecici4 = head;
                fprintf(fp1,"\n%s\n}\n",gecici4->C);
                head = head->ptr;
                free(gecici4->C);
                free(gecici4);
            }
            else
                fprintf(fp1,"}");
        }
        else
        {
            fprintf(fp1,"%s",okuyucu);
        }
        int m;
        for(m = 0;m<=255;m++)
            okuyucu[m] = '\0';
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}

bool kontrol(char* satir,int x)
{
    char mask[9] = {'f','o','r','(','A','B','C',')','{'};
    bool sonuc = true;
    int i =0;
    int maskI = 0;
    while(satir[i] != '\0' && satir[i] != '\n' && satir[i] != EOF)
    {
        if(i == 0 && satir[i] != 'f')
        {
            printf("%s\n",satir);
            printf("^");
            printf("\n %d.satir , f bekleniyor\n",x);
            sonuc = false;
            break;
        }
        else if(i == 1 && satir[i] != 'o')
        {
            printf("%s\n",satir);
            printf(" ^");
            printf("\n %d.satir , o bekleniyor\n",x);
            sonuc = false;
            break;
        }
        else if(i == 2 && satir[i] != 'r')
        {
            printf("%s\n",satir);
            printf("  ^");
            printf("\n %d.satir , r bekleniyor\n",x);
            sonuc = false;
            break;
        }
        else if(i == 3 && satir[i] != '(')
        {
            printf("%s\n",satir);
            printf(" ^");
            printf("\n %d.satir, ( bekleniyor\n",x);
            sonuc = false;
            break;
        }
        else if (mask[maskI] == 'A' || mask[maskI] == 'B' || mask[maskI] == 'C')
        {
            int j = i;
            int count = 0;
            char gecici = satir[i];
            if(mask[maskI] == 'A' || mask[maskI] == 'B')
            {
                while(gecici != ';')
                {
                    j++;
                    gecici = satir[j];
                    if(gecici == ')' || gecici == '\n' || gecici == '\0' || gecici == EOF)
                    {
                        printf("\n %s",satir);
                        printf("   ^");
                        printf("\n %d.satir, ; bekleniyor ",x);
                        return false;
                    }
                    count++;
                }
            }
            if(mask[maskI] == 'C')
            {
                while(gecici != ')')
                {
                    j++;
                    gecici = satir[j];
                    if(gecici == '\n' || gecici == '\0' || gecici == EOF)
                    {
                        printf("%s\n",satir);
                        printf("   ^");
                        printf("\n %d.satir, ) bekleniyor ",x);
                        return false;
                    }
                     count++;
                }
            }
            i+=count;
        }

        maskI++;
        if(maskI > 8)
        {
            printf("%s\n",satir);
            printf("\n %d.satir, 'for()'dan sonra fazla karakter girildi' ",x);
            return false;
        }
        i++;
    }
    return sonuc;
}
bool icindemi(char *satir)
{
    int i = 0;
    bool sonuc = false;
    while(satir[i] != '\n' && satir[i] != '\0' && satir[i] != EOF)
    {
        if(satir[i] == 'f' && satir[i+1] == 'o' && satir[i+2] == 'r')
            return true;
        i++;
    }
    return sonuc;
}
char* forToWhile(char*a,FILE *fp)
{
    int i = 4; //4 OLMASININ SEBEBI 'FOR(' KISMINI ATLAYIP DIREK 'A' YI OKUMAK ISTEMEMIZ
    int l = 0; //A,B,C,D DIZILERI ICIN KULLANILACAK
    int ilkNV=0;
    int ikiNV=0;
    int ilkP=0;
    char A[20] = {'\0'};
    char B[20] = {'\0'};
    char *C =(char*)malloc(20);
    int j ;
    for(j=0;j<=19;j++)
        C[j]='\0';
    while(a[i] != '\0' && a[i] != EOF)
    {
        if(a[i] == ';' && ilkNV == 0)
        {
            ilkNV = 1;
            l=0;
            i++; //NOKTALI VIRGULU ATLA
        }
        else if(a[i] == ';' && ikiNV == 0)
        {
            ikiNV = 1;
            l=0;
            i++; //NOKTALI VIRGULU ATLA
        }
        else if(a[i] == ')' && ilkP == 0)
        {
            ilkP = 1;
            l=0;
        }
        if(ilkNV != 1)
            A[l] = a [i];
        else if(ikiNV != 1)
            B[l] = a [i];
        else if(ilkP != 1)
            C[l] = a[i];
        l++;
        i++;
    }
    fprintf(fp,"\n%s\n",A);
    fprintf(fp,"while(%s)",B);
    if(a[i-2]=='{')
        fprintf(fp,"{\n");
    return C;
}
