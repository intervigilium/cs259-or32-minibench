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
#define ITERATIONS 100
#endif

#define CHUNK 16384

int main(int argc, char *argv[])
{
  int i, j, k, ret;
  int diff_count;
  unsigned int ticks;
  z_stream strm;
  z_stream sec_strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];
#ifdef USE_SECURE
  unsigned char sec_in[CHUNK];
  unsigned char sec_out[CHUNK];
#endif

  /* allocate deflate state */
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK) {
    printf("Error initializing zlib\n");
    exit(-1);
  }
#ifdef USE_SECURE
  sec_strm.zalloc = Z_NULL;
  sec_strm.zfree = Z_NULL;
  sec_strm.opaque = Z_NULL;
  ret = deflateInit(&sec_strm, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK) {
    printf("Error initializing zlib\n");
    exit(-1);
  }
#endif

  printf("Initialized deflate\n");

  srand(1337);

  or1k_timer_init(TIMER_HZ);
  or1k_timer_enable();

  printf("Performing %d deflate iterations\n", ITERATIONS);
  for (i = 0; i < ITERATIONS; i++) {
    for (j = 0; j < CHUNK; j++) {
      in[j] = (unsigned char) (rand() % 256);
#ifdef USE_SECURE
      sec_in[j] = in[j];
#endif
    }

    /* start deflate */
    strm.avail_in = CHUNK;
    strm.next_in = in;

    strm.avail_out = CHUNK;
    strm.next_out = out;
#ifdef USE_SECURE
    sec_strm.avail_in = CHUNK;
    sec_strm.next_in = sec_in;

    sec_strm.avail_out = CHUNK;
    sec_strm.next_out = sec_out;

    ret = deflate(&strm, 0, 0);
    if (ret == Z_STREAM_ERROR) {
      printf("Error in deflate!\n");
      break;
    }
    ret = deflate(&sec_strm, 0, 1);
    if (ret == Z_STREAM_ERROR) {
      printf("Error in secure deflate!\n");
      break;
    }
    diff_count = 0;
    for (k = 0; k < CHUNK; k++)
        if (sec_out[k] != out[k])
            diff_count++;
    printf("Difference: %d bytes\n", diff_count);
#else
    ret = deflate(&strm, 0, 0);
    if (ret == Z_STREAM_ERROR) {
      printf("Error in deflate!\n");
      break;
    }
#endif
  }
  printf("Finished %d deflate iterations\n", ITERATIONS);
  deflateEnd(&strm);

  ticks = or1k_timer_get_ticks();
  printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

  return 0;
}
