//Questo programma dimezza una variabile inserita da tastiera usando il suo indirizzo

#include <stdio.h>

int main(){

    float n = 0;
    float *pn = &n;

    printf("Inserisci un numero di cui vuoi dimezzare il valore:\n");
    scanf("%f", pn);

    n = (*pn)/2;
    printf("Il numero dimezzato e': %f", n);

    return 0;
}