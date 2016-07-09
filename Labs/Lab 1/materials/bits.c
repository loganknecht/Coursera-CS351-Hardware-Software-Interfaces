#include <math.h>          // For puts
#include <stdio.h>          // For puts
#include "print_bits.h"

/*
 * CSE 351 HW1 (Data Lab)
 *
 * Logan Knecht - <USERID>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 *
 * You will provide your solution to this homework by
 * editing the collection of functions in this source file.
 *
 * INTEGER CODING RULES:
 *
 * Replace the "return" statement in each function with one
 * or more lines of C code that implements the function. Your code
 * must conform to the following style:
 *
 * int Funct(arg1, arg2, ...) {
 *   // brief description of how your implementation works
 *   int var1 = Expr1;
 *   ...
 *   int varM = ExprM;
 *
 *   varJ = ExprJ;
 *   ...
 *   varN = ExprN;
 *   return ExprR;
 * }
 *
 * Each "Expr" is an expression using ONLY the following:
 * 1. Integer constants 0 through 255 (0xFF), inclusive. You are
 * not allowed to use big constants such as 0xffffffff.
 * 2. Function arguments and local variables (no global variables).
 * 3. Unary integer operations ! ~
 * 4. Binary integer operations & ^ | + << >>
 *
 * Some of the problems restrict the set of allowed operators even further.
 * Each "Expr" may consist of multiple operators. You are not restricted to
 * one operator per line.
 *
 * You are expressly forbidden to:
 * 1. Use any control constructs such as if, do, while, for, switch, etc.
 * 2. Define or use any macros.
 * 3. Define any additional functions in this file.
 * 4. Call any functions.
 * 5. Use any other operations, such as &&, ||, -, or ? :
 * 6. Use any form of casting.
 * 7. Use any data type other than int.  This implies that you
 *    cannot use arrays, structs, or unions.
 *
 * You may assume that your machine :
 * 1. Uses 2s complement, 32 - bit representations of integers.
 * 2. Performs right shifts arithmetically.
 * 3. Has unpredictable behavior when shifting an integer by more
 * than the word size.
 *
 * EXAMPLES OF ACCEPTABLE CODING STYLE :
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 *
 * int pow2plus1(int x) {
 *   // exploit ability of shifts to compute powers of 2
 *   return (1 << x) + 1;
 * }
 *
 *
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 *
 * int pow2plus4(int x) {
 *   // exploit ability of shifts to compute powers of 2
 *   int result = (1 << x);
 *   result += 4;
 *   return result;
 * }
 *
 * NOTES:
 * 1. Use the dlc (data lab checker) compiler (described in the handout) to
 *    check the legality of your solutions.
 * 2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
 *    that you are allowed to use for your implementation of the function.
 *    The max operator count is checked by dlc. Note that '=' is not
 *    counted; you may use as many of these as you want without penalty.
 * 3. Use the btest test harness to check your functions for correctness.
 * 4. The maximum number of ops for each function is given in the
 *    header comment for each function. If there are any inconsistencies
 *    between the maximum ops in the writeup and in this file, consider
 *    this file the authoritative source.
 *
 *
 *      * STEP 2: Modify the following functions according the coding rules.
 *      *
 *      *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *      *   Use the dlc compiler to check that your solutions conform
 *      *   to the coding rules.
 *
 *
 */
#endif


// Rating: 1
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    // X (6)
    //  00000110
    // ~11111001
    
    // Y (5)
    //  00000101
    // ~11111010
    
    // ~11111001
    // ~11111010
    // |11111011
    
    // ~00000100
    // printf("%s\n", );
    
    int x_complement = ~x;
    int y_complement = ~y;
    
    int x_or_y = x_complement | y_complement;
    int complemented_x_or_y = ~x_or_y;
    
    // printf("X bits: ");
    // printBits(sizeof(x), &x);
    // printf("Y bits: ");
    // printBits(sizeof(y), &y);
    // printf("X complement bits: ");
    // printBits(sizeof(x_complement), &x_complement);
    // printf("Y complement bits: ");
    // printBits(sizeof(y_complement), &y_complement);
    // printf("Or'ed bits: ");
    // printBits(sizeof(x_or_y), &x_or_y);
    // printf("Complemented Or'ed bits: ");
    // printBits(sizeof(complemented_x_or_y), &complemented_x_or_y);
    
    return complemented_x_or_y;
}


