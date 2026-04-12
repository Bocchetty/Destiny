#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "magazzino.h"

//definizione operazioni
//per come sono impostate le funzoni si presume che l'accesso all'array e quindi ai prodotti sia effettuato attraverso il numero identificativo che corrisponde 
// con la loro posizione nell'array

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

void inserisci_datiprodotto(struct prodotto *prodotti, int *riemp, char *new_cod){

    if ((*riemp + 1) < MAXDIM){

        printf("Inserisci dati prodotto: \n");

        //printf("Inserisci Codice: \n");
        //fgets((prodotti + *riemp) -> codice, MAXLEN, stdin);

        strcpy(prodotti[*riemp].codice, new_cod);
        printf("Codice inserito! \n"),

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

void modifica_codice(struct prodotto *prodotti, int *riemp){

    int pos = 0;

    printf("A quale prodotto vuoi modificare il codice? \n");
    scanf("%d", &pos);
    flush();

    if(pos >= 0 && pos < *riemp){
        printf("Inserisci il nuovo codice: \n");
        fgets((prodotti + pos) -> codice, MAXLEN, stdin);
        //fgets(prodotti[pos].codice, MAXLEN, stdin);
    
        remove_n(prodotti, pos);
    }else{
        printf("Posizione non valida!");
    }

}

void fornisci_codice(struct prodotto *prodotti, int *riemp){

    int pos = 0;

    printf("Di quale prodotto cerchi il codice? \n");
    scanf("%d", &pos);
    flush();

    if(pos >= 0 && pos < *riemp){
        printf("Il codice del prodotto %d è: %s\n", pos, prodotti[pos].codice);
        
    }else{
        printf("Posizione non valida!");
    }

}

void visualizza_datiprodotto(struct prodotto *prodotti, int *riemp){

    int pos = 0;

    printf("Di quale prodotto cerchi il codice? \n");
    scanf("%d", &pos);
    flush();

    if(pos >= 0 && pos < *riemp){

        printf("Dati prodotto %d: \n", pos);

        printf("CODICE\tGENERE\tQUANTITA'\n");
        printf("%s\t%s\t%d\n", (prodotti + pos)->codice,(prodotti + pos)->genere,(prodotti + pos)->qta);
    }else{
        printf("Posizione non valida!\n");
    }
}

void inizializza_magazzino_vuoto(struct prodotto *prodotti, int *riemp){

    printf("Inizializzo il riempimento del magazzino a 0 \n");
    riemp = 0;

}

void inizializza_magazzino(struct prodotto *prodotti, int *riemp, char *new_cod){

    printf("Quanti prodotti vuoi inserire nel magazzino? \n");
    scanf("%d", riemp);

    if(*riemp < MAXDIM){
        for(int i = 0; i < *riemp; i++){

            printf("Inserisci codice del nuovo prodotto: \n");
            fgets(new_cod, MAXLEN, stdin);
            flush();
            int cerca = cerca_codice_prodotto(prodotti, riemp, new_cod);

            if(cerca == -1){

                inserisci_datiprodotto(prodotti, &i, new_cod);
                printf("Inserimento riuscito! \n");


            }else{
                printf("Prodotto già presente! \n");
            }

        }
    }else{
        printf("Dimensione massima raggiunta! \n");
    }

}

int cerca_codice_prodotto(struct prodotto *prodotti, int *riemp, char *new_cod){

    //char new_cod[MAXLEN];

    bool trovato = false;

    for(int i = 0; i < *riemp; i++){

        int cmp = strcmp(new_cod, prodotti[i].codice);

        if(cmp == 0){
            printf("Il prodotto è presente in magazzino, in posizione %d", i);
            trovato = true;
            return 1;
        }
    }

    if(trovato == false){
        printf("Prodotto non presente in magazzino! \n");
        return -1;
    }

}

void elimina_prodotto(struct prodotto *prodotti, int *riemp){

    int pos;

    printf("Inserisci posizione del prodotto che vuoi eliminare: \n");
    scanf("%d", &pos);
    flush();

    if(pos >= 0 && pos < *riemp){

        prodotti[pos] = prodotti[*riemp - 1];

        (*riemp)--;
        
    }else{
        printf("Posizione non valida!");
    }

}

void inserisci_prodotto(struct prodotto *prodotti, int *riemp, char *new_cod){

    int pos;

    printf("In quale posizione vuoi inserire il prodotto? \n");
    scanf("%d", &pos);
    flush();

    if((*riemp + 1) < MAXDIM){
        if(pos >= 0 && pos < *riemp){

            printf("Inserisci codice del nuovo prodotto: \n");
            fgets(new_cod, MAXLEN, stdin);
            flush();
            int cerca = cerca_codice_prodotto(prodotti, riemp, new_cod);

            if(cerca == -1){

                strcpy(prodotti[pos].codice, new_cod);
                printf("Codice inserito! \n");

                printf("Inserisci Genere: \n");
                fgets((prodotti + *riemp) -> genere, MAXLEN, stdin);

                printf("Inserisci Quantità: \n");
                scanf("%d", &(prodotti + *riemp) -> qta);
        
                flush();
                remove_n(prodotti, pos);
                (*riemp)++;

            }else{
                printf("Prodotto già presente! \n");
            }

        }else{
            printf("Posizione non valida!");
        }
    }else{
        printf("Dimensione massima raggiunta! \n");
    }
}

void visualizza_magazzino(struct prodotto *prodotti, int *riemp){

    printf("Visualizza prodotti in magazzzino: \n");

    for(int i = 0; i < *riemp; i++){

        visualizza_datiprodotto(prodotti, &i);

    }
}