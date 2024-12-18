#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 30
#define MAXDIM 100

struct libro{
    
    int anno;
    char titolo[MAXCHAR];
    int numero_pagine;
    int prezzo;
};

void inserimento(struct libro *libri, int dim);
void stampa(struct libro *libri, int dim);
int conta_occorrenze_soglia(struct libro *libri, int dim, int soglia);
struct libro* elimina(struct libro *libri, int *dim, int soglia);

int main(){
    
    int dim = 0;
    int scelta = 0;
    int soglia = 0;
    printf("Quanti libri vuoi inserire?\n");
    scanf("%d", &dim);
    getchar();
    
    struct libro* libri = malloc(sizeof(struct libro)*dim);

    if(libri == NULL){
        printf("Memoria non allocata!");
        return 0;
    }
    
    inserimento(libri, dim);
    
    do{
        printf("Quale operazione vuoi svolgere?\n");
        printf("1. Stampa\n");
        printf("2. Elimina libri in base ad una soglia di prezzo\n");
        printf("3. Esci\n");
        scanf("%d",&scelta);
        
        switch(scelta){
            
            case 1:
            stampa(libri, dim);
            break;
            
            case 2:
            printf("Quale soglia di prezzo vuoi imporre?\n");
            scanf("%d", &soglia);
            libri = elimina(libri, &dim, soglia);
            stampa(libri, dim);
            break;
            
            case 3:
            printf("Arrivederci\n");
            break;
            
            default:
            printf("Scelta non consentita!\n");
            break;
        }
    }while(scelta != 3);
    free(libri);
    
    return 0;
}

void inserimento(struct libro *libri, int dim){
    
    for(int i = 0; i < dim; i ++){
     printf("Inserimento info libro\n");
     printf("Anno:\n");
     scanf("%d", &(libri + i) -> anno);
     getchar();
     printf("Titolo\n");
     fgets((libri + i) -> titolo, MAXCHAR, stdin);
     (libri + i)->titolo[strcspn((libri + i)->titolo, "\n")] = '\0';
     printf("Numero pagine\n");
     scanf("%d", &(libri + i)-> numero_pagine);
     printf("Prezzo\n");
     scanf("%d", &(libri + i)-> prezzo);
    }
}

void stampa(struct libro *libri, int dim){
    
    printf("Stampa libri:\n");
    for(int i = 0; i < dim; i++){
     printf("ANNO\tTITOLO\tNUMERO DI PAGINE\tPREZZO\n");
     printf("%d\t%s\t%d\t\t\t%d\n", (libri + i)->anno,(libri + i)->titolo,(libri + i)->numero_pagine,(libri + i)->prezzo);
    }
}

int conta_occorrenze_soglia(struct libro *libri, int dim, int soglia){
    int occorrenze = 0;
    for(int i = 0; i < dim; i++){
     if((libri + i)->prezzo > soglia){
        occorrenze++;
     }
    }
    return occorrenze;
}

struct libro* elimina(struct libro *libri, int *dim, int soglia){
    
    int occorrenze = conta_occorrenze_soglia(libri, *dim, soglia);

    struct libro* new_libri = malloc(sizeof(struct libro)*(*dim-occorrenze));
        if(new_libri != NULL){
            int j = 0;
            for(int i = 0; i <*dim; i++){
                if((libri + i)->prezzo <= soglia){
                *(new_libri + j) = *(libri + i);
                j++;
                }
            }
        }
            
    free(libri);
    (*dim) = (*dim) - occorrenze;
    return new_libri;
}