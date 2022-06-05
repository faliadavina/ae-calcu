/*
 *	File          : binarytree.h
 *	Deskripsi     : Header file dari ADT Stack
 */
 
#ifndef binarytree_H
#define binarytree_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************* MAKRO-MAKRO BERPARAMETER **************/

#define Nil NULL
#define Info(P) (P)->info
#define Num(P) (P)->info.num
#define Opr(P) (P)->info.opr
#define isOpr(P) (P)->info.isOpr
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next


/************* DEKLARASI TYPE SEBAGAI ATRIBUT DATA ADT *************/

typedef char String[50];

typedef struct{
	double num;			// Untuk menampung angka numerik
	char opr;			// Untuk menampung operator matematis
	boolean isOpr;		// Penanda bahwa info dalam node berupa operator
}infotype;
typedef struct tElmtNode *addrTree;
typedef struct tElmtNode {
	infotype info;
	addrTree left;
	addrTree right;
} ElmtNode;

/*******************************************************************/
/*                      DEFINISI PRIMITIF ADT                      */
/*******************************************************************/

/* 	Method ini digunakan untuk membuat node dalam Tree
	dan mengembalikan alamatnya */
addrTree createNode(infotype X);

/*	Method ini mengembalikan address hasil alokasi Tree */ 
addrTree AlokasiNode (addrTree *newNode);

/*	Method untuk menampilkan elemen pada tree 
	I.S: Tree P dideklarasikan
	Info setiap node pada tree P ditampilkan */
void printInfoTree(addrTree P);

/*	Method ini digunakan untuk memasukkan ekspresi postfix
	ke dalam node binary tree dan mengembalikan alamatnya */
addrTree insertNode(String postfix);

/*	Method ini digunakan untuk membangun Tree yang terdiri
	dari node-node yang telah dibuat dan mengembalikan alamatnya */
addrTree buildTree(infotype X, addrTree root);

/*	Method ini digunakan untuk membuat info dalam node Tree dan
	mengembalikan tipe data infotype */
infotype createInfo(double num, char opr, boolean isOpr);

/* 	Melakukan operasi perhitungan matematis dari ekspresi 
	aritmatik binary tree dengan traversal in order dan mengembalikan
	hasil akhir perhitungan */
double calculateTree (addrTree root);

/*	Melakukan operasi perhitungan dari satu operasi natematika dan
	mengembalikan hasilnya */
double calculate (char opr, double left, double right);

#endif
