#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "print_bits.h"

// Original
// int test(int i, long int l) {
//     return i == ((int)l);
// }

// "Fixed"
int test(int i, long int l) {
    return i == ((int)l);
}

int main(int argc, const char* argv[]) {
    srand(time(NULL));
    int i = rand();
    // creates two random 2 byte ints and assigns them to a 4 byte long int
    long int l = (rand() << 31) | rand();
    int test_output = test(i, l);
    printf("i: %d", i);
    printf("\n");
    printf("l: %ld", l);
    printf("\n");
    printf("\n");
    
    printf("int i: %d", i);
    printf("\n");
    printBits(sizeof(i), &i);
    printf("\n");
    
    printf("long int l: %ld", l);
    printf("\n");
    printBits(sizeof(l), &l);
    printf("\n");
    
    printf("int l: %d", (int)l);
    printf("\n");
    printBits(sizeof((int)l), &l);
    printf("\n");
    
    printf("test_output: %d", test_output);
    printf("\n");
    
    return 0;
}
