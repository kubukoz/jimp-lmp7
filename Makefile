reader: main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c -o build/reader

reader-alt: main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c -o build/reader-alt -DALT=1


main.c: skorowidz.c wektor.c szukaj.c wypis.c wypis_alt.c
skorowidz.c: skorowidz.h wektor.h
wektor.c: wektor.h
szukaj.c: szukaj.h
wypis.c: wypis.h
wypis_alt.c: wypis_alt.h

test: reader
	build/reader Makefile wektor
test-alt: reader-alt
	build/reader-alt main.c printf int

clean:
	cd build && rm *