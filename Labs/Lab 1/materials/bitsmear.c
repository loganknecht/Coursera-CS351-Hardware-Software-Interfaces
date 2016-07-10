#include <stdio.h>          // For puts

#include "print_bits.h"

int main(int argc, char* argv[]) {
    printf("Beginning main bitsmear.c\n");
    
    unsigned int bit_smear_example = 2147483648;
    unsigned int temp = 0;
    
    
    temp = bit_smear_example >> 16;
    bit_smear_example = bit_smear_example | temp;
    printBits(sizeof(bit_smear_example), &bit_smear_example);
    temp = bit_smear_example >> 8;
    bit_smear_example = bit_smear_example | temp;
    printBits(sizeof(bit_smear_example), &bit_smear_example);
    temp = bit_smear_example >> 4;
    bit_smear_example = bit_smear_example | temp;
    printBits(sizeof(bit_smear_example), &bit_smear_example);
    temp = bit_smear_example >> 2;
    bit_smear_example = bit_smear_example | temp;
    printBits(sizeof(bit_smear_example), &bit_smear_example);
    temp = bit_smear_example >> 1;
    bit_smear_example = bit_smear_example | temp;
    printBits(sizeof(bit_smear_example), &bit_smear_example);
    //--------------------------------------------------------------------------
    // bit_smear_example |= bit_smear_example >> 16;
    // printBits(sizeof(bit_smear_example), &bit_smear_example);
    // bit_smear_example |= bit_smear_example >> 8;
    // printBits(sizeof(bit_smear_example), &bit_smear_example);
    // bit_smear_example |= bit_smear_example >> 4;
    // printBits(sizeof(bit_smear_example), &bit_smear_example);
    // bit_smear_example |= bit_smear_example >> 2;
    // printBits(sizeof(bit_smear_example), &bit_smear_example);
    // bit_smear_example |= bit_smear_example >> 1;
    // printBits(sizeof(bit_smear_example), &bit_smear_example);
}