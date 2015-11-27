# jimp-lmp7

Nasz zajumisty projekt na laboratorium Języków i Metod Programowania.

# Usage

    git clone https://github.com/kubukoz/jimp-lmp7
    cd jimp-lmp7
    make reader
    ./reader nazwapliku szukane slowa itd

# Example (tutaj bez kolorów)

Dla pliku main.c (as of `Fri Nov 27 01:57:53 CET 2015`)

    Słowo fprintf znaleziono w liniach:
    18:             fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1]);
    23:             fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0]);
    
    Słowo int znaleziono w liniach:
    9:      int main(int argc, char **argv) {
    10:         int i;
    11:         int ilosc_linii;
    12:         int ilosc_slow;
    34:                 int *wystapienia = znajdz_slowo(argv[i + 2], buf);
    35:                 int ilosc_indeksow = wystapienia[0];
    36:                 int *indeksy = wystapienia + 1;


# Wersja alt
    make reader-alt
    ./reader-alt nazwapliku szukane slowa
    
# Testy
    make test
    (or make test-alt)
