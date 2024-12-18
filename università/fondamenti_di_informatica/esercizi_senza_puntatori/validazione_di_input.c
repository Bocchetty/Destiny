// Questo programma valida l'input inserito dall'utente
#include <stdio.h>

int main(){

    int a = 0;

    do {
    printf("Inserisci un numero tra 1 e 12\n");
    scanf("%d", &a);
    if (a<1 || a>12)
        printf("Valore non valido!\n");
    }while (a<1 || a>12);

    printf("Il numero e' incluso nell'intervallo [1, 12]");

    return 0;
}