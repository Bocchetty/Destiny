//Questo programma calcola se un numero è multiplo di un'altro

#include <stdio.h>

int main(){

    int a = 0;
    int b = 0;

    printf("Inserisci due numeri\n");
    scanf("%d" "%d", &a, &b);

    if (a%b == 0){

        printf("Il numero %d e' multiplo di %d\n", a, b);

    }else{

        printf("Il numero %d non e' multiplo di %d\n", a, b);
    }
    return 0;
}