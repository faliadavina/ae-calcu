/*
 *	File          : pajak.h
 *	Deskripsi     : Header file untuk perhitungan pajak 
 */
 
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "boolean.h"

/************* DEKLARASI TYPE SEBAGAI ATRIBUT DATA ADT *************/

typedef char String[50];
typedef struct{
    int gaji;
    int gajiPasangan;
    int status;
    int jml_anak;
    char berpenghasilan; 
}Pajak;

/*******************************************************************/
/*                      DEFINISI PRIMITIF ADT                      */
/*******************************************************************/

/*  Method ini digunakan untuk membuat data yang dibutuhkan dalam
    perhitungan pajak dan mengembalikan tipe data Pajak */
Pajak createData(int gaji, int gajiPasangan, int status, int jml_anak, char berpenghasilan);

/*  Method ini digunakan untuk melakukan input data dan melakukan
    operasi perhitungan pajak serta mengembalikan tipe data pajak */
Pajak calcuPajak(Pajak data);

/*  Method ini digunakan untuk menghitung jumlah Gaji pertahun 
    dan mengembalikan nilainya */
int totalGajiPertahun(int gaji);

/* Method ini digunakan untuk menghitung jumlah PTKP dan 
    mengembalikan nilainya */
int hitungPTKP(Pajak data);

/*  Method ini digunakan untuk menghitung jumlah PKP dan
    mengembalikan nilainya */
int hitungPKP(Pajak data);

/*  Method ini digunakan untuk menghitung jumlah PPh dan
    mengembalikan nilainya */
int hitungPPh(Pajak data);

/*  Method ini digunakan untuk menampilkan kalkulator pajak
    serta menampilkan hasil operasi perhitungannya */
void mainPajak();

/* Method ini digunakan untuk mengecek input*/
boolean cekInputan(String c);

