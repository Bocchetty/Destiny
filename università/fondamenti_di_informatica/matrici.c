// DA FARE

/*Data una matrice con 4 righe e 3 colonne, stampa la matrice, calcolare la somma ed il
massimo dei valori per ogni riga*/
#include <stdio.h>

int somma_riga(int mat[][3], int MAX_COL, int riga_da_sommare);

int somma(int mat[4][3], int riga, int colonna);
int ris=0;
int riga = 3;
int colonna = 4;
int main(){
    int mat [4][3]={
                    {1,2,3},
                    {4,5,6},
                    {7,8,9},
                    {10,11,12} ,
                    };
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("mat[%d][%d]è %d\n", i,j,mat[i][j]);
        }
    }
    int somma_temp = 0;
    for(int i=0;i<4;i++){
        
        somma_temp = 0;

        for(int j=0;j<3;j++){
            somma_temp += mat[i][j];
        }
        //ho finito di scorrere la riga i-esima
        printf("Somma riga %d : %d\n",i, somma_temp);
    }

    int somma_riga_0 = somma_riga(mat, 3, 0);
    printf("somma riga 0: %d\n", somma_riga_0);

    //printf("Somma: %d", somma(mat[4][3], riga, colonna));
                 
return 0;
}

int somma_riga(int mat[][3], int MAX_COL, int riga_da_sommare){

    int somma = 0;
    for(int j=0; j<MAX_COL; j++)
        somma = somma + mat[riga_da_sommare][j];
        // somma = mat[riga_da_sommare][j] + mat[riga_da_sommare][j+1]; //PROVARE
    return somma;
}

/*
int somma(int mat[4][3], int riga, int colonna){

    int somm
    for(int i=0;i<colonna;i++){

    }
    
    return ris;
}
*/

// TODO: impostare una funzione che ritorni un array dove ogni
// l'elemento i-esimo è la somma della riga i-esima (int *funzione (...), int [] funzione(...))

// TODO2 : impostare una funzione che passato l'indice di riga
// ti ritorni la somma di quella riga (int funzione())

//TODO3: fare una funzione che sommi le colonne