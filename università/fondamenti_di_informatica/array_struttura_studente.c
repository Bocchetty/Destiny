//Questo programma gestisce un'array di strutture "studente" nei quali vengono memorizzate varie informazioni

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 50
#define MAX_STUDENTI 100

struct studente{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int eta;
    float media_voti;
    bool lavoratore;
};
struct studente studenti[MAX_STUDENTI];

void inserisci_info(struct studente studenti[], int n_studenti);
void stampa_studente(struct studente studenti[], int n_studenti);
void flush();

int main(){
    
    int n_studenti = 0;

    printf("Inserisci il numero di studenti che vuoi inserire (Deve essere inferiore a %d)\n", MAX_STUDENTI);
    scanf("%d", &n_studenti);
    flush();
    inserisci_info(studenti, n_studenti);
    stampa_studente(studenti, n_studenti);

    return 0;
}

void flush(){

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void inserisci_info(struct studente studenti[], int n_studenti){

    int lavoratore = 0;

    for(int i = 0; i < n_studenti; i++){
        printf("Inserisci informazioni su studente N. %d\n", i);
        printf("Inserisci NOME:\n");
        fgets(studenti[i].nome, MAXLEN, stdin);
        printf("Inserisci COGNOME:\n");
        fgets(studenti[i].cognome, MAXLEN, stdin);
        printf("Inserisci ETA':\n");
        scanf("%d", &studenti[i].eta);
        printf("Inserisci MEDIA VOTI:\n");
        scanf("%f", &studenti[i].media_voti);
        printf("LAVORATORE? (si 1/no 0)\n");
        scanf("%d", &lavoratore);
        if(lavoratore == 1){
            studenti[i].lavoratore = true;
        }else if (lavoratore == 0) {
            studenti[i].lavoratore = false;
        }else {
            printf("Valore non valido!");
        }
        flush();
    }
}

void stampa_studente(struct studente studenti[], int n_studenti){

    for(int i = 0; i < n_studenti; i++){
        printf("Informazioni studente N. %d\n", i);
        printf("NOME: %s\n", studenti[i].nome);
        printf("COGNOME: %s\n", studenti[i].cognome);
        printf("ETA': %d\n", studenti[i].eta);
        printf("MEDIA VOTI: %f\n", studenti[i].media_voti);
        printf("LAVORATORE: %d\n", studenti[i].lavoratore);
    }
}