#include <stdio.h>
#include <stdlib.h>
#include "skorowidz.h"
#include "szukaj.h"

/*zakładamy, że linie będą krótsze niż 8kB*/
#define BUFSIZE 8192

int main(int argc, char **argv) {
    int i;
    int ilosc_linii;
    int ilosc_slow;
    char buf[BUFSIZE];

    FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

    if (in == NULL) {
        fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    if (argc < 3) {
        fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0]);
        return EXIT_FAILURE;
    }

    ilosc_slow = argc - 2;
    skorowidz *skorowidz = utworz_skorowidz(ilosc_slow, argv + 2);

    for (ilosc_linii = 1; fgets(buf, BUFSIZE, in) != NULL; ilosc_linii++) {

        /*dla każdego słowa sprawdzamy, ile razy i gdzie pojawiło się w linii*/
        for (i = 0; i < ilosc_slow; i++) {
            int *wystapienia = znajdz_slowo(argv[i + 2], buf);
            int ilosc_indeksow = wystapienia[0];
            int *indeksy = wystapienia + 1;

            if (ilosc_indeksow > 0)
                dodaj_wystapienia(skorowidz, i, buf, indeksy, ilosc_indeksow, ilosc_linii);
        }
    }

    wypisz_skorowidz(skorowidz);

    return EXIT_SUCCESS;
}
