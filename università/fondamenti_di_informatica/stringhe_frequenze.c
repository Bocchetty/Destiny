//DA TERMINARE
//Questo programma calcola le frequenze delle iniziali di nomi inseriti da tastiera

#include<stdio.h>
#include<string.h>
#define MAXLEN 100

int main(){

    char nome[MAXLEN];
    int nomi = 0;

    while(strchr(nome, '.') != NULL){

        printf("Scrivi un nome (Scrivi . per terminare): \n");
        fgets(nome, MAXLEN, stdin);

        nomi++;
    }

 return 0;
}