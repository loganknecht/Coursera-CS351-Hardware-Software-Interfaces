# Problem 01
## Question
Homework Problem 2.76 (pg 126)

Suppose we are given the task of generating code to multiply integer variable x by various different constant factors K. To be efficient, we want to use only the operations +, -, <<.

For the following values of K, write C expressions to perform the multiplication using at most three operations per expression.
A. K = 17:
B. K = -7:
C. K = 60:
D. K = -112:

## Answer
2



# Problem 02
## Question
What, if anything, is wrong with the code below?

int test(int i, long int l) { 
    return i == ((int)l);
}

## Answer
- by default it returns 0
- the value returned is a boolean value
- the return type signature is integer 
- the long's conversion to the integer type will remove precision
  - this results in the 2 most significant bytes being cut off
  - the remaining bytes are the two least significant bytes


# Problem 03
## Question
For this problem you will use the jack-of-all-trades tool objdump to examine executable programs on Linux.

Be sure to work on this problem on the provided VM.

You will need a copy of the code for Lab 1 (your code does not have to be entirely correct or complete but at least some of your puzzle functions should be filled in).


A. Run make in your Lab 1 directory to build your code.
Run the command objdump -t btest| grep text and examine the output.
What do the strings in the rightmost column of the output represent?


B. Use objdump to disassemble your btest code (review the "Machine Programming" lecture in section 3 or check the man page to find the right flag).
Find the labels in the assembly code corresponding to your bit puzzle functions. 
What x86 assembly instructions appear to perform right-shift and left-shift operations?


C. Most Linux distributions include several other useful programs for examining binary files containing machine code.
Try out commands such as 
- ldd
- file
- nm
- strings
- readelf
- try other flags with objdump.
Report something neat, unusual, or unexpected that you find. Don't forget to use the man pages to learn more about all of these programs.


D. Run the objdump -t command on a different program on the system - choose one in the /usr/bin/ directory.

You will likely see the output "SYMBOL TABLE: no symbols".

Why does objdump -t appear to work on your program, but not on others?

## Answer

### Part A
0000000100000e70 l       0e SECT   01 0000 [.text] _usage
0000000100000f00 l       0e SECT   01 0000 [.text] _get_num_val
0000000100000fd0 l       0e SECT   01 0000 [.text] _test_function
0000000100000b30 g       0f SECT   01 0000 [.text] _Signal
0000000100000000 g       0f SECT   01 0010 [.text] __mh_execute_header
0000000100000af0 g       0f SECT   01 0000 [.text] _addOK
0000000100000b00 g       0f SECT   01 0000 [.text] _bang
0000000100000a60 g       0f SECT   01 0000 [.text] _bitAnd
0000000100000a70 g       0f SECT   01 0000 [.text] _bitXor
0000000100000b10 g       0f SECT   01 0000 [.text] _conditional
00000001000016e0 g       0f SECT   01 0000 [.text] _f2u
0000000100000aa0 g       0f SECT   01 0000 [.text] _fitsBits
0000000100000ad0 g       0f SECT   01 0000 [.text] _getByte
0000000100000b20 g       0f SECT   01 0000 [.text] _isPower2
0000000100000ae0 g       0f SECT   01 0000 [.text] _logicalShift
0000000100000ba0 g       0f SECT   01 0000 [.text] _main
0000000100000ac0 g       0f SECT   01 0000 [.text] _sign
00000001000017b0 g       0f SECT   01 0000 [.text] _test_addOK
00000001000017d0 g       0f SECT   01 0000 [.text] _test_bang
00000001000016f0 g       0f SECT   01 0000 [.text] _test_bitAnd
0000000100001700 g       0f SECT   01 0000 [.text] _test_bitXor
00000001000017e0 g       0f SECT   01 0000 [.text] _test_conditional
0000000100001720 g       0f SECT   01 0000 [.text] _test_fitsBits
0000000100001770 g       0f SECT   01 0000 [.text] _test_getByte
00000001000017f0 g       0f SECT   01 0000 [.text] _test_isPower2
00000001000017a0 g       0f SECT   01 0000 [.text] _test_logicalShift
0000000100001750 g       0f SECT   01 0000 [.text] _test_sign
0000000100001710 g       0f SECT   01 0000 [.text] _test_thirdBits
0000000100000a90 g       0f SECT   01 0000 [.text] _thirdBits
0000000100000b80 g       0f SECT   01 0000 [.text] _timeout_handler
00000001000016d0 g       0f SECT   01 0000 [.text] _u2f

