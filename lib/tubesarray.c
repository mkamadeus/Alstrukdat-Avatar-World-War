
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "tubesarray.h"

void MakeEmpty (TabInt * T, int maxel)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    TI(*T) = (int *) malloc ((maxel+1)*sizeof(int));
    Neff(*T)=0;
    MaxEl(*T)=maxel;
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
	free (TI(*T));
	MaxEl(*T)=0;
	Neff(*T)=0;
}

void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    IdxType n, i = -1;
    while ( (n < 0) || (n > MaxEl(*T)) ) 
    {
        scanf("%d", &n);
    }

    if (n > 0) 
    {
        Neff(*T) = n;
        for (i = IdxMin; i < IdxMin+n; i++) 
        {
            scanf("%d\n", &(Elmt(*T,i)));
        }
    }
    else
    {
		MakeEmpty(&*T, MaxEl(*T));
	}
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    if (IsEmpty(T)) 
    {
        printf("[]");
    } 
    else 
    {
        IdxType i, l = GetLastIdx(T);
        printf("[%d", Elmt(T,IdxMin));
        for (i = IdxMin+1; i <= l; i++) 
        {
            printf(",%d", Elmt(T,i));
        }
        printf("]");
    }
}

IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    if (IsEmpty(T)) 
    {
		return IdxUndef;
	}

    IdxType i, l = GetLastIdx(T);
    for (i = IdxMin; i <= l; i++) 
    {
        if (Elmt(T,i) == X) 
        {
            return i;
        }
    }

    return IdxUndef;
}
