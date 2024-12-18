#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct studente{
    char matricola[9];
    char nome[10];
    char cognome[30];
    int esami_sostenuti;
};

struct studente_media{
    char matricola[9];
    bool maggiore_media;
};

void inserisci_studenti(struct studente *studenti, int riemp);
void stampa(struct studente *studenti, int riemp);
void scambia(struct studente *a, struct studente *b);
int minimo_matricola(struct studente *studenti, int inizio, int riemp);
void selection_sort(struct studente *studenti, int riemp);
void ricerca_binaria(struct studente *studenti, int riemp);
float media_esami(struct studente *studenti, int riemp);
void studenti_media(struct studente *studenti, struct studente_media *studenti_m, int riemp);
void stampa_media(struct studente_media *studenti_m, int riemp);

int main(){
    
    int riemp = 0;
    
    printf("Quanti studenti vuoi aggiungere?\n");
    scanf("%d", &riemp);
    getchar();
    
    struct studente *studenti = malloc(riemp * sizeof(struct studente));
    
    inserisci_studenti(studenti, riemp);
    
    stampa(studenti, riemp);
    
    selection_sort(studenti, riemp);
    printf("Studenti ordinati:\n");
    stampa(studenti, riemp);
    
    ricerca_binaria(studenti, riemp);
    
    struct studente_media *studenti_m = malloc(riemp * sizeof(struct studente_media));
    studenti_media(studenti, studenti_m, riemp);
    stampa_media(studenti_m, riemp);
    
    free(studenti);
    free(studenti_m);
    return 0;
}

void inserisci_studenti(struct studente *studenti, int riemp){
    
    printf("Inserisci le informazioni di %d studenti\n", riemp);
    for(int i = 0; i < riemp; i++){
        
        printf("Matricola:\n");
        scanf("%s", (studenti + i)-> matricola);
        
        printf("Nome:\n");
        scanf("%s", (studenti + i)-> nome);
        getchar();
        
        printf("Cognome:\n");
        fgets((studenti + i)-> cognome, 30, stdin);
        (studenti + i)->cognome[strcspn((studenti + i)->cognome, "\n")]='\0';
        
        printf("Numero di esami sostenuti:\n");
        scanf("%d", &(studenti + i)-> esami_sostenuti);
        
    }
}

void stampa(struct studente *studenti, int riemp){
    
    printf("Lista studenti:\n");
    
    for(int i = 0; i < riemp; i++){
        
     printf("Matricola\tNome\tCognome\t\tNumero esami sostenuti\n");
     
     printf("%s\t\t%s\t%s\t\t%d\n",
                                (studenti + i)->matricola,
                                (studenti + i)->nome,
                                (studenti + i)->cognome,
                                (studenti + i)->esami_sostenuti);
    }
}

void scambia(struct studente *a, struct studente *b){
    
    struct studente temp = *a;
    *a = *b;
    *b = temp;
}

int minimo_matricola(struct studente *studenti, int inizio, int riemp){
    
    int pos_min = 0;
    char min[9];
    
    for(int i = inizio; i<riemp; i++){
        if(i==inizio || strcmp((studenti + i)->matricola, min)<0){
            strcpy(min, (studenti + i)->matricola);
            pos_min = i;
        }
    }
    return pos_min;
}

void selection_sort(struct studente *studenti, int riemp){
    
    for(int i = 0; i < riemp-1; i++){
        
        int pos_min = minimo_matricola(studenti, i ,riemp);
        scambia((studenti + i), (studenti + pos_min));
    }
}

void ricerca_binaria(struct studente *studenti, int riemp){
    
    int pos = -1;
    int inizio = 0;
    int fine = riemp;
    char matricola[9];
    bool trovato = false;
    
    printf("Inserisci matricola dello studente che cerchi\n");
    getchar();
    fgets(matricola, 9, stdin);
    matricola[strcspn(matricola, "\n")]='\0';
    
    do{
        int medio = (inizio + fine)/2;
        
        if(strcmp((studenti + medio)->matricola, matricola)==0){
            pos = medio;
            trovato = true;
        }else if(strcmp((studenti + medio)->matricola, matricola)<0){
            fine = medio-1;
        }else{
            inizio = medio +1;
        }
    }while(inizio<=fine && pos ==-1);
    
    if(trovato == true){
        printf("Studente trovato in posizione %d\n", pos);
        printf("Matricola\tNome\tCognome\t\tNumero esami sostenuti\n");
             printf("%s\t\t%s\t%s\t\t%d\n",
                                (studenti + pos)->matricola,
                                (studenti + pos)->nome,
                                (studenti + pos)->cognome,
                                (studenti + pos)->esami_sostenuti);
        
     }else{
        printf("studente non trovato!\n");
    }
}

float media_esami(struct studente *studenti, int riemp){
    
    int somma = 0;
    float media = 0;
    
    for(int i = 0; i < riemp; i++){
        somma += (studenti + i)->esami_sostenuti;
    }
    
    media = (float)somma/riemp;
    
    return media;
}

void studenti_media(struct studente *studenti, struct studente_media *studenti_m, int riemp){
    
    float media = media_esami(studenti, riemp);
    
    for(int i = 0; i < riemp; i++){
        
        strcpy((studenti_m + i)->matricola, (studenti + i)->matricola);
        if((studenti+i)->esami_sostenuti>media){
            (studenti_m + i)->maggiore_media = true;
        }
    }
}

void stampa_media(struct studente_media *studenti_m, int riemp){
    printf("Lista studenti:\n");
    for (int i = 0; i < riemp; i++){
        
        printf("Matricola\tMaggiore Media\n");
        printf("%s\t\t\t%d\n", (studenti_m + i)->matricola, (studenti_m + i)->maggiore_media);
    }
}