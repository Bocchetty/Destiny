//Questo programma conta quante volte è uscito un numero estratto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int estrazioni = 0;
    int max = 2;
    int cont0 = 0;
    int cont1 = 0;
    int cont2 = 0;

    //Inizializzazione random
    int seed = time(NULL);
    srand(seed);

    printf("Quante estrazioni vuoi fare?\n");
    scanf("%d", &estrazioni);

    for (int i = 1; i <= estrazioni; i++){

        //Estrazione numero
        int estr = rand()%3;
        printf("Numero estratto : %d\n", estr);

        if (estr == 0){
            ++cont0;
        }else if(estr == 1){
            ++cont1;
        }else{
            ++cont2;
        }

    }

    //Calcolo frequenza
    float freq0 = ((float)cont0 / estrazioni);
    float freq1 = ((float)cont1 / estrazioni);
    float freq2 = ((float)cont2 / estrazioni);

    printf("Il numero 0 e' stato estratto %d volte su %d con frequenza %f\n", cont0, estrazioni, freq0);
    printf("Il numero 1 e' stato estratto %d volte su %d con frequenza %f\n", cont1, estrazioni, freq1);
    printf("Il numero 2 e' stato estratto %d volte su %d con frequenza %f\n", cont2, estrazioni, freq2);

    return 0;
}