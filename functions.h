#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


typedef struct verado {
    char nev[20];
    char vercsoport[10];
    char email[20];
    int hanyszor;
    char datum;
}verado;


int beolvas(verado **u, char *fNev, int *h);
void lista(verado *u, int h);
int keres(verado *u, int h, char *nev);
int ujVerado(verado **u, int *h);
int emailCheck(char *eTemp);
int nevCheck(char *nevTemp);
int vercsoportCheck(char *vercsoportTemp);
int hanyszorCheck(int *hanyszorCheck);
void kilep(verado *u, char *fNev, int h);
int megEgyszer();
int opciok();



#endif // FUNCTIONS_H_INCLUDED































