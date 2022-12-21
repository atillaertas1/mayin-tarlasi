#include<stdio.h>
#include"define.h"
#include"alt_tablo.c"
#include"baslangic_tablo.c"
#include"tabloyu_yazdir.c"
#include"mayinlari_yerlestirme.c"

int main()
{
    printf("mayin tarlasi activated!\n");
    alt_tablo();
    baslangic_tablo();   

    
    do
    {
        tabloyu_yazdir(); 
        printf("\n");
        printf("LUTFEN VERILEN DEGERLERI c(SATIR,SUTUN), b(SATIR,SUTUN) veya e(SATIR,SUTUN) PARANTEZSIZ BIR SEKILDE GIRIN !!!!\n");
        scanf("%c,%d,%d",&giris,&satir,&sutun);
        printf("\n");
        if(giris == 'c'){
            ilerleme = kazan_kaybet(satir,sutun);
        }
        else{
            if(giris  == 'b')
            {
                if(mayin_sayisi > d_sayaci)
                {
                    d_sayaci ++;
                    matris[satir][sutun] ='B'
                }
            }
        }
        else{
            if(giris == 'e')
            {
                if(d_sayaci > 0)
                {
                    d_sayaci--;  
                }
            gizli_matris[satir][sutun] = '#';
            ilerleme = kazan_kaybet(satir,sutun);
            }

        }
        
        if(ilerleme == LOSE)
        {
            printf("birdahaki sefere!\n");
            tabloyu_yazdir();
        }
        
        printf("Bir oyuna daha var misin? [1-EVET] [2-HAYIR]");
        scanf("%d",&yenidena);
        
        switch(yenidena)
        {
            case 1:
                d_sayaci = 0;
                ilerleme = DEVAM;
                    alt_tablo();
                    baslangic_tablo();
                break;

            case 2:
                printf("SEN BILIRSIN :kızgın_surat:");
                break;
            
            default:
                printf("duzgun deger gir!!!\n");
        }

        if(ilerleme == WIN)
        {
            printf("TEBRIKLER\n");
            tabloyu_yazdir();

        printf("Bir oyuna daha var misin? [1-EVET] [2-HAYIR]");
        scanf("%d",&yenidena);
        
        switch(yenidena)
        {
            case 1:
                d_sayaci = 0;
                ilerleme = DEVAM;
                    alt_tablo();
                    baslangic_tablo();
                break;

            case 2:
                printf("SEN BILIRSIN :kızgın_surat:");
                break;
            
            default:
                printf("duzgun deger gir!!!\n");
        }
            
        }
        
        
        
    }while(1);
    

    return 0;
}
