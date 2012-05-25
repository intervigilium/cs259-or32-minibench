#include <stdio.h>
#include <stdlib.h>
#include "secure_func.h"

#ifndef FIB_NUM
#define FIB_NUM 25
#endif

int simple_fibonacci(int fib_num, int use_secure)
{
  int i;
  int prev = 1;
  int sum = 1;

  for (i = 2; i < fib_num; i++) {
    if (use_secure)
      sum = secure_add(sum, prev);
    else
      sum += prev;
    prev = sum - prev;
    printf("current sum: %d, prev sum: %d\n", sum, prev);
  }

  return sum;
}

int main(int argc, char *argv[])
{
#ifdef USE_SECURE
  printf("%d-th Fibonacci number is: %d\n", FIB_NUM, simple_fibonacci(FIB_NUM, 1));
#else
  printf("%d-th Fibonacci number is: %d\n", FIB_NUM, simple_fibonacci(FIB_NUM, 0));
#endif

  return 0;
}
