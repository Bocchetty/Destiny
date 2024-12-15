//Questo programma implementa l'algoritmo di ordinamento selection sort

#include<stdio.h>
#include<stdbool.h>
#define MAXDIM 100

void stampa(int *v, int riemp);
void scambia(int *a, int*b);
int minimo(int *v, int inizio, int fine);
void selection_sort(int *v, int riemp);
void ricerca_binaria(int *v, int riemp, int n);

int main(){

    int v[MAXDIM];
    int riemp = 0;
    int n = 0;
    printf("Inserisci grandezza del vettore (minimo 20)\n");
    scanf("%d", &riemp);

    printf("Inserisci numeri interi positivi nel vettore:\n");
    for(int i = 0; i < riemp; i++){
        scanf("%d", v + i);
    }

    stampa(v, riemp);

    printf("Ordino il vettore in maniera crescente\n");
    selection_sort(v, riemp);

    stampa(v, riemp);

    do{
        printf("Quale numero vuoi cercare?\n");
        scanf("%d", &n);
        ricerca_binaria(v, riemp, n);
    }while(n > 0);

    return 0;
}

void stampa(int *v, int riemp){

    printf("\n|");
    for(int i = 0; i < riemp; i++){
        printf(" %d ", *(v + i));
    }
    printf("|\n");
}

void scambia(int *a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int minimo(int *v, int inizio, int fine){

    int min;
    int indice_min = -1;
    for(int i = inizio; i <= fine; i++){
        if(*(v + i) < min || i == inizio){
            min = *(v + i);
            indice_min = i;
        }
    }
    return indice_min;
}

void selection_sort(int *v, int riemp){

    for(int i = 0; i < riemp-1; i++){
        int pos_min = minimo(v, i, riemp-1);
        scambia((v + i), (v + pos_min));
    }
}

void ricerca_binaria(int *v, int riemp, int n){

    int primo = 0;
    int ultimo = riemp-1;
    bool trovato = false;
    int pos = -1;

    if(n < 0){
        return;
    }

    do{
        
        int medio = (int)(primo + ultimo)/2;
        if(*(v + medio) == n){
            trovato = true;
            pos = medio;
        }else if(*(v + medio) < n){
            primo = medio + 1;
        }else{
            ultimo = medio - 1;
        }
    }while(primo <= ultimo && pos == -1);

    if(trovato == true){
        printf("Numero trovato!\n");
    }else {
        printf("Numero non trovato!\n");
    }
}