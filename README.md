# jimp-lmp7

Nasz zajumisty projekt na laboratorium Języków i Metod Programowania.

# Usage

    git clone https://github.com/kubukoz/jimp-lmp7
    cd jimp-lmp7
    make reader
    ./reader nazwapliku szukane slowa itd

# Example (tutaj bez kolorów)

Dla pliku main.c (as of `Fri Nov 27 01:57:53 CET 2015`)

    ./reader main.c fprintf int

    Słowo fprintf znaleziono w liniach:
        fprintf(stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1]);
        fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0]);

    Słowo int znaleziono w liniach:
    int main(int argc, char **argv) {
        int i;
        int ilosc_linii;
        int ilosc_slow;
                int *wystapienia = znajdz_slowo(argv[i + 2], buf);
                int ilosc_indeksow = wystapienia[0];
                int *indeksy = wystapienia + 1;



# Wersja alt
    make reader-alt
    ./reader-alt nazwapliku szukane slowa
    
# Testy
    make test
    (or make test-alt)
