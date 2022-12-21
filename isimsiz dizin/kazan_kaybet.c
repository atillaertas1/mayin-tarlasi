#include<stdio.h>
#include"define.h"

int kazan_kaybet(int satir,int sutun)
{
    int x = 0;
    
    if(matris[satir][sutun] == -1)  //bomba varsa
    {
        x = LOSE;
    }    
    else
    {
        if(matris[satir][sutun] > 0)    // bomba degilse ve cevresinde bomba var ise
        {
            gizli_matris[satir][sutun] = ('0' + matris[satir][sutun]); //gizliden cikartip gercek degeri gosterdik
            x = oyun_bitti_mi_kontrol();
            x = DEVAM;
        }    
    }
    else
    {
        komsulari_goster(satir_sutun);
    }


    return x;
}
