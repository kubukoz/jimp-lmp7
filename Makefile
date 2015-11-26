
reader: main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c -o reader

reader-alt: main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c -o reader-alt -DALT=1


main.c: skorowidz.c wektor.c wypis.c
skorowidz.c: skorowidz.h wektor.h
wektor.c: wektor.h
szukaj.c: szukaj.h
wypis.c: wypis.h
wypis_alt.c: wypis_alt.h

test: reader
	./reader main.c printf int
test-alt: reader-alt
	./reader-alt main.c printf int