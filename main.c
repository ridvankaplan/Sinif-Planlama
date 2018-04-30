#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//Ýkinci ogretimlerin birinci ogretimlerden sonraki kayit siralarini bulmak icin bu fonksiyonu kullanýyoruz
void kayit_yenile(char isim[1000][15],char soyisim[1000][15],char numara[1000][10],char kayit_sirasi[1000][5],char ogretim_turu[1000][5],int boyut,int ayni[4])
{
    int i,sayac=1,j,x=ayni[2];

    for(i=0; i<boyut; i++)
    {
        if(strcmp(numara[i],"-")==0)//Birinci ogretimlerin sayilarini buluyoruz
        {
            if(strcmp(ogretim_turu[i],"I")==0 || strcmp(ogretim_turu[i],"1")==0)
                sayac++;
        }
    }
    for(i=0; i<boyut; i++)
    {
        {

            if(strcmp(numara[i],"-")==0)
            {
                if(strcmp(ogretim_turu[i],"II")==0 || strcmp(ogretim_turu[i],"2")==0)
                {
                    for(j=0; j<boyut; j++)
                    {
                        int b[2][5];
                        itoa(sayac,&b[0],10);
                        if(strcmp(kayit_sirasi[j],b)==0)
                        {
                            char a[2][5];
                            itoa(x,&a[0],10);
                            strcpy(kayit_sirasi[j],a[0]);
                            x++;
                            sayac++;
                        }
                    }
                }
            }
        }

    }
}

