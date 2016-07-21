#include <stdio.h>
#include <stdlib.h>

// Original
// int test(int i, long int l) {
//     return i == ((int)l);
// }

// "Fixed"
int test(int i, long int l) {
    return i == ((int)l);
}

int main(int argc, const char* argv[]) {
    int i = rand() % 20;
    // creates two random 2 byte ints and assigns them to a 4 byte long int
    long int l = (rand() << 31) | rand();
    int test_output = test(i, l);
    printf("test_output: %d", test_output);
    printf("\n");
    
    return 0;
}
