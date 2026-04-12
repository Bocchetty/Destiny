#include "magazzino.h" //importo l'header
#include <stdio.h>

int main(){

    int magazzino[MAXDIM];
    int riemp;
    struct prodotto *prodotti[MAXDIM];
    char new_cod[MAXLEN];

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
            inizializza_magazzino_vuoto(*prodotti, &riemp);
            break;

            case 2:
            inizializza_magazzino(*prodotti, &riemp, new_cod);
            break;

            case 3:
            inserisci_datiprodotto(*prodotti, &riemp, new_cod);
            break;

            case 4:
            modifica_codice(*prodotti, &riemp);
            break;
            
            case 5:
            fornisci_codice(*prodotti, &riemp);
            break;

            case 6:
            visualizza_datiprodotto(*prodotti, &riemp);
            break;

            case 7:
            printf("Inserisci il codice del prodotto che cerchi: \n");
            fgets(new_cod, MAXLEN, stdin);
            flush();
            cerca_codice_prodotto(*prodotti, &riemp, new_cod);
            break;

            case 8:
            elimina_prodotto(*prodotti, &riemp);
            break;

            case 9:
            inserisci_prodotto(*prodotti, &riemp, new_cod);
            break;

            case 10:
            visualizza_magazzino(*prodotti, &riemp);
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