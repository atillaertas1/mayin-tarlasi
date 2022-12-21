#include<stdio.h>
#include"define.h"


int oyun_bitti_mi_kontrol()
{
    int i,j;
    int sayac = 0;
    int durum;
    

    for(i = 1; i <= TABLO_BOYUT; i++)
    {
        for(j = 1; j <= TABLO_BOYUT; j++)
        {
            if(gizli_matris[i][j] == 'B')
            {
                if(matris[i][j] == -1)
                {
                    sayac++;              
                }
            }        
        }    
    }
    if(sayac == MAYIN_SAYISI)
    {
        durum = WIN;    
    }
    else
    {
        durum = DEVAM;    
    }
    
    return durum;
}
