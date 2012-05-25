#include <stdio.h>
#include <stdlib.h>
#include "secure_func.h"

#ifndef FIB_NUM
#define FIB_NUM 25
#endif

void simple_fibonacci(int *res, int fib_num, int use_secure)
{
  int i;
  int prev = 1;
  int sum = 1;
  res[0] = 1;
  res[1] = 1;

  for (i = 2; i < fib_num; i++) {
    if (use_secure)
      res[i] = secure_add(res[i-1], res[i-2]);
    else
      res[i] = res[i-1] + res[i-2];
    /* printf("current sum: %d, prev sum: %d\n", res[i], res[i-1]); */
  }
}

int main(int argc, char *argv[])
{
  int i;
  int res[FIB_NUM];
  int sec_res[FIB_NUM];

#ifdef USE_SECURE
  simple_fibonacci(res, FIB_NUM, 0);
  simple_fibonacci(sec_res, FIB_NUM, 1);
  for (i = 0; i < FIB_NUM; i++) {
    printf("Difference %d: %d\n", i, sec_res[i] - res[i]);
  }
#else
  simple_fibonacci(res, FIB_NUM, 0);
  for (i = 0; i < FIB_NUM; i++) {
    printf("Fibonacci number %d is: %d\n", i+1, res[i]);
  }
#endif

  return 0;
}
