#include<stdio.h>
#include"define.h"

void tabloyu_yazdir()
{
    int i,j;

    for(i = 1; i <= TABLO_BOYUTU; i++)
    {
        printf("%3d",i);    
    }
    printf("\n");

    for(i = 1; i <= TABLO_BOYUTU; i++)
    {
        for(j = 1; j <= TABLO_BOYUTU; j++)
        {
            printf("%3c",gizli_matris[i][j]);
        }
        printf("  ||%d",i);
        printf("\n");
    }
    for(i = 1; i <= TABLO_BOYUTU; i++)
    {
        printf("---");    
    }
}
