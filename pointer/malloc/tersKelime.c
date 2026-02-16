#include <stdio.h>
#include <stdlib.h>

void ters(char *p, int n);

int main(){
    int n;
    printf("yazinin kac elemanli olucagini giriniz\n");
    scanf("%d", &n);
    getchar();

    char *p = (char *) malloc ((n + 1) * sizeof(char));
    printf("yaziyi giriniz\n");
    fgets(p, n + 1, stdin);

    printf("%s\n", p);
    ters(p, n);

    free(p);
    system("pause");
    return 0;
}

void ters(char *p, int n){
    char temp = *p;
    for (int i = 0; i < ((n + 1) / 2 ); i++){
        temp = *(p + i);
        *(p + i) = *(p + (n - i));
        *(p + (n - i)) = temp;
    }

    for (int i = 0; i < n + 1; i++){
        printf("%c", *(p + i));
    }
    
    printf("\n");
    
}
