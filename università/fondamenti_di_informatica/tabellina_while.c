//Questo programma stampa la tabellina di un numero inserito dall'utente

#include <stdio.h>

int main(){

    int a = 0;
    int cont = 1;

    printf("Inserisci il numero di cui desideri la tabellina\n");
    scanf("%d", &a);

    while(cont <= 10){

        int ris = a * cont;
        printf("%d x %d = %d\n", a, cont, ris);
        //printf("%d x %d = %d\n", a, cont, a*cont);
        cont++;
    }
    return 0;
}