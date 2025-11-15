#include <stdio.h>
#include <string.h>

#define MAX_BIT 100

int pangkat_dua(int bil_input) {
    int hasil_pangkat = 1;
    for (int i = 0; i < bil_input; i++) {
        hasil_pangkat *= 2;
    }
    return hasil_pangkat;
}

//biner
void biner_ke_desimal(int bil_input) {
    int desimal = 0;
    int i = 0; 
    int bil_sisa;
    int input_awal = bil_input;

    while (bil_input != 0) {
        bil_sisa = bil_input % 10; 
        bil_input /= 10;      
        
        int nilai_posisi = pangkat_dua(i);
        desimal += bil_sisa * nilai_posisi;

        printf("Digit %d x 2^%d: %d x %d = %d\n", bil_sisa, i, bil_sisa, nilai_posisi, bil_sisa * nilai_posisi);
        i++; 
    }
    printf("_________________________+ \n");
    printf("Hasil Konversi: %d", desimal);
}

void biner_ke_oktal(char biner[]) {
    int panjang_bit = strlen(biner);
    int hasil_blok[MAX_BIT];
    int index_blok = 0;

    for (int i = panjang_bit - 1; i >= 0; i -= 3) {  //keseluruhan
        int nilai_dalam_blok = 0;
        int jumlah_nilai_blok = 0;
        
        printf("Blok %d: \n", index_blok + 1);
        for (int j = 0; j < 3; j++) {  //perblok
            int current_index = i-j;

            if (current_index >= 0) {
                int digit = biner[current_index] - '0';  //kovers char ke int
                nilai_dalam_blok = digit * pangkat_dua(j);  
                printf("%c x 2^%d: %d\n", biner[current_index], j, nilai_dalam_blok);
                jumlah_nilai_blok += nilai_dalam_blok;
            } else {
                printf("0 x 2^%d: 0\n", j);
            }
        } 
        printf("Jumlah = %d\n", jumlah_nilai_blok);
        printf("\n");

        hasil_blok[index_blok] = jumlah_nilai_blok;
        index_blok++;
    }
    printf("Hasil konversi: ");
    for (int j = index_blok - 1; j >= 0; j--) {
        printf("%d", hasil_blok[j]);
    }
}

void biner_ke_heksa(char biner[]) {
    int panjang_bit = strlen(biner);
    int hasil_blok[MAX_BIT];
    int index_blok = 0;

    for (int i = panjang_bit - 1; i >= 0; i -= 4) {  //keseluruhan
        int nilai_dalam_blok = 0;
        int jumlah_nilai_blok = 0;
        
        printf("Blok %d: \n", index_blok + 1);
        for (int j = 0; j < 4; j++) {  //perblok
            int current_index = i-j;

            if (current_index >= 0) {
                int digit = biner[current_index] - '0';  //kovers char ke int
                
                nilai_dalam_blok = digit * pangkat_dua(j); 
                printf("%c x 2^%d: %d\n", biner[current_index], j, nilai_dalam_blok);
                jumlah_nilai_blok += nilai_dalam_blok;
            } else {
                printf("0 x 2^%d: 0\n", j);
            }
        }

        char heksa_digit;  //konvers int ke char
        if (jumlah_nilai_blok < 10) {
            heksa_digit = jumlah_nilai_blok + '0';  //0=48
        } else {
            heksa_digit = jumlah_nilai_blok - 10 + 'A';  //A==65
        }
        printf("Jumlah dalam Desimal = %d\n", jumlah_nilai_blok);
        printf("Heksa = %c\n", heksa_digit); 
        printf("\n");

        hasil_blok[index_blok] = heksa_digit;
        index_blok++;
    }
    printf("Hasil konversi: ");
    for (int j = index_blok - 1; j >= 0; j--) {
        printf("%c", hasil_blok[j]);
    }
}

