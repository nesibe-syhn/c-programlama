#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomNuber(int *p);
void yeni(int *p);
void mutlak(int *p);
void yazdir(int *p);
int max(int *p);

int boyut;
int k;

int main(){
    srand(time(0));
    do{
        printf("dizinin boyutunu giriniz\n");
        scanf("%d", &boyut);
    } while (boyut > 50 || boyut < 1);
    int dizi[boyut];
    do{
        printf("guncelleme sayisini giriniz\n");
        scanf("%d", &k);
    } while (k < 1);

    randomNuber(dizi);

    int yeniDizi[boyut];
    for (int i = 0; i < boyut; i++){
        yeniDizi[i] = dizi[i];
    }
    
    int *p = dizi;

    yeni(p);

    printf("\n\nSON DIZI\n");
    printf("son dizideki en buyuk eleman = %d\n", *(p + max(p)));

    printf("\n\nILK DIZI\n");
    printf("Ayni indiste, dizinin ilk (orijinal) halindeki eleman = %d\n", yeniDizi[max(p)]);

    system("pause");
    return 0;
}

void randomNuber(int *p){
    for (int i = 0; i < boyut; i++){
        *(p + i) = rand() % 99 + 1;
    }
    printf("\nDIZININ ORJINALI\n\n");
    yazdir(p);
    printf("\n\n");
}

void yeni(int *p){
    while (k != 0){
        mutlak(p);
        k--;
    }
    printf("\n\nEN SON\n\n");
    yazdir(p);
}

void mutlak(int *p){
    int sonuc = 0;
    int array[boyut];
    for (int i = 0; i < boyut; i++){
        array[i] = *(p + i);
    }
    
    for (int i = 0; i < boyut; i++){
        sonuc = 0;
        if (i != (boyut - 1)){
            int b = array[i] - array[i + 1]; // son eleman hariç diğer durumlar için
            if (b >= 0) sonuc = b;
            else if (b < 0) sonuc = (-b);
            *(p + i) = sonuc;
        }
        else if (i == (boyut - 1)){
            int a = array[i] - array[0]; // son eleman için
            if (a >= 0) sonuc = a;
            else if (a < 0) sonuc = (-a);
            *(p + i) = sonuc;
        }
    }
    printf("\n");
    yazdir(p);
    printf("\n");
}

void yazdir(int *p){
    for (int i = 0; i < boyut; i++){
        printf("dizi[%d] = %d\n", i , *(p + i));
    }
}

int max(int *p){
    int max = *p;
    for (int i = 0; i < boyut; i++){
        max = (max <= *(p + i)) ? *(p + i) : max;
    }
    int maxIndis = 0;
    for (int i = 0; i < boyut; i++){
        if (max == *(p + i)){
           maxIndis = i;
        }
    }
    return maxIndis;
}