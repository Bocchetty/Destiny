// Questo programma richiede due array di numeri e ne restituisce la somma degli elementi omologhi

#include <stdio.h>

int main(){

    int MAXDIM = 5;
    int vettore_A [MAXDIM];
    int vettore_B [MAXDIM];
    int vettore_C [MAXDIM];

    for (int i = 0; i < MAXDIM; i++){

        printf("Inserisci un numero nell'array A\n");
        scanf("%d", &vettore_A[i]);
    }

    for (int i = 0; i < MAXDIM; i++){

        printf("Inserisci un numero nell'array B\n");
        scanf("%d", &vettore_B[i]);
    }

    for (int i = 0; i < MAXDIM; i++){

        vettore_C[i] = vettore_A[i] + vettore_B[i];
    }

    printf("Vettore A : \n");
    for (int i = 0; i < MAXDIM; i++){

        printf("%d\n", vettore_A[i]);
    }

    printf("Vettore B : \n");
    for (int i = 0; i < MAXDIM; i++){

        printf("%d\n", vettore_B[i]);
    }

    printf("Vettore C : \n");
    for (int i = 0; i < MAXDIM; i++){

        printf("%d\n", vettore_C[i]);
    }

    return 0;
}