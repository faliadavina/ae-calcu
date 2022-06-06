/*
 *	File          : pajak.c
 *	Deskripsi     : Body file untuk perhitungan pajak 
 */

#include "pajak.h"
#include <ctype.h>

/* Digunakan untuk membuat data yang dibutuhkan */
Pajak createData(int gaji, int gajiPasangan, int status, int jml_anak, char berpenghasilan){
	Pajak data; 
	data.gaji = gaji; 
	data.gajiPasangan = gajiPasangan; 
	data.status = status; 
	data.jml_anak = jml_anak; 
	data.berpenghasilan = berpenghasilan;
	
	return data;
}

/* Modul untuk menampilkan tampilan kalkulator pajak */
Pajak calcuPajak(Pajak data){
    int gaji = 0, status = 0, gajiPasangan = 0, jml_anak = 0;
	char berpenghasilan; 
    String tmp;
	 
	// Algoritma
	system("cls");
	printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n\xb3                         \xb3");
	printf("\n\xb3     Kalkulator Pajak    \xb3");
	printf("\n\xb3                         \xb3");
	printf("\n\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	printf("\n\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");
	
    /* Input Gaji */
    printf("\nMasukkan Penghasilan Anda (sebulan): Rp. ");
	scanf("%s", &tmp);
    if(!cekInputan(tmp)){
        system("cls");
        calcuPajak(data);
    }else{
        gaji = strtod(tmp, NULL);
    }

    /* Input Status */
	printf("\nMasukkan Status Anda (1. Menikah/ 2. Lajang)(1/2) : ");
	scanf("%s", &tmp);
    if(!cekInputan(tmp)){
        system("cls");
        calcuPajak(data);
    }else{
        status = strtod(tmp, NULL);
    }
    
    switch (status)
	{
	case 1:
		printf("\nApakah Pasangan anda Berpenghasilan ?(y/n) ");
		scanf("%s",&berpenghasilan);
        if(berpenghasilan == 'y' || berpenghasilan == 'Y'){
			/* Input Gaji Pasangan */
            printf("\nInput Penghasilan Pasangan Anda (sebulan): Rp. ");
			scanf("%s",&tmp);
            if(!cekInputan(tmp)){
                system("cls");
                calcuPajak(data);
            }else{
                gajiPasangan = strtod(tmp, NULL);
            }
            
            /* Input Jumlah Anak */
            printf("\nMasukkan Jumlah Anak Sedarah yang Dimiliki (Maksimal 3 Anak, Jika tidak ada input 0) : ");
            scanf("%d", &jml_anak);
            if(!cekInputan(tmp)){
                system("cls");
                calcuPajak(data);
            }else{
                jml_anak = strtod(tmp, NULL);
            }
            printf("\n\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");
        
        }else if(berpenghasilan == 'n' || berpenghasilan == 'N'){
            
            /* Input Jumlah Anak */
            printf("\nMasukkan Jumlah Anak Sedarah yang Dimiliki (Maksimal 3 Anak, Jika tidak ada input 0) : ");
            scanf("%s", &tmp);
            if(!cekInputan(tmp)){
                system("cls");
                calcuPajak(data);
            }else{
                jml_anak = strtod(tmp, NULL);
            }
            printf("\n\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");
            
		}else{
               system("cls");
               calcuPajak(data);
        }
        
        break; 
        
    case 2 : 
    	/* Input Jumlah Anak */
			printf("\nMasukkan Jumlah Anak Sedarah yang Dimiliki (Maksimal 3 Anak, Jika tidak ada input 0) : ");
	        scanf("%s", &tmp);
            if(!cekInputan(tmp)){
                system("cls");
                calcuPajak(data);
            }else{
                jml_anak = strtod(tmp, NULL);
            }
			printf("\n\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");	
		break; 
	default: 
		printf("Inputan yang kamu masukkan tidak valid!\n");
		system("pause");
		calcuPajak(data);
	}
	data=createData(gaji, gajiPasangan, status, jml_anak, berpenghasilan);
	
	return data;  
}

/* Digunakan untuk menghitung jumlah Gaji pertahun */
int totalGajiPertahun(int gaji){ 	
	return gaji*12;  
}

/* Digunakan untuk menghitung jumlah PTKP */
int hitungPTKP(Pajak data){
    int totalGaji, totalGajiPasangan, PTKP;

    totalGaji = totalGajiPertahun(data.gaji);
    totalGajiPasangan = totalGajiPertahun(data.gajiPasangan);
	
	if(totalGaji > 54000000){
		PTKP = 54000000;
    if(data.status == 1 && data.berpenghasilan == 'n'){
        PTKP+=4500000;
    }else if(data.status == 1 && data.berpenghasilan == 'y' || data.berpenghasilan == 'Y'){
        if(totalGajiPasangan > 54000000){
            PTKP+=54000000;
        }else{
            PTKP+=4500000;
        }
    }
    
    if(data.jml_anak == 1){
        PTKP+=4500000;
    }else if(data.jml_anak == 2){
        PTKP+=9000000;
    }else if(data.jml_anak >= 3){
        PTKP+=13500000;
    }
	}else{
		PTKP = 0;
	}
    return PTKP;
}

/* Digunakan untuk menghitung jumlah PKP */
int hitungPKP(Pajak data){
	int totalPKP, dataPTKP;
	dataPTKP = hitungPTKP(data);
	if(hitungPTKP(data) == 0 || totalGajiPertahun(data.gaji+data.gajiPasangan) <= dataPTKP){
		totalPKP = 0;
	}else{
		totalPKP = (totalGajiPertahun(data.gaji+data.gajiPasangan) - hitungPTKP(data));
	}
    return totalPKP;  
}

/* Digunakan untuk menghitung jumlah PPh */
int hitungPPh(Pajak data){
    int PPH, dataPKP; 
    dataPKP = hitungPKP(data);
    
    if (dataPKP < 50000000)
    {
        PPH = dataPKP*5/100;
    }else if (dataPKP >= 50000000 && dataPKP <= 250000000)
    {
        PPH = dataPKP*15/100;
    }else if (dataPKP >=250000000 && dataPKP <= 500000000)
    {
        PPH = dataPKP*25/100;
    }else{
        PPH = dataPKP*50/100;
    }
    return PPH;    
}

void mainPajak(){
	Pajak data;
	int GajiPertahun, jumlahPTKP, jumlahPKP, jumlahPPH;
	char ulang;
	do{
		data = calcuPajak(data);
		GajiPertahun = totalGajiPertahun(data.gaji+data.gajiPasangan);
		gotoxy(1,18);
		printf("\n\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
		printf("\n\xb3  Total Gaji : Rp. %d", GajiPertahun);
		gotoxy(31,20);
		printf("\xb3");
		jumlahPTKP = hitungPTKP(data);
		printf("\n\xb3  Total PTKP : Rp. %d", jumlahPTKP);
		gotoxy(31,21);
		printf("\xb3");
		jumlahPKP = hitungPKP(data);
		printf("\n\xb3  Total PKP  : Rp. %d", jumlahPKP);
		gotoxy(31,22);
		printf("\xb3");
		jumlahPPH = hitungPPh(data);
		printf("\n\xb3  Total PPh  : Rp. %d", jumlahPPH);
		gotoxy(31,23);
		printf("\xb3");
		printf("\n\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
		printf("\n\nUlang perhitungan pajak? (y/n): ");
		fflush(stdin);
		scanf("%c", &ulang);
	}while(ulang != 'n');  
	
}

boolean cekInputan(String c){
    int i;
	for(i=0; i<strlen(c); i++){
		if(!isdigit(c[i])){
			return false;
		}
	}
	return true;
}
