#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOTFOUND -1

int indeks_slowa(char *slowo, char *linia) {
    char *addr = strstr(linia, slowo);
    if (addr == NULL) return NOTFOUND;
    else return addr - linia;
}

//można zamienić na np. c == ' '
int znak_wyklucza_slowo(char c) {
    return isalpha(c) || isnumber(c);
}

int gdzie_jest_cale_slowo(char *slowo, char *linia) {
    int idx = indeks_slowa(slowo, linia);
    if (idx < 0)
        return NOTFOUND;
    else if (idx > 0 && znak_wyklucza_slowo(linia[idx - 1]))
        return NOTFOUND;

    if (idx == strlen(linia) - 1)
        return idx;
    else if (!znak_wyklucza_slowo(linia[idx + strlen(slowo)]))
        return idx;
    else return NOTFOUND;
}

/*
 * Pierwszy element to ilosć wystąpień
 * */
int *znajdz_slowo(char *slowo, char *linia) {
    int idx = 0;
    int ilosc_wystapien = 1;
    int dlugosc_linii = strlen(linia);

    /*NIE USUWAC MALLOCA BO SIE ROZWALI :)*/
    int *indeksy = malloc(0);

    //więcej niż znaków w linii to tych wystąpień nie będzie
    int *wystapienia = malloc(dlugosc_linii * sizeof(int));

    wystapienia[0] = 0;

    while (idx < dlugosc_linii) {
        int adres = gdzie_jest_cale_slowo(slowo, linia + idx);
        if (adres < 0)
            break;
        else {
            wystapienia[ilosc_wystapien] = idx + adres;
            ilosc_wystapien++;
            idx += adres + strlen(slowo);
        }
    }

    wystapienia[0] = ilosc_wystapien - 1;

    indeksy = realloc(wystapienia, ilosc_wystapien * sizeof(int));

    return indeksy;
}