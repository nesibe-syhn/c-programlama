#include <stdio.h>
#include <stdlib.h>

void menu(int b, int dizi[]);
void sayilariGir(int b, int dizi[]);
void ikiCarp(int b, int dizi[]);
void karesiniAl(int b, int dizi[]);
void negatif(int b, int dizi[]);
void islem(int b,int dizi[], void (*kiyasla)(int, int[]));

int main(){
    int a;
    printf("kac elemanli olucagini giriniz\n");
    scanf("%d", &a);
    int dizi[a];

    sayilariGir(a, dizi);

    menu(a, dizi);

    system("pause");
    return 0;
}

void menu(int b, int dizi[]){
    int secenek;
    do{
        printf("1- tum elemanlari 2 ile carpin\n");
        printf("2- tum elemanlarin karesini alin\n");
        printf("3- elemanlari negatif yap\n");
        printf("4- cikis\n");
        printf("yapicaginiz islemi seciniz\n");

        scanf("%d", &secenek);

        switch (secenek){
        case 1:
            printf("\n\n");
            islem(b, dizi, ikiCarp);
            break;
        case 2:
            printf("\n\n");
            islem(b, dizi, karesiniAl);
            break;
        case 3:
            printf("\n\n");
            islem(b, dizi, negatif);
            break;
        case 4:
            printf("\n\n");
            printf("cikis yapiliyor\n");
            break;
        default:
            printf("gecersiz secim\n");
            break;
        }
    }while (secenek != 4);
}

void sayilariGir(int b,int dizi[]){
    printf("sayilari giriniz\n");

    for (int i = 0; i < b; i++){
        printf("%d. sayi = ", i + 1);
        scanf("%d", &dizi[i]);
        printf("\n");
    }
}

void islem(int b,int dizi[], void (*kiyasla)(int, int[])){
    kiyasla(b, dizi);
}

void ikiCarp(int b, int dizi[]){
    for (int i = 0; i < b; i++){
        printf("%d. sayinin 2 kati = %d\n", i + 1, dizi[i] * 2);
    }
}

void karesiniAl(int b, int dizi[]){
    for (int i = 0; i < b; i++){
        printf("%d. sayinin karesi = %d\n", i + 1, dizi[i] * dizi[i]);
    } 
}


void negatif(int b, int dizi[]){
    for (int i = 0; i < b; i++){
        printf("%d. sayinin negatifi = %d\n", i + 1, -1 * dizi[i]);
    }
}
