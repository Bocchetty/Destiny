//Questo programma gestisce l'inventario di una biblioteca

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXDIM 200
#define MAXLEN 50

struct libro{

    char autore[MAXLEN];
    char titolo[MAXLEN];
    char anno[MAXLEN];
    int copie;
};

struct libro libri[MAXDIM];

void flush();
void stampa(struct libro *libri, int riemp);
void remove_n(struct libro *libri, int riemp);
void inserimento(struct libro *libri, int *riemp);
void cancellazione(struct libro *libri, int *riemp);
void copie_complessive(struct libro *libri, int riemp, int *somma_copie);
void ricerca(struct libro *libri, int riemp, char *titolo_cercato);
void stampa_libro(struct libro *libri, int riemp, char *titolo_cercato);

int main(){
    
    int scelta = 0;
    int riemp = 4;
    int somma_copie = 0;
    char titolo_cercato[MAXLEN];

    strcpy((libri + 0)->autore, "Virgilio");
    strcpy((libri + 0)->titolo, "Eneide");
    strcpy((libri + 0)->anno, "19 a.C.");
    (libri + 0)->copie = 5;

    strcpy((libri + 1)->autore, "Andrea Camilleri");
    strcpy((libri + 1)->titolo, "La forma dell'acqua");
    strcpy((libri + 1)->anno, "1994");
    (libri + 1)->copie = 2;

    strcpy((libri + 2)->autore, "Frank Herbert");
    strcpy((libri + 2)->titolo, "Dune");
    strcpy((libri + 2)->anno, "1965");
    (libri + 2)->copie = 1;

    strcpy((libri + 3)->autore, "Italo Svevo");
    strcpy((libri + 3)->titolo, "La coscienza di Zeno");
    strcpy((libri + 3)->anno, "1923");
    (libri + 3)->copie = 10;

    do{
        printf("Menu' interattivo:\n");
        printf("1. Stampa inventario\n");
        printf("2. Inserimento nuovo libro\n");
        printf("3. Cancellazione libro\n");
        printf("4. Conteggio numero di copie complessive\n");
        printf("5. Ricerca per titolo\n");
        printf("0. Esci\n");
        printf("Quale operazione vuoi effettuare?\n");
        scanf("%d", &scelta);
        flush();

        switch(scelta){

            case 1:
            stampa(libri, riemp);
            break;

            case 2:
            inserimento(libri, &riemp);
            break;

            case 3:
            cancellazione(libri, &riemp);
            break;

            case 4:
            copie_complessive(libri, riemp, &somma_copie);
            break;

            case 5:
            ricerca(libri, riemp, titolo_cercato);
            break;

            case 0:
            printf("Arrivederci\n");
            break;

            default:
            printf("Scelta non valida\n");
            break;
        }

    } while(scelta != 0);

    return 0;
}

void flush(){

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void stampa(struct libro *libri, int riemp){

    for (int i = 0; i < riemp; i++){

        printf("\n----------\n");
        printf("%s ", (libri + i)-> titolo);
        printf("- %s ", (libri + i)-> autore);
        printf("(%s)\n", (libri + i)-> anno);
        printf("N. Copie: %d\n", (libri + i)-> copie);
    }
}

void remove_n(struct libro *libri, int riemp){
    int len = 0;

    len = strlen((libri + riemp)->titolo);
    (libri + riemp)->titolo[len-1] = '\0';

    len = strlen((libri + riemp)->autore);
    (libri + riemp)->autore[len-1] = '\0';

    len = strlen((libri + riemp)->anno);
    (libri + riemp)->anno[len-1] = '\0';

    //oppure

    (libri + riemp)->titolo[strcspn((libri + riemp)->titolo, "\n")] = '\0';
}

void inserimento(struct libro *libri, int *riemp){

    if(*riemp < MAXDIM){

     printf("Inserisci informazioni libro\n");
     printf("TITOLO: \n");
     fgets((libri + *riemp)-> titolo, MAXLEN, stdin);

     printf("AUTORE: \n");
     fgets((libri + *riemp)-> autore, MAXLEN, stdin);

     printf("ANNO: \n");
     fgets((libri + *riemp)-> anno, MAXLEN, stdin);

     printf("COPIE: \n");
     scanf("%d", &(libri + *riemp)-> copie);

     flush();
     remove_n(libri, *riemp);
     (*riemp)++;
     printf("Libro aggiunto all'inventario\n");
    

    }else {
    printf("Inserimento fallito, dimensione massima raggiunta!\n");
    }
}

void cancellazione(struct libro *libri, int *riemp){

    int pos = 0;
    printf("Quale libro vuoi cancellare?\n");
    scanf("%d", &pos);
    flush();

    for(int i = pos; i < *riemp; i++){

        strcpy((libri + i)->titolo, (libri + i + 1)->titolo);
        strcpy((libri + i)->autore, (libri + i + 1)->autore);
        strcpy((libri + i)->anno, (libri + i + 1)->anno);
        (libri + i)->copie = (libri + i + 1)->copie;

    }
    (*riemp)--;

}

void copie_complessive(struct libro *libri, int riemp, int *somma_copie){

    for(int i = 0; i < riemp; i++){
        *somma_copie += (libri + i)->copie;
    }
    printf("Numero totale di copie disponibili: %d\n", *somma_copie);
}

void ricerca(struct libro *libri, int riemp, char *titolo_cercato){

    bool trovato = false;
    int len = 0;

    printf("Inserisci il titolo del libro che cerchi:\n");
    fgets(titolo_cercato, MAXLEN, stdin);
    len = strlen(titolo_cercato);
    titolo_cercato[len-1] = '\0';
    for(int i = 0; i < riemp; i++){

        if(strcmp((libri + i)->titolo, titolo_cercato)== 0){
            trovato = true;
        }
    }
    if(trovato == true){
        printf("Libro trovato!\n");
        stampa_libro(libri, riemp, titolo_cercato);
    }else {
        printf("Libro non trovato!\n");
    }
}
void stampa_libro(struct libro *libri, int riemp, char *titolo_cercato){

    for(int i = 0; i < riemp; i++){
        if((strcmp((libri + i)->titolo, titolo_cercato)== 0)){
         printf("----------\n");
         printf("%s ", (libri + i)-> titolo);
         printf("- %s", (libri + i)-> autore);
         printf("(%s)\n", (libri + i)-> anno);
         printf("N. Copie: %d\n", (libri + i)-> copie);
        }
    }
}