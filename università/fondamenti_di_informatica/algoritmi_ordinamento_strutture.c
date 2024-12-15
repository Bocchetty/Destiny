//Questo programma applica gli algoritmi di ordinamento su di un array di strutture

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAXLEN 50
#define MAXDIM 100

struct studente{

    char nome[MAXLEN];
    char cognome[MAXLEN];
    int eta;
};

struct studente studenti[100];

void flush();
void remove_n(struct studente *studenti, int riemp);
void inserimento(struct studente *studenti, int *riemp);
void stampa(struct studente *studenti, int riemp);
void scambia(struct studente *a, struct studente *b);
int minimo_char(struct studente *studenti, int inizio, int fine);
void selection_sort(struct studente *studenti, int riemp);
void insertion_sort();
void selection_sort_indici();

int main(){

    bool inserimenti_terminati = false;
    int riemp = 0;
    int terminati = -1;
    int scelta = -1;

    do {
     printf("Inserisci uno studente\n");
     inserimento(studenti, &riemp);

     printf("Vuoi inserire un'altro studente? (1.Si/0.No)\n");
     scanf("%d", &terminati);
     flush();
     if(terminati == 0){
        inserimenti_terminati = true;
     }

    }while(inserimenti_terminati == false);

    stampa(studenti, riemp);

    printf("Scegli quale ordinamento usare:\n");
    printf("1. Selection sort\n");
    printf("2. Insertion sort\n");
    printf("3. Selection sort su indici\n");
    scanf("%d", &scelta);
    flush();

    switch (scelta){

        case 1:
        printf("Ordinamento per cognome utilizzando selection sort\n");
        selection_sort(studenti, riemp);
        break;

        case 2:
        printf("Ordinamento per cognome utilizzando insertion sort\n");
        break;

        case 3:
        printf("Ordinamento per cognome utilizzando selection sort su indici\n");
        break;

        default:
        printf("Scelta non consentita!");
        break;
    }

    stampa(studenti, riemp);

    return 0;
}

void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void remove_n(struct studente *studenti, int riemp){

    (studenti + riemp)->nome[strcspn((studenti + riemp) -> nome, "\n")] = '\0';
    (studenti + riemp)->cognome[strcspn((studenti + riemp) -> cognome, "\n")] = '\0';
}

void inserimento(struct studente *studenti, int *riemp){

    if(*riemp + 1 < MAXDIM){
     printf("Inserisci Nome:\n");
     fgets((studenti + *riemp) -> nome, MAXLEN, stdin);
     printf("Inserisci Cognome:\n");
     fgets((studenti + *riemp) -> cognome, MAXLEN, stdin);

     printf("Inserisci Eta':\n");
     scanf("%d", &(studenti + *riemp) -> eta);

     flush();
     (*riemp)++;
     remove_n(studenti, *riemp);
     printf("Studente aggiunto!\n");
    }else{
     printf("Inserimento fallito dimensione massima raggiunta!\n");
    }
}

void stampa(struct studente *studenti, int riemp){

    printf("Info studenti:\n");
    int n = 1;

    for(int i = 0; i < riemp; i++){

        printf("%d) %s %s - %d anni\n", n, (studenti + i)->cognome, (studenti + i)->nome, (studenti + i)->eta);
        n++;
    }
}

void scambia(struct studente *a, struct studente *b){

//scambia campo a campo
    struct studente  tmp = *a;
    *a = *b;
    *b = tmp;
}

int minimo_char(struct studente *studenti, int inizio, int fine){

    char min;
    int indice_min = -1;

    for(int i = inizio; i < fine; i++){
        /*
        if(*(studenti + i)->cognome < min || i == inizio){
            min = *(studenti + i)->cognome;
            indice_min = i;
        }
        */

        if(strcmp((studenti + i)->cognome, &min)<0 || i == inizio){
            min = *(studenti + i)->cognome;
            indice_min = i;
        }
    }
    return indice_min;
}

void selection_sort(struct studente *studenti, int riemp){

    for(int i = 0; i < riemp-1; i++){
        int indice_min = minimo_char(studenti, i, riemp-1);
        scambia((studenti + i), (studenti + indice_min));
    }
}