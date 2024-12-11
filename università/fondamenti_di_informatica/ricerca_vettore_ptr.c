//Questo programma ricerca la posizione di un numero di un vettore tramite l'utilizzo dei puntatori

#include<stdio.h>
#include<stdbool.h>
#define MAXDIM 100

bool ricerca(int *v, int riemp, int n, int *pos);
int ricerca_occ(int *v, int riemp, int n, int volte);
void eliminazione(int *v, int *riemp, int n_elim, int *pos);

int main(){

    int v[MAXDIM];
    int riemp = 0;
    int n = 0;
    int pos = 0;
    int volte = 0;
    int n_elim = 0;

    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &riemp);

    printf("Inserisci %d numeri\n", riemp);

    for(int i = 0; i<riemp; i++){

        scanf("%d", (v+i));
    }
    printf("\n| ");
    for(int i = 0; i<riemp; i++){

        printf("%d ", *(v+i));
    }
    printf("|\n");

    printf("Quale numero vuoi cercare?\n");
    scanf("%d", &n);

    if(ricerca(v, riemp, n, &pos) == true){
        printf("Numero %d trovato in posizione: %d\n", n, pos);
    }else {
    printf("Numero %d non trovato!\n", n);
    }

    volte = ricerca_occ(v, riemp, n, volte);
    printf("Il numero e' stato trovato %d volte\n", volte);

    printf("Quale numero vuoi eliminare?\n");
    scanf("%d", &n_elim);
    
    if(ricerca(v, riemp, n_elim, &pos) == true){

        eliminazione(v, &riemp, n_elim, &pos);

        printf("Riempimento aggiornato: %d\n", riemp);

        printf("\n| ");
        for(int i = 0; i<riemp; i++){

            printf("%d ", *(v+i));
        }
        printf("|\n");
    }else {
    printf("Numero %d non trovato eliminazione non riuscita!\n", n);
    }

    return 0;
}

bool ricerca(int *v, int riemp, int n, int *pos){

    for(int i = 0; i<riemp; i++){

        if(*(v + i) == n){
            *pos = i;
            return true;
        }
    }
    return false;

}

int ricerca_occ(int *v, int riemp, int n, int volte){

    for(int i = 0; i < riemp; i++){
        if(*(v+i) == n){
            volte++;
        }
    }
    return volte;
}

void eliminazione(int *v, int *riemp, int n_elim, int *pos){

    ricerca(v, *riemp, n_elim, pos);
    for(int i = *pos; i<*riemp-1; i++){
     *(v + i) = *((v + i)+1);
    }
    (*riemp)--;

}