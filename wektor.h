#ifndef _WEKTOR_H_
#define _WEKTOR_H_

typedef struct {
    char *linia;
    int *indeksy;
    int ilosc_indeksow;
} linia_info;

typedef struct {
    linia_info *linie;
    int max;
    int size;
} wektor;

void dodaj_linie(wektor *w, char *cala_linia, int *indeksy, int ilosc_indeksow);

wektor utworz_wektor();

#endif
