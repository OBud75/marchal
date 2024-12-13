source=main.asm
output=prog.out

run:
	nasm -f elf64 -o main.o ${source}
	ld -o ${output} main.o
	rm -f main.o
	./${output}

clean:
	rm -f ${output}

