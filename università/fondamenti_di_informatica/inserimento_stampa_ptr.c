//Questo programma inserisce un'elemento in coda ad un'array usando i puntatori

#include<stdio.h>
#include<stdbool.h>
#define MAXDIM 100

void creazione_array(int *v, int riemp);
void stampa_array(int *v, int riemp);
bool inserimento(int *v, int *riemp, int n_ins);
void inserimento2(int *v, int *riemp, int n_ins, bool *esito);

int main(){

    int v[MAXDIM];
    int riemp = 0;
    int n_ins = 0;
    bool esito = false;

    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &riemp);

    creazione_array(v, riemp);
    stampa_array(v, riemp);

    printf("Quale numero vuoi inserire?\n");
    scanf("%d", &n_ins);

    esito = inserimento(v, &riemp, n_ins);
    if(esito == true){
        printf("Inserimento riuscito!\n");
        stampa_array(v, riemp);
    }else{
        printf("Inserimento NON riuscito!\n");
    }

    printf("Quale numero vuoi inserire?\n");
    scanf("%d", &n_ins);

    inserimento2(v, &riemp, n_ins, &esito);
    if(esito == true){
        printf("Inserimento riuscito!\n");
        stampa_array(v, riemp);
    }else{
        printf("Inserimento NON riuscito!\n");
    }


    return 0;
}

void creazione_array(int *v, int riemp){

    printf("Inserisci %d elementi:\n", riemp);
    int n = 1;

    for (int i = 0; i<riemp; i++){

        scanf("%d", (v + i));
        printf("Inserisci ancora %d elementi:\n", riemp-n);
        n++;

    }
}

void stampa_array(int *v, int riemp){

    printf("| ");
    for(int i = 0; i<riemp; i++){

        printf("%d ", *(v + i));
    }
    printf("|\n");
}

bool inserimento(int *v, int *riemp, int n_ins){

    if(*riemp < MAXDIM){
     *(v + (*riemp)) = n_ins;
     (*riemp)++;
     printf("Riempimento aggiornato: %d\n", *riemp);
     return true;

    }else {

    return false;
    }
}

void inserimento2(int *v, int *riemp, int n_ins, bool *esito){

    if(*riemp < MAXDIM){
     *(v + (*riemp)) = n_ins;
     (*riemp)++;
     printf("Riempimento aggiornato: %d\n", *riemp);
     *esito = true;

    }else {

    *esito = false;
    }
}