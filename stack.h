/*
 *	File          : stack.h
 *	Deskripsi     : Header file dari ADT Stack
 */

#ifndef _stack_H
#define _stack_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/************* MAKRO-MAKRO BERPARAMETER **************/

#define nil NULL
#define info(p) (p)->info
#define prev(p) p->prev
#define top(s) (s).top

/************* DEKLARASI TYPE SEBAGAI ATRIBUT DATA ADT *************/

typedef char String[50];

typedef struct telmstack *addrStack;

typedef struct telmstack{
	char info;
	addrStack prev;
}tabstack;

typedef struct{
	addrStack top;
}stack;

/*******************************************************************/
/*                      DEFINISI PRIMITIF ADT                      */
/*******************************************************************/

/* Method ini berfungsi untuk membuat Stack
   I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil */
void createstack(stack *s);

/* Method ini mengirim sebuah address jika alokasi type Stack berhasil */
addrStack alokasi(char x);

/* Modul berfungsi untuk melakukan dealokasi/pengembalian address P
   I.S : P terdefinisi
   F.S : P dikembalikan ke sistem */
void dealokasi(addrStack p);

/* Method ini berfungsi untuk memasukkan info ke dalam stack. 
   I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama */
void push(stack *s, char x);

/* Method ini berfungsi untuk mengeluarkan elemen yang berada paling atas
   I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s) */
void pop(stack *s, char *x);

/* Method ini berfungsi untuk menampilkan data dalam stack mulai dari yang 
   paling bawah hingga yang paling atas.
   I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai 
         dengan bottom jika tidak kosong */
void cetakstack(stack s);

/* Modul ini digunakan untuk mengecek apakah stack kosong atau tidak. 
Modul ini akan mengirimkan true apabila stack kosong dan false jika tidak kosong */
boolean isstackempty(stack s);

/* Modul ini digunakan untuk mengkononversi ekspresi Infix ke Postfix
   I.S: String postfix belum terbentuk
   F.S: String postfix dari inputan user terbentuk */
void InfixToPostfix (String infix, String postfix);

/* Mengembalikan nilai prioritas dari suatu operator */
int priority(char x);

/* Mengembalikan nilai true, jika operator a memiliki 
   prioritas yang lebih rendah dibanding operator b */
boolean cekPriority(char a, char b);

#endif

