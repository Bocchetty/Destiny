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
void inserisci_datiprodotto(struct prodotto *prodotti, int *riemp, char *new_cod);
void modifica_codice(struct prodotto *prodotti, int *riemp);
void fornisci_codice(struct prodotto *prodotti, int *riemp);
void visualizza_datiprodotto(struct prodotto *prodotti, int *riemp);
void inizializza_magazzino_vuoto(struct prodotto *prodotti, int *riemp);
void inizializza_magazzino(struct prodotto *prodotti, int *riemp, char *new_cod);
int cerca_codice_prodotto(struct prodotto *prodotti, int *riemp, char *new_cod);
void elimina_prodotto(struct prodotto *prodotti, int *riemp);
void inserisci_prodotto(struct prodotto *prodotti, int *riemp, char *new_cod);
void visualizza_magazzino(struct prodotto *prodotti, int *riemp);

#endif // fine include guard (evito che il file .h venga incluso più volte nel main)