// Questo programma implementa le funzionalità di una calcolatrice una calcolatrice

#include <stdio.h>

int main(){

    //Valori inseriti da utente
    int a = 0;
    int b = 0;
    //Variabile con risultato operazioni
    int c = 0;
    //Variabile selettore operazione
    int operazione = 0;

    printf("Inserisci due operandi:\n");
    scanf("%d""%d", &a, &b);

    printf("Scegli l'operazione: \n 1 per +\n 2 per -\n 3 per *\n 4 per /\n 5 per %%\n");
    scanf("%d", &operazione);
    //E' possibile fare uno switch dando in input direttamente l'operazione richiesta ed usare una variabile di tipo char

    switch(operazione){

        case 1:
        c = a + b;
        printf("%d" " + " "%d" " = " "%d", a, b, c);
        break;
    
        case 2:
        c = a - b;
        printf("%d" " - " "%d" " = " "%d", a, b, c);
        break;

        case 3:
        c = a * b;
        printf("%d" " * " "%d" " = " "%d", a, b, c);
        break;

        case 4:
        c = a / b;
        printf("%d" " / " "%d" " = " "%d", a, b, c);
        break;

        case 5:
        c = a % b;
        printf("%d" " %% " "%d" " = " "%d", a, b, c);
        break;

        default:
        printf("Operazione non valida");
    }
    return 0;
}