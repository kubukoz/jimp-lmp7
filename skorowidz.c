#include <stdlib.h>
#include "wektor.h"
#include "skorowidz.h"
#include "wypis.h"
#include <stdio.h>

skorowidz utworz_skorowidz(int rozmiar, char **slowa) {
    int i;
    skorowidz sk = *(skorowidz *) malloc(sizeof(skorowidz));
    sk.slowa = slowa;
    sk.ilosc_slow = rozmiar;
    sk.wystapienia = malloc(rozmiar * sizeof(wektor));
    for (i = 0; i < rozmiar; i++)
        sk.wystapienia[i] = *utworz_wektor();
    return sk;
}

void dodaj_wystapienia(skorowidz *sk, int nr_slowa, char *linia, int *indeksy, int ilosc_indeksow) {
    dodaj_linie(&(sk->wystapienia)[nr_slowa], linia, indeksy, ilosc_indeksow);
}

void wypisz_skorowidz(skorowidz sk) {
    int i;
    for (i = 0; i < sk.ilosc_slow; i++) {
        int j;
        char *slowo = sk.slowa[i];
        wektor wystapienia_slowa;

        wystapienia_slowa = sk.wystapienia[i];

        wystapienia_slowa.size > 0
        ? printf("Słowo %s znaleziono w liniach:\n", slowo)
        : printf("Nie znaleziono słowa %s.\n", slowo);

        for (j = 0; j < wystapienia_slowa.size; j++) {

            linia_info linia = wystapienia_slowa.linie[j];
            wypisz_linie(linia.linia, linia.indeksy, linia.ilosc_indeksow, slowo);
        }

        printf("\n");
    }
}