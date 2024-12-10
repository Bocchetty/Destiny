//Questo programma implementa la funzione swap usando i puntatori

#include <stdio.h>
#include<stdlib.h>

int main(){

    int a = 0;
    int b = 0;
    int temp = 0;
    int *pa = &a;
    int *pb = &b;
    int *pt = &temp;

    printf("Inserisci due interi:\n");
    scanf("%d", pa);
    scanf("%d", pb);

    printf("Prima dello scambio A=%d, B=%d\n", *pa, *pb);
    printf("Indirizzo di A: %p\n", pa);
    printf("Indirizzo di B: %p\n", pb);
    *pt = *pa;
    *pa = *pb;
    *pb = *pt;
    printf("Dopo lo scambio A=%d, B=%d\n", *pa, *pb);
    printf("Indirizzo di A: %p\n", pa);
    printf("Indirizzo di B: %p\n", pb);

    return 0;
}