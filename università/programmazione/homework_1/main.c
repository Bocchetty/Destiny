#include "magazzino.h" //importo l'header
#include <stdio.h>

int main(){

    int magazzino[MAXDIM];
    int riemp;
    struct prodotto *prodotti[MAXDIM];

    //menù contestuale

    int scelta = 0;

    do{

        printf("Menù interattivo: \n");
        printf("1. Inizializza Magazzino Vuoto \n");
        printf("2. Inizializza Magazzino \n");
        printf("3. Inserisci Dati Prodotto \n");
        printf("4. Modifica Codice \n");
        printf("5. Fornisci Codice \n");
        printf("6. Visualizza Dati Prodotto \n");
        printf("7. Cerca Codice Prodotto \n");
        printf("8. Elimina Prodotto \n");
        printf("9. Inserisci Prodotto \n");
        printf("10. Visualizza Magazzino \n");
        printf("0. Esci \n");
        printf("Quale operazione vuoi effettuare? \n");

        scanf("%d", &scelta);
        flush();

        switch(scelta){

            case 1:

            break;

            case 2:

            break;

            case 3:
            inserisci_datiprodotto(*prodotti, &riemp);
            break;

            case 4:

            break;

            case 5:

            break;

            case 6:

            break;

            case 7:

            break;

            case 8:

            break;

            case 9:

            break;

            case 10:

            break;

            case 0:
            printf("Arrivederci! \n");
            break;

            default:
            printf("Scelta non valida! \n");
            break;


        }


    }while(scelta !=0);
    return 0;
}