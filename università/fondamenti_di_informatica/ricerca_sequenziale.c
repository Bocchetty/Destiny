//Questo programma implementa la ricerca sequenziale

#include<stdio.h>
#include<stdbool.h>
#define MAXDIM 20

void ricerca_sequenziale(int *v, int riemp, int confronti, int n);

int main(){

    int riemp = 0;
    int v[MAXDIM];
    int confronti = 0;
    int n = 0;
    
    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &riemp);

    printf("Inserisci %d elementi\n", riemp);
    for(int i = 0; i < riemp; i++){
        scanf("%d", v + i);
    }

    do{
    printf("Quale numero vuoi cercare?\n");
    scanf("%d", &n);
    ricerca_sequenziale(v, riemp, confronti, n);
    }while(n >= 0);

    return 0;
}

void ricerca_sequenziale(int *v, int riemp, int confronti, int n){

    bool trovato = false;
    if(n < 0){
        return;
    }

    for(int i = 0; i < riemp; i++){
        
        if(*(v + i) == n){
            trovato = true;
            confronti = i + 1;
        }
    }

    if(trovato == true){
        printf("Numero trovato!\n");
        printf("Numero confronti: %d\n", confronti);
    }else{
        printf("Numero non trovato\n");
    }
}