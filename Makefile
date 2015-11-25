
reader: main.c skorowidz.c wektor.c szukaj.c
	$(CC) main.c skorowidz.c wektor.c szukaj.c -o reader


main.c: skorowidz.c wektor.c
skorowidz.c: skorowidz.h wektor.h
wektor.c: wektor.h
szukaj.c: szukaj.h

test: reader
	./reader main.c printf int