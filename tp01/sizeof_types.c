// Exercice 1.3
#include <stdio.h>

int main()
{
    printf("sizeof(char): %zu\n", sizeof(char));
    printf("sizeof(signed char): %zu\n", sizeof(signed char));
    printf("sizeof(unsigned char): %zu\n", sizeof(unsigned char));

    printf("sizeof(short): %zu\n", sizeof(short));
    printf("sizeof(unsigned short): %zu\n", sizeof(unsigned short));

    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(unsigned int): %zu\n", sizeof(unsigned int));

    printf("sizeof(long int): %zu\n", sizeof(long int));
    printf("sizeof(unsigned long int): %zu\n", sizeof(unsigned long int));

    printf("sizeof(long): %zu\n", sizeof(long));
    printf("sizeof(long int): %zu\n", sizeof(long int));

    printf("sizeof(float): %zu\n", sizeof(float));

    printf("sizeof(double): %zu\n", sizeof(double));

    printf("sizeof(long double): %zu\n", sizeof(long double));

    return 0;
}