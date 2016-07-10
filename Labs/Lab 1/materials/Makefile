all: lab

lab:
	gcc -g -Wall -std=gnu99 -o output *.c
	./output

bits:
	gcc -g -Wall -std=gnu99 -o output bits.c print_bits.c
	./output

bitsmear:
	gcc -g -Wall -std=gnu99 -o output bitsmear.c print_bits.c
	./output

clean:
	$(RM) bits print_bits