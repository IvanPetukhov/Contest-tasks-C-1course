all: program

program: asm.o main.o
	gcc -o program asm.o main.o
	
asm.o:
	nasm -f elf32 -o asm.o asm.asm
	
main.o:
	gcc -std=gnu99 -m32 -c -o main.o main.c
	
clean:
	rm -f *.o program*