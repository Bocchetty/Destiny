//Questo programma gestisce i voti della carriera universiraria di uno studente

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAXDIM 100

void stampa_voti(int *voti, bool *lode, int *riemp);
void inserimento(int *voti, bool *lode, int *riemp);
void calcolo_media(int *voti, int *riemp, float *media);
void ind_voto_max(int *voti, int *riemp);
void ind_voto_min(int *voti, int *riemp);

int main(){

    int scelta = 0;
    int voti[MAXDIM];
    bool lode[MAXDIM];
    int riemp = 0;
    float media = 0;

    do {
    
    printf("Menu' interattivo\n");
    printf("1. Inserimento nuovo voto\n");
    printf("2. Calcola media\n");
    printf("3. Individuazione voto max\n");
    printf("4. Individuazione voto min\n");
    printf("0. Esci\n");
    printf("Quale operazione vuoi eseguire?\n");
    scanf("%d", &scelta);

    switch (scelta) {

        case 1:
        inserimento(voti, lode, &riemp);
        break;

        case 2:
        calcolo_media(voti, &riemp, &media);
        break;

        case 3:
        ind_voto_max(voti, &riemp);
        break;

        case 4:
        ind_voto_min(voti, &riemp);
        break;

        case 0:
        printf("Arrivederci\n");
        break;

        default:
        printf("Valore inserito non valido!\n");
        break;
    
    }

    stampa_voti(voti, lode, &riemp);
    }while (scelta != 0);

    return 0;
}

void stampa_voti(int *voti, bool *lode, int *riemp){

    printf("\nLista voti:\n");
    printf("| ");
    for(int i = 0; i < *riemp; i++){
        printf("%d ", *(voti + i));
        if(*(voti+i) == 30){
            if(*(lode + i) == true){
                printf("con lode ");
            }
        }
    }
    printf("|\n");
}

void inserimento(int *voti, bool *lode, int *riemp){

    int voto = 0;
    printf("Inserisci voto (18<=voto<=30)\n");
    scanf("%d", &voto);
    if(voto>=18 && voto<=30){
        *(voti + *riemp) = voto;
        if(voto == 30){
            char voto_lode;
            printf("Con lode? (S/N)\n");
            scanf(" %c", &voto_lode);
            if(voto_lode == 's'){
                *(lode + *riemp) = true;
            }
        }else {
        *(lode + *riemp) = false;
        }

        (*riemp)++;

    }else {
    printf("Voto non valido!\n");
    }

}

void calcolo_media(int *voti, int *riemp, float *media){

    int somma_voti = 0;
    for(int i = 0; i<*riemp; i++){
        somma_voti += *(voti + i);
    }
    *media = (float)somma_voti/(*riemp);
    printf("Media voti: %0.2f\n", *media);
}

void ind_voto_max(int *voti, int *riemp){
    
    int max = 18;
    for(int i = 0; i < *riemp; i++){
        if(*(voti + i) > max){
            max = *(voti + i);
        }
    }
    printf("Voto massimo: %d\n", max);
}

void ind_voto_min(int *voti, int *riemp){

    int min = 30;
    for(int i = 0; i < *riemp; i++){
        if(*(voti + i) < min){
            min = *(voti + i);
        }
    }
    printf("Voto minimo: %d\n", min);
}