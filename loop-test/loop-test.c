#include <stdio.h>
#include <stdlib.h>
#include "secure_func.h"

#ifndef FIB_NUM
#define FIB_NUM 20
#endif

int simple_fibonacci(int fib_num)
{
  int i;
  int prev = 1;
  int sum = 1;

  for (i = 2; i < fib_num; i++) {
#ifdef USE_SECURE
    sum = secure_add(sum, prev);
#else
    sum += prev;
#endif
    prev = sum - prev;
    printf("current sum: %d, prev sum: %d\n", sum, prev);
  }

  return sum;
}

int main(int argc, char *argv[])
{
  unsigned long xor_t0 = 0x003fff80;
  unsigned long xor_t1 = 0xf000000f;

  printf("0x%.8x xor 0x%.8x = 0x%.8x\n", xor_t0, xor_t1, secure_xor(xor_t0, xor_t1));

  printf("%d-th Fibonacci number is: %d\n", FIB_NUM, simple_fibonacci(FIB_NUM));

  return 0;
}
