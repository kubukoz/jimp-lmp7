#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NOTFOUND -1

int indeks_slowa(char *slowo, char *linia) {
    char *addr = strstr(linia, slowo);
    if (addr == NULL) return NOTFOUND;
    else return addr - linia;
}

int gdzie_jest_cale_slowo(char *slowo, char *linia) {
    int idx = indeks_slowa(slowo, linia);
    if (idx < 0)
        return NOTFOUND;
    else if (idx > 0 && isalpha(linia[idx - 1]))
        return NOTFOUND;

    if (idx == strlen(linia) - 1)
        return idx;
    else if (!isalpha(linia[idx + strlen(slowo)]))
        return idx;
    else return NOTFOUND;
}

int ilosc_wystapien_slowa(char *slowo, char *linia) {
    int idx = 0;
    int wystapienia = 0;

    int dlugosc_linii = strlen(linia);

    while (idx < dlugosc_linii) {
        int adres = gdzie_jest_cale_slowo(slowo, linia + idx);
        if (adres < 0)
            break;
        else {
            wystapienia++;
            idx += adres + strlen(slowo);
        }
    }
    return wystapienia;
}