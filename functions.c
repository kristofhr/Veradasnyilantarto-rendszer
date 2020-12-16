#include <stdio.h>
#include "functions.h"


int opciok()
{
    int opcio;
    printf("\n Valaszthato opciok: \n");
    printf("\n 1: Veradok listaja \n");
    printf("\n 2: Uj verado hozzadasa \n");
    printf("\n 3: Adott vercsoport keresese, kapcsolodo tagok felkerese veradasra a program altal kuldott emailen keresztul, valamint megelozven a bizalmat, veradas-szamuk es legutobbiveradasuk datumanak felulirasa mind a program listajaban, mind a nyilvantartast dokumentalo allomanyban. \n");
    printf("\n 4: Kilepes \n");
    scanf("%d", &opcio);
    system("clear");
    return opcio;
}

void kilep(verado *u, char *fNev, int h)
{
    FILE *fp = NULL; char save; int i;

    printf("Lehet, hogy valtozott a lista!\n");
    printf("Valtozasokat menti? (i/n) ");
    scanf(" %c", &save);


    if(save == 'i')
    {
        fp = fopen(fNev, "w");
        for(i = 0; i < h; i++)
        {
            fprintf(fp, "%-20s%-20s", u[i].nev, u[i].datum);
            fprintf(fp, "%-20s%-20s", u[i].nev, u[i].hanyszor);
        }
        fflush(fp);
        fclose(fp);
    }
    free(u);

    printf("Kilepes!\n");
}



int ujVerado(verado **u, int *h)
{
    char nevTemp[20]; emailTemp[20];


    printf("Nev: \n"); scanf("%19s", nevTemp);
    if(nevCheck(nevTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }

/*
    printf("Vercsoport: \n"); scanf("%19s", vercsoportTemp);
    if(vercsoportCheck(vercsoportTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }

*/
    printf("Email cim: \n"); scanf("%19s", emailTemp);
    if(emailCheck(emailTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }


/*
    printf("Hanyszor adott eddig vert: \n"); scanf("%19d", hanyszorTemp);
    if(hanyszorCheck(hanyszorTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }
*/

    if(!(*u = (verado *)realloc(*u, ++(*h)*sizeof(verado))))
    {
        printf("Hiba, keves memoria!\n");
        if(megEgyszer()){return 1;} else {return 0;}
    }


    return 0;
}




int emailCheck(char *eTemp)
{
    int i = 0, dotIndex, atIndex, numberOfDots = -1, numberOfAts = -1, diff;

    while(eTemp[i])
    {
        if(eTemp[i] == '.') { dotIndex = i; numberOfDots++; }
        if(eTemp[i] == '@') { atIndex = i; numberOfAts++; }
        i++;
    }
    if((diff = dotIndex - atIndex) < 0) {return 1;}
    if(numberOfDots || numberOfAts) {return 1;}
    if(!dotIndex || !atIndex || dotIndex == i-1 || atIndex == i-1 || diff == 1) {return 1;}
    return 0;
}

void lista(verado *u, int h)
{
    int i;
    for(i = 0; i < h; i++)
    {
        printf("Nev: %-20s\n", u[i].nev, u[i].email);
        printf("Vercsoport: %-20s\n", u[i].nev, u[i].vercsoport);
        printf("Email: %-20s\n", u[i].nev, u[i].email);
        printf("Hanyszor adott vert: %-20s\n" , u[i].nev, u[i].hanyszor);
        printf("Datum: %-20s\n" , u[i].tel, u[i].datum);
    }
}


int beolvas(verado **u, char *fNev, int *h)
{
    FILE *fp = NULL; char ch; int i;
    printf("Beolvasando fajl neve: "); scanf("%s", fNev);
    if(!(fp = fopen(fNev, "r")))
    {
        printf("Hiba, nem lehet megnyitni!");
        printf("Hibas eleresi ut! \n");
        if(megEgyszer()){return 1;}
        else {printf("Kilepes! \n"); return 2;}
    }
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n'){ (*h)++; }
    }
    if(*u = (verado *)malloc(*h*sizeof(verado)))
    {
        printf("HIBA, nincs eleg memoria!\n");
        if(megEgyszer()) { return 1; }
            else { printf("A program kilep!\n"); return 2; }
    }
    rewind(fp);
    for(i = 0; i < *h; i++)
    {
        fscanf(fp, "%s%s%s%d", (*u)[i].nev,(*u)[i].vercsoport, (*u)[i].email, (*u)[i].hanyszor, &(*u)[i].datum);
    }
    fclose(fp); printf("Fajl beolvasva.\n");
    return 0;
}



int megEgyszer()
{
    char ujra;
    printf("Megprobalja ujra? (i / n) ");
    scanf(" %c", &ujra);
    if(ujra == 'i') { return 1; }
    else { return 0; }
}



