//Ayni isimden öðrenci varsa fazla olanlarin bilgilerine X atiyoruz
void silme_islemi(char isim[1000][15],char soyisim[1000][15],char kayit_sirasi[1000][5],char ogretim_turu[1000][5],char numara[1000][10],int boyut,int ayni[4])
{
    int i,j;
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            if(i!=j && strcmp(isim[i],isim[j])==0 && strcmp(soyisim[i],soyisim[j])==0)
            {
                strcpy(isim[i],"X");
                strcpy(soyisim[i],"X");
                printf("%s %s %s\n",ogretim_turu[i],isim[j],soyisim[j]);
                if(strcmp(ogretim_turu[i],"I")==0)
                    ayni[1]++;
                if(strcmp(ogretim_turu[i],"II")==0)
                    ayni[2]++;
            }
        }
    }
    ayni[0]=ayni[1]+ayni[2];
}
void kayit_guncelleme(char isim[1000][15],char soyisim[1000][15],char kayit_sirasi[1000][5],char ogretim_turu[1000][5],char numara[1000][10],int boyut,int ayni[4])
{
    //Kayit sirasi 0 olanlara numaralarindan kayit siralarini cekip kayit siralarina atiyoruz
    int i;
    int numara1[boyut];
    for(i=0; i<boyut; i++)
    {
        numara1[i]=atoi(numara[i]);
        if(strcmp(kayit_sirasi[i],"0")==0)
        {
            itoa(numara1[i]%1000,&kayit_sirasi[i],10);
        }
    }
    for(i=0; i<boyut; i++)//Ayni kayittan olduðu için silinen yani ismine X atilan kayit kaydýrýlarak üstüne siradaki kayit yerleþiyor
    {
        if(strcmp(isim[i],"X")==0)
        {

            int j;
            for(j=i; j<boyut; j++)
            {
                strcpy(isim[j],isim[j+1]);
                strcpy(soyisim[j],soyisim[j+1]);
                strcpy(ogretim_turu[j],ogretim_turu[j+1]);
                int gecici=atoi(numara[j+1]);
                gecici--;
                itoa(gecici,&numara[j+1],10);
                strcpy(numara[j],numara[j+1]);
                gecici=atoi(kayit_sirasi[j+1]);
                gecici--;
                itoa(gecici,&kayit_sirasi[j+1],10);
                strcpy(kayit_sirasi[j],kayit_sirasi[j+1]);
                strcpy(isim[j+1],"X");
                strcpy(soyisim[j+1],"X");

            }

        }

    }

    int x=0,y=0;
    for(i=0; i<boyut-ayni[1]-ayni[2]; i++)
    {
        if(atoi(numara[i])/100000!=17)
            x++;
    }
    for(i=0; i<boyut-ayni[1]-ayni[2]; i++)
    {
        if(strcmp(ogretim_turu[i],"1")==0 && atoi(numara[i])/100000==17)
            y++;
    }
    int j=1;

    for(i=x+y; i<boyut-ayni[1]-ayni[2]; i++)
    {
        int a=i-x+1;
        char dizi[2][5];
        itoa(a,&dizi[0],10);
        strcpy(kayit_sirasi[i],dizi[0]);
        j++;
    }

}
//Numarasi olmayan ogrencilere numara veriyoruz
void numara_atama(char kayit_sirasi[1000][5],char ogretim_turu[1000][5],char numara[1000][10],int boyut)
{
    int i;
    for(i=0; i<boyut; i++)
    {
        if(strcmp("-",numara[i])==0)
        {
            strcpy(numara[i],"170");
            if(strcmp(ogretim_turu[i],"I")==0)
            {
                strcpy(ogretim_turu[i],"1");
                strcat(numara[i],"1");
            }
            else   if(strcmp(ogretim_turu[i],"1")==0)
            {
                strcpy(ogretim_turu[i],"1");
                strcat(numara[i],"1");

            }
            if(strcmp(ogretim_turu[i],"II")==0)
            {
                strcpy(ogretim_turu[i],"2");
                strcat(numara[i],"2");
            }
            else  if(strcmp(ogretim_turu[i],"2")==0)
            {
                strcpy(ogretim_turu[i],"2");
                strcat(numara[i],"2");
            }
            if(strlen(kayit_sirasi[i])==3)
            {
                strcat(numara[i],kayit_sirasi[i]);
            }
            if(strlen(kayit_sirasi[i])==2)
            {
                strcat(numara[i],"0");
                strcat(numara[i],kayit_sirasi[i]);
            }
            if(strlen(kayit_sirasi[i])==1)
            {
                strcat(numara[i],"00");
                strcat(numara[i],kayit_sirasi[i]);
            }
        }
        else if(strcmp(ogretim_turu[i],"I")==0)
        {
            strcpy(ogretim_turu[i],"1");
        }

        if(strcmp(ogretim_turu[i],"II")==0)
        {
            strcpy(ogretim_turu[i],"2");
        }
    }
}
//Ogrenci numarasina gore listeyi siraliyoruz
void numara_siralama(char isim[1000][15],char soyisim[1000][15],char kayit_sirasi[1000][5],char ogretim_turu[1000][5],char numara[1000][10],int boyut)
{
    int i,j;

    for(i=0; i<boyut-1; i++)
    {
        for(j=i+1; j<boyut; j++)
        {
            if(strcmp(numara[i],numara[j])>0)
            {
                char gecici[5][20];

                strcpy(gecici[0],numara[i]);
                strcpy(numara[i],numara[j]);
                strcpy(numara[j],gecici[0]);

                strcpy(gecici[0],isim[i]);
                strcpy(isim[i],isim[j]);
                strcpy(isim[j],gecici[0]);

                strcpy(gecici[0],soyisim[i]);
                strcpy(soyisim[i],soyisim[j]);
                strcpy(soyisim[j],gecici[0]);

                strcpy(gecici[0],kayit_sirasi[i]);
                strcpy(kayit_sirasi[i],kayit_sirasi[j]);
                strcpy(kayit_sirasi[j],gecici[0]);

                strcpy(gecici[0],ogretim_turu[i]);
                strcpy(ogretim_turu[i],ogretim_turu[j]);
                strcpy(ogretim_turu[j],gecici[0]);
            }
        }
    }
}
//Dolu birinci ve ikinci ogretim siniflarina göre sýnýf dosyasý oluþturuyoruz
void azsinif_dosyaya_yazdir(int birinci_ogr,int ikinci_ogr,int kapasite2[7],char isim[1000][15],char soyisim[1000][15],char kayit_sirasi[1000][5],char ogretim_turu[1000][5],char numara[1000][10],int boyut)
{
    char gecici[5][10];
    int a=0,x=1;
    int i,j=0;
    for(i=0; i<birinci_ogr; i++)
    {
        a=0;
        FILE *yeni_dosya;

        itoa(i+1,&gecici[0],10);
        strcpy(gecici[1],"Enaz_Sinif");
        strcat(gecici[1],gecici[0]);
        strcat(gecici[1],"ogr1.txt");
        yeni_dosya=fopen(gecici[1],"w+");

        while(j<boyut)
        {
            if(strcmp(ogretim_turu[j],"1")==0)
            {
                if(kapasite2[i]!=a)
                {
                    fprintf(yeni_dosya,"%d-  %7s %15s %10s %3s %5s\n",x,numara[j],isim[j],soyisim[j],kayit_sirasi[j],ogretim_turu[j]);
                    x++;
                    a++;
                }
                else
                    goto loop;
            }
            j++;
        }
loop:
        fclose(yeni_dosya);
    }
    x=1;
    j=0;
    for(i=0; i<ikinci_ogr; i++)
    {
        a=0;
        FILE *yeni_dosya;

        itoa(i+1,&gecici[0],10);
        strcpy(gecici[1],"Enaz_Sinif");
        strcat(gecici[1],gecici[0]);
        strcat(gecici[1],"ogr2.txt");
        yeni_dosya=fopen(gecici[1],"w+");
        while(j<boyut)
        {
            if(strcmp(ogretim_turu[j],"2")==0)
            {
                if(kapasite2[i]!=a)
                {
                    fprintf(yeni_dosya,"%d-  %7s %15s %10s %3s %5s\n",x,numara[j],isim[j],soyisim[j],kayit_sirasi[j],ogretim_turu[j]);
                    x++;
                    a++;
                }
                else
                    goto dongu;
            }
            j++;
        }
dongu:
        fclose(yeni_dosya);
    }
}

