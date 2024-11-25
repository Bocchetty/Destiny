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
    printf("[");
    for (int i = 0; i < MAXDIM; i++){

        printf("\t%d\t,", vettore_A[i]);
    }
    printf("]\n");

    printf("Vettore B : \n");
    printf("[");
    for (int i = 0; i < MAXDIM; i++){

        printf("\t%d\t,", vettore_B[i]);
    }
    printf("]\n");

    printf("Vettore C : \n");
    printf("[");
    for (int i = 0; i < MAXDIM; i++){

        printf("\t%d\t,", vettore_C[i]);
    }
    printf("]\n");

    return 0;
}