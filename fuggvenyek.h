#ifndef FUGGVENYEK_H_INCLUDED
#define FUGGVENYEK_H_INCLUDED

int opciok()
{
    int opcio;
    printf("\n Valaszthato opciok: \n");
    printf("\n 1: Ugyfelek listaja \n");
    printf("\n 2: Utalas \n");
    printf("\n 3: Regisztracio \n");
    printf("\n 4: Kilepes \n");
    scanf("%d", &opcio);
    system("clear");
    return opcio;
}

void kilep(ugyfel *u, char *fNev, int h)
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
            fprintf(fp, "%-20s%-20s", u[i].nev, u[i].email);
            fprintf(fp, "%-20s\t%d\n", u[i].tel, u[i].egyenleg);
        }
        fflush(fp);
        fclose(fp);
    }
    free(u);

    printf("Kilepes!\n");
}


int ujUgyfel(ugyfel **u, int *h)
{
    char emailTemp[20], telTemp[20];


    printf("Email: \n"); scanf("%19s", emailtemp);
    if(emailCheck(emailTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }


    printf("Telefonszam: \n"); scanf("%19s", teltemp);
    if(telCheck(telTemp)){
        printf("Hiba, nem megfelelo foramtum! \n");
        if(megEgyszer()){return 1;} else {return 0;}
    }


    if(!(*u = (ugyfel *)realloc(*u, ++(*h)*sizeof(ugyfel))))
    {
        printf("Hiba, keves memoria!\n");
        if(megEgyszer()){return 1;} else {return 0;}
    }

    masol(emailTemp, (*u)[*h-1].email);
    masol(telTemp, (*u)[*h-1].tel);
    printf("Nev: "); scanf("%19s", (*u)[*h-1].nev);
    printf("Egyenleg: "); scanf("%d", &(*u)[*h-1].egyenleg);
    return 0;
}


void masol(char *innen, char *ide)
{
    int i = 0;
    while(innen[i]){ide[i = innen[i]; i++;}
    ide[i] = 0;

}


int emailCheck(char *eTemp)
{
    int i = 0, dotIndex, altIndex, numberOfDots = -1, numberOfAts = -1, diff;

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


int telCheck(char *tTemp)
{
    int i = 0;

    while(tTemp[i])
    {
        if(tTemp[i] < '0' || tTemp[i] > '9') {return 1;}
        i++;
    }
    return 0;
}


int stringHossz(char *n)
{
    int i = 0;
    while(n[i]) {i++;}
    return i;
}

int keres(ugyfel *u, int h, char *nev)
{
    int i, j, nevHossz = stringHossz(nev);
    for (i = 0; i < h; i++)
    {
        if(nevHossz == stringHossz(u[i].nev))
        {
            j = 0;
            while(j < nevHossz && nev[j] == u[i].nev[j]) {j++;}
            if(j == nevHossz) {return i;}
        }
    }
    return -1;
}



int utalas(ugyfel *u, int h)
{
    char utaloNev[20], kedvezmenyezettNev[20];
    int utaloIndex, kedvIndex, osszeg;
    printf("Utalo neve: "); scanf("%s", utaloNev);
    if((utaloIndex = keres(u, h, utaloNev)) == -1)
    {
        printf("Hiba, a nev nem talalhato.\n");
        if(megEgyszer()) {return 1;} else {return 0;}
    }


    printf("Kedvezmenyezett neve: "); scanf("%s", kedvezmenyezettNev);
    if((kedvIndex = keres(u, h, kedvezmenyezettNev)) == -1)
    {
        printf("Hiba, a nev nem talalhato.\n");
        if(megEgyszer()) {return 1;} else {return 0;}
    }


    printf("Osszeg: "); scanf("%s", &osszeg);
    if(u[utaloIndex].egyenleg < osszeg)
    {
        printf("Hiba, nincs eleg penz a szamlan.\n");
        if(megEgyszer()) {return 1;} else {return 0;}
    }
    u[utaloIndex].egyenleg -= osszeg;
    u[kedvIndex].egyenleg += osszeg;
    printf("Osszeg atutalva.\n");
    return 0;
}

void lista(ugyfel *u, int h)
{
    int i;
    for(i = 0; i < h; i++)
    {
        printf("Nev: %-20s email: %-20s ", u[i].nev, u[i].email);
        printf("tel: %-20s egyenleg: %d\", u[i].tel, u[i].eegyenleg);
    }
}



int beolvas(ugyfel **u, char *Nev, int *h)
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
    if(*u = (ugyfel *)malloc(*h*sizeof(ugyfel))))
    {
        printf("Error, nincs eleg memoria!\n");
        if(megEgyszer()) { return 1; }
            else { printf("A program kilep!\n"); return 2; }
    }
    rewind(fp);
    for(i = 0; i < *h; i++)
    {
        fscanf(fp, "%s%s%s%d", (*u[i].nev, (*u)[i].email, (*u)[i].tel, &(*u)[i].egyenleg);
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

#endif // FUGGVENYEK_H_INCLUDED
