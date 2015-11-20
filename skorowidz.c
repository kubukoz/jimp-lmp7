#include <stdlib.h>
#include "wektor.h"
#include "skorowidz.h"
#include <stdio.h>

skorowidz utworz_skorowidz(int rozm, char **words) {
    int i;
    skorowidz sk = {};
    sk.slowa = words;
    sk.wystapienia = malloc(rozm);
    for (i = 0; i < rozm; i++)
        sk.wystapienia[i] = *utworz_wektor();
    return sk;
}

void dodaj_wystapienie(skorowidz *sk, int i, int linia) {
    dodaj_linie(&(sk->wystapienia)[i], linia);
}