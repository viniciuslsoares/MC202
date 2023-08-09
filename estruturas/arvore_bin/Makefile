all: cliente  

cliente: cliente.o arvore_bin.o
	gcc cliente.o arvore_bin.o -lm -o cliente

cliente.o: cliente.c arvore_bin.h
	gcc -std=c99 -Wall -c cliente.c

arvore_bin.o: arvore_bin.c arvore_bin.h
	gcc -std=c99 -Wall -c arvore_bin.c

clean:
	rm -f cliente.o arvore_bin.o