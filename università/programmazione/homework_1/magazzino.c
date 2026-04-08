#include <stdio.h>
#include <string.h>
#include "magazzino.h"

//definizione operazioni

void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//funzione che rimuove i \n salvati nel terminale a seguito dell'utilizzo di fgets
void remove_n(struct prodotto *prodotti, int riemp){
    int len = 0;

    len = strlen((prodotti + riemp)-> codice);
    (prodotti + riemp)-> codice[len-1] = '\0';

    len = strlen((prodotti + riemp)-> genere);
    (prodotti + riemp)-> genere[len-1] = '\0';

}

void inserisci_datiprodotto(struct prodotto *prodotti, int *riemp){

    if ((*riemp + 1) < MAXDIM){

        printf("Inserisci dati prodotto: \n");

        printf("Inserisci Codice: \n");
        fgets((prodotti + *riemp) -> codice, MAXLEN, stdin);

        printf("Inserisci Genere: \n");
        fgets((prodotti + *riemp) -> genere, MAXLEN, stdin);

        printf("Inserisci Quantità: \n");
        scanf("%d", &(prodotti + *riemp) -> qta);
        
        flush();
        remove_n(prodotti, *riemp);
        (*riemp)++;

        printf("Inserimento riuscito! \n");

    }else{
        printf("Inserimento fallito, dimensione massima raggiunta! \n");
    }

    
}