#include <stdio.h>
#include <stdlib.h>

/* This program emits the Thue-Morse sequence up to the given number of digits.
 * It should be invoked by:
 *      ./thuemorse [digits]
 * where digits is an integer.
 * It should compile with
 *      cc thuemorse.c -o thuemorse -std=c99
 */

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Pass a number of digits as an argument:\n");
        printf("    ./thuemorse [digits]\n");
        return 1;
    }

    unsigned maxdigits = atoi(argv[1]);
    
    for (unsigned num = 0; num < maxdigits; ++num) {
        // count the number of ones in the binary expansion of num
        unsigned ones = 0, curr = num;
        while (curr) {
            ones += (curr & 1);
            curr = curr >> 1;
        }
        putchar(48 + (ones % 2));
    }
    printf("\n");

    return 0;
}
