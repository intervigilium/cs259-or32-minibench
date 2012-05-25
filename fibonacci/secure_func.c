/*
 * implementation for secure OR32 functions
 */

#include "secure_func.h"

int secure_add(int a, int b)
{
  asm volatile("l.addx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_sub(int a, int b)
{
  asm volatile("l.subx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_mul(int a, int b)
{
  asm volatile("l.mulx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_div(int a, int b)
{
  asm volatile("l.divx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_and(int a, int b)
{
  asm volatile("l.andx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_or(int a, int b)
{
  asm volatile("l.orx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

int secure_xor(int a, int b)
{
  asm volatile("l.xorx %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

double secure_fp_add(double a, double b)
{
  asm volatile("lf.addx.s %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

double secure_fp_sub(double a, double b)
{
  asm volatile("lf.subx.s %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

double secure_fp_mul(double a, double b)
{
  asm volatile("lf.mulx.s %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}

double secure_fp_div(double a, double b)
{
  asm volatile("lf.divx.s %0,%1,%2;"
               : "=r"(a)
               : "r"(a), "r"(b)
               );
  return a;
}
