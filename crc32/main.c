#include <stdio.h>
#include <or1k-support.h>
#include "crc32.h"

#ifndef TIMER_HZ
#define TIMER_HZ 1000
#endif

#ifndef ITERATIONS
#define ITERATIONS 100
#endif

#define CHUNK_SIZE 16384

int
main(int argc, char *argv[]) {
    DWORD crc, secure_crc;
    long charcnt;
    int i, j;
    register errors = 0;
    unsigned int ticks;
    char in_buf[CHUNK_SIZE];

    srand(1337);

    or1k_timer_init(TIMER_HZ);
    or1k_timer_enable();

    printf("Performing %d CRC32 iterations\n", ITERATIONS);
    for (i = 0; i < ITERATIONS; i++) {
        for (j = 0; j < CHUNK_SIZE; j++) {
            in_buf[j] = (char) (rand() % 256);
        }

        /* start CRC32 */
#ifdef USE_SECURE
        secure_crc = crc32(in_buf, CHUNK_SIZE, 1);
        crc = crc32(in_buf, CHUNK_SIZE, 0);
        printf("CRC32: 0x%.8x, expected 0x%.8x\n", secure_crc, crc);
#else
        crc = crc32(in_buf, CHUNK_SIZE, 0);
        printf("CRC32: 0x%.8x\n", crc);
#endif
    }
    printf("Finished %d CRC32 iterations\n", ITERATIONS);

    ticks = or1k_timer_get_ticks();
    printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

    return(errors != 0);
}
