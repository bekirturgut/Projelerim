#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Kart_Turleri
{
    char Kart_Tur[6];
    char Kart_Isim[6];
    int KartPuan;
} Desteler;

typedef struct Oyun
{
    char isim[20];
    int Oyuncu_Puani;
    int Kart_Sayisi;
    Desteler *Oyuncu_Kartlari;
} Oyuncular;

void Kartlari_Tanimlama (Desteler *Deste_Kartlari);
void Oyun_Kurma(Oyuncular *Players,Oyuncular *SISTEM,Desteler *Deste,int Oyuncu_Sayisi);
void Oyun_Devam(Oyuncular *Players,Oyuncular *SISTEM,Desteler *Deste,int Oyuncu_Sayisi);
void sleep_milisaniye(unsigned int milisaniye);

void sleep_milisaniye(unsigned int milisaniye) {
    usleep(milisaniye * 1000);
}

void Metin_Yazma(char Metin[100])
{
    int i;
    for(i=0;i<strlen(Metin);i++)
    {
        printf("%c",Metin[i]);
        sleep_milisaniye(20);
    }
}

void Kartlari_Tanimlama (Desteler *Deste_Kartlari)
{
    int i,j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<13; j++)
        {
            if(i==0)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Tur,"MACA");
            }
            if(i==1)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Tur,"SINEK");
            }
            if(i==2)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Tur,"KUPA");
            }
            if(i==3)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Tur,"KARO");
            }
            /////////////////////////////////////////////////////////
            if(j==0)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"AS");
                (Deste_Kartlari+(i*13+j))->KartPuan = 11;
            }
            if(j==1)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"KUPA");
                (Deste_Kartlari+(i*13+j))->KartPuan = 10;
            }
            if(j==2)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"VALE");
                (Deste_Kartlari+(i*13+j))->KartPuan = 10;
            }
            if(j==3)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"JOKER");
                (Deste_Kartlari+(i*13+j))->KartPuan = 10;
            }
            if(j==4)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"10");
                (Deste_Kartlari+(i*13+j))->KartPuan = 10;
            }
            if(j==5)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"9");
                (Deste_Kartlari+(i*13+j))->KartPuan = 9;
            }
            if(j==6)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"8");
                (Deste_Kartlari+(i*13+j))->KartPuan = 8;
            }
            if(j==7)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"7");
                (Deste_Kartlari+(i*13+j))->KartPuan = 7;
            }
            if(j==8)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"6");
                (Deste_Kartlari+(i*13+j))->KartPuan = 6;
            }
            if(j==9)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"5");
                (Deste_Kartlari+(i*13+j))->KartPuan = 5;
            }
            if(j==10)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"4");
                (Deste_Kartlari+(i*13+j))->KartPuan = 4;
            }
            if(j==11)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"3");
                (Deste_Kartlari+(i*13+j))->KartPuan = 3;
            }
            if(j==12)
            {
                strcpy((Deste_Kartlari+(i*13+j))->Kart_Isim,"2");
                (Deste_Kartlari+(i*13+j))->KartPuan = 2;
            }
        }
    }

}

