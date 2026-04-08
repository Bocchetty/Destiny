#ifndef MAGAZZINO_H // se la macro magazzino non è definita
#define MAGAZZINO_H // definiscila

#define MAXLEN 30 //definisco a tempo di compilazione una lunghezza massima per le stringhe
#define MAXDIM 15 //definisco una lunghezza massima per l'array magazzino implicando un'allocazione statica

struct prodotto{

        char codice[MAXLEN];
        char genere[MAXLEN];
        int qta;

};

//prototipi operazioni

void flush();
void remove_n(struct prodotto *prodotti, int riemp);
void inserisci_datiprodotto(struct prodotto *prodotti, int *riemp);
void modifica_codice();
void fornisci_codice();
void visualizza_datiprodotto();
void inizializza_magazzino_vuoto();
void inizializza_magazzino();
void cerca_codice_prodotto();
void elimina_prodotto();
void inserisci_prodotto();
void visualizza_magazzino();

#endif // fine include guard (evito che il file .h venga incluso più volte nel main)