int main()
{
    clock_t basla;
    basla=clock();

    FILE *dosya;
    dosya=fopen("Ogrenci-Listesi.txt","r+");
    int i=0,j,kontrol,boyut=0;
    char isim[1000][15],soyisim[1000][15],numara[1000][10];
    char kayit_sirasi[1000][5],ogretim_turu[1000][5];
    int ayni[4];
    //Txt dosyasindan bilgileri okuyoruz
    while(!feof(dosya))
    {
        fscanf(dosya,"%s %s %s %s %s",&numara[i],&isim[i],&soyisim[i],&kayit_sirasi[i],&ogretim_turu[i]);
        i++;
    }
    boyut=i;

    printf("Ismi 2 Defa Gecen Ogrencilerin Isimleri Silinmistir\n\nIsimler :\n");

    silme_islemi(isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut,ayni);

    printf("\n2'den Fazla ismi tekrar eden ogrenci yoktur\n\n");

    kayit_yenile(isim,soyisim,numara,kayit_sirasi,ogretim_turu,boyut,ayni);

    numara_atama(kayit_sirasi,ogretim_turu,numara,boyut);

    numara_siralama(isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut);

    kayit_guncelleme(isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut,ayni);




    int birinci_ogretim=0,ikinci_ogretim=0;
    int kontrol1[boyut];
    //Kac tane birinci ve ikinci oðretim oðrencisi var onu buluyoruz
    for(i=0; i<boyut-ayni[1]-ayni[2]; i++)
    {
        kontrol1[i]=(atoi(numara[i])/1000)%10;
        if(kontrol1[i]==1)
            birinci_ogretim++;
        if(kontrol1[i]==2)
            ikinci_ogretim++;
    }
    printf("\n\nbirinci ogretim %d ikinci ogretim %d\n\n",birinci_ogretim,ikinci_ogretim);
    int birinci_ogretim1=birinci_ogretim;
    int ikinci_ogretim2=ikinci_ogretim;
    int birinci_ogretim3=birinci_ogretim;
    int ikinci_ogretim3=ikinci_ogretim;
    int sinif_sayisi;
    int birinci_ogr=0,ikinci_ogr=0;
    printf("Sinif Sayisini Giriniz: ");
    scanf("%d",&sinif_sayisi);

    int kapasite[sinif_sayisi];
    int kapasite1[sinif_sayisi];
    int kapasite2[sinif_sayisi];
    for(i=0; i<sinif_sayisi; i++)
    {
        printf("%d.Sinifin kapasitelerini giriniz: ",i+1);
        scanf("%d",&kapasite[i]);
    }
    printf("\nDersi alan ogrenci sayisi : 1. ogretim:  %d kisi 2. ogretim:  %d kisi vardir\n\n",birinci_ogretim,ikinci_ogretim);
    int gecici1;
    for(i=0; i<sinif_sayisi-1; i++)//Sinif kapasitelerini buyukten kucuge siraliyoruz
    {
        for(j=i+1; j<sinif_sayisi; j++)
        {
            if(kapasite[i]<kapasite[j])
            {
                gecici1=kapasite[j];
                kapasite[j]=kapasite[i];
                kapasite[i]=gecici1;
            }
        }
    }
    for(i=0; i<sinif_sayisi; i++)
    {
        kapasite1[i]=kapasite[i];
        kapasite2[i]=kapasite[i];
    }
    for(i=0; i<sinif_sayisi; i++)
        printf("%d\n",kapasite[i]);
    for(i=0; i<sinif_sayisi; i++)
    {
        while(1)
        {
            birinci_ogretim1--;
            kapasite[i]--;
            if(kapasite[i]==0)
                break;
            if(birinci_ogretim1==0)
                break;
        }
        if(birinci_ogretim1==0)
            break;
    }
    for(i=0; i<sinif_sayisi; i++)
    {
        if(kapasite[i]!=kapasite2[i])
            birinci_ogr++;
    }
    for(i=0; i<sinif_sayisi; i++)
    {
        while(1)
        {
            ikinci_ogretim2--;
            kapasite1[i]--;
            if(kapasite1[i]==0)
                break;
            if(ikinci_ogretim2==0)
                break;
        }
        if(ikinci_ogretim2==0)
            break;
    }
    for(i=0; i<sinif_sayisi; i++)
    {
        if(kapasite1[i]!=kapasite2[i])
            ikinci_ogr++;
    }
    printf("En az dagilim : 1. ogretim - ");
    for(i=0; i<sinif_sayisi; i++)
        printf("%d ",kapasite2[i]-kapasite[i]);

    printf("  2. ogretim - ");
    for(i=0; i<sinif_sayisi; i++)
        printf("%d ",kapasite2[i]-kapasite1[i]);
    printf("\n%d %d\n\n",birinci_ogr,ikinci_ogr);

    azsinif_dosyaya_yazdir(birinci_ogr,ikinci_ogr,kapasite2,isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut);

    //esitsinif_dosyaya_yazdir(birinci_ogretim,birinci_ogr,ikinci_ogr,sinif_sayisi,isim,soyisim,kayit_sirasi,ogretim_turu,numara);
    printf("Tum ogrenciler yerlestirilmistir\n");
    int secim;
    while(1)
    {
Loop1:
        printf("Yeni ogrenci kayiti yapmak istiyormusunuz?(Evet icin 1 Hayir icin herhangi bir tus a basiniz: ");
        scanf("%d",&secim);
        printf("\n");
        if(secim==1)
        {
            printf("Ogrenci adi: ");
            scanf("%s",&isim[boyut-ayni[0]]);
            printf("Ogrenci soyadi: ");
            scanf("%s",&soyisim[boyut-ayni[0]]);
            printf("Ogrencinin ogretim turu: ");
            scanf("%s",&ogretim_turu[boyut-ayni[0]]);
            for(i=0; i<boyut-ayni[0]; i++)
            {
                if(strcmp(isim[boyut-ayni[0]],isim[i])==0 && strcmp(soyisim[boyut-ayni[0]],soyisim[i])==0)
                {
                    printf("Ayni isim ve soyisimde ogrenci vardir lutfen baska bir isim ve soyismi giriniz\n");
                    goto Loop1;
                }
            }
            strcpy(numara[boyut-ayni[0]],"-");
            int x=boyut-ayni[0];
            printf("%d\n",x);
            int kayit=atoi(kayit_sirasi[x-1])+1;
            itoa(kayit,&kayit_sirasi[x],10);
            numara_atama(kayit_sirasi,ogretim_turu,numara,boyut);
            kayit_guncelleme(isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut,ayni);
            boyut++;
        }
        else
            break;
    }

    azsinif_dosyaya_yazdir(birinci_ogr,ikinci_ogr,kapasite2,isim,soyisim,kayit_sirasi,ogretim_turu,numara,boyut-ayni[1]-ayni[2]);
    for(j=1; j<boyut-ayni[1]-ayni[2]; j++)
        printf("%d  %7s %15s %10s %3s %5s\n",j,numara[j],isim[j],soyisim[j],kayit_sirasi[j],ogretim_turu[j]);

    fclose(dosya);
    clock_t dur;
    dur=clock();
    printf("Programin Calismasi %d Saniye Surdu \n",(dur-basla)/CLOCKS_PER_SEC);
    return 0;
}
