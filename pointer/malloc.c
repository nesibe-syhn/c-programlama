#include <stdio.h>
#include <stdlib.h>

void tersi(int *p, int n);

int main(){
    int n;
    printf("dizinin kac elemanli olicagini giriniz\n");
    scanf("%d", &n);

    int *p = (int *) malloc(n * sizeof(int));
    printf("%d tane sayi giriniz\n", n);
    for (int i = 0; i < n; i++){
        printf("%d. sayi = ", i + 1);
        scanf("%d", &p[i]);
        printf("\n");
    }

    printf("tersi \n");

    tersi(p, n);

    free(p);
    system("pause");
    return 0;
}

// n dizinin eleman sayisi
void tersi(int *p, int n){
    for (int i = n - 1 ; i >= 0; i--){
        printf("%d", *(p + i));
        printf("\n");
    }
}
