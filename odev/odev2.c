#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input();
void esitle(int orjinal[], int dizi[], int boyut);
void randomNumber(int dizi[], int boyut);
void yazdir(int dizi[], int boyut);
void kontrol(int *p, int *boyut);
void bubbleshort(int dizi[], int boyut);
void birlesim(int diziA[], int diziB[], int boyutA, int boyutB);
void kesisim(int diziA[], int diziB[], int boyutA, int boyutB);
void fark(int birinci[], int ikinci[], int boyutA, int boyutB);

int main(){
    srand(time(0));
    int n;
    int m;

    printf("a dizisinin boyutunu giriniz (1 - 200) = ");
    n = input();
    printf("b dizisinin boyutunu giriniz (1 - 200) = ");
    m = input();

    int a[n];
    int b[m];

    randomNumber(a, n);
    randomNumber(b, m);

    printf("\n\n\tDIZI A \n");
    yazdir(a, n);

    printf("\n\n\n\tDIZI B \n");
    yazdir(b, m);


    bubbleshort(a, n);
    bubbleshort(b, m);

    int *p = a;
    int *ptr = b;

    kontrol(p, &n);
    kontrol(ptr, &m);

    int a_set[n];
    int b_set[m];

    esitle(a, a_set, n);
    esitle(b, b_set, m);

    printf("\n\n\n\tA_SET DIZISI\n\n");
    yazdir(a_set, n);
    
    
    printf("\n\n\tB_SET DIZISI\n\n");
    yazdir(b_set, m);

    printf("\tA U B \n");
    birlesim(a_set, b_set, n, m);
    printf("\tA n B \n ");
    kesisim(a_set, b_set, n, m);
    printf("\tA - B \n");
    fark(a_set, b_set, n, m);
    printf("\tB - A \n");
    fark(b_set, a_set, m, n);

    system("pause");
    return 0;
}

int input(){
    int boyut;
    while (scanf("%d", &boyut) != 1 || boyut > 200 || boyut < 1){
        puts("");
        printf("hatali giris yaptiniz tekrar giriniz(1 - 200) = ");
    }
    return boyut;
}

void randomNumber(int dizi[], int boyut){
    for (int i = 0; i < boyut; i++){
        dizi[i] = (rand() % 101) - 50;
    }
}

void yazdir(int dizi[], int boyut){
    for (int i = 0; i < boyut; i++){
        printf("%d. = %d\n", i + 1 , dizi[i]);
    }
}

void kontrol(int *p, int *boyut){
    for (int i = 0; i < *boyut -  1 ; i++){
        for (int j = i + 1; j < *boyut; j++){
            if (*(p + i) == *(p + j)){
                for (int k = j; k < *boyut - 1; k++){
                    *(p + k) = *(p + k + 1);
                }
                (*boyut)--;
                j = j - 1;
            }
        }
    }
}

void bubbleshort(int dizi[], int boyut){
    int temp = 0;
    for (int i = 0; i < boyut - 1; i++){
        for (int j = 0; j < boyut - 1 - i; j++){
            if (dizi[j] > dizi[j + 1]){
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

void esitle(int orjinal[], int dizi[], int boyut){
    for (int i = 0; i < boyut; i++){
        dizi[i] = orjinal[i];
    }
}

void birlesim(int diziA[], int diziB[], int boyutA, int boyutB){
    int boyut = boyutA + boyutB;
    int yeni[boyut];
    for (int i = 0; i < boyutA; i++){
        yeni[i] = diziA[i];
    }
    int c = 0;
    for (int i = boyutA; i < boyut; i++){
        yeni[i] = diziB[c];
        c++;
    }
    int *p = yeni;
    bubbleshort(yeni, boyut);
    kontrol(p, &boyut);
    yazdir(yeni, boyut);
}

void kesisim(int diziA[], int diziB[], int boyutA, int boyutB){
    int boyut = boyutA + boyutB;
    int sayi = 0;
    for (int i = 0; i < boyutA; i++){
        for (int j = 0; j < boyutB; j++){
            if (diziA[i] == diziB[j]){
                sayi++;
            }
        }
    }
    int yeni[sayi];
    int c = 0;
    for (int i = 0; i < boyutA; i++){
        for (int j = 0; j < boyutB; j++){
            if (diziA[i] == diziB[j]){
                yeni[c] = diziA[i];
                c++;
            }
        }
    }
    yazdir(yeni, sayi);
}

void fark(int birinci[], int ikinci[], int boyutA, int boyutB){
    int gosterge = 0;
    int sayac = 0;
    for (int i = 0; i < boyutA; i++){
        gosterge = 0;
        for (int j = 0; j < boyutB; j++){
            if (birinci[i] == ikinci[j]){
                gosterge++;
            }
        }
        if (gosterge == 0){
            sayac++;
        }
    }
    int yeni[sayac];
    sayac = 0;
    for (int i = 0; i < boyutA; i++){
        gosterge = 0;
        for (int j = 0; j < boyutB; j++){
            if (birinci[i] == ikinci[j]){
                gosterge++;
            }
        }
        if (gosterge == 0){ 
            yeni[sayac] = birinci[i];
            sayac++;
        }
    }
    yazdir(yeni, sayac);
}