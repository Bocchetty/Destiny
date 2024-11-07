// Questo programma resistuisce il mese in base all'intero inserito dall'utente

# include <stdio.h>

int main(){

    int a = 0;

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

    return 0;
}