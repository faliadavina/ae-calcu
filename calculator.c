/*
 *	File          : calculator.c
 *	Deskripsi     : Body file untuk calculator 
 */
 
 #include "calculator.h"

/*  Method yang digunakan untuk menampilkan menu pada aplikasi ae-calcu 
    I.S: Menu belum ditampilkan pada layar
    F.S: Menu ditampilkan pada layar */
void menu(){
	printf("             ae - calcu\n");
	printf(" _________________________________ \n");
	printf("|                                 |\n");
	printf("|              Mulai              |\n");
	printf("|             Bantuan             |\n");
	printf("|             Credits             |\n");
	printf("|              Exit               |\n");
	printf("|                                 |\n");
	printf("|_________________________________|\n");
	//printf("+---------------------------------+\n");
	printf("\nMasukkan Pilihan Anda (1-4) ");
}

/*  Modul untuk menentukan posisi output 
    I.S: Posisi output tidak diatur
    F.S: Posisi output telah diatur */
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*  Modul untuk menampilkan tampilan menu pilihan fitur 
    I.S: Menu pilihan fitur belum ditampilkan
    F.S: Menu pilihan fitur telah ditampilkan */
void mulai(){
	/* Kamus Data */
	int pilihanCalcu;
	
	system("cls");
	printf("             ae - calcu\n");
	printf(" _________________________________\n");
	printf("|               MENU              |\n");
	printf("|_________________________________|\n");
	printf("|                                 |\n");
	printf("|         Kalkulator Dasar        |\n");
	printf("|         Kalkulator Pajak        |\n");
	printf("|             Kembali             |\n");
	printf("|                                 |\n");
	printf("+---------------------------------+\n");
	printf("\nMasukkan Pilihan Anda (1-3) ");
	scanf("%d", &pilihanCalcu);
	switch (pilihanCalcu)
	{
	case 1:
		calcuDasar();
		break;
	case 2:
		mainPajak();
		break;
	case 3:
		menu();
		break;
	default:
		printf("Inputan yang kamu masukkan tidak valid!\n");
		system("pause");
		mulai();
	}
}

/*  Method untuk menampilkan fitur bantuan 
    I.S: Teks bantuan belum tampil di layar
    F.S: Teks bantuan tampil di layar */
void bantuan(){
	char kembali;
	system("cls");
	printf("                     ae - calcu\n");
	printf(" ____________________________________________________\n");
	printf("|                      BANTUAN                       |\n");
	printf("|____________________________________________________|\n");
	printf("|===================== BANTUAN ======================|\n");
	printf("|[1] Gunakan 'Kalkulator Dasar' untuk meghitung      |\n");
	printf("|    ekspresi matematika                             |\n");
	printf("|    Simbol - Simbol yang ada pada kalkulator umum : |\n");
	printf("|    1. 0 - 9 berarti angka dari 0 'nol' sampai 9    |\n");
	printf("|    2. '(' berarti kurung buka                      |\n");
	printf("|    3. ')' berarti kurung tutup                     |\n");
	printf("|    4. '+' berati pertambahan                       |\n");
	printf("|    5. '-' berarti pengurangan                      |\n");
	printf("|    6. 'x' berarti perkalian                        |\n");
	printf("|    7. ':' berarti pembagian                        |\n");
	printf("|    8. '^' berarti pangkat                          |\n");
	printf("|    9. 'v' berarti akar pangkat                     |\n");
	printf("|    10. Cara menggunakan akar pangkat yaitu dengan  |\n");
	printf("|    ketentuan [pangkat+v+angka yang akan diakarkan] |\n");
	printf("|    contoh : 3v8 (dibaca akar pangkat 3 dari 8)     |\n");
	printf("|[2] Gunakan 'Kalkulator Pajak' untuk menghitung     |\n");
	printf("|    pajak penghasilan.                              |\n");
	printf("|    Pengguna diarahkan untuk dapat menginput data : |\n");
	printf("|    1. Gaji Per-tahun                               |\n");
	printf("|    2. Status Perkawinan                            |\n");
	printf("|    3. Jumlah anak sedarah yang dimiliki            |\n");
	printf("+----------------------------------------------------+\n");
	printf("Kembali? (y/n)");
	scanf("%s", &kembali);
	if (kembali == 'y')
	{
		menu();
	}else if(kembali == 'n'){
		bantuan();
	}else{
		printf("Inputan tidak valid!\n");
		system("pause");
	}
	
}
/*  Method untuk menampilkan credit program
    I.S: Credit belum ditampilkan pada layar
    F.S: Credit ditampilkan pada layar */
void credits(){
	char kembali;
	system("cls");
	printf("             ae - calcu\n");
	printf(" _________________________________\n");
	printf("|              CREDITS            |\n");
	printf("|_________________________________|\n");
	printf("|                                 |\n");
	printf("|          Amelia Nathasa         |\n");
	printf("|      Falia Davina Gustaman      |\n");
	printf("|           Nayara Saffa          |\n");
	printf("|                                 |\n");
	printf("| @D4 - Teknik Informatika POLBAN |\n");
	printf("+---------------------------------+\n");
	printf("Kembali? (y/n)");
	scanf("%s", &kembali);
	if (kembali == 'y')
	{
		menu();
	}else{
		printf("Inputan tidak valid!\n");
		system("pause");
		credits();
	}
}

