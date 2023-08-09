all: lab08  

lab08: lab08.o mapa.o
	gcc lab08.o mapa.o -lm -o lab08

lab08.o: lab08.c mapa.h
	gcc -std=c99 -Wall -c lab08.c

mapa.o: mapa.c mapa.h
	gcc -std=c99 -Wall -c mapa.c

clean:
	rm -f lab08.o mapa.o