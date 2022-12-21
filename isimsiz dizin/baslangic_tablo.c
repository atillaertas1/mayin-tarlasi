#include<stdio.h>
#include"define.h"

void baslangic_tablo()
{
    int i,j;
    
    for(i = 0; i <= TABLO_BOYUTU + 1; i++)
    {
        for(j = 0; j<= TABLO_BOYUTU + 1; j++)
        {
            gizli_matris[i][j] = '#';
        }    
    }

    for(i = 0; i <= TABLO_BOYUTU + 1; i++)
    {
        gizli_matris[i][0] = '*';
        gizli_matris[i][TABLO_BOYUTU + 1] = '*';    
    }

    for(j = 0; j <= TABLO_BOYUTU + 1; j++)
    {
        gizli_matris[0][j] = '*';
        gizli_matris[TABLO_BOYUTU + 1][j] = '*';
    }


}
