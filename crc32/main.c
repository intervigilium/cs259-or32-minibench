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
    int i, j, k;
    register errors = 0;
    unsigned int ticks;
    char in_buf[CHUNK_SIZE];
#ifdef USE_SECURE
    int bit_cnt = 0;
    int diff_cnt = 0;
#endif

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

        bit_cnt = 0;
        for (k = 0; k < sizeof(secure_crc) * 4; k++) {
            if (((secure_crc >> k) & 0x1) != ((crc >> k) & 0x1))
                bit_cnt++;
        }
        diff_cnt += bit_cnt;
        printf("CRC32: differing bits: %d\n", bit_cnt);
#else
        crc = crc32(in_buf, CHUNK_SIZE, 0);
        printf("CRC32: 0x%.8x\n", crc);
#endif
    }
    printf("Finished %d CRC32 iterations\n", ITERATIONS);
#ifdef USE_SECURE
    printf("Average differing bits: %d\n", diff_cnt / ITERATIONS);
#endif

    ticks = or1k_timer_get_ticks();
    printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

    return(errors != 0);
}
