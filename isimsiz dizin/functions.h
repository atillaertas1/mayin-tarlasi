

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
