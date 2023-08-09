all: cliente  

cliente: cliente.o heap.o
	gcc cliente.o heap.o -lm -o cliente

cliente.o: cliente.c heap.h
	gcc -std=c99 -Wall -c cliente.c

heap.o: heap.c heap.h
	gcc -std=c99 -Wall -c heap.c

clean:
	rm -f cliente.o heap.o