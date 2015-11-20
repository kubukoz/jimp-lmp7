#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr
#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int main(int argc, char **argv) {
    int i, j;
    int ile_linii;
    int ile_slow;
    char buf[BUFSIZE];

    FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

    if (argc < 3) {
        fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (in == NULL) {
        fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    skorowidz skorowidz = utworz_skorowidz(argc - 2, argv + 2);
    ile_slow = argc - 2;
    ile_linii = 0;
    while (fgets(buf, BUFSIZE, in) != NULL) {
        ile_linii++;
        for (i = 0; i < ile_slow; i++) {
            if (strstr(buf, skorowidz.slowa[i]) != NULL) {
                dodaj_wystapienie(&skorowidz, i, ile_linii);
            }
        }

    }

    for (i = 0; i < ile_slow; i++) {
        if (skorowidz.wystapienia[i].size > 0) {
            printf("słowo \"%s\" wystąpiło w liniach:", skorowidz.slowa[i]);
            for (j = 1; j <= skorowidz.wystapienia[i].size; j++)
                printf(" %d", skorowidz.wystapienia[i].linie[j]);
            printf("\n");
        } else {
            printf("nie napotkano słowa \"%s\"\n", skorowidz.slowa[i]);
        }
    }

    return EXIT_SUCCESS;
}
