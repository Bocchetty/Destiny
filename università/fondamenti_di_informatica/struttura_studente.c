//Questo programma confronta le informazioni di due studenti manipolando due costrutti di tipo struct

#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define n_voti 3

struct studente{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int eta;
    int voti [n_voti];
};

void stampa_studente(struct studente s);

int main(){

    struct studente s1, s2;

    printf("Inserisci le informazioni del primo studente\n");
    printf("Inserisci nome del primo studente\n");
    scanf("%s",s1.nome);
    printf("Inserisci cognome del primo studente\n");
    scanf("%s",s1.cognome);
    printf("Inserisci eta del primo studente\n");
    scanf("%d", &s1.eta);
     for(int i = 0; i<n_voti; i++){
         printf("Inserisci voto esame\n");
         scanf("%d", &s1.voti[i]);
    }

    printf("Inserisci le informazioni del secondo studente\n");
    printf("Inserisci nome del secondo studente\n");
    scanf("%s",s2.nome);
    printf("Inserisci cognome del secondo studente\n");
    scanf("%s",s2.cognome);
    printf("Inserisci eta del secondo studente\n");
    scanf("%d", &s2.eta);
     for(int i = 0; i<n_voti; i++){
         printf("Inserisci voto esame\n");
         scanf("%d", &s2.voti[i]);
    }

    stampa_studente(s1);
    stampa_studente(s2);

    return 0;
}

void stampa_studente(struct studente s){

    printf("\n-----\n");
    printf("NOME: %s\n", s.nome);
    printf("COGNOME: %s\n", s.cognome);
    printf("ETA' %d\n", s.eta);
    printf("Voti ultimi esami;\n");
    for(int i= 0; i<n_voti; i++){
        printf("%d\n", s.voti[i]);
    }
    printf("\n-----\n");

}