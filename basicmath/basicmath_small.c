#include "snipmath.h"
#include <stdio.h>
#include <math.h>
#include <or1k-support.h>

#ifndef TIMER_HZ
#define TIMER_HZ 1000
#endif

/* The printf's may be removed to isolate just the math calculations */

int main(void) {
    double  a1 = 1.0, b1 = -10.5, c1 = 32.0, d1 = -30.0;
    double  a2 = 1.0, b2 = -4.5, c2 = 17.0, d2 = -30.0;
    double  a3 = 1.0, b3 = -3.5, c3 = 22.0, d3 = -31.0;
    double  a4 = 1.0, b4 = -13.7, c4 = 1.0, d4 = -35.0;
    double  x[3];
    double  y[3];
    double X;
    int     solutions;
    int i;
    unsigned long l = 0x3fed0169L;
    struct int_sqrt q;
    struct int_sqrt u;
    long n = 0;
    unsigned int ticks;

    or1k_timer_init(TIMER_HZ);
    or1k_timer_enable();

#if 1
    /* solve some cubic functions */
    printf("********* CUBIC FUNCTIONS ***********\n");
    /* should get 3 solutions: 2, 6 & 2.5   */
#ifdef USE_SECURE
    SolveCubic(a1, b1, c1, d1, &solutions, x, 0);
    SolveCubic(a1, b1, c1, d1, &solutions, y, 1);
    printf("Difference:");
    for (i=0; i<solutions; i++)
        printf(" %f",x[i]-y[i]);
    printf("\n");
#else
    SolveCubic(a1, b1, c1, d1, &solutions, x, 0);
    printf("Solutions:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]);
    printf("\n");
#endif
    /* should get 1 solution: 2.5           */
#ifdef USE_SECURE
    SolveCubic(a2, b2, c2, d2, &solutions, x, 0);
    SolveCubic(a2, b2, c2, d2, &solutions, y, 1);
    printf("Difference:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]-y[i]);
    printf("\n");
#else
    SolveCubic(a2, b2, c2, d2, &solutions, x, 0);
    printf("Solutions:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]);
    printf("\n");
#endif
#ifdef USE_SECURE
    SolveCubic(a3, b3, c3, d3, &solutions, x, 0);
    SolveCubic(a3, b3, c3, d3, &solutions, y, 1);
    printf("Difference:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]-y[i]);
    printf("\n");
#else
    SolveCubic(a3, b3, c3, d3, &solutions, x, 0);
    printf("Solutions:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]);
    printf("\n");
#endif
#ifdef USE_SECURE
    SolveCubic(a4, b4, c4, d4, &solutions, x, 0);
    SolveCubic(a4, b4, c4, d4, &solutions, y, 1);
    printf("Difference:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]-y[i]);
    printf("\n");
#else
    SolveCubic(a4, b4, c4, d4, &solutions, x, 0);
    printf("Solutions:");
    for(i=0; i<solutions; i++)
        printf(" %f",x[i]);
    printf("\n");
#endif
    /* Now solve some random equations */
#if 0
    for(a1=1; a1<10; a1++) {
        for(b1=10; b1>0; b1--) {
            for(c1=5; c1<15; c1+=0.5) {
                for(d1=-1; d1>-11; d1--) {
                    SolveCubic(a1, b1, c1, d1, &solutions, x);
                    printf("Solutions:");
                    for(i=0; i<solutions; i++)
                        printf(" %f",x[i]);
                    printf("\n");
                }
            }
        }
    }
#endif
#endif

#if 1
    printf("********* INTEGER SQR ROOTS ***********\n");
    /* perform some integer square roots */
#if 0
    for (i = 0; i < 1001; ++i) {
        usqrt(i, &q, 0);
        printf("sqrt(%3d) = %2d\n", i, q.sqrt);
    }
#endif
#ifdef USE_SECURE
    usqrt(l, &q, 0);
    usqrt(l, &u, 1);
    printf("Difference = %X\n", q.sqrt - u.sqrt);
#else
    usqrt(l, &q, 0);
    printf("Sqrt(%lX) = %X\n", l, q.sqrt);
#endif
#endif

#if 1
    printf("********* ANGLE CONVERSION ***********\n");
#ifdef USE_SECURE
    for (X = 0.0; X <= 360.0; X += 1.0)
        printf("Difference= %.12f\n", deg2rad(X, 0) - deg2rad(X, 1));
#else
    for (X = 0.0; X <= 360.0; X += 1.0)
        printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X, 0));
#endif
    puts("");
#ifdef USE_SECURE
    for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
        printf("Difference= %.12f\n", rad2deg(X, 0) - deg2rad(X, 1));
#else
    for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
        printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X, 0));
#endif

    ticks = or1k_timer_get_ticks();
    printf("********* ANGLE CONVERSION ***********\n");
#endif
    printf("Elapsed: %d ticks at %d Hz\n", ticks, TIMER_HZ);

    return 0;
}
