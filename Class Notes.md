# Important Notes
## Section 1

Nothing of value in this section

## Section 2
- Electronically storing bits is determined by the voltage
  - 0.0V to 0.5V is off
  - 2.8V to 3.3V is on
  - intermediate ranges is what determines speed in computer because that change between state delays

## Section 3
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
  - & is used to find the ‘address of a value’
  - * is used to find the ‘value at an address in memory’ or ‘dereference the address’
