
reader: main.c skorowidz.c wektor.c szukaj.c wypis.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c wypis.c -o reader


main.c: skorowidz.c wektor.c wypis.c
skorowidz.c: skorowidz.h wektor.h
wektor.c: wektor.h
szukaj.c: szukaj.h
wypis.c: wypis.h

test: reader
	./reader main.c printf int