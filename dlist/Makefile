all: dlist.o main.c
	gcc main.c dlist.o -o main.out
dlist.o: dlist.c dlist.h
	gcc -c dlist.c
clean:
	rm main
