#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int indeks_slowa(char *slowo, char *linia);

int gdzie_jest_cale_slowo(char *slowo, char *linia);

int ilosc_wystapien_slowa(char *slowo, char *linia);

void szukaj_slowa(char *slowo, char *line, skorowidz *sk, int nr_linii);