// desimal
void desimal_ke_biner(int bil_input) {
    int biner_array[MAX_BIT];
    int i = 0; 

    while (bil_input > 0) {
        int bil_sisa = bil_input % 2; 
        int nilai_sebelum_bagi = bil_input; 
        
        int hasil_bagi = bil_input / 2;

        printf("%d dibagi 2 = %d, Sisa: %d\n", nilai_sebelum_bagi, hasil_bagi, bil_sisa);
        
        bil_input = hasil_bagi; 
        biner_array[i] = bil_sisa; 
        i++; 
    }

    printf("Hasil Konversi: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", biner_array[j]);
    }
    printf("\n");
}

void desimal_ke_oktal(int bil_input) {
    int oktal_array[MAX_BIT];
    int i = 0; 
    int input_awal = bil_input;

    while (bil_input > 0) {
        int bil_sisa = bil_input % 8; 
        int hasil_bagi = bil_input / 8;
        
        printf("%d dibagi 8 = %d, Sisa: %d\n", bil_input, hasil_bagi, bil_sisa);
        bil_input = hasil_bagi;
        oktal_array[i] = bil_sisa; 
        i++; 
    }

    printf("Hasil Konversi: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", oktal_array[j]); 
    }
}

void desimal_ke_heksa(int bil_input) {
    char heksa_array[MAX_BIT];
    int i = 0; 

    while (bil_input > 0) {
        int bil_sisa = bil_input % 16; 
        int hasil_bagi = bil_input / 16;

        char heksa_digit;  //konvers int ke char
        if (bil_sisa < 10) {
            heksa_digit = bil_sisa + '0';  //0=48
        } else {
            heksa_digit = bil_sisa - 10 + 'A';  //A==65
        }

        printf("%d dibagi 16 = %d, Sisa: %d -> Heksa: %c\n", bil_input, hasil_bagi, bil_sisa, heksa_digit);
        bil_input = hasil_bagi;
        heksa_array[i] = heksa_digit;
        i++;
    }

    printf("Hasil Konversi: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", heksa_array[j]); 
    }
}
// oktal
int pangkat_delapan(int bil_input) {
    int hasil_pangkat = 1;
    for (int i = 0; i < bil_input; i++) {
        hasil_pangkat *= 8;
    }
    return hasil_pangkat;
}

void oktal_ke_desimal(int bil_input) {
    int desimal = 0;
    int i = 0; 
    int bil_sisa; 

    while (bil_input != 0) {
        bil_sisa = bil_input % 10;  
        int nilai_posisi = pangkat_delapan(i);
        int hasil_kali = bil_sisa * nilai_posisi;
        
        printf("Digit %d x 8^%d: %d x %d = %d\n", bil_sisa, i, bil_sisa, nilai_posisi, hasil_kali);
        desimal += bil_sisa * pangkat_delapan(i); 
        bil_input /= 10;
        i++; 
    }
    printf("_________________________+\n");
    printf("Hasil Konversi: %d", desimal);
}

void oktal_ke_biner(char oktal[]) {
    int panjang = strlen(oktal);
    char* kode_biner;

    for (int i = 0; i < panjang; i++) {
        int digit_oktal = oktal[i] - '0';  //konversi int ke char

        switch (digit_oktal) {
            case 0: kode_biner = "000"; break;
            case 1: kode_biner = "001"; break;
            case 2: kode_biner = "010"; break;
            case 3: kode_biner = "011"; break;
            case 4: kode_biner = "100"; break;
            case 5: kode_biner = "101"; break;
            case 6: kode_biner = "110"; break;
            case 7: kode_biner = "111"; break;
        }
        printf("Digit Oktal %c = %s\n", oktal[i], kode_biner);
    }

    printf("Hasil Konversi: ");
    for (int i = 0; i < panjang; i++) {
        int digit_oktal = oktal[i] - '0';
        switch (digit_oktal) {
            case 0: printf("000"); break;
            case 1: printf("001"); break;
            case 2: printf("010"); break;
            case 3: printf("011"); break;
            case 4: printf("100"); break;
            case 5: printf("101"); break;
            case 6: printf("110"); break;
            case 7: printf("111"); break;
        }
    }
}

