#include <stdio.h>
#include <stdlib.h>

/* This program emits the Thue-Morse sequence up to the given number of digits.
 * It should be invoked by:
 *      ./thuemorse [digits]
 * where digits is an integer.
 * It should compile with
 *      cc thuemorse.c -o thuemorse -std=c99
 */

#include "queue.h"

void stream_digits(const unsigned maxdigits, const unsigned buffersize,
                   char* *buffer, struct Queue *queue) {
    char *elem = *buffer; // pointer to start of current string

    for (unsigned num = 0; num < maxdigits; ++num) {
        // count the number of ones in the binary expansion of num
        unsigned ones = 0, curr = num;
        while (curr) {
            ones += (curr & 1);
            curr = curr >> 1;
        }

        // store the result in the buffer:
        *elem++ = (ones % 2);

        // when the buffer is full, add the contents to the queue and create a
        // new buffer:
        if (!((num + 1) % buffersize)) {
            enqueue(*buffer, queue);
            *buffer = (char *)malloc(buffersize * sizeof(char));
            elem = *buffer;
        }
    }
}

void print_buffer(const char *buffer, unsigned stop) {
    const char *elem = buffer;
    for (elem = buffer; elem < buffer + stop; ++elem) {
        putchar(48 + *elem);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Pass a number of digits as an argument:\n");
        printf("    ./thuemorse [digits]\n");
        return 1;
    }

    unsigned maxdigits = atoi(argv[1]);
    unsigned buffersize = 1 << 20;
    char *buffer = (char *)malloc(buffersize * sizeof(char));
    struct Queue queue = {0, 0};

    // first process: generate lots of digits and queue the results:
    stream_digits(maxdigits, buffersize, &buffer, &queue);

    // second process: print the queued strings:
    while (queue.end) {
        print_buffer((const char *)((queue.end)->item), buffersize);
        dequeue(&queue);
    }
    // when both these processes are complete...
    // print anything left over in the buffer, then free it:
    if (buffer) {
        print_buffer(buffer, (maxdigits % buffersize));
        free(buffer);
    }
    printf("\n");

    return 0;
}
