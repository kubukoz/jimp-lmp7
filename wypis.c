#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wypis.h"

#define ZIELONY_POCZATEK   "\x1b[32m"
#define ZIELONY_KONIEC   "\x1b[0m"
#define WYPISZ_ZIELONYM ZIELONY_POCZATEK"%.*s"ZIELONY_KONIEC

/*wypisuje linię zaznaczając wystąpienia słowa innym kolorem*/
void wypisz_linie(char *linia, int nr_linii, int *indeksy, int ilosc_indeksow, char *slowo) {
    int i;
    int dlugosc_slowa = strlen(slowo);
    int poczatek_slowa = indeksy[0];
    int akt = 0;

    printf("%d:\t", nr_linii);
    for (i = 0; i < ilosc_indeksow; i++) {
        printf("%.*s", poczatek_slowa - akt, linia + akt);

        printf(WYPISZ_ZIELONYM, dlugosc_slowa, linia + poczatek_slowa);
        akt = poczatek_slowa + dlugosc_slowa;

        indeksy++;
        poczatek_slowa = *indeksy;
    }

    /*Tutaj wypis tego co zostało po wypisaniu wszystkich wystąpień słowa*/
    dlugosc_slowa = strlen(linia);
    printf("%.*s", dlugosc_slowa - akt, linia + akt);
}
