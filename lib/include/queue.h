/* File : queue.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* isi adalah integer */

#ifndef queue_H
#define queue_H

#include "boolean.h"
#define unDef -1
#define Max 10
typedef int infotype;
typedef int address;
typedef struct {
	infotype *T;
	address HEAD;
	int count;
	int maxElement;
} queue;

/* Definisi queue kosong: HEAD=Nil; TAIL=Nil. */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah queue, maka akses elemen : */

#define Head(Q) (Q).HEAD
#define Count(Q) (Q).count
#define Tail(Q) (Q).HEAD+(Q).count-1
#define infoHead(Q) (Q).T[(Q).HEAD]
#define infoTail(Q) (Q).T[((Q).HEAD+(Q).count-1)%(Q).maxElement]
#define maxEl(Q) (Q).maxElement

/* *** Kreator *** */
void createEmpty (queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
/* *** Destruktor *** */
void deAlokasi(queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* ********* Prototype ********* */
boolean isEmpty (queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean isFull (queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int nbElmt (queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */


/* *** Primitif Add/Delete *** */
void Add (queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (queue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

#endif
