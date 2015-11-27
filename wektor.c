#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wektor.h"

#define MAXLINESIZE 8192
#define MAXSIZE 2

/*tworzy pusty wektor o rozmiarze ustalonym w MAXSIZE*/
wektor utworz_wektor() {
    wektor w;
    w.max = MAXSIZE;
    w.linie = malloc(w.max * sizeof(linia_info));
    w.size = 0;
    return w;
}

/*dodaje linię z indeksami wystąpień słowa do wektora*/
void dodaj_linie(wektor *w, char *cala_linia, int nr_linii, int *indeksy, int ilosc_indeksow) {

    /*sprawdzamy, czy trzeba powiększyć rozmiar wektora*/
    if (w->size + 1 > w->max) {
        w->max += MAXSIZE;
        linia_info *linie_temp = realloc(w->linie, w->max * sizeof(linia_info));
        w->linie = linie_temp;
    }

    linia_info linia;
    linia.linia = malloc(strlen(cala_linia) * sizeof(char));
    linia.nr = nr_linii;
    linia.indeksy = indeksy;
    linia.ilosc_indeksow = ilosc_indeksow;

    strcpy(linia.linia, cala_linia);

    w->linie[w->size] = linia;

    w->size++;
}