/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // X (4)
    //  00000100
    // ~11111011
    
    // Y (5)
    //  00000101
    // ~11111010
    
    //  11111011 X complement
    //  00000101 Y starting value
    // &00000001
    // ~11111110
    
    //  11111010 Y complement
    //  00000100 X starting value
    // &00000000
    // ~11111111
    
    //  11111110
    //  11111111
    // &11111110
    // ~00000001
    
    // Expected Value
    //  00000100
    //  00000101
    // ^00000001
    
    int x_complement = ~x;
    int y_complement = ~y;
    
    int x_and_y_complement = x & y_complement;
    int x_complement_and_y = x_complement & y;
    
    int output = ~(~x_and_y_complement & ~x_complement_and_y);
    
    return output;
}


/*
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 * and the rest set to 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
    // TODO: FAIL - REMOVE THE FOR LOOP
    int bit_offset = 3;
    
    long int_byte_size = sizeof(int);
    long int_bit_size = int_byte_size * 8;
    
    int bits_to_return = 0;
    
    for(int i = 0; i < int_bit_size; i = i + 1) {
        bits_to_return = bits_to_return | 1;
        bits_to_return = bits_to_return << bit_offset;
    }
    bits_to_return = bits_to_return | 1;
    // printf("int bit size: %lu\n", int_bit_size);
    // printf("int byte size: %lu\n", int_byte_size);
    // printBits(sizeof(bits_to_return), &bits_to_return);
    
    return bits_to_return;
}


// Rating: 2
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {

    // INCORRECT SOLUTION
    // fitsBits(5,3) = 0         5 = number 3 = bits to support
    // Not negative, return 0
    // fitsBits(-4,3) = 1   -   -4 = number 3 = bits to support
    // if (2 ^ n - 1) < x
    //     continue
    // 100 -> 011
    // int max_bit_value = (int)pow((double) 2, (n - 1));
    // int can_bit_fit = ((max_bit_value >= x) ? 1 : 0);
    // int is_x_less_than_zero = (x < 0);
    
    // // only process if x < 0, because a twos complement has to be negative
    // if(!is_x_less_than_zero) {
    //     can_bit_fit = 0;
    // }
    
    // return can_bit_fit;
    //--------------------------------------------------------------------------
    return (1 << (n - 1) > x);
}


/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    return 2;
}


/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    return 2;
}


// Rating: 3
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    return 2;
}


/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    return 2;
}


// Rating: 4
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    return 2;
}


// Extra Credit: Rating: 3
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    return 2;
}


// Extra Credit: Rating: 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    return 2;
}

int main(int argc, char* argv[]) {
    printf("Beginning main loop in bits.c\n");
    // int bit_and_result = bitAnd(5, 6);
    // int bit_and_result = bitAnd(6, 5);
    // printBits(sizeof(bit_and_result), &bit_and_result);
    // printf("=======\n");
    // int bit_or_result = bitXor(4, 5);
    // int bit_or_result = bitXor(5, 4);
    // printBits(sizeof(bit_or_result), &bit_or_result);
    // printf("=======\n");
    // int third_bit =
    // thirdBits();
    // printf("=======\n");
    printf("fitsBits(5,3): %i\n", fitsBits(5, 3));
    printf("fitsBits(-4,3): %i\n", fitsBits(-4, 3));
    // printf("=======\n");
    
    
    // thirdBits();
    // float f = 23.45f;
    // printBits(sizeof(f), &f);
}
