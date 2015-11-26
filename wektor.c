#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wektor.h"

#define MAXLINESIZE 8192
#define MAXSIZE 2

wektor *utworz_wektor() {
    wektor *w = malloc(sizeof w);
    w->max = MAXSIZE;
    w->linie = malloc(w->max * sizeof(char));
    w->size = 0;
    return w;
}

void dodaj_linie(wektor *w, char *cala_linia, int *indeksy, int ilosc_indeksow) {
    int i;

    if (w->size + 1 > w->max) {
        w->max += MAXSIZE;
        linia_info *linie_temp = realloc(w->linie, w->max * sizeof(char));
        w->linie = linie_temp;
    }

    linia_info linia = {};
    linia.linia = malloc(strlen(cala_linia) * sizeof(char));
    linia.indeksy = malloc(ilosc_indeksow * sizeof(int));
    linia.ilosc_indeksow = ilosc_indeksow;

    for (i = 0; i < ilosc_indeksow; i++)
        linia.indeksy[i] = indeksy[i];

    strcpy(linia.linia, cala_linia);

    w->linie[w->size] = linia;

    w->size++;
}