//Questo programma implementa la ricerca binaria

#include<stdio.h>
#include<stdbool.h>
#define MAXDIM 20

void ricerca_binaria(int *v, int riemp, int confronti, int n);

int main(){

    int riemp = 0;
    int v[MAXDIM];
    int confronti = 0;
    int n = 0;
    int pos = -1;
    
    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &riemp);

    printf("Inserisci %d elementi in maniera ordinata\n", riemp);
    for(int i = 0; i < riemp; i++){
        scanf("%d", v + i);
    }

    do{
    printf("Quale numero vuoi cercare?\n");
    scanf("%d", &n);
    ricerca_binaria(v, riemp, confronti, n);
    }while(n >= 0);

    return 0;
}

void ricerca_binaria(int *v, int riemp, int confronti, int n){

    int primo = 0;
    int ultimo = riemp-1;
    bool trovato = false;
    int pos = -1;

    if(n < 0){
        return;
    }

    do {
     int medio = (int)((primo + ultimo)/2);
     confronti ++;

     if(n == *(v + medio)){
         pos = medio;
         trovato = true;
     }else if(n < *(v + medio)){
         ultimo = medio-1;
     }else {
         primo = medio +1;
     }
    }while(primo<=ultimo && pos == -1);

    if(trovato == true){
        printf("Numero trovato in posizione: %d\n", pos);
        printf("Numero di confronti: %d\n", confronti);
    }else {
        printf("Numero non trovato!\n");
    }
}