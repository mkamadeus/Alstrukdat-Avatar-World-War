/* File : queuelistlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* isi adalah integer */

#ifndef queuelistlinier_H
#define queuelistlinier_H

#include "boolean.h"
#define Nil NULL
typedef int infotype;
typedef struct qElmtq *address;
typedef struct qElmtq {
	infotype indeks;
	infotype info;
	address next;
} Elmtq;
typedef struct {
	address First;
	address Last;
	int MaxEl;
} Queue;

/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */

#define Indeks(P) (P)->indeks
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(Q) ((Q).First)
#define Last(Q) ((Q).Last)
#define MaxEl(Q) (Q).MaxEl

infotype Head(Queue Q);

infotype Tail(Queue Q);

infotype InfoHead(Queue Q);

infotype InfoTail(Queue Q);

address Alokasi (infotype X);
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

#endif