void Oyun_Kurma(Oyuncular *Players,Oyuncular *SISTEM,Desteler *Deste,int Oyuncu_Sayisi)
{

    int random,i,j,isim;
    char Oyuncu_Isimi[19];

    strcpy(Players->isim,"SISTEM");
    SISTEM->Oyuncu_Puani = 0;
    SISTEM->Kart_Sayisi = 2;

    random = rand() % 52;

    strcpy(SISTEM->Oyuncu_Kartlari->Kart_Tur,(Deste+random)->Kart_Tur);
    strcpy(SISTEM->Oyuncu_Kartlari->Kart_Isim,(Deste+random)->Kart_Isim);
    SISTEM->Oyuncu_Kartlari->KartPuan = (Deste+random)->KartPuan;
    SISTEM->Oyuncu_Puani += SISTEM->Oyuncu_Kartlari->KartPuan;

    random = rand() % 52;

    strcpy((SISTEM->Oyuncu_Kartlari+1)->Kart_Tur,(Deste+random)->Kart_Tur);
    strcpy((SISTEM->Oyuncu_Kartlari+1)->Kart_Isim,(Deste+random)->Kart_Isim);
    (SISTEM->Oyuncu_Kartlari+1)->KartPuan = (Deste+random)->KartPuan;
    SISTEM->Oyuncu_Puani += SISTEM->Oyuncu_Kartlari->KartPuan;
    while(SISTEM->Oyuncu_Puani>21)
    {

        random = rand() % 52;

        SISTEM->Oyuncu_Puani = 0;
        SISTEM->Kart_Sayisi = 2;

        strcpy(SISTEM->Oyuncu_Kartlari->Kart_Tur,(Deste+random)->Kart_Tur);
        strcpy(SISTEM->Oyuncu_Kartlari->Kart_Isim,(Deste+random)->Kart_Isim);
        SISTEM->Oyuncu_Kartlari->KartPuan = (Deste+random)->KartPuan;
        SISTEM->Oyuncu_Puani += SISTEM->Oyuncu_Kartlari->KartPuan;

        random = rand() % 52;

        strcpy((SISTEM->Oyuncu_Kartlari+1)->Kart_Tur,(Deste+random)->Kart_Tur);
        strcpy((SISTEM->Oyuncu_Kartlari+1)->Kart_Isim,(Deste+random)->Kart_Isim);
        (SISTEM->Oyuncu_Kartlari+1)->KartPuan = (Deste+random)->KartPuan;
        SISTEM->Oyuncu_Puani += (SISTEM->Oyuncu_Kartlari+1)->KartPuan;
    }


    for(i=0; i<Oyuncu_Sayisi; i++)
    {
        char metin[50] = " Oyuncu Isim : ";
        printf("\n\t\t    %d.",i+1);
        Metin_Yazma(metin);
        scanf("%s",&Oyuncu_Isimi);
        strcpy((Players+i)->isim,Oyuncu_Isimi);

        random = rand() % 52;

        (Players+i)->Oyuncu_Puani = 0;
        (Players+i)->Kart_Sayisi = 2;

        strcpy((Players+i)->Oyuncu_Kartlari->Kart_Isim,(Deste+random)->Kart_Isim);
        strcpy((Players+i)->Oyuncu_Kartlari->Kart_Tur,(Deste+random)->Kart_Tur);
        (Players+i)->Oyuncu_Kartlari->KartPuan = (Deste+random)->KartPuan;
        (Players+i)->Oyuncu_Puani += (Players+i)->Oyuncu_Kartlari->KartPuan;

        random = rand() % 52;

        strcpy(((Players+i)->Oyuncu_Kartlari+1)->Kart_Isim,(Deste+random)->Kart_Isim);
        strcpy(((Players+i)->Oyuncu_Kartlari+1)->Kart_Tur,(Deste+random)->Kart_Tur);
        ((Players+i)->Oyuncu_Kartlari+1)->KartPuan = (Deste+random)->KartPuan;
        (Players+i)->Oyuncu_Puani += ((Players+i)->Oyuncu_Kartlari+1)->KartPuan;


    }
    char Metin[4][40] = {,"OYUN KURULUYOR LUTFEN BEKLEYINIZ.","OYUN KURULUYOR LUTFEN BEKLEYINIZ..","OYUN KURULUYOR LUTFEN BEKLEYINIZ...","OYUN KURULUYOR LUTFEN BEKLEYINIZ...."};
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            system("cls");
            printf("*******  **        ******     *****  **    ** **        ******     *****  **    ** \n");
            printf("******** **       ********   ******* **    ** **       ********   ******* **    ** \n");
            printf("**    ** **       **    **  **       **    ** **       **    **  **       **    ** \n");
            printf("**    ** **       **    ** **        **   **  **       **    ** **        **   **  \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("**    ** **       **    ** **        **   **  **    ** **    ** **        **   **  \n");
            printf("**    ** **       **    **  **       **    ** **    ** **    **  **       **    ** \n");
            printf("******** *******  **    **   ******* **    **  ******  **    **   ******* **    ** \n");
            printf("*******  ******** **    **    *****  **    **   ****   **    **    *****  **    ** \n");
            printf("-----------------------------------------------------------------------------------\n\n\n");
            printf("\t\t\t%s",Metin[j]);
            sleep_milisaniye(150);
        }
    }
}

