#include "boolean.h"
#include "arraytubes.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void makeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return (IdxMin);
}
IdxType getLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean isEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean isFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void bacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int i, N;
    scanf ("%d\n", &N);
    while (!(N >= 0 && N <= MaxNbEl(*T))) {
        scanf ("%d\n", &N);
    }
    for (i = 1; i <= N; i++) {
        scanf ("%d\n", &Elmt(*T,i));
    }
}
void bacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    int i, a;
    i = IdxMin;
    scanf ("%d\n", &Elmt(*T,i));
    while ((Elmt(*T,i) != (-9999)) && (i < IdxMax)) {
        i++;
        scanf ("%d\n", &Elmt(*T,i));
    }
}
void tulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    int i;
    if (Neff(T) == 0) {
        printf ("Tabel Kosong\n");
    }
    else {
        for (i = IdxMin; i <= Neff(T); i++) {
            printf ("[%d]", i);
            printf ("%d\n", Elmt(T,i));
        }
    }
}
void tulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    int i;
    printf ("[");
    for (i = 0; i <= Neff(T); i++) {
        if (i < Neff(T)) {
            printf ("%d,", Elmt(T,i));
        }
        else {
            printf ("%d", Elmt(T,i));
        }
    }
    printf ("]");
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    int i;
    i = IdxMin;
    if (IsEmpty) {
        return IdxUndef;
    }
    else {
        while (X != Elmt(T,i)) {
            i++;
        }
        if (X == Elmt (T, i)) {
            return i;
        }
        else {
            return IdxUndef;
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    int i;
    for (i = 0; i <= Neff(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}
TabInt inverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    int i, j, a;
    for (i = 0; i < (Neff(T)/2); i++) {
        for (j = Neff(T); j > (Neff(T)/2); j--) {
            a = Elmt(T, j);
            Elmt(T, j) = Elmt(T, i);
            Elmt(T, i) = a;
        }
    }
    return T;
}