//Questo programma manipola un'array di strutture studente con le relative informazioni

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAXLEN 50
#define MAXDIM 100

struct studente{

    char nome[MAXLEN];
    char cognome[MAXLEN];
    int eta;
    float media;
    bool lavoratore;

};

struct studente studenti[MAXDIM];

void flush();
void inserisci_studente(struct studente *studenti, int *riemp);
void stampa(struct studente *studenti, int riemp, char *nome_cercato, char *cognome_cercato);
int eta(struct studente *studenti, int riemp, char *nome_cercato, char *cognome_cercato);
void media_non_lavoratori(struct studente *studenti, int riemp);
void stampa_inf(struct studente *studenti, int riemp);

int main(){

    int scelta = 0;
    int riemp = 0;
    char nome_cercato[MAXLEN];
    char cognome_cercato[MAXLEN];
    int ris = 0;

    do {
    
    printf("Menu' interattivo\n");
    printf("1. Inserisci studente\n");
    printf("2. Stampa studente dato nome e cognome\n");
    printf("3. Eta' dati nome e cognome\n");
    printf("4. Media studenti non lavoratori\n");
    printf("5. Stampa studenti con eta' inferiore a 25 anni\n");
    printf("0. Esci\n");
    printf("Quale operazione vuoi eseguire?\n");
    scanf("%d", &scelta);
    flush();

    switch (scelta) {

        case 1:
        inserisci_studente(studenti, &riemp);
        break;

        case 2:
        stampa(studenti, riemp, nome_cercato, cognome_cercato);
        break;

        case 3:
        ris = eta(studenti, riemp, nome_cercato, cognome_cercato);
        if(ris != -1){
            printf("L'eta' di %s %s e' %d\n", nome_cercato, cognome_cercato, ris);
        };
        break;

        case 4:
        media_non_lavoratori(studenti, riemp);
        break;

        case 5:
        stampa_inf(studenti, riemp);
        break;

        case 0:
        printf("Arrivederci\n");
        break;

        default:
        printf("Valore inserito non valido!\n");
        break;
    
    }

    }while (scelta != 0);

    return 0;
}

void flush(){

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void inserisci_studente(struct studente *studenti, int *riemp){

    if((*riemp + 1) < MAXDIM){
    
     int lun = 0;
     char lavoro;
     printf("Inserisci dati studente\n");
     printf("Inserisci NOME:\n");
     fgets((studenti + *riemp) -> nome, MAXLEN, stdin);

     lun = strlen((studenti + *riemp) -> nome);
     (studenti + *riemp) -> nome[lun-1] = '\0';

     printf("Inserisci COGNOME:\n");
     fgets((studenti + *riemp) -> cognome, MAXLEN, stdin);

     lun = strlen((studenti + *riemp) -> cognome);
     (studenti + *riemp) -> cognome[lun-1] = '\0';

     printf("Inserisci ETA'\n");
     scanf("%d", &(studenti + *riemp) -> eta);
     printf("Inserisci MEDIA\n");
     scanf("%f", &(studenti + *riemp) -> media);
     printf("Studente LAVORATORE? (s/n)\n");
     scanf("%s", &lavoro);

     if(lavoro == 's'){
         (studenti + *riemp) -> lavoratore = true;
     }else{
         (studenti + *riemp) -> lavoratore = false;
     }

     (*riemp)++;
     flush();
    }else {
    return;
    }
}

void stampa(struct studente *studenti, int riemp, char *nome_cercato, char *cognome_cercato){

    bool trovato = false; 
    printf("Inserisci il nome dello studente che cerchi\n");
    scanf("%s", nome_cercato);
    printf("Inserisci il cognome dello studente che cerchi\n");
    scanf("%s", cognome_cercato);
    flush();
    printf("\n");

    for(int i = 0; i < riemp; i++){

        if((strcmp((studenti + i)->nome, nome_cercato) == 0) && (strcmp((studenti + i)->cognome, cognome_cercato) == 0)){

            trovato = true;
            printf("Studente trovato!\n");
            printf("%s\n", (studenti + i)->nome);
            printf("%s\n", (studenti + i)->cognome);
            printf("%d\n", (studenti + i)->eta);
            printf("%0.2f\n", (studenti + i)->media);
            if(((studenti + i)->lavoratore) == 1){
                printf("Lavoratore\n");
            }else {
                printf("Non lavoratore\n");
            }
            
        }
    }
    if(trovato == false){
    printf("Studente non trovato!\n");
    }
}

int eta(struct studente *studenti, int riemp, char *nome_cercato, char *cognome_cercato){
    
    bool trovato = false; 
    int eta = 0;
    printf("Inserisci il nome dello studente di cui cerchi l'eta'\n");
    scanf("%s", nome_cercato);
    printf("Inserisci il cognome dello studente di cui cerchi l'eta'\n");
    scanf("%s", cognome_cercato);
    flush();
    printf("\n");

    for(int i = 0; i < riemp; i++){

        if((strcmp((studenti + i)->nome, nome_cercato) == 0) && (strcmp((studenti + i)->cognome, cognome_cercato) == 0)){

            trovato = true;
            eta = (studenti + i)->eta;
        }
    }
    if(trovato == false){
    printf("Studente non trovato!\n");
    return -1;
    }else {
    return eta;
    }
}

void media_non_lavoratori(struct studente *studenti, int riemp){

    bool lav = false;
    printf("Media studenti non lavoratori:\n");
    for(int i = 0; i < riemp; i++){
        if((studenti + i)->lavoratore == 0){
            lav = true;
            printf("Media di %s %s e' %0.2f\n", (studenti + i)->nome, (studenti + i)->cognome, (studenti + i)->media);
        }
    }
    if(lav == false){
        printf("Non sono presenti studenti non lavoratori\n");
    }
}

void stampa_inf(struct studente *studenti, int riemp){

    bool trov = false;
    for(int i = 0; i < riemp; i++){
        if((studenti + i)->eta < 25){
            trov = true;
            printf("Info studente:\n");
            printf("%s\n", (studenti + i)->nome);
            printf("%s\n", (studenti + i)->cognome);
            printf("%d\n", (studenti + i)->eta);
            printf("%0.2f\n", (studenti + i)->media);
            if((studenti + i)->lavoratore == 1){
                printf ("Lavoratore\n");
            }else {
                printf("Non lavoratore\n");
            }
        }
    }
    if(trov == false){
        printf("Non sono presenti studenti con eta' inferiore a 25 anni\n");
    }
}