# include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau lebih Blank */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata */
{
    /* KAMUS LOKAL*/
    int i;

    /* ALGORITMA */
    i = 1;
    while ((CC != MARK) && (CC != BLANK) && (i <= NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}