#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


#define BOYUT 8 
#define MAYİN 3
#define KAZANDİN 1   
#define KAYBETTİN -1  
#define DEVAM 0   


char tablo[BOYUT+2][BOYUT+2];    
int baslangic_tablo[BOYUT+2][BOYUT+2];   
int mayin_sayisi,y=0;    
int bayrak_sayaci = 0;


void alt_tablo_olusturma();
void tabloyu_baslatma();
void alt_tabloyu_bastirma();
void tabloyu_bastirma();
void mayin_yerlestirme();
int durum_kontrol();
void kesfet(int sutun,int kolon);
int tabloyu_ac(int sutun,int kolon);




int main(void)
{
  int sutun,kolon;
    int ilerleme;

    int yeniden;
    char action;
    printf("Mayin Tarlasi oyunumuza hosgeldiniz\n");
    alt_tablo_olusturma();
    tabloyu_baslatma();
    do
    {
        tabloyu_bastirma();
        printf("\n");
        printf("Lutfen su formatta giriniz: c,sutun,kolon veya d,sutun,kolon veya e,sutun,kolon\n");
        scanf("%c,%d,%d",&action,&sutun,&kolon);
        printf("\n");

        if(action == 'c')
        {

            ilerleme=tabloyu_ac(sutun,kolon);
        }
        else if(action == 'd')
        {
            if(mayin_sayisi >bayrak_sayaci)
            {
                bayrak_sayaci++;
                tablo[sutun][kolon]='D';
                ilerleme=durum_kontrol();
            }
        }
        else if(action == 'e')
        {
            if(bayrak_sayaci>0)
            {
                bayrak_sayaci--;
            }
            tablo[sutun][kolon]='#';
            ilerleme=tabloyu_ac(sutun,kolon);
        }


        if(ilerleme==KAYBETTİN)
        {
            printf("Arkadasim oyunu kaybettin \n");
            alt_tabloyu_bastirma();
            printf("Oyunu yendiden oynamak istiyorusunuz? [1-Evet][0-Hayir] \n");
            scanf("%d",&yeniden);
            switch(yeniden)
            {
            case 0:
                printf("Tesekk�rler Gorusuruz\n");
                return 0;
                break;
            case 1:
                bayrak_sayaci=0;
                ilerleme=DEVAM;
                alt_tablo_olusturma();
                tabloyu_baslatma();
                break;
            default:
                printf("Yanlis bir deger girdiniz\n");
                break;
            }
        }

        if(ilerleme==KAZANDİN)
        {
            printf("Bravo Harika bir is cikardin\n");
            alt_tabloyu_bastirma();
            printf("Oyunu yendiden oynamak istiyor musunuz? [1-Evet][0-Hayir] \n");
            scanf("%d",&yeniden);
            switch(yeniden)
            {
            case 0:
                printf("Oynadiginiz icin tesekkurler!\n");
                return 0;
                break;
            case 1:
                bayrak_sayaci=0;
                ilerleme=DEVAM;
                alt_tablo_olusturma();
                tabloyu_baslatma();
                break;
            default:
                printf("Yanlis bir deger girdiniz.\n");
                break;
            }

        }

    }
    while(1);
    return 0;

}

void alt_tablo_olusturma()
{
	int i,j,mayin_sayisi;


	
	for(i=0;i<=BOYUT+1;i++)
	{
		for(j=0;j<=BOYUT+1;j++)
		{
			baslangic_tablo[i][j]= 0;
		}
	}
	for(i=0;i<=BOYUT;i++)
	{
		baslangic_tablo[i][0]= 1;
		baslangic_tablo[i][BOYUT+1]= 1;
	}
	for(j=0;j<=BOYUT;j++)
	{
		baslangic_tablo[0][j]= 1;
		baslangic_tablo[BOYUT+1][j]= 1;
	}
    mayin_sayisi =MAYİN;
	mayin_yerlestirme();

}

