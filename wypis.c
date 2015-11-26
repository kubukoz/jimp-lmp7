//
// Created by Michał Romaszko on 26.11.2015.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wypis.h"

void wypisz_linie(char *linia, int *indeks, int ilosc_indeksow, char *slowo){
    int i;
    int dlugosc_slowa=strlen(slowo);
    int poczatek_slowa=*indeks;
    int akt=0;

    for(i=0; i<ilosc_indeksow;i++){
        printf("%.*s",poczatek_slowa-akt,linia+akt);

        printf("\x1b[32m%.*s\x1b[0m",dlugosc_slowa,linia+poczatek_slowa);
        akt=poczatek_slowa+dlugosc_slowa;

        indeks++;
        poczatek_slowa=*indeks;
    }

    /* Tutaj wypis tego co zostalo po wypisaniu wszystkich slow */

    dlugosc_slowa=strlen(linia);
    printf("%.*s",dlugosc_slowa-akt,linia+akt);

}