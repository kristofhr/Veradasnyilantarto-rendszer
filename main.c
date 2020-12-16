#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"







int main()
{
    verado *verado = NULL; char fajlNev[100]; int hossz = 0, ujra;
    while (ujra = beolvas(&verado, fajlNev, &hossz))
    {
        if(ujra == 2){return 0;}
    }

    while(1)
    {
        switch(opciok())
        {
            case 1: lista(verado, hossz); break;
            case 2: while(ujVerado(&ujVerado, &hossz)); break;
            case 3: keres(verado, fajlNev, hossz); break;
            case 4: kilep(verado, fajlNev, hossz); return 0;
            default: printf("Az On választasa: \n");
        }
    }
}