void tabloyu_baslatma()
{
	int i,j;

	
	for(i=0;i<=BOYUT+1;i++)
	{
		for(j=0;j<=BOYUT+1;j++)

			tablo[i][j]= '#';
		}
	for(i=0;i<=BOYUT;i++)
		{
			tablo[i][0]= '*';
			tablo[i][BOYUT+1]= '*';
		}
	for(j=0;j<=BOYUT;j++)
		{
			tablo[0][j]= '*';
			tablo[BOYUT+1][j]= '*';
		}

}

void tabloyu_bastirma(){
	int i,j;

	printf("\n");
	
	for(i=1;i<=BOYUT;i++){
		printf("%3d",i);
	}
	printf("\n");

	
	for(i=1;i<=BOYUT;i++){
		printf("---");
	}
	printf("\n");

	
	for(i=1;i<=BOYUT;i++){
		for(j=1;j<=BOYUT;j++){
			printf("%3c",tablo[i][j]);
		}
		printf(" |%d",i);
		printf("\n");
	}

	
	for(i=1;i<=BOYUT;i++){
		printf("___");
	}
}

void alt_tabloyu_bastirma()
{
	int i,j;

	printf("\n");
	
	for(i=1;i<=BOYUT;i++){
		printf("%3d",i);
	}
	printf("\n");

	
	for(i=1;i<=BOYUT;i++){
		printf("---");
	}
	printf("\n");

	
	for(i=1;i<=BOYUT;i++){
		for(j=1;j<=BOYUT;j++){
			printf("%3d",baslangic_tablo[i][j]);
		}
		printf(" |%d",i);	
		printf("\n");
	}

	
	for(i=1;i<=BOYUT;i++){
		printf("___");
	}
	printf("\n");
}


void mayin_yerlestirme()
{
	srand(time(NULL)); 
	int i,j,k,p,sutun,kolon;
	mayin_sayisi = MAYİN;

		
		for(i=1;i<=mayin_sayisi;i++)
		{
			sutun=1+rand()%BOYUT;
			kolon=1+rand()%BOYUT;
			if(baslangic_tablo[sutun][kolon]== -1) i--;
			baslangic_tablo[sutun][kolon]= -1;
                            for(k=-1;k<=1;k++){
                                for(p=-1;p<=1;p++){
                                    if(baslangic_tablo[sutun][kolon]==-1){
                                    if(baslangic_tablo[sutun+k][kolon+p]!=-1)
                                    {
                                    baslangic_tablo[sutun+k][kolon+p]++;
                                    }
                            }
                        }
                    }

                }



        }









int durum_kontrol()
{
	int i,j,y=0,durum;
	for(i=1;i<=BOYUT;i++)
	{
        for(j=1;j<=BOYUT;j++)
        {
            if(tablo[i][j]=='D')
			{
                if(baslangic_tablo[i][j]==-1)
                {
                    y++;
                }
			}

        }
	}
	if(y==MAYİN)
	{
		durum=KAZANDİN;
	}
	else
		durum=DEVAM;

	return durum;
}

void kesfet(int sutun, int kolon) {
	int i, j;


	tablo[sutun][kolon] = '0' + baslangic_tablo[sutun][kolon];
  
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			
			if (baslangic_tablo[sutun + i][kolon + j] > 0 && tablo[sutun + i][kolon + j] == '#')
			{
				tablo[sutun + i][kolon + j] = '0'+ baslangic_tablo[sutun + i][kolon + j];
			}
			
			else if (baslangic_tablo[sutun + i][kolon + j] == 0 && tablo[sutun + i][kolon + j] == '#')
			{
				kesfet(sutun + i, kolon + j);
			}
		}
	}
}


int tabloyu_ac(int sutun, int kolon)
{
	int x=0;
    if (baslangic_tablo[sutun][kolon] == -1)
    {
    	x=KAYBETTİN;
    }
    else if (baslangic_tablo[sutun][kolon] > 0)
    {
        tablo[sutun][kolon] = ('0' + baslangic_tablo[sutun][kolon]);
    
        x=DEVAM;
	}
    else
    {
    	kesfet(sutun, kolon);
    }
    return x;
}




