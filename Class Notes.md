# Important Notes

## C Syntax Shortcuts
  - !!x
    - Converts X to a boolean value
  - Using << to do base 2 mutliplication
    - This only works for base 2 multiplication
    - x << 2 == x * 2^2
    - x << y == x * 2^y

## Section 0
Nothing of value in this section

## Section 1
- Electronically storing bits is determined by the voltage
  - 0.0V to 0.5V is off
  - 2.8V to 3.3V is on
  - intermediate ranges is what determines speed in computer because that change between state delays

## Section 2
### Machine Words
- size is determined by architecture  
  - Until recently, most machines used 32-bit (4-byte) words  
  - Limits addresses to 4GB  
    - Became too small for memory-intensive applicaFons  
  - Most current x86 systems use 64-bit (8-byte) words  
    - Potential address space: 264 ≈ 1.8 X 1019 bytes (18 EB – exabytes)
  - For backward-compaFbility, many CPUs support different word sizes
    - Always a power-of-2 in the number of bytes: 1, 2, 4, 8, ...

### Byte Ordering Example
- Big Endian vs Little Endian
  - Example variable exists at the memory address 0x01234567
  - Big Endian
    - Stored from left to right
    - Example variable would be stored as: 01-23-45-67
  - Little Endian
    - Stored from right to left
    - Kind of like a stack?
    - Stored as: 67-45-23-01

### Addresses and Pointers in C
- Syntax
  - &
    - is used to find the ‘address of a value’
  - *
    - is used to find the ‘value at an address in memory’ or ‘dereference the address’

### De Morgans Law
- not(A and B) == not(A) or not(B)
  - True Condition
    - Either A, B or both is False
  - False Condition
    - Both A and B need must be True
  - Only fails when A and B are both True
  - not(1 and 1) == FALSE
  - not(1 and 0) == TRUE
  - not(0 and 1) == TRUE
  - not(0 and 0) == TRUE

- not(A or B) == not(A) and not(B)
  - True Condition
    - Both A and B must be False
  - False Condition
    - Either A and B are both True
  - not(1 or 1) == FALSE
  - not(1 or 0) == FALSE
  - not(0 or 1) == FALSE 
  - not(0 or 0) == TRUE

## Section 3
### Acronyms
- CISC
  - Complex Instruction Set Computer
  - Many different instructions with many different formats
  - Only a small subset encountered with Linux programs
- EIP
  - Extended Instrucution Point
- IP
  - Instrucution Point
- ISA
  - Instructure Set Architecture: Set of basic instructions available to the compiler.
- PC
  - Program Counter
  - Special register that holds the address of the instruction that will execute next
  - Called EIP in IA32
  - Called RIP in x86-64
- RISC
  - Reduced Instruction Set Computer
  - Uses simpler instructions

### Definitions
- Architecture
  - The parts of a processor design that one needs to understand to write assembly code
    -  "What is directly visible to software"
  - Number of registers
- Cache
  - Is a fast piece of memory that exists inside the processor
- Microarchitecture
  - These are details of HOW the architecture is implemented
    - Cache size
      - Not directly visible to software
    - Core frequency
      - Do not know about frequency when writing code

### ISA
- Defines system's state
  - registers, program counter, all contents of memory
- Defines instructions the cpu can execute
  - What instructions are available to use
    - add, sub, mov, etc.
    - defines the effect these have on system's state
- Defines registers
  - How many there are
  - How wide are they
    - 32 bits, 64 bits, etc
- Defines memory
  - How to specify memory location/address modes

### x86 Roadmap
- x86 is a CISC
- 8086
  - 1978
  - 16 bit processor
  - 1 MB address space
- 386
  - 1985
  - 32-bit processor
  - Added flat address
    - Means single source of addressing for memory, paging was not a concern anymore
  - 32-bit Linux/gcc environment targets i386 by defaul
- Pentium 4F
  - 2005
  - 64-bit
  - Sometimes called x86-64
- Core 2 Duo
  - 2006
  - 2 Cores on the processor for parallel processing
- Core i7
  - 2008
  - 4 Cores

### Assembly Programmer's View
- Program counter
- Register file
- Condition codes
  - Provides status information about operations performed

## Section 4
%eax == The value in the register
(%eax) == The memory address of the value for the register %eax

int eax == %eax    // These are the same
int* eax == (%eax) // These are the same

compile namer: http://www.swansontec.com/sregisters.html

