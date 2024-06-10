all: main clean

main: main.o add.o
	gcc main.o add.o -o main

main.o: main.c
	gcc -c main.c

add.o: add.asm
	nasm -f elf32 add.asm -o add.o

clean:
	rm -rf *.o 


