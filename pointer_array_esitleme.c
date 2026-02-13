#include <stdio.h>
#include <stdlib.h>

void gir(int satir , int sutun, int *p, int dizi[satir][sutun]);
void yazdir(int satir , int sutun, int *p, int dizi[satir][sutun]);

int main(){
    int satir;
    int sutun;
    printf("satir sayisi\n");
    scanf("%d", &satir);
    printf("sutun sayisini giriniz\n");
    scanf("%d", &sutun);

    int dizi[satir][sutun];
    int *p = *dizi;


    gir(satir, sutun, p, dizi);
    yazdir(satir, sutun, p, dizi);

    system("pause");
    return 0;
}

void gir(int satir , int sutun, int *p, int dizi[satir][sutun]){
    printf("matris degerlerini giriniz\n");

    for (int i = 0; i < satir; i++){
        p = *(dizi + i);
        for (int j = 0; j < sutun; j++){
            printf("dizi[%d][%d] = ", i, j);
            scanf("%d", (p + j));
        }
        printf("\n");
    }
    
}

void yazdir(int satir , int sutun, int *p, int dizi[satir][sutun]){

    for (int i = 0; i < satir; i++){
        p = *(dizi + i);
        for (int j = 0; j < sutun; j++){
            printf("dizi[%d][%d] = %d\t", i, j, *(p + j));
        }
        printf("\n");
    }
}
