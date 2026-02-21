//HESAP MAKİNESİ
#include <stdio.h>
#include <stdlib.h>

int carp(int a, int b);
int topla(int a, int b);
int coz(int a, int b, int (*deneme)(int, int)); //Function Pointer

int main(){
    int a;
    int b;
    printf("1. sayiyi giriniz\n");
    scanf("%d", &a);
    printf("2. sayiyi giriniz\n");
    scanf("%d", &b);
    int secim;
    printf("toplama yapmak icin 1 carpma yapmak icin 2 yi tuslayiniz\n");
    scanf("%d", &secim);

    if (secim == 1){
        int t = coz(a, b, topla);
        printf("toplami = %d\n", t);
    }
    else if(secim == 2){
        int c = coz(a, b, carp);
        printf("carpim = %d\n", c);
    }
    else{
        printf("gecersiz islem girdiniz\n");
    }

    system("pause");
    return 0;
}

int carp(int a , int b){
    return a* b;
}

int topla(int a, int b){
    return a + b;
}

int coz(int a, int b, int (*deneme)(int, int)){
    return deneme(a, b);
}