void oktal_ke_heksa(char oktal[]) {
    int panjang = strlen(oktal);
    char biner[MAX_BIT]; 
    biner[0] = '\0'; 

    char peta_biner[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    printf("1. Oktal -> Biner\n");
    for (int i = 0; i < panjang; i++) {
        int digit_oktal = oktal[i] - '0'; // Konversi char ke int

        printf("Digit Oktal %c = %s\n", oktal[i], peta_biner[digit_oktal]);
        printf("\n");
        strcat(biner, peta_biner[digit_oktal]); 
    }
    printf("2. Biner utuh: %s\n\n", biner);
    printf("3. Biner -> Heksadesimal\n");
    biner_ke_heksa(biner);
}

//heksa
int pangkat_enamBelas(int bil_input) {
    int hasil_pangkat = 1;
    for (int i = 0; i < bil_input; i++) {
        hasil_pangkat *= 16;
    }
    return hasil_pangkat;
}

void heksa_ke_desimal(char heksa_input[]) {
    int panjang = strlen(heksa_input);
    int desimal = 0;
    int i = 0; 
    int nilai_digit; 

    for (int j = panjang - 1; j >= 0; j--) {
        char heksa = heksa_input[j]; 
        int hasil_kali=0;

        if (heksa >= '0' && heksa <= '9') {
            nilai_digit = heksa - '0'; //konversi char ke int
        } else if (heksa >= 'A' && heksa <= 'F') {
            nilai_digit = heksa - 'A' + 10; //konversi char huruf ke int (A=65)
        } else {
            printf("Error: Input Heksadesimal tidak valid.\n");
        }

        int nilai_posisi = pangkat_enamBelas(i);
        hasil_kali = nilai_digit * nilai_posisi; 
        printf("Digit %c x 16^%d: %d x %d = %d\n", heksa, i, nilai_digit, nilai_posisi, hasil_kali);

        desimal += hasil_kali;
        i++;
    }      
    printf("______________________________+\n");
    printf("Hasil konversi: %d", desimal);
}

void heksa_ke_biner(char heksa_input[]) {
    int panjang = strlen(heksa_input);
    int nilai_digit;

    for (int i = 0; i < panjang; i++) {
        char heksa = heksa_input[i]; 

        if (heksa >= '0' && heksa <= '9') {
            nilai_digit = heksa - '0'; //konversi char ke int
        } else if (heksa >= 'A' && heksa <= 'F') {
            nilai_digit = heksa - 'A' + 10; //konversi char huruf ke int (A=65)
        } else {
            printf("Error: Input Heksadesimal tidak valid.\n");
        }

        char* kode_biner;
        switch (nilai_digit) {
            case 0: kode_biner = "0000"; break;
            case 1: kode_biner = "0001"; break;
            case 2: kode_biner = "0010"; break;
            case 3: kode_biner = "0011"; break;
            case 4: kode_biner = "0100"; break;
            case 5: kode_biner = "0101"; break;
            case 6: kode_biner = "0110"; break;
            case 7: kode_biner = "0111"; break;
            case 8: kode_biner = "1000"; break;
            case 9: kode_biner = "1001"; break;
            case 10: kode_biner = "1010"; break; 
            case 11: kode_biner = "1011"; break; 
            case 12: kode_biner = "1100"; break; 
            case 13: kode_biner = "1101"; break; 
            case 14: kode_biner = "1110"; break; 
            case 15: kode_biner = "1111"; break; 
        }
        printf("Digit Heksa %c = %s\n", heksa, kode_biner);
    }
    printf("Hasil konversi: ");
    for (int i = 0; i < panjang; i++) {
        char heksa_char = heksa_input[i];
            
        if (heksa_char >= '0' && heksa_char <= '9') {
            nilai_digit = heksa_char - '0';
        } else if (heksa_char >= 'A' && heksa_char <= 'F') {
            nilai_digit = heksa_char - 'A' + 10;
        } else if (heksa_char >= 'a' && heksa_char <= 'f') {
            nilai_digit = heksa_char - 'a' + 10;
        }
        switch (nilai_digit) {
            case 0: printf("0000"); break;
            case 1: printf("0001"); break;
            case 2: printf("0010"); break;
            case 3: printf("0011"); break;
            case 4: printf("0100"); break;
            case 5: printf("0101"); break;
            case 6: printf("0110"); break;
            case 7: printf("0111"); break;
            case 8: printf("1000"); break;
            case 9: printf("1001"); break;                case 10: printf("1010"); break;
            case 11: printf("1011"); break;
            case 12: printf("1100"); break;
            case 13: printf("1101"); break;
            case 14: printf("1110"); break;                case 15: printf("1111"); break;
        }
    }
    
}

void heksa_ke_oktal(char heksa_input[]) {
    int panjang = strlen(heksa_input);
    char biner[MAX_BIT]; 
    biner[0] = '\0'; 

    char peta_biner[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    printf("1. Heksadesimal -> Biner\n");
    for (int i = 0; i < panjang; i++) {
        char heksa = heksa_input[i]; 
        int nilai_indeks;

        if (heksa >= '0' && heksa <= '9') {  //konversi char ke int (0=48, A=65)
            nilai_indeks = heksa - '0'; 
        } else if (heksa >= 'A' && heksa <= 'F') {
            nilai_indeks = heksa - 'A' + 10; 
        } else {
            printf("Error: Input Heksadesimal tidak valid.\n");
        }

        printf("Digit Heksa %c = %s", heksa, peta_biner[nilai_indeks]);
        printf("\n\n");
        strcat(biner, peta_biner[nilai_indeks]); 
    }
    printf("2. Biner utuh: %s\n\n", biner);
    printf("3. Biner -> Oktal\n");
    biner_ke_oktal(biner);
}

int main() {
    int pilih;
    
    do {
        printf("=== Program Konversi Sistem Bilangan ===\n");
        printf("1. Desimal ke Biner\n");
        printf("2. Desimal ke Oktal\n");
        printf("3. Desimal ke Heksadesimal\n");
        printf("4. Biner ke Desimal\n");
        printf("5. Biner ke Oktal\n");
        printf("6. Biner ke Heksadesimal\n");
        printf("7. Oktal ke Desimal\n");
        printf("8. Oktal ke Biner\n");
        printf("9. Oktal ke Heksadesimal\n");
        printf("10. Heksadesimal ke Desimal\n");
        printf("11. Heksadesimal ke Biner\n");
        printf("12. Heksadesimal ke Oktal\n");
        printf("13. Keluar\n");
        printf("-------------------------------------\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilih);
        printf("\n");

        int input;
        char input_arr[MAX_BIT];

        if (pilih < 4) {
            printf("Masukkan bilangan Desimal: ");
            scanf("%d", &input);
        } else if (pilih == 4) {
            printf("Masukkan bilangan Biner: ");
            scanf("%d", &input);
        } else if (pilih < 7) {
            printf("Masukkan bilangan Biner: ");
            scanf("%s", input_arr);
        }else if (pilih == 7) {
            printf("Masukkan bilangan Oktal: ");
            scanf("%d", &input);
        } else if (pilih < 10) {
            printf("Masukkan bilangan Oktal: ");
            scanf("%s", input_arr);
        }else if (pilih <= 12) {
            printf("Masukkan bilangan Heksa: ");
            scanf("%s", input_arr);
        } else if (pilih == 13) {
            printf("Sampai Jumpa...!!");
        }

        switch(pilih) {
            case 1: desimal_ke_biner(input); break;
            case 2: desimal_ke_oktal(input); break;
            case 3: desimal_ke_heksa(input); break;
            case 4: biner_ke_desimal(input); break;
            case 5: biner_ke_oktal(input_arr); break;
            case 6: biner_ke_heksa(input_arr); break;
            case 7: oktal_ke_desimal(input); break;
            case 8: oktal_ke_biner(input_arr); break;
            case 9: oktal_ke_heksa(input_arr); break;
            case 10: heksa_ke_desimal(input_arr); break;
            case 11: heksa_ke_biner(input_arr); break;
            case 12: heksa_ke_oktal(input_arr); break;
        }
        printf("\n\n");
    } while (pilih != 13);

    return 0;
}
