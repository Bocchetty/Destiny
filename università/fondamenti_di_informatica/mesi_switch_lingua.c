// Questo programma resistuisce il mese in italiano o inglese in base all'intero inserito dall'utente

# include <stdio.h>

int main(){

    int a = 0;
    int lingua = 0;

    printf("Lingua/Language 1 ITA, 2 ENG:\n");
    scanf("%d", &lingua);

    if (lingua == 1){

        printf("Scrivi un numero intero tra 1 e 12:\n");
    scanf("%d", &a);

    switch (a){

        case 1:
        printf("Il mese selezionato e' Gennaio\n");
        break;
        case 2:
        printf("Il mese selezionato e' Febbraio\n");
        break;
        case 3:
        printf("Il mese selezionato e' Marzo\n");
        break;
        case 4:
        printf("Il mese selezionato e' Aprile\n");
        break;
        case 5:
        printf("Il mese selezionato e' Maggio\n");
        break;
        case 6:
        printf("Il mese selezionato e' Giugno\n");
        break;
        case 7:
        printf("Il mese selezionato e' Luglio\n");
        break;
        case 8:
        printf("Il mese selezionato e' Agosto\n");
        break;
        case 9:
        printf("Il mese selezionato e' Settembre\n");
        break;
        case 10:
        printf("Il mese selezionato e' Ottobre\n");
        break;
        case 11:
        printf("Il mese selezionato e' Novembre\n");
        break;
        case 12:
        printf("Il mese selezionato e' Dicembre\n");
        break;
        default:
        printf("Errore, il numero non e' compreso tra 1 e 12\n");
        break;

    }
    }else if (lingua == 2){

        printf("Write a number between 1 and 12:\n");
    scanf("%d", &a);

    switch (a){

        case 1:
        printf("The month selected is January\n");
        break;
        case 2:
        printf("The month selected is February\n");
        break;
        case 3:
        printf("The month selected is March\n");
        break;
        case 4:
        printf("The month selected is April\n");
        break;
        case 5:
        printf("The month selected is May\n");
        break;
        case 6:
        printf("The month selected is June\n");
        break;
        case 7:
        printf("The month selected is July\n");
        break;
        case 8:
        printf("The month selected is August\n");
        break;
        case 9:
        printf("The month selected is September\n");
        break;
        case 10:
        printf("The month selected is October\n");
        break;
        case 11:
        printf("The month selected is November\n");
        break;
        case 12:
        printf("The month selected is December\n");
        break;

        default:
        printf("Error, the number is not between 1 and 12\n");
        break;

    }
     }else{
        printf("Lingua non valida/Invalid language");
     };
    

    return 0;
}