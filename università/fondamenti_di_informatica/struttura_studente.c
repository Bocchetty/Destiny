//Questo programma confronta le informazioni di due studenti manipolando due costrutti di tipo struct

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 100
#define n_voti 3

struct studente{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int eta;
    int voti [n_voti];
};

void stampa_studente(struct studente s);
bool studenti_omonimi(struct studente s1, struct studente s2);
int media_voti(struct studente s1, struct studente s2);
void flush();

int main(){

    struct studente s1, s2;

    printf("Inserisci le informazioni del primo studente\n");
    printf("Inserisci nome del primo studente\n");
    //scanf("%s",s1.nome);
    fgets(s1.nome, MAXLEN, stdin);
    printf("Inserisci cognome del primo studente\n");
    //scanf("%s",s1.cognome);
    fgets(s1.cognome, MAXLEN, stdin);
    printf("Inserisci eta del primo studente\n");
    scanf("%d", &s1.eta);
     for(int i = 0; i<n_voti; i++){
         printf("Inserisci voto esame\n");
         scanf("%d", &s1.voti[i]);
    }
    flush();

    printf("Inserisci le informazioni del secondo studente\n");
    printf("Inserisci nome del secondo studente\n");
    //scanf("%s",s2.nome);
    fgets(s2.nome, MAXLEN, stdin);
    printf("Inserisci cognome del secondo studente\n");
    //scanf("%s",s2.cognome);
    fgets(s2.cognome, MAXLEN, stdin);
    printf("Inserisci eta del secondo studente\n");
    scanf("%d", &s2.eta);
     for(int i = 0; i<n_voti; i++){
         printf("Inserisci voto esame\n");
         scanf("%d", &s2.voti[i]);
    }

    stampa_studente(s1);
    stampa_studente(s2);

    if(studenti_omonimi(s1, s2) == true){
        printf("I due studenti sono omonimi!\n");
    }else {
     printf("I due studenti non sono omonimi!\n");
    }

    if(media_voti(s1,s2) == -1){
        printf("%s %s ha la media piu' alta di %s %s\n", s1.nome, s1.cognome, s2.nome, s2.cognome);
    }else if (media_voti(s1,s2) == +1) {
        printf("%s %s ha la media piu' alta di %s %s\n", s2.nome, s2.cognome, s1.nome, s1.cognome);
    }else {
        printf("%s %s e %s %s hanno la stessa media\n", s1.nome, s1.cognome, s2.nome, s2.cognome);
    }

    return 0;
}

void flush(){

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void stampa_studente(struct studente s){

    printf("\n-----\n");
    printf("NOME: %s\n", s.nome);
    printf("COGNOME: %s\n", s.cognome);
    printf("ETA' %d\n", s.eta);
    printf("Voti ultimi esami:\n");
    for(int i= 0; i<n_voti; i++){
        printf("%d, ", s.voti[i]);
    }
    printf("\n");
    printf("\n-----\n");

}

bool studenti_omonimi(struct studente s1, struct studente s2){
    if(strcmp(s1.nome, s2.nome) == 0 && strcmp(s1.cognome, s2.cognome) == 0){
        return true;
    }

    return false;
}

int media_voti(struct studente s1, struct studente s2){
    int somma_s1 = 0;
    int somma_s2 = 0;

    for(int i = 0; i<n_voti; i++){
        somma_s1 += s1.voti[i];
        somma_s2 += s2.voti[i];
    }
    float media_s1 = (float)somma_s1/n_voti;
    float media_s2 = (float)somma_s2/n_voti;

    if(media_s1 > media_s2){
        return -1;
    }else if (media_s1 < media_s2) {
        return +1;
    }else {
     return 0;
    }
}