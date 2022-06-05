/*
 *	File          : calculator.h
 *	Deskripsi     : header file untuk calculator 
 */
 
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string.h>
#include <windows.h>
#include "binarytree.h"
#include "stack.h"
#include "pajak.h"
#include "boolean.h"

/*  Method yang digunakan untuk menampilkan menu pada aplikas ae-calcu 
    I.S: Menu belum ditampilkan pada layar
    F.S: Menu ditampilkan pada layar */
void menu();

/*  Modul untuk menentukan posisi output 
    I.S: Posisi output tidak diatur
    F.S: Posisi output telah diatur */
void gotoxy(int x, int y);

/*  Modul untuk menampilkan tampilan menu pilihan fitur 
    I.S: Menu pilihan fitur belum ditampilkan
    F.S: Menu pilihan fitur telah ditampilka */
void mulai();

/*  Method untuk menjalankan fitur kalkulator dasar 
    I.S: Fitur kalkulator dasar belum dijalankan
    F.S: Fitur kalkulator dasar dijalankan */
void calcuDasar();

/*  Modul untuk menjalankan fitur kalkulator pajak 
    I.S: Fitur kalkulator pajak belum dijalankan 
    F.S: Fitur kalkulator pajak dijalankan */
void mainPajak();

/*  Method untuk menampilkan fitur bantuan 
    I.S: Teks bantuan belum tampil di layar
    F.S: Teks bantuan tampil di layar */
void bantuan();

/*  Method untuk menampilkan credit program
    I.S: Credit belum ditampilkan pada layar
    F.S: Credit ditampilkan pada layar */
void credits();

/*  Mengembalikan nilai true jika input user sesuai dengan aturan */
boolean cekInput(String input);

/*  Mengembalikan nilai true jika c berupa operator matematis */
boolean cekOperator(char c);

/*  Mengembalikan nilai true jika c berupa angka */
boolean cekAngka(char c);

/* Mengembalikan nilai true jika c berupa tanda kurung */
boolean cekParentheses(char c);

#endif
