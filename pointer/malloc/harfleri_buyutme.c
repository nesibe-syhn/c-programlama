#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //toupper fonksiyonu icin eklendi

void yaz(char *p, int n);
void buyut(char *p, int n);
void yazdir(char *p, int n);


int main(){
    printf("kac elemanli oldugunu belirle\n");
    int n;
    scanf("%d", &n);
    getchar();

    char *p = (char *) malloc ((n + 1) * sizeof(char));
    yaz(p, n);
    buyut(p, n);
    yazdir(p, n);


    free(p);
    system("pause");
    return 0;
}

void yaz(char *p, int n){
    printf("kucuk ve buyuk harf karisik olucak sekilde yazi yazin\n");
    fgets(p, n + 1 , stdin);
}

//buyuk harfe cevirir
void buyut(char *p, int n){
    while (*p != '\0'){
        *p = toupper(*p);
        p++;
    }
}

void yazdir(char *p, int n){
    printf("%s", p);
    printf("\n");
}
