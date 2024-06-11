all: main clean

main: main.o function_1.o function_2.o function_3.o 
	gcc -m32 main.o function_1.o function_2.o function_3.o -o main

main.o: 
	gcc -m32 -c main.c

function_1.o: 
	nasm -f elf32 src/function_1.asm -o function_1.o

function_2.o: 
	nasm -f elf32 src/function_2.asm -o function_2.o

function_3.o: 
	nasm -f elf32 src/function_3.asm -o function_3.o

clean:
	rm -rf *.o 


