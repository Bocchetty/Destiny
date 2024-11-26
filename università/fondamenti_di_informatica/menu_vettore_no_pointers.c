//Menù contestuale per effettuare operazioni su array inseriti da tastiera

#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 100

void stampa(int v[], int riemp);
int inserimento(int v[], int riemp, int valore);
int eliminazione(int v[], int riemp, int valore_da_eliminare);
int ricerca(int v[], int riemp, int valore_da_ricercare);

int main(){

    int scelta = 0;
    int v[MAXDIM];
    int dim = 0;

    printf("Scrivi la dimensione del tuo array\n");
    scanf("%d", &dim);
    for (int i = 0; i < dim; i++){

     printf("Inserisci un numero nell'array A\n");
     scanf("%d", &v[i]);
    }

    int riemp = dim;
    int valore = 0;
    int ris = 0;

    do{

    printf("Quale operazione vuoi effettuare?\n 1. Stampa\n 2. Inserimento\n 3. Eliminazione\n 4 Ricerca\n 0. Esci\n");
    scanf("%d", &scelta);

    switch(scelta){

        case 1:
         stampa(v, riemp);
         break;

        case 2:
         printf("Scrivi il valore da inserire\n");
         scanf("%d", &valore);
         ris = inserimento(v, riemp, valore); //riemp aggiornato
         if (ris != -1)
             riemp = ris; //Aggiorno il riempimento dopo l'inserimento
         else
          printf("Limite di dimensione raggiunto!");
         break;

        case 3:
         printf("Scrivi l'indice dell'elemento da eliminare\n");
         scanf("%d", &valore);
         ris = eliminazione(v, riemp, valore);
         if (ris != -1)
             riemp = ris; //Aggiorno il riempimento dopo l'eliminazione
         else
          printf("Indice non valido!");
         break;
        
        case 4:
         printf("Scrivi l'elemento che vuoi ricercare\n");
         scanf("%d", &valore);
         ris = ricerca(v, riemp, valore);
         if (ris == -1){
            printf("Valore non trovato!\n");
         }else{
         printf("L'indice in cui si trova il valore e' %d\n", ris);
         }
         break;

        default:
            if (scelta!= 0)
             printf("Scelta non consentita!\n");
            else
             break;
    }
    }while (scelta != 0);
    printf("Ciao!\n");

    return 0;
}

void stampa(int v[], int riemp){

 printf("Nel vettore sono presenti i seguenti elementi:\n");
 printf("[");

    for (int i = 0; i < riemp; i++)
        printf("\t%d,\t", v[i]);

    printf("]\n");
}

int inserimento(int v[], int riemp, int valore){

    if (riemp < MAXDIM){
     v[riemp] = valore; //Inserisco il valore all'indice attuale del riempimento
     riemp ++;
     return riemp;

    }else {
     return -1;
    }
}

int eliminazione(int v[], int riemp, int valore){

    if (valore < 0 || valore > riemp)
        return -1;
    else{
     riemp--;
     for(int i = valore; i < riemp; i++)
     v[i] = v[i+1];
    }

    return riemp;

}

int ricerca(int v[], int riemp, int valore){

    bool valore_trovato = false;
    int i = 0;
    while( i < riemp && valore_trovato == false){

         if(valore == v[i]){
             valore_trovato = true;
         }else{
             i++;
         }
    }
    if (valore_trovato == true){
        return i;
    }else{
        return -1;
    }
}