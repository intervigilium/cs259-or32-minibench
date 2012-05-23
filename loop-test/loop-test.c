#include <stdio.h>
#include <stdlib.h>


#ifndef FIB_NUM
#define FIB_NUM 20
#endif

int add(int a, int b)
{
#ifdef SECURE_ADD
  asm volatile("l.addx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
#else
  return a + b;
#endif
}

int simple_fibonacci(int fib_num)
{
  int i;
  int prev = 1;
  int sum = 1;

  for (i = 2; i < fib_num; i++) {
    sum = add(sum, prev);
    prev = sum - prev;
    printf("current sum: %d, prev sum: %d\n", sum, prev);
  }

  return sum;
}

int main(int argc, char *argv[])
{
  int fib_num;

  fib_num = FIB_NUM;

  printf("%d-th Fibonacci number is: %d\n", fib_num, simple_fibonacci(fib_num));

  return 0;
}
