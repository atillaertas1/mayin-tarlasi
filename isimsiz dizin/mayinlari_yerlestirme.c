#include<stdio.h>
#include"define.h"
#include<time.h>
#include<sys/time.h>

void mayin_yerlestir()
{
    srand(time(NULL));
    mayin_sayisi = MAYIN_SAYISI;
    int i, j, k, p, satir, sutun;

    for(i = 1; i <= mayin_sayisi; i++)
    {
        satir = 1 + rand() % TABLO_BOYUTU; //burada randın TABLO_BOYUTU ile bölümünden kalanlara 1 ekleyip rastgele satir sayisi atadim // random gelen sayi en fazla TABLO_BOYUTU'ndan 1 eksik olacagi icin +1 ekledim
        sutun = 1 + rand() % TABLO_BOYUTU; //aynı sekilde sutuna da uyguladım
        //printf("%d%d",satir,sutun);
        if(matris[satir][sutun] == -1) //eger mayin varsa i yi bir azaltıp tekrar deger atamaya calistim yoksa mayin sayisi eksik cikabilir
        {
            i--;        
        }
        matris[satir][sutun] = -1; // mayin atamasi gerceklestirildi
        

        for(k = -1; k <= 1; k++)    // k -1,0,1 alabilir eger matris 3.satirda ise 2-3-4'üncü satırları bulmak icin
        {
            for(p = -1; p <= 1; p++)    //p -1,0,1 alabilir eger matris 2.sutunda ise 1-2-3'üncü sutunları bulmak icin
            {
                if(matris[i][j] == -1) //eger i ve j de mayin varsa
                {
                    if(matris[satir + k][sutun + p] != -1) //eger komsularında bomba yoksa
                    {
                        matris[satir + k][sutun + p]++;  //bomba göstergelerini 1 arttır
                    }                
                }
            }        
        }
    }

}
