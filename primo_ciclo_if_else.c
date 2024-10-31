// Questo programma introduce il primo programma con il costrutto if-else

#include <stdio.h>

int main(){

    int a = 0;

    printf("Inserisci un numero intero\n");
    scanf("%d", &a);

    if(a>10)
        printf("Il numero e' maggiore di 10\n");
    else{
        if(a<10)
            printf("Il numero e' minore di 10\n");
        else
                printf("Il numero e' uguale a 10\n");
    };

    return 0;
}