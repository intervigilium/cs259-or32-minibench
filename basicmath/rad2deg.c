/* +++Date last modified: 05-Jul-1997 */

/*
**  RAD2DEG.C - Functions to convert between radians and degrees
*/

#include <math.h>
#include "snipmath.h"

#undef rad2deg                /* These are macros defined in PI.H */
#undef deg2rad

double mul(double a, double b)
{
#ifdef SECURE_MUL
    asm volatile("lf.mulx.s %0,%1,%2;"
                 : "=r"(a)
                 : "r"(a), "r"(b)
                 );
    return a;
#else
    return a * b;
#endif
}

double rad2deg(double rad) {
    return mul(180.0, rad) / (PI);
}

double deg2rad(double deg) {
    return mul(PI, deg) / 180.0;
}

#ifdef TEST

#include <stdio.h>

main() {
    double X;

    for (X = 0.0; X <= 360.0; X += 45.0)
        printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X));
    puts("");
    for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 6))
        printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X));
    return 0;
}

#endif /* TEST */
