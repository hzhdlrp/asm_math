FUNCTIONS = fun_1.asm fun_2.asm fun_3.asm test_fun_1.asm test_fun_2.asm test_fun_3.asm
FUNCTIONS_OBJ = $(FUNCTIONS:.asm=.o)
FUNCTIONS_DIR = src/functions

DERIVATIVES = fun_1_der.asm fun_2_der.asm fun_3_der.asm test_1_der.asm test_2_der.asm test_3_der.asm
DERIVATIVES_OBJ = $(DERIVATIVES:.asm=.o)
DERIVATIVES_DIR = src/derivatives

LIB = root.c integral.c
LIB_OBJ = $(LIB:.c=.o)
LIB_DIR = lib

all: integral clean

integral: main.o $(FUNCTIONS_OBJ) $(DERIVATIVES_OBJ) $(LIB_OBJ)
	gcc -m32 main.o $(FUNCTIONS_OBJ) $(DERIVATIVES_OBJ) $(LIB_OBJ) -o integral

main.o: main.c
	gcc -m32 -m32 -c main.c

$(LIB_OBJ): %.o: $(LIB_DIR)/%.c
	gcc -m32 -c $< -o $@

$(FUNCTIONS_OBJ): %.o: $(FUNCTIONS_DIR)/%.asm
	nasm -f elf32 $< -o $@

$(DERIVATIVES_OBJ): %.o: $(DERIVATIVES_DIR)/%.asm
	nasm -f elf32 $< -o $@

clean:
	rm -rf *.o 

test: test.o $(FUNCTIONS_OBJ) $(DERIVATIVES_OBJ) $(LIB_OBJ) 
	gcc -m32 test.o $(FUNCTIONS_OBJ) $(DERIVATIVES_OBJ) $(LIB_OBJ) -o test
	rm -rf *.o