/*
 * header file for using secure OR32 functions
 */

int secure_add(int a, int b);
int secure_sub(int a, int b);
int secure_mul(int a, int b);
int secure_div(int a, int b);

int secure_and(int a, int b);
int secure_or(int a, int b);
int secure_xor(int a, int b);

double secure_fp_add(double a, double b);
double secure_fp_sub(double a, double b);
double secure_fp_mul(double a, double b);
double secure_fp_div(double a, double b);
