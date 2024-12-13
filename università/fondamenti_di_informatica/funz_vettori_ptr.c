//Questo programma manipola un'array di interi

#include<stdio.h>
#include <math.h>
#include<stdbool.h>
#define MAXDIM 10

void inserimento(int *v, int n);
void stampa(int *v);
void ricerca(int*v, int quad, int*p, int *curr_ind);
void stampa_2(int*v, int*p, int *curr_ind);

int main(){

    int v[MAXDIM];
    int n = 0;
    int quad = 0;
    int *p;
    int curr_ind = 0;

    printf("Inserisci un numero < di %d che popolera' l'array con i suoi quadrati fino a MAXDIM\n", MAXDIM);
    scanf("%d", &n);

    inserimento(v, n);
    stampa(v);

    printf("Inserisci il quadrato di cui desideri il puntatore\n");
    scanf("%d", &quad);

    ricerca(v, quad, p, &curr_ind);
    stampa_2(v, p, &curr_ind);

    return 0;
}

void inserimento(int *v, int n){
    for(int i = 0; i <= MAXDIM; i++){
        *(v + i) = pow(n, i);
    }
}

void stampa(int *v){

    printf("\n|");
    for(int i = 0; i<=MAXDIM; i++){
        printf(" %d ", *(v + i));
    }
    printf("|\n");
}

void ricerca(int*v, int quad, int *p, int *curr_ind){

    bool trovato = false;
    for(int i = 0; i<=MAXDIM; i++){
        if(*(v + i) == quad){
            printf("%p", (v + i));
            int*p = (v + i);
            *curr_ind = i;
            trovato = true;
        }
    }

    if(trovato == false){
        printf("Quadrato non trovato!\n");
    }
}

void stampa_2(int*v, int*p, int *curr_ind){

    printf("\n|");
    for(int i = *curr_ind; i<=MAXDIM; i++){
        printf(" %d ", *(v + i));
    }
    printf("|\n");

}