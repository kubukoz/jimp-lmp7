
reader: main.c skorowidz.c wektor.c
	$(CC) main.c skorowidz.c wektor.c -o reader


main.c: skorowidz.c wektor.c
skorowidz.c: skorowidz.h wektor.h
wektor.c: wektor.h

test: reader
	./reader main.c printf int