//
// Created by Michał Romaszko on 26.11.2015.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wypis.h"


void wypisz_linie(char *linia, int *indeksy, int ilosc_indeksow, char *slowo) {
    int i, j;
    int dlugosc_slowa = strlen(slowo);
    int poczatek_slowa = *indeksy;
    int akt = 0;

    printf("%s", linia);
    for (i = 0; i < ilosc_indeksow; i++) {
        for (j = akt; j < poczatek_slowa; j++)
            printf(" ");
        for (j = poczatek_slowa; j < poczatek_slowa + dlugosc_slowa; j++)
            printf("~");
        akt = poczatek_slowa + dlugosc_slowa;

        indeksy++;
        poczatek_slowa = *indeksy;
    }
    printf("\n");
}