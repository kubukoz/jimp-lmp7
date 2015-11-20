#ifndef __SKOROWIDZ__
#define __SKOROWIDZ__

#include "wektor.h"

typedef struct {
    char **slowa;
    wektor *wystapienia;
} skorowidz;

skorowidz utworz_skorowidz(int size, char **words);

void dodaj_wystapienie(skorowidz *sk, int i, int linia);

#endif