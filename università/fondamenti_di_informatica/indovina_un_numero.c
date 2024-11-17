//Questo programma chiede all'utente di indovinare un numero già fissato

#include <stdio.h>

int main(){

    int n = 17; //Numero segreto
    int u = 0;  //Numero utente

    do{
        printf("Indovina il numero:\n");
        scanf("%d", &u);
    }while(u != n);
    
    printf("Hai indovinato il numero complimenti!");

    return 0;
}