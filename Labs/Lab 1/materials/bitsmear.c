#include <stdio.h>          // For puts
#include <limits.h>
#include <stdbool.h>

#include "print_bits.h"


void print_bits(int bits_to_print) {
    printBits(sizeof(bits_to_print), &bits_to_print);
}

int smear_bit(int bit_to_smear, bool debug) {
    if(debug) {
        printf("Smearing: %d\n", bit_to_smear);
        print_bits(bit_to_smear);
    }
    bit_to_smear = bit_to_smear | (bit_to_smear >> 16);
    if(debug) { print_bits(bit_to_smear); }
    bit_to_smear = bit_to_smear | (bit_to_smear >> 8);
    if(debug) { print_bits(bit_to_smear); }
    bit_to_smear = bit_to_smear | (bit_to_smear >> 4);
    if(debug) { print_bits(bit_to_smear); }
    bit_to_smear = bit_to_smear | (bit_to_smear >> 2);
    if(debug) { print_bits(bit_to_smear); }
    bit_to_smear = bit_to_smear | (bit_to_smear >> 1);
    if(debug) { print_bits(bit_to_smear); }
    
    return bit_to_smear;
}
int main(int argc, char* argv[]) {
    printf("Beginning main bitsmear.c\n");
    
    int int_byte_size = sizeof(int);
    int int_bit_size = int_byte_size * 8;
    
    //--------------------------------------------------------------------------
    unsigned int bit_smear_example = 1;
    for(int i = 0; i < int_bit_size; i = i + 1) {
        printf("================================\n");
        smear_bit(bit_smear_example, true);
        bit_smear_example = bit_smear_example << 1;
    }
    //--------------------------------------------------------------------------
    // This the way to hard-code the above
    
    // unsigned int bit_smear_example = 2147483648;
    // unsigned int bit_smear_example = 1073741824;
    // unsigned int bit_smear_example = 536870912;
    // unsigned int bit_smear_example = 268435456;
    // unsigned int bit_smear_example = 268435456;
    // unsigned int bit_smear_example = 134217728;
    // unsigned int bit_smear_example = 67108864;
    // unsigned int bit_smear_example = 33554432;
    // unsigned int bit_smear_example = 16777216;
    // unsigned int bit_smear_example = 8388608;
    // unsigned int bit_smear_example = 4194304;
    // unsigned int bit_smear_example = 2097152;
    // unsigned int bit_smear_example = 1048576;
    // unsigned int bit_smear_example = 524288;
    // unsigned int bit_smear_example = 262144;
    // unsigned int bit_smear_example = 131072;
    // unsigned int bit_smear_example = 65536;
    // unsigned int bit_smear_example = 32768;
    // unsigned int bit_smear_example = 16384;
    // unsigned int bit_smear_example = 8192;
    // unsigned int bit_smear_example = 4096;
    // unsigned int bit_smear_example = 2048;
    // unsigned int bit_smear_example = 1024;
    // unsigned int bit_smear_example = 512;
    // unsigned int bit_smear_example = 256;
    // unsigned int bit_smear_example = 128;
    // unsigned int bit_smear_example = 64;
    // unsigned int bit_smear_example = 32;
    // unsigned int bit_smear_example = 16;
    // unsigned int bit_smear_example = 8;
    // unsigned int bit_smear_example = 4;
    // unsigned int bit_smear_example = 2;
    // unsigned int bit_smear_example = 1;
    
    // unsigned int bit_smear_example = INT_MIN; // 2147483647
    // unsigned int bit_smear_example = INT_MAX; // (-2147483647-1)
    
    // smear_bit(bit_smear_example, true);
}