// A ve B matrislerinin carpimi
#include <stdio.h>
#include <stdlib.h>

void input(int a[3][3], int b[3][3]);
void yazdir(int a[3][3], int b[3][3]);
void carp(int a[3][3], int b[3][3]);
void carpimyazdir(const int c[3][3]); // sonucu yazdırırken hiçbir hata olmasın karışmasın diye const kullanıldı

int main(){
    int a[3][3];
    int b[3][3];

    input(a, b);
    yazdir(a, b);
    carp(a, b);

    system("pause");
    return 0;
}

void input(int a[3][3], int b[3][3]){
    printf("MATRISLERIN DEGERLERINI GIRINIZ\n\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void yazdir(int a[3][3], int b[3][3]){
    printf("\n\nMATRIS SEKLINDE YAZDIRILMIS HALI\n\n");

    printf("A DIZISI\n\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("B DIZISI\n\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void carp(int a[3][3], int b[3][3]){
    int c[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    carpimyazdir(c);
}

void carpimyazdir(const int c[3][3]){
    printf("\nA x B CARPIMI\n\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}
