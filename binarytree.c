/*
 *	File          : binarytree.c
 *	Deskripsi     : Body file dari ADT Stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "boolean.h"
#include "binarytree.h"
#include "stack.h"

/*******************************************************************/
/*  DEFINISI PRIMITIF ADT                                          */
/*******************************************************************/

/* 	Method ini digunakan untuk membuat node dalam Tree
	dan mengembalikan alamatnya */
addrTree createNode(infotype X){
	addrTree P = Nil;
	
	P = AlokasiNode(&P);
	if(P != Nil){
		Num(P) = X.num;
		Opr(P) = X.opr;
		isOpr(P) = X.isOpr;
		Left(P) = Nil;
		Right(P) = Nil;
	}
	return P;
}

/*	Method ini mengembalikan address hasil alokasi Tree */ 
addrTree AlokasiNode (addrTree *newNode){
	addrTree P;
	P = (addrTree)malloc(sizeof(ElmtNode));
	return P;
}

/*	Method untuk menampilkan elemen pada tree 
	I.S: Tree P dideklarasikan
	F.S: Info setiap node pada tree P ditampilkan */
void printInfoTree(addrTree P){
	if(P == Nil){
		return;
	}
	printInfoTree(Left(P));
	if(cekOperator(Opr(P))){
		printf("%c", Opr(P));
	}else{
		printf("%0.2f", Num(P));
	}
		
	printInfoTree(Right(P));
}

/*	Method ini digunakan untuk memasukkan ekspresi postfix
	ke dalam node binary tree dan mengembalikan alamatnya */
addrTree insertNode(String postfix){
	/* Kamus Data */
	addrTree t = nil;
	int i, idx;
	String tmp;
	double num, temp;
	char opr;
	
	/* Algoritma */
	for(i=strlen(postfix)-1; i>=0; i--){
		if(postfix[i] == ' '){
			continue;
		}
		
		// Memasukkan angka kedalam tree dimulai dari elemen postfix paling akhir
		if(cekAngka(postfix[i]) || postfix[i] == '.'){
			idx = 0;
			do{
				tmp[idx] = postfix[i];
				idx++;
				i--;
			}while((i>=0 && cekAngka(postfix[i]) || postfix[i] == '.'));
			tmp[idx] = '\0';
			
			// Ubah String menjadi double
			num = strtod(strrev(tmp), Nil);
			
			// Memasukkan elemen kedalam tree
			t = buildTree(createInfo(num, opr, false), t);
		}else{
			t = buildTree(createInfo(temp, postfix[i], true), t);
		}
	}
	return t;
}

/*	Method ini digunakan untuk membangun Tree yang terdiri
	dari node-node yang telah dibuat dan mengembalikan alamatnya */
addrTree buildTree(infotype X, addrTree root){
	addrTree newNode;
	
	if(root == Nil){
		return createNode(X);
	}
	
	// Jika anak kanan kosong atau berupa operator 
	// maka masukkan node baru menjadi anak kanan
	if(Right(root) == Nil || isOpr(Right(root))){
		newNode = buildTree(X, Right(root));
		if(newNode != Nil){
			Right(root) = newNode;
			return root;
		}
	}

	// Jika anak kiri kosong atau berupa operator 
	// maka masukkan node baru menjadi anak kiri	
	if(Left(root) == Nil || isOpr(Left(root))){
		newNode = buildTree(X, Left(root));
		if(newNode != Nil){
			Left(root) = newNode;
			return root;
		}
	}
	
	// Jika tidak memenuhi kriteria di atas return nil
	return Nil;
}

/*	Method ini digunakan untuk membuat info dalam node Tree dan
	mengembalikan tipe data infotype */
infotype createInfo(double num, char opr, boolean isOpr){
	infotype X;
	
	X.num = num;
	X.opr = opr;
	X.isOpr = isOpr;
	
	return X;
}

/* 	Melakukan operasi perhitungan matematis dari ekspresi aritmatika 
	binary tree dengan traversal in order dan mengembalikan hasil akhir 
	perhitungan */
double calculateTree (addrTree root){
	/* Kamus Data */
	double left, right;
	
	/* Algoritma */
	if(!isOpr(root)){
		return Num(root);
	}
	
	left = calculateTree(Left(root));
	
	right = calculateTree(Right(root));
	
	return calculate(Opr(root), left, right);
	
}

/*	Melakukan operasi perhitungan dari satu operasi matematika dan
	mengembalikan hasilnya */
double calculate (char opr, double left, double right){
	switch(opr){
		case '-':
			return left-right;
		case '+':
			return left+right;
		case ':':
			return left/right;
		case 'x':
			return left*right;
		case 'v':
			return pow(right, 1/left);
		case '^':
			return pow(left, right);
	}
}
