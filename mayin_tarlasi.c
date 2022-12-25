#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//define
#define TABLO_BOYUTU 8 //MATRISIN BOYUTUNU BELIRLEME 8X8
#define MAYIN_SAYISI 3  //MAYIN SAYISINI BELIRLEME
#define WIN 1   //KAZANMA
#define LOSE -1  //KAYBETME
#define DEVAM 0

//globaller
char char_matris[TABLO_BOYUTU + 2][TABLO_BOYUTU + 2];   // char matrisi
int reel_matris[TABLO_BOYUTU + 2][TABLO_BOYUTU + 2];   // int matrisi
int mayin_sayisi, y = 0;    //y mayin sayaci olarak kullanilmistir
int bayrak_sayaci = 0;    //bayraklari tutan degisken

//fonksiyonlar
void tablo_hatlari(void);
void baslangic_tablosu(void);
void reel_matrisi_yazdir(void);
void char_matrisi_yazdir(void);
void mayinlari_yerlestir(void);
void mayin_tarlasi_kesifcisi(int satir,int sutun);
int konum_gosterici(int satir,int sutun);
int win_or_lose_kontrol(void);



//main
void sta()
{
    int satir, sutun, ilerleme, yeniden;
    char action;//Hangi harf

    printf("MAYIN TARLASI AKTIF BASARILAR!!!\n");
    tablo_hatlari();
    baslangic_tablosu();
    do
    {
        char_matrisi_yazdir();
        printf("\n");
        printf("1-Konum acma: k,satir,sutun\n2-Bayrak koyma: b,satir,sutun\n");
        scanf("%c,%d,%d", &action, &satir, &sutun);
        printf("\n");

        if(action == 'k')
        {
            ilerleme = konum_gosterici(satir, sutun);
        }
        else if(action == 'b')
        {
            if(mayin_sayisi > bayrak_sayaci)
            {
                bayrak_sayaci++;
                char_matris[satir][sutun] = 'B';
                ilerleme = win_or_lose_kontrol();
            }
        }
        /*else if(action == 'i')
        {
            if(bayrak_sayaci > 0)
            {
                bayrak_sayaci--;
            }
            char_matris[satir][sutun] = '#';
            ilerleme = konum_gosterici(satir, sutun);
        }*/


        if(ilerleme == LOSE)
        {
            printf("GAME OVER!!!!!\n");
            reel_matrisi_yazdir();
            printf("Oyunu tekrar oynamak ister misin? [1-Evet][2-Hayir] \n");
            scanf("%d", &yeniden);
            switch(yeniden)
            {
                case 2:
                    printf("See you!!\n");
                    return 0;
                    break;
                case 1:
                    bayrak_sayaci = 0;
                    ilerleme = DEVAM;
                    tablo_hatlari();
                    baslangic_tablosu();
                    break;
                default:
                    printf("Yanlis deger girdin!!\n");
                    break;
            }
        }

        if(ilerleme == WIN)
        {
            printf("Vay be ne oyundu ama!\n");
            reel_matrisi_yazdir();
            printf("Oyunu tekrar oynamak ister misin? [1-Evet][2-Hayir] \n");
            scanf("%d", &yeniden);
            switch(yeniden)
            {
                case 2:
                    printf("See you!!\n");
                    return 0;
                    break;
                case 1:
                    bayrak_sayaci = 0;
                    ilerleme = DEVAM;
                    tablo_hatlari();
                    baslangic_tablosu();
                    break;
                default:
                    printf("Yanlis deger girdin!!!!\n");
                    break;
            }
        }
    }
    while(1);
    return 0;

}

//tablo hatlari
void tablo_hatlari(void)
{
    int i, j, mayin_sayisi;


    for(i = 0; i <= TABLO_BOYUTU + 1; i++) // 8x8 matrisin cevresindekileri de 0 yapmak icin 10 kere donduruyoruz +1 o yüzden
    {
        for(j = 0; j <= TABLO_BOYUTU + 1; j++)
        {
            reel_matris[i][j] = 0;
        }
    }

    for(i = 0; i <= TABLO_BOYUTU; i++)
    {
        reel_matris[i][0] = 1;                  // birinci sutundaki degerleri 1 yapar
        reel_matris[i][TABLO_BOYUTU + 1] = 1;     // son sutundaki degerleri 1 yapar
    }

    for(j = 0; j <= TABLO_BOYUTU; j++)
    {
        reel_matris[0][j] = 1;                  //birinci satirdaki tüm degerleri 1 yapar
        reel_matris[TABLO_BOYUTU + 1][j] = 1;     //son satirdaki tüm degerleri 1 yapar
    }
    mayin_sayisi = MAYIN_SAYISI; //ilerde mayin sayisini arttirip azaltacagimiz icin simdiden degisken bir deger mayin sayimizi atiyoruz
    mayinlari_yerlestir();  //mayinlari yerlestirme fonksiyonunu

}
//karakter matrisini olusturma
void baslangic_tablosu() //tablo_hatlari yapimizin aynisi sadece aynisini karakter matrisine de atiyoruz kullanicinin degerleri görmesini istemeyiz :D
{
    int i, j;

    for(i = 0; i <= TABLO_BOYUTU + 1; i++)
    {
        for(j = 0; j <= TABLO_BOYUTU + 1; j++)
            char_matris[i][j]= '#';
    }

    for(i = 0; i <= TABLO_BOYUTU; i++)
    {
        char_matris[i][0] = '*';                // birinci sutundaki degerleri * yapar
        char_matris[i][TABLO_BOYUTU + 1] = '*';   // son sutundaki degerleri * yapar
    }

    for(j = 0; j<= TABLO_BOYUTU; j++)
    {
        char_matris[0][j] = '*';                //birinci satirdaki tüm degerleri * yapar
        char_matris[TABLO_BOYUTU + 1][j] = '*';   //son satirdaki tüm degerleri * yapar
    }

}