/*******************************************************************/
/*  OPERASI CALCULATOR DASAR                                       */
/*******************************************************************/

/*  Method untuk menjalankan fitur kalkulator dasar 
    I.S: Fitur kalkulator dasar belum dijalankan
    F.S: Fitur kalkulator dasar dijalankan */
void calcuDasar(){
	// Kamus Data
	String input, postfix;
	addrTree t;
	char ulang = 'y';
	double result;
	
	do{
		// Algoritma
		system("cls");
		printf("\t\t\t      Kalkulator Dasar\n");
		
		printf("\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
		printf("\n\t\t                                             ");
		printf("\n\t\t                                             ");
		printf("\n\t\t                                             ");
		printf("\n\t\t                                             ");
		printf("\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
		printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
		printf("\n\t\t    \xb3 1 \xb3   \xb3 2 \xb3   \xb3 3 \xb3   \xb3 + \xb3   \xb3 - \xb3");
		printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
		printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
		printf("\n\t\t    \xb3 4 \xb3   \xb3 5 \xb3   \xb3 6 \xb3   \xb3 x \xb3   \xb3 / \xb3");
		printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
		printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
		printf("\n\t\t    \xb3 7 \xb3   \xb3 8 \xb3   \xb3 9 \xb3   \xb3 ^ \xb3   \xb3 v \xb3");
		printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
		printf("\n\n\t\t\t    \xda\xc4\xc4\xc4\xbf\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
		printf("\n\t\t\t    \xb3 0 \xb3\t    \xb3 ( \xb3   \xb3 ) \xb3");
		printf("\n\t\t\t    \xc0\xc4\xc4\xc4\xd9\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
		printf("\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
		fflush(stdin);
		gotoxy(21, 4); scanf("%s", &input);
		
		if (cekInput(input) == false) {
			input[0] = '\0'; // Kosongkan string
			gotoxy(21, 7); system("pause");
			system("cls");
			calcuDasar();
		}
		InfixToPostfix(input, postfix);
		t = insertNode(postfix);
		result = calculateTree(t);
		
		// Jika hasil kalkulasi berupa desimal
		if(ceil(result) > result){
			gotoxy(21, 5); printf("= %0.2f", result);
		}else{
			gotoxy(21, 5); printf("= %0.f", result);
		}
		gotoxy(70, 10); printf("Ulang perhitungan? (y/n): ");
		fflush(stdin);
		scanf("%c", &ulang);		
	}while(ulang != 'n');
	
}

/*  Mengembalikan nilai true jika input user sesuai dengan aturan */
boolean cekInput(String input){
    int i, j, length;
    boolean inputTrue = true, nextAngka = true;   // Buat mennetukan inputan selanjutnya harus angka atau bukan

    // Cek inputan awal dan akhir tidak boleh operator
    if(cekOperator(input[0]) == true || cekOperator(input[length-1]) == true){
        gotoxy(21, 5); printf("Inputan tidak sesuai!");
		gotoxy(21, 6); printf("[Terdapat operator di awal atau di akhir]");
        return false;
    }

    // Cek keseluruhan inputan
    for(i=0; i<strlen(input)-1; i++){
        if(cekParentheses(input[i]) == true){
        	
			// Menambahkan 0 di awal string, jika inputan indeks pertama negatif
			if(input[i] == '(' && input[i+1] == '-'){
				length = strlen(input);
        		for(j=length-1; j>=i+1; j--){
        			input[j+1] = input[j];
				}
				input[i+1] = '0';
				input[length+1] = '\0';
			}
            continue;
        }

        if (cekAngka(input[i]) == true)
        {
            nextAngka = false;
            continue;
        }

        // Cek apakah ada operator yang bersebelahan
        if((cekOperator(input[i]) == true) && (nextAngka == false)){
            nextAngka = true;
            // Cek apakah ada pembagian angka dengan nol
	        if(input[i] == ':' && input[i+1] == '0'){
	        	gotoxy(21, 5); printf("Inputan tidak sesuai!");
				gotoxy(21, 6); printf("[Terdapat pembagian dengan angka 0 (nol)]");
	        	return false;
			}
            continue;
        }else{
            gotoxy(21, 5); printf("Inputan tidak sesuai!");
            return false;
        }
    }
    
    return inputTrue;
}

/*  Mengembalikan nilai true jika c berupa operator matematis */
boolean cekOperator(char c){
    if(c == '^' || c == 'v' || c == 'x' || c == ':' || c == '+' || c == '-' || c == '.'){
        return true;
    }else{
        return false;
    }
}

/*  Mengembalikan nilai true jika c berupa angka */
boolean cekAngka(char c){
    if (c >= '0' && c <= '9'){
        return true;
    }else{
        return false;
    }
}

/* Mengembalikan nilai true jika c berupa tanda kurung */
boolean cekParentheses(char c){
    if(c == '(' || c == ')'){
        return true;
    }else{
        return false;
    }
}
