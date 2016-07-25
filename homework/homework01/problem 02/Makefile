all: print_bits problem02

C_Compiler = gcc
Compiler_Flags = -g -Wall -std=gnu99

print_bits:
	$(C_Compiler) $(Compiler_Flags) -c -o print_bits print_bits.c

problem02:
	$(C_Compiler) $(Compiler_Flags) -o problem02 print_bits.c problem02.c && ./problem02

clean:
	rm print_bits problem02