//karakter matrisi yazdirma
void char_matrisi_yazdir(){
    int i, j;

    printf("\n");

    for(i = 1; i <= TABLO_BOYUTU; i++){     //tablonun en üstüne 1den baslayarak 8e kadar degerleri yazdirma
        printf("%3d", i);
    }
    printf("\n");


    for(i = 1; i <= TABLO_BOYUTU; i++){
        printf("~~~");
    }
    printf("\n");


    for(i = 1; i <= TABLO_BOYUTU; i++){         //8x8 matrisi karakter matrisi ile ekrana yazdiriyoruz (8x8 degisebilir)
        for(j = 1; j <= TABLO_BOYUTU; j++){
            printf("%3c", char_matris[i][j]);
        }
        printf("  ||%d", i);	                //tablonun sonuna 1den 8e kadar yazdirma
        printf("\n");
    }


    for( i = 1; i <= TABLO_BOYUTU; i++){        //tablonun en altina susleme
        printf("___");
    }
}

//arka plan matrisi
void reel_matrisi_yazdir(){
    int i, j;

    printf("\n");

    for(i = 1; i <= TABLO_BOYUTU; i++){         //tablonun ustune 1den 8e kadar yazdirir
        printf("%3d",i);
    }
    printf("\n");


    for(i = 1; i <= TABLO_BOYUTU; i++){
        printf("---");
    }
    printf("\n");


    for(i = 1; i <= TABLO_BOYUTU; i++){
        for(j = 1; j <= TABLO_BOYUTU; j++){
            printf("%3d", reel_matris[i][j]);   //matrisin arka planda donen degerlerini yazdirir
        }
        printf(" ||%d", i);
        printf("\n");
    }


    for(i = 1; i <= TABLO_BOYUTU; i++){
        printf("___");
    }
    printf("\n");
}


void mayinlari_yerlestir()
{
    srand(time(NULL)); //random
    int i, j, k, p, satir, sutun;
    mayin_sayisi = MAYIN_SAYISI;


    for(i = 1; i <= mayin_sayisi; i++)
    {
        satir = 1 + rand() % TABLO_BOYUTU;//bir sayinin tablo boyutu ile olan bolumu en fazla tablo boyutu - 1 olabilir tum tablo boyutunun oldugu satirda olsun diye +1
        sutun = 1 + rand() % TABLO_BOYUTU;//bir sayinin tablo boyutu ile olan bolumu en fazla tablo boyutu - 1 olabilir tum tablo boyutunun oldugu sutunda olsun diye +1

        if(reel_matris[satir][sutun] == -1) //eger bu degerlerde bomba varsa asagidaki bir azaltir donguyu tekrarlatir
        {
            i--;
        }

        reel_matris[satir][sutun]= -1; //mayin yerlestirildi

        //mayinin cevresindeki degerleri 1 arttirma  (k,p -1,0,1 degerleri alabilir bunlari satir ve sutuna uygulayarak cevresini kontrol ettiriyoruz)
        for(k = -1; k <= 1; k++){
            for(p = -1; p <= 1; p++){
                if(reel_matris[satir][sutun] == -1){ //Bombaysa
                    if(reel_matris[satir+k][sutun+p] != -1) // komsusu bomba degilse
                    {
                        reel_matris[satir+k][sutun+p] += 1; //cevresindeki bomba sayisini 1 arttir
                    }
                }
            }
        }
    }
}

//oyunu kontrol etme
int win_or_lose_kontrol()
{
    int i, j, durum , y = 0;

    //tablodaki bayrak koyulan yerler gercekten mayin mi onu sayiyor
    for(i = 1; i <= TABLO_BOYUTU; i++){
        for(j = 1; j <= TABLO_BOYUTU; j++){
            if(char_matris[i][j] == 'B'){
                if(reel_matris[i][j] == -1){
                    y ++; //mayin sayaci
                }
            }
        }
    }

    if(y == MAYIN_SAYISI){//eger mayin sayaci mayin sayisina esitse
        durum=WIN;
    }

    else{//degilse oyuna devam
        durum=DEVAM;
    }
    return durum;
}

void mayin_tarlasi_kesifcisi(int satir, int sutun) {
    int i, j;


    char_matris[satir][sutun] = '0' + (char)reel_matris[satir][sutun];//gercek degerleri karakter matrisine atiyoruz
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {

            if (reel_matris[satir + i][sutun + j] > 0 && char_matris[satir + i][sutun + j] == '#')//komsusu mayinli degil ve acik degil ise
            {
                char_matris[satir + i][sutun + j] = '0'+ (char)reel_matris[satir + i][sutun + j];//komsuyu goster
            }

            else if (reel_matris[satir + i][sutun + j] == 0 && char_matris[satir + i][sutun + j] == '#')//sayi 0 sa ve kapaliysa
            {
                mayin_tarlasi_kesifcisi(satir + i, sutun + j);//komsuya gec ve ayni fonksiyonu birdaha uygula
            }
        }
    }
}


int konum_gosterici(int satir, int sutun)
{
    int x=0;
    if (reel_matris[satir][sutun] == -1)//eger bombaysa
    {
        x=LOSE;
    }

    else if (reel_matris[satir][sutun] > 0)//komsusu mayinliysa
    {
        char_matris[satir][sutun] = ('0' + (char)reel_matris[satir][sutun]);//ac
        x=DEVAM;
    }
    else{//bossa
        mayin_tarlasi_kesifcisi(satir, sutun);//komsularini acarak ilerle
    }

    return x; //lose or devam dondur
}
