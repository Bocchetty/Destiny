//Questo programma chiede all'utente di indovinare un numero estratto in maniera randomica

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int tentativo;  //Numero utente

    int seed = time(NULL);
    srand(seed);
    int numeroGrande = rand();
    int n = 1 + (numeroGrande % 5); //Numero segreto

    do{

        printf("Indovina il numero compreso tra 1 e 5:\n");
        scanf("%d", &tentativo);

        if (tentativo != n)
            printf("Hai sbagliato riprova!\n");

    }while(tentativo != n);
    
    printf("Hai indovinato il numero complimenti!");

    return 0;
}