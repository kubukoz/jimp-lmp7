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

/*można zamienić na np. c != ' '*/
int czy_znak_jest_slowny(char c) {
    return isalpha(c) || isnumber(c);
}

/*szuka wystąpień słowa w linii, takich że po jego lewej i prawej stronie
 * nie ma znakow słownych - spełniających warunek czy_znak_jest_slowny*/
int gdzie_jest_cale_slowo(char *slowo, char *linia) {
    int idx = indeks_slowa(slowo, linia);
    if (idx < 0)
        return NOTFOUND;
    else if (idx > 0 && czy_znak_jest_slowny(linia[idx - 1]))
        return NOTFOUND;

    if (idx == strlen(linia) - 1)
        return idx;
    else if (!czy_znak_jest_slowny(linia[idx + strlen(slowo)]))
        return idx;
    else return NOTFOUND;
}

/*
 * Zwraca indeksy początków słowa, jeśli występuje ono w linii.
 * Pierwszy element to ilosć wystąpień, kolejne to indeksy wystąpień.

 * np. jeśli słowo nie znajduje się w linii, wynik będzie miał postać [0].
 * */
int *znajdz_slowo(char *slowo, char *linia) {
    int idx = 0;
    int ilosc_wystapien = 1;
    int dlugosc_linii = strlen(linia);

    /*odkomentować jakby się sypało*/
    int *indeksy/* = malloc(0)*/;

    /*więcej niż znaków w linii to tych wystąpień nie będzie*/
    int *wystapienia = malloc(dlugosc_linii * sizeof(int));

    wystapienia[0] = 0;

    while (idx < dlugosc_linii - 1) {
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

    /*szczędzimy trochę pamięci :)*/
    indeksy = realloc(wystapienia, ilosc_wystapien * sizeof(int));

    return indeksy;
}
