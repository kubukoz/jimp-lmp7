#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wypis.h"
#include "wypis_alt.h"

#include "wektor.h"
#include "skorowidz.h"

#ifdef ALT
#define wypisz_linie wypisz_linie_alt
#else
#define wypisz_linie wypisz_linie
#endif

/*tworzy skorowidz o danym rozmiarze z podanych słów*/
skorowidz utworz_skorowidz(int rozmiar, char **slowa) {
    int i;
    skorowidz sk;
    sk.slowa = slowa;
    sk.ilosc_slow = rozmiar;
    sk.wystapienia = malloc(rozmiar * sizeof(wektor));
    for (i = 0; i < rozmiar; i++)
        sk.wystapienia[i] = utworz_wektor();
    return sk;
}

/*dodaje linie do wystapien slowa pod indeksem nr_slowa*/
void dodaj_wystapienia(skorowidz *sk, int nr_slowa, char *linia, int *indeksy, int ilosc_indeksow) {
    dodaj_linie(&(sk->wystapienia)[nr_slowa], linia, indeksy, ilosc_indeksow);
}

/*wypisuje znalezione wystapienia wszystkich slow*/
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