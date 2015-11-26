//
// Created by Michał Romaszko on 26.11.2015.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wypis.h"

#define ZIELONY_POCZATEK   "\x1b[32m"
#define ZIELONY_KONIEC   "\x1b[0m"
#define WYPISZ_ZIELONYM ZIELONY_POCZATEK"%.*s"ZIELONY_KONIEC

void wypisz_linie(char *linia, int *indeksy, int ilosc_indeksow, char *slowo) {
    int i;
    int dlugosc_slowa = strlen(slowo);
    int poczatek_slowa = *indeksy;
    int akt = 0;

    for (i = 0; i < ilosc_indeksow; i++) {
        printf("%.*s", poczatek_slowa - akt, linia + akt);

        printf(WYPISZ_ZIELONYM, dlugosc_slowa, linia + poczatek_slowa);
        akt = poczatek_slowa + dlugosc_slowa;

        indeksy++;
        poczatek_slowa = *indeksy;
    }

    /* Tutaj wypis tego co zostalo po wypisaniu wszystkich slow */

    dlugosc_slowa = strlen(linia);
    printf("%.*s", dlugosc_slowa - akt, linia + akt);

}