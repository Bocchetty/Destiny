// Questo programma data una stringa in input, visualizza una stringa contenente le sue vocali e un'altra contenente le sue consonanti

#include<stdio.h>
#include<string.h>
#define MAXLEN 50

int main(){

    char stringa[MAXLEN]; //Stringa inserita dall'utente
    char vocali[] = "aeiouAEIOU"; //Lista vocali

    char strvoc[MAXLEN]; //Vocali contenute nella stringa inserita dall'utente
    char strcons[MAXLEN]; //Consonanti contenute nella stringa inserita dall'utente
    int voc_index = 0; //Indice Vocali
    int cons_index = 0; //Indice Consonanti
    int j = 0; //Contatore fino a \0

    printf("Inserisci una stringa\n");
    fgets(stringa, MAXLEN, stdin);

 while(stringa[j] != 0){
    for (int i = 0; i<strlen(stringa); i++){

        if(strchr(vocali, stringa[i]) != NULL){ //Se è una vocale

         strvoc[voc_index++] = stringa[i];
         }else{ //Se è una consonante
       
         strcons[cons_index++] = stringa[i];
         }
     j++;
    }
 }
    
    strvoc[voc_index] = 0; //Inserisce carattere tappo
    strcons[cons_index] = 0; //Inserisce carattere tappo

    printf("La stringa inserita e':\n %s", stringa);
    printf("Le vocali contenute nella stringa inserita sono:\n %s\n", strvoc);
    printf("Le consonanti contenute nella stringa inserita sono:\n %s\n", strcons);

    return 0;
}