-t
--syms
   Print the symbol table entries of the file.  This is similar to the information provided by the nm
   program, although the display format is different.  The format of the output depends upon the format of
   the file being dumped, but there are two main types.  One looks like this:

           [  4](sec  3)(fl 0x00)(ty   0)(scl   3) (nx 1) 0x00000000 .bss
           [  6](sec  1)(fl 0x00)(ty   0)(scl   2) (nx 0) 0x00000000 fred

   where the number inside the square brackets is the number of the entry in the symbol table, the sec number
   is the section number, the fl value are the symbol's flag bits, the ty number is the symbol's type, the
   scl number is the symbol's storage class and the nx value is the number of auxilary entries associated
   with the symbol.  The last two fields are the symbol's value and its name.

   The other common output format, usually seen with ELF based files, looks like this:

           00000000 l    d  .bss   00000000 .bss
           00000000 g       .text  00000000 fred

   Here the first number is the symbol's value (sometimes refered to as its address).  The next field is
   actually a set of characters and spaces indicating the flag bits that are set on the symbol.  These
   characters are described below.  Next is the section with which the symbol is associated or *ABS* if the
   section is absolute (ie not connected with any section), or *UND* if the section is referenced in the file
   being dumped, but not defined there.

   After the section name comes another field, a number, which for common symbols is the alignment and for
   other symbol is the size.  Finally the symbol's name is displayed.

   The flag characters are divided into 7 groups as follows:

   "l"
   "g"
   "u"
   "!" The symbol is a local (l), global (g), unique global (u), neither global nor local (a space) or both
       global and local (!).  A symbol can be neither local or global for a variety of reasons, e.g., because
       it is used for debugging, but it is probably an indication of a bug if it is ever both local and
       global.  Unique global symbols are a GNU extension to the standard set of ELF symbol bindings.  For
       such a symbol the dynamic linker will make sure that in the entire process there is just one symbol
       with this name and type in use.


   "w" The symbol is weak (w) or strong (a space).

   "C" The symbol denotes a constructor (C) or an ordinary symbol (a space).

   "W" The symbol is a warning (W) or a normal symbol (a space).  A warning symbol's name is a message to be
       displayed if the symbol following the warning symbol is ever referenced.

   "I"
   "i" The symbol is an indirect reference to another symbol (I), a function to be evaluated during reloc
       processing (i) or a normal symbol (a space).

   "d"
   "D" The symbol is a debugging symbol (d) or a dynamic symbol (D) or a normal symbol (a space).

   "F"
   "f"
   "O" The symbol is the name of a function (F) or a file (f) or an object (O) or just a normal symbol (a space). 



The final column is the symbol's name. These are the names of the C functions.

### Part B

### Part C

### Part D



# Problem 04 (Optional)
## Question
What, if anything, is wrong with the code below?

int test(float f, double d) {
    return ((double)f) == d;
}

## Answer




# Problem 05 (Optional)
## Question
Optional Material: Recall that a floating point number is of the form: (-1)S x M x 2E .

M is the mantissa and 2E is the exponent.

Also recall that M ranges from 1.0 to (almost) 2.0.

Tell us the values of M and E for the number 15.0.

Note we do not expect you to encode this in IEEE 754 representation, we want you to just tell us in decimal the values of M and E, and the binary value of the frac (recall frac = M - 1.0).

## Answer




# Problem 06 (Optional)
## Question
Homework Problem 2.88 (pg 129)

We are running programs on a chine where values of type int have a 32-bit two's-complement representation. Values of type float use the 32-bit IEEE format, and values of type double use the 64-bit IEEE format.

We generate arbitrary integer values x, y, and z, and convert them to values of type double as follows:

/* Create some arbitrary values */
int x = random();
int y = random();
int z = random();
/* Convert to double */
double dx=(double)x; 
double dy=(double)y; 
double dz=(double)z;


For each of the following C expressions, you are to indicate whether or not the expression always

## Answer


