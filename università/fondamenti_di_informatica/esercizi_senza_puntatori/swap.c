// Questo programma inverte il valore di due variabili scelte dall'utente

#include <stdio.h>

int main(){

    int a = 0; int b = 0;

    printf("Inserisci il valore di a: \n");
    scanf("%d", &a);
    
    printf("Inserisci il valore di b: \n");
    scanf("%d", &b);

    // Scambio valori usando una variabile terza temporanea

    int tmp = 0;

    tmp = a;
    a = b;
    b = tmp;

    printf("Dopo lo scambio a vale : %d mentre b vale :%d\n", a, b);

    return 0;
}