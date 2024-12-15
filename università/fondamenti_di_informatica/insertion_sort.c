//Questo algoritmo implementa l'insertion sort su un vettore

#include<stdio.h>
#define MAXDIM 100

void stampa(int *v, int riemp);
void scambia(int *a, int *b);
void insertion_sort(int *v, int riemp);

int main(){

    int v[MAXDIM];
    int riemp = -1;

    printf("Quanti elementi vuoi inserire nell'array?\n");
    scanf("%d", &riemp);

    printf("Inserisci %d elementi nell'array\n", riemp);
    for(int i = 0; i < riemp; i++){
        scanf("%d", v + i);
    }

    stampa(v, riemp);

    printf("Riordino gli elementi dell'array con l'insertion sort\n");
    insertion_sort(v, riemp);

    stampa(v, riemp);

    return 0;
}

void stampa(int *v, int riemp){

    printf("\n|");
    for(int i = 0; i < riemp; i++){
        printf(" %d ", *(v + i));
    }
    printf("|\n");
}

void scambia(int *a, int *b){
    int tmp = *a;
    *a =  *b;
    *b = tmp;
}

void insertion_sort(int *v, int riemp){

    for(int i = 1; i < riemp; i++){
        int j = i;
        while(*(v + j) < *(v + j-1) && j > 0){
         scambia((v + j), (v + j-1));
         j--;
        }
    }
}