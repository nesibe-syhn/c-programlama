#include <stdio.h>
#include <stdlib.h>

void input(int dizi[3][3]);
void tranzpoz(const int dizi[3][3]);
void yazdir(const int dizi[3][3]);

int main(){
    int dizi[3][3];
    input(dizi);
    yazdir(dizi);
    tranzpoz(dizi);

    system("pause");
    return 0;
}

void input(int dizi[3][3]){
    printf("dizinin elemanlarini giriniz\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("dizi[%d][%d] = ", i, j);
            scanf("%d", &dizi[i][j]);
        }
    }
}

void tranzpoz(const int dizi[3][3]){
    printf("\n\ntranzpoz\n");
    int t[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            t[i][j] = dizi[j][i];
        }
    }
    yazdir(t);
}

void yazdir(const int dizi[3][3]){

    printf("\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d    ", dizi[i][j]);
        }
        printf("\n");
    }
}
