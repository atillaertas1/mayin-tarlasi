#include<stdio.h>
#include"define.h"
#include"mayinlari_yerlestirme.c"


void alt_tablo()
{

    int i, j, mayin;

    for(i = 0; i <= TABLO_BOYUTU + 1; i++) // 8x8 matris ve çevresindeki tüm birimlere 0 yerleştirdim
    {
        for(j = 0; j <= TABLO_BOYUTU + 1; j++)
        {
            matris[i][j] = 0;              // iki for ile tüm degerleri 0 a eşitledim          
        }
    }

    for(i = 0; i <= TABLO_BOYUTU + 1;i++) 
    {
        matris[i][0] = 1;                  // 8x8 matrisin en üst satirini 1 e eşitledim
        matris[i][TABLO_BOYUTU + 1] = 1;   // 8x8 matrisin en alt satirini 1 e eşitledim
    }

    for(j = 0; j <= TABLO_BOYUTU + 1;j++)
    {
        matris[0][j] = 1;                  // 8x8 matrisin en sol sutununu 1 e eşitledim
        matris[TABLO_BOYUTU + 1][0] = 1;   // 8x8 matrisin en sag sutununu 1 e eşitledim
    }
    mayin_sayisi = MAYIN_SAYISI;
    mayin_yerlestir();
}
