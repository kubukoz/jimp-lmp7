#include <stdlib.h>
#include <stdio.h>
#include "wektor.h"

#define MAXSIZE 2

wektor *utworz_wektor() {
    wektor *w = malloc(sizeof w);
    w->linie = malloc(MAXSIZE);
    w->max = MAXSIZE;
    w->size = 0;
    return w;
}

void dodaj_linie(wektor *w, int linia) {
    if (w->size + 1 > w->max) {
        w->max += MAXSIZE;
        w->linie = realloc(w->linie, w->max);
    }

    w->linie[w->size] = linia;
    w->size++;
}