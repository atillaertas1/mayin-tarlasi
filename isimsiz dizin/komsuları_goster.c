#include<stdio.h>
#include"define.h"

void komsuları_goster(int satir, int sutun)
{
    int i,j;
    gizli_matris[satir + 1][sutun + 1] = '0' + matris[satir + i][sutun + j];

    for(i = -1, i<= 1; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            if(matris[satir + i][sutun + j] > 0 && gizli_matris[satir + i][sutun + j] == '#')
            {
                gizli_matris[satir + 1][sutun + 1] = '0' + matris[satir + i][sutun + j];
            }
            else{
                if(matris[satir + i][sutun + j] == 0 && gizli_matris[satir + i][sutun + j] == '#')
            {
                komsuları_goster(satir + i,sutun + j);
            }            
            }
        }

    }

}
