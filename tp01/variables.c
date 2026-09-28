// Exercice 1.4
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    char c = -100;
    short s = -30000;
    int i = -2000000000;
    long int li = -1234567890L;
    long long int lli = -1234567890123456789LL;
    unsigned char uc = UCHAR_MAX;
    unsigned short us = USHRT_MAX;
    unsigned int ui = UINT_MAX;
    unsigned long int uli = ULONG_MAX;
    unsigned long long int ulli = ULLONG_MAX;
    float f = -3.14f;
    double d = 3.14159265358979;
    long double ld = -3.14159265358979323846L;

    printf("char            : %d\n", c);
    printf("short           : %hd\n", s);
    printf("int             : %d\n", i);
    printf("long int        : %ld\n", li);
    printf("long long int   : %lld\n", lli);
    printf("unsigned char       : %hhu\n", uc);
    printf("unsigned short      : %hu\n", us);
    printf("unsigned int        : %u\n", ui);
    printf("unsigned long int   : %lu\n", uli);
    printf("unsigned long long  : %llu\n", ulli);
    printf("float       : %f\n", f);
    printf("double      : %lf\n", d);
    printf("long double : %Lf\n", ld);

    return 0;
}