//Questo programma manipola un'array di vettori tramite l'utilizzo di puntatori

#include <stdbool.h>
#include <stdio.h>
#define MAXDIM 100

void riempi_array(int *v, int riemp);
void stampa_array(int *v, int riemp);
void inserimento(int *v, int *riemp, int ins);
void ricerca(int *v, int riemp, int valore_da_cercare, int *pos);
void cancellazione(int *v, int *riemp, int canc, int *pos);
void cont_occ(int *v, int riemp, int valore_da_cercare);

int main(){

    int v[MAXDIM]; //Inizializzo vettore
    int riemp = 0; //Riempimento vettore
    int scelta = 0; //Scelta menù interattivo
    int ins = 0; //Numero da inserire
    int pos = 0; //Posizione numero da ricercare
    int canc = 0; //Numero da cancellare
    int valore_da_cercare = 0; //Numero da ricercare

    //Inizializzazione array
    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &riemp);
    riempi_array(v, riemp);

    do {
    printf("Menu' interattivo\n");
    printf("1. Stampa\n");
    printf("2. Inserimento\n");
    printf("3. Cancellazione\n");
    printf("4. Ricerca\n");
    printf("5. Conteggio Occorrenze\n");
    printf("0. Esci\n");
    printf("Quale operazione vuoi effettuare?\n");
    scanf("%d", &scelta);

    switch(scelta){

        case 1:
        stampa_array(v, riemp);
        break;

        case 2:
        printf("Quale numero vuoi inserire?\n");
        scanf("%d", &ins);
        inserimento(v, &riemp, ins);
        break;

        case 3:
        printf("Quale numero vuoi cancellare?\n");
        scanf("%d", &canc);
        cancellazione(v, &riemp, canc, &pos);
        break;

        case 4:
        printf("Quale numero vuoi cercare?\n");
        scanf("%d", &valore_da_cercare);
        ricerca(v, riemp, valore_da_cercare, &pos);
        break;

        case 5:
        printf("Di quale numero vuoi cercare le occorrenze?\n");
        scanf("%d", &valore_da_cercare);
        cont_occ(v, riemp, valore_da_cercare);
        break;

        default:
        printf("Scelta non consentita!");
        break;
    }

    }while (scelta != 0);

    return 0;
}

void riempi_array(int *v, int riemp){ //Inserimento iterativo di interi nell'array

    int n = 1;
    printf("Inserisci %d elementi:\n", riemp);
    for(int i = 0; i < riemp; i++){ 
        scanf("%d", (v + i));
        printf("Inserisci ancora %d elementi\n", riemp-n);
        n++;
    }
}

void stampa_array(int *v, int riemp){ //Stampa iterativa di interi nell'array

    printf("\n| ");
    for(int i = 0; i < riemp; i++){
        printf("%d ", *(v + i));
    }
    printf("|\n");
}

void inserimento(int *v, int *riemp, int ins){ //Inserimento di un numero in coda all'array

    if((*riemp + 1)!= MAXDIM){
    *(v + (*riemp)) = ins;
    (*riemp)++;
    }else {
    printf("Elemento non inserito, dimensione massima raggiunta!\n");
    }
}

void ricerca(int *v, int riemp, int valore_da_cercare, int *pos){ //Ricerca di un elemento dato il valore

    bool esito = false;
    
    for(int i = 0; i < riemp; i++){
        if(*(v + i) == valore_da_cercare){
            *pos = i;
            printf("L'elemento si trova in posizione %d\n", *pos);
            esito = true;
        }
    }
    if(esito == false){
        printf("Numero non trovato!");
    }
}

void cancellazione(int *v, int *riemp, int canc, int *pos){ //Cancellazione di un elemento dato il valore
    ricerca(v, *riemp, canc, pos);

    for(int i = *pos; i < *riemp; i++){
        *(v + i) = (*(v + i) + 1);
    }
    (*riemp)--;
    *pos = 0;

}

void cont_occ(int *v, int riemp, int valore_da_cercare){ //Conteggio occorrenze di un numero dato

    bool esito = false;
    int occ = 0;

    for(int i = 0; i < riemp; i++){
        if(*(v + i) == valore_da_cercare){
            (occ)++;
            esito = true;
        }
    }
    if(esito == false){
        printf("Numero non trovato!\n");
    }else {
    printf("Il numero e' stato trovato %d volte\n", occ);
    }
}