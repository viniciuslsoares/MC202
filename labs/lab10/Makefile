lab10: lab10.o heap.o
	gcc lab10.o hash.o -lm -o lab10

lab10.o: lab10.c hash.h
	gcc -std=c99 -Wall -Werror -c lab10.c

heap.o: hash.c hash.h
	gcc -std=c99 -Wall -Werror -c hash.c