#ifndef __SKOROWIDZ__
#define __SKOROWIDZ__

#include "wektor.h"

typedef struct {
    char **slowa;
    int ilosc_slow;
    wektor *wystapienia;
} skorowidz;

skorowidz *utworz_skorowidz(int rozmiar, char **slowa);

void dodaj_wystapienia(skorowidz *sk, int nr_slowa, char *linia, int *indeksy, int ilosc_indeksow, int nr_linii);

void wypisz_skorowidz(skorowidz *sk);
#endif
