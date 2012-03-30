/*
 * UCLA Winter 2012 CS 259
 * Basic benchmark based on zlib compression
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <or1k-support.h>
#include "zlib.h"

#ifndef TIMER_HZ
#define TIMER_HZ 1000
#endif

#ifndef ITERATIONS
#define ITERATIONS 1000
#endif

#define CHUNK 16384

int main(int argc, char *argv[])
{
  int i, ret;
  unsigned int ticks;
  z_stream strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];

  /* allocate deflate state */
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK) {
    printf("Error initializing zlib\n");
    exit(-1);
  }

  srand(1337);

  or1k_timer_init(TIMER_HZ);
  or1k_timer_enable();

  for (i = 0 i < ITERATIONS; i++) {
    for (i = 0; i < CHUNK; i++) {
      in[i] = (unsigned char) rand(256);
    }

    /* start deflate */

  }

  ticks = or1k_timer_get_ticks();
  printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

  return 0;
}
