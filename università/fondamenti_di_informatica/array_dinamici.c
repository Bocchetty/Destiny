//Questo programma manipola un'array allocato dinamicamene

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* inserimento(int *v, int *riemp, int *pos);
void stampa(int *v, int riemp);
int ricerca_minimo(int *v, int riemp);
void conteggio_zero(int *v, int riemp);
int * cancellazione(int *v, int *riemp, int *pos);
void ricerca(int *v, int riemp);

int main(){
    
    int riemp = 0;
    int scelta = 0;
    int pos = -1;
    int pos_min = -1;

    printf("Inserisci la dimensione del vettore:\n");
    scanf("%d", &riemp);

    int *v = (int*)malloc(sizeof(int) * riemp); //Alloco dinamicamente un'array di interi
    if(v == NULL){
        printf("Allocazione non riuscita!\n");
        return -1;
    }

    printf("Inserisci elementi nell'array:\n");
    for(int i = 0; i < riemp; i++){
        scanf("%d", v + i);
    }

    do {
     printf("Menu' interattivo\n");
     printf("1. Inserimento di un elemento in una determinata posizione\n");
     printf("2. Stampa elementi\n");
     printf("3. Ricerca dell'elemento con valore minimo, restituendone la posizione\n");
     printf("4. Conteggio degli elementi con valore pari a zero\n");
     printf("5. Rimozione di un elemento data la sua posizione\n");
     printf("6. Ricerca di un elemento\n");
     printf("0. Esci\n");

     printf("Quale operazione vuoi eseguire?\n");
     scanf("%d", &scelta);

     switch (scelta){

        case 1:
        v = inserimento(v, &riemp, &pos);
        break;

        case 2:
        stampa(v, riemp);
        break;

        case 3:
        pos_min = ricerca_minimo(v, riemp);
        printf("L'elemento minimo si trova in posizione: %d\n", pos_min);
        break;

        case 4:
        conteggio_zero(v, riemp);
        break;

        case 5:
        v = cancellazione(v, &riemp, &pos);
        break;

        case 6:
        ricerca(v, riemp);
        break;

        case 0:
        printf("Arrivederci!\n");
        break;

        default:
        printf("Scelta non consentita!");
        break;
     }

    }while (scelta != 0);
    free(v);

    return 0;
}

int* inserimento(int *old_v, int *riemp, int *pos){

    int n = 0;
    printf("Che elemento vuoi inserire?\n");
    scanf("%d", &n);

    while(*pos == -1 || *pos > *riemp){
        printf("In quale posizione?\n");
        scanf("%d", pos);
        if(*pos > *riemp){
        printf("Posizione non valida, riprova\n");
        }
    }

    int *new_v = (int*)malloc(sizeof(int) * ((*riemp) + 1));

    if(new_v != NULL){

     for(int i = 0; i < *pos; i++){

     *(new_v + i) = *(old_v + i);
     }

     *(new_v + *pos) = n;

     for(int i = *pos; i < *riemp; i++){

     *(new_v + i + 1) = *(old_v + i);
     }

     (*riemp)++;
     free(old_v);

     }else{
    
     printf("Inserimento fallito, memoria non allocata!\n");
     new_v = old_v;
    }

    return new_v;
}

void stampa(int *v, int riemp){

    printf("\n|");
    for(int i = 0; i < riemp; i++){

        printf(" %d ", *(v + i));
    }
    printf("|\n");
}

int ricerca_minimo(int *v, int riemp){

    int minimo = 1000;
    int pos;
    for(int i = 0; i < riemp; i++){
        if(*(v + i) < minimo){
            minimo = *(v + i);
            pos = i;
        }
    }
    printf("L'elemento minimo e': %d\n", minimo);
    return pos;
}

void conteggio_zero(int *v, int riemp){

    int cont = 0;
    for(int i = 0; i < riemp; i++){
        if(*(v + i) == 0){
            cont++;
        }
    }
    printf("Il numero di elementi con valore zero e': %d\n", cont);
}

int * cancellazione(int *old_v, int *riemp, int *pos){
    
    printf("Quale posizione vuoi eliminare?\n");
    scanf("%d", pos);

    int* new_v = (int*)malloc(sizeof(int) * (*riemp) - 1);

    for(int i = 0; i < *pos; i++){
        *(new_v + i) = *(old_v + i);
    }

    for(int i = *pos; i < *riemp; i++){
        *(new_v + i) = *(old_v + i + 1);
    }

    (*riemp)--;
    free(old_v);
    return new_v;
}

void ricerca(int *v, int riemp){

    int pos = 0;
    int val = 0;
    bool trovato = false;
    printf("Quale valore vuoi cercare?\n");
    scanf("%d", &val);
    for(int i = 0; i < riemp; i++){

        if(*(v + i) == val){
            trovato = true;
            pos = i;
        }
    }
    if(trovato == true){
    printf("Valore %d trovato in posizione %d\n", val, pos);
    }else {
    printf("Valore non trovato!\n");
    }
}