//Questo programma calcola il minimo, il massimo e la media di voti di un'esame

#include <stdio.h>
#include <stdbool.h>

int main(){

    int voto = 0;
    int cont = 0;
    int min = 30;
    int max = 18;
    float media = 0;
    int scelta= 0;
    bool inserimenti_terminati = false;

    while(!inserimenti_terminati){

        do{

            do{

                printf("Inserisci il voto\n");
                scanf("%d", &voto);

                if (voto<18 || voto>30){
                    printf("Voto deve essere compreso tra 18 e 30!\n");
                }

            }while(voto<18 || voto>30);

                //Aggiorna min
                if (voto<min){
                    min = voto;
                }

                //Aggiorna max
                if (voto>max){
                    max = voto;
                }

                //Somma voti
                media += voto;

                //Contatore numero voti
                cont++;

            printf("Vuoi inserire altri voti? (1 Si/ 2 No)\n");
            scanf("%d", &scelta);
        }while (scelta == 1);
        inserimenti_terminati = true;
    }

    //Calcolo media
    media = media/cont;

    printf("Voto min: %d\nVoto max: %d\nMedia voti: %f\n", min, max, media);

    return 0;
}