void Oyun_Devam(Oyuncular *Players,Oyuncular *SISTEM,Desteler *Deste,int Oyuncu_Sayisi)
{
    int i,j,k,random;
    char secim;
    for(i=0; i<Oyuncu_Sayisi; i++)
    {
        while(1)
        {
            system("cls");
            printf("*******  **        ******     *****  **    ** **        ******     *****  **    ** \n");
            printf("******** **       ********   ******* **    ** **       ********   ******* **    ** \n");
            printf("**    ** **       **    **  **       **    ** **       **    **  **       **    ** \n");
            printf("**    ** **       **    ** **        **   **  **       **    ** **        **   **  \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("**    ** **       **    ** **        **   **  **    ** **    ** **        **   **  \n");
            printf("**    ** **       **    **  **       **    ** **    ** **    **  **       **    ** \n");
            printf("******** *******  **    **   ******* **    **  ******  **    **   ******* **    ** \n");
            printf("*******  ******** **    **    *****  **    **   ****   **    **    *****  **    ** \n");
            printf("-----------------------------------------------------------------------------------\n\n");


            printf("\n\t\t\t\t---------------------\n\t\t\t\t| SISTEM (PUAN : %?) |\n\t\t\t\t---------------------\n\t\t\t\tKARTLAR ===>");
            printf(" %s |",SISTEM->Oyuncu_Kartlari->Kart_Isim);
            for(j=1; j<SISTEM->Kart_Sayisi; j++)
            {
                printf(" %? |");
            }
            if((Players+i)->Oyuncu_Puani<=21)
            {
                printf("\n\n\n\t\t\t\t");
                for(k=0;k<strlen((Players+i)->isim)+15;k++)
                {
                    printf("-");
                }
                printf("\n\t\t\t\t| %s (PUAN : %d) |\n\t\t\t\t",(Players+i)->isim,(Players+i)->Oyuncu_Puani);
                for(k=0;k<strlen((Players+i)->isim)+15;k++)
                {
                    printf("-");
                }
                printf("\n\t\t\t\tKARTLAR ===>");
                for(j=0; j<(Players+i)->Kart_Sayisi; j++)
                {
                    printf(" %s |",((Players+i)->Oyuncu_Kartlari+j)->Kart_Isim);
                }
                printf("\n\n\n\t\t\t\t----------------\n\t\t\t\t| 1-) Kart Cek |\n\t\t\t\t| 2-) KAL      |\n\t\t\t\t----------------\n\t\t\t\t SECIM YAP : ");
                scanf("%c",&secim);
                if(secim=='2')
                {
                    break;
                }
                else if(secim=='1')
                {
                    random = rand() % 52;
                    (Players+i)->Kart_Sayisi ++;
                    (Players+i)->Oyuncu_Kartlari = realloc((Players+i)->Oyuncu_Kartlari,sizeof(Desteler)*(Players+i)->Kart_Sayisi);
                    strcpy(((Players+i)->Oyuncu_Kartlari+((Players+i)->Kart_Sayisi-1))->Kart_Tur,(Deste+random)->Kart_Tur);
                    strcpy(((Players+i)->Oyuncu_Kartlari+((Players+i)->Kart_Sayisi-1))->Kart_Isim,(Deste+random)->Kart_Isim);
                    ((Players+i)->Oyuncu_Kartlari+((Players+i)->Kart_Sayisi-1))->KartPuan = (Deste+random)->KartPuan;
                    if(((Players+i)->Oyuncu_Kartlari-2)->Kart_Isim == 'AS')
                    {
                        (Players+i)->Oyuncu_Puani += 1;
                    }
                    else
                    {
                        (Players+i)->Oyuncu_Puani += (Deste+random)->KartPuan;
                    }
                }
                sleep(1);
            }
            else if((Players+i)->Oyuncu_Puani>21)
            {
                printf("\n\n\n\t\t\t\t");
                for(k=0;k<strlen((Players+i)->isim)+15;k++)
                {
                    printf("-");
                }
                printf("\n\t\t\t\t| %s (PUAN : %d) |\n\t\t\t\t",(Players+i)->isim,(Players+i)->Oyuncu_Puani);
                for(k=0;k<strlen((Players+i)->isim)+15;k++)
                {
                    printf("-");
                }
                printf("\n\t\t\t\tKARTLAR ===>");
                for(j=0; j<(Players+i)->Kart_Sayisi; j++)
                {
                    printf(" %s |",((Players+i)->Oyuncu_Kartlari+j)->Kart_Isim);
                }
                printf("\n\n\t\tKAYBETTIN\n\t\t2SN SONRA SIRADAKI OYUNCUYA GECILECEK\n\n");
                sleep(2);
                break;
            }

        }
    }
    while(1)
    {
            system("cls");
            printf("*******  **        ******     *****  **    ** **        ******     *****  **    ** \n");
            printf("******** **       ********   ******* **    ** **       ********   ******* **    ** \n");
            printf("**    ** **       **    **  **       **    ** **       **    **  **       **    ** \n");
            printf("**    ** **       **    ** **        **   **  **       **    ** **        **   **  \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
            printf("**    ** **       **    ** **        **   **  **    ** **    ** **        **   **  \n");
            printf("**    ** **       **    **  **       **    ** **    ** **    **  **       **    ** \n");
            printf("******** *******  **    **   ******* **    **  ******  **    **   ******* **    ** \n");
            printf("*******  ******** **    **    *****  **    **   ****   **    **    *****  **    ** \n");
            printf("-----------------------------------------------------------------------------------\n\n");
            printf("\t\t\t\t------------------\n\t\t\t\t| SISTEM OYNUYOR |\n\t\t\t\t------------------\n\n");

            printf("\n\t\t\t------------------\n\t\t\tSISTEM (PUAN : %d)\n\t\t\t------------------\n\t\t\tKARTLAR ===>",SISTEM->Oyuncu_Puani);
            for(j=0; j<SISTEM->Kart_Sayisi; j++)
            {
                printf(" %s |",(SISTEM->Oyuncu_Kartlari+j)->Kart_Isim);
            }
            if(SISTEM->Oyuncu_Puani<17)
            {
                sleep(1);
                random = rand() % 52;
                SISTEM->Kart_Sayisi ++;
                SISTEM->Oyuncu_Kartlari = realloc(SISTEM->Oyuncu_Kartlari,sizeof(Desteler)*SISTEM->Kart_Sayisi);
                strcpy((SISTEM->Oyuncu_Kartlari+(SISTEM->Kart_Sayisi-1))->Kart_Tur,(Deste+random)->Kart_Tur);
                strcpy((SISTEM->Oyuncu_Kartlari+(SISTEM->Kart_Sayisi-1))->Kart_Isim,(Deste+random)->Kart_Isim);
                (SISTEM->Oyuncu_Kartlari+(SISTEM->Kart_Sayisi-1))->KartPuan = (Deste+random)->KartPuan;
                if((SISTEM->Oyuncu_Kartlari-2)->Kart_Isim == 'AS')
                {
                    SISTEM->Oyuncu_Puani += 1;
                }
                else
                {
                    SISTEM->Oyuncu_Puani += (Deste+random)->KartPuan;
                }
            }
            else
            {
                for(i=0;i<Oyuncu_Sayisi;i++)
                {
                    printf("\n\n\n\t\t\t");
                    for(k=0;k<strlen((Players+i)->isim)+30;k++)
                    {
                        printf("-");
                    }
                    printf("\n\t\t\t| %s (PUAN : %d) ===> ",(Players+i)->isim,(Players+i)->Oyuncu_Puani);

                    if((Players+i)->Oyuncu_Puani >21) printf("KAYBETTI");
                    else if((Players+i)->Oyuncu_Puani < SISTEM->Oyuncu_Puani) printf("KAYBETTI");
                    else if((Players+i)->Oyuncu_Puani > SISTEM->Oyuncu_Puani) printf("KAZANDI");
                    else if((Players+i)->Oyuncu_Puani = SISTEM->Oyuncu_Puani) printf("BERABERE");

                    printf(" |\n\t\t\t");

                    for(k=0;k<strlen((Players+i)->isim)+30;k++)
                    {
                        printf("-");
                    }
                    printf("\n\t\t\t\tKARTLAR ===>");
                    for(j=0; j<(Players+i)->Kart_Sayisi; j++)
                    {
                        printf(" %s |",((Players+i)->Oyuncu_Kartlari+j)->Kart_Isim);
                    }
                    sleep(1);
                }
                printf("\n\n\n\n\t\t\tOYUN BITMISTIR 2SN SONRA SONLANDIRILACAK...");
                sleep(2);
                break;
            }

    }
}


int main()
{
    srand(time(NULL));

    int i,Oyuncu_Sayisi;
    Desteler *Deste;
    Deste = malloc(sizeof(Desteler)*52);

    Oyuncular *Players;
    Oyuncular *SISTEM;
    SISTEM = malloc(sizeof(Oyuncular));
    SISTEM->Oyuncu_Kartlari = malloc(sizeof(Desteler)*2);

    Kartlari_Tanimlama(Deste);
    printf("\t                          ********    ****\n");
    sleep_milisaniye(20);
    printf("\t                         **********  *****\n");
    sleep_milisaniye(20);
    printf("\t                                 **     **\n");
    sleep_milisaniye(20);
    printf("\t                                 **     **\n");
    sleep_milisaniye(20);
    printf("\t                          *********     **\n");
    sleep_milisaniye(20);
    printf("\t                         *********      **\n");
    sleep_milisaniye(20);
    printf("\t                         **             **\n");
    sleep_milisaniye(20);
    printf("\t                         **             **\n");
    sleep_milisaniye(20);
    printf("\t                         **********    ****\n");
    sleep_milisaniye(20);
    printf("\t                          ********    ******\n\n");
    sleep_milisaniye(20);
    printf("*******  **        ******     *****  **    ** **        ******     *****  **    ** \n");
    sleep_milisaniye(20);
    printf("******** **       ********   ******* **    ** **       ********   ******* **    ** \n");
    sleep_milisaniye(20);
    printf("**    ** **       **    **  **       **    ** **       **    **  **       **    ** \n");
    sleep_milisaniye(20);
    printf("**    ** **       **    ** **        **   **  **       **    ** **        **   **  \n");
    sleep_milisaniye(20);
    printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
    sleep_milisaniye(20);
    printf("*******  **       ******** **        ******   **       ******** **        ******   \n");
    sleep_milisaniye(20);
    printf("**    ** **       **    ** **        **   **  **    ** **    ** **        **   **  \n");
    sleep_milisaniye(20);
    printf("**    ** **       **    **  **       **    ** **    ** **    **  **       **    ** \n");
    sleep_milisaniye(20);
    printf("******** *******  **    **   ******* **    **  ******  **    **   ******* **    ** \n");
    sleep_milisaniye(20);
    printf("*******  ******** **    **    *****  **    **   ****   **    **    *****  **    ** \n");
    sleep_milisaniye(20);
    char Metin1[100] = "\n\n\t\t    HOSGELDINIZ OYUNCU SAYISINI GIRINIZ : ";
    Metin_Yazma(Metin1);
    scanf("%d",&Oyuncu_Sayisi);

    Players = malloc(sizeof(Oyuncular)*Oyuncu_Sayisi);

    for(i=0; i<Oyuncu_Sayisi; i++)
    {
        (Players+i)->Oyuncu_Kartlari = malloc(sizeof(Desteler)*2);
    }


    //   Kart Kontrol
    /*
    for(i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            printf("%s\t%s\t%d\n",(Deste+i*13+j)->Kart_Tur,(Deste+i*13+j)->Kart_Isim,(Deste+i*13+j)->KartPuan);
        }
        printf("\n\n");
    }
    scanf("%d");
    */


    Oyun_Kurma(Players,SISTEM,Deste,Oyuncu_Sayisi);
    Oyun_Devam(Players,SISTEM,Deste,Oyuncu_Sayisi);
    return 0;
}
