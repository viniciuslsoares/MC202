all: cliente  

cliente: cliente.o hash.o
	gcc cliente.o hash.o -lm -o cliente

cliente.o: cliente.c hash.h
	gcc -std=c99 -Wall -c cliente.c

hash.o: hash.c hash.h
	gcc -std=c99 -Wall -c hash.c

clean:
	rm -f cliente.o hash.o