// Exercice 1.5
#include <stdio.h>

int main()
{
    int a = 16;
    int b = 3;

    printf("Addition a+b : %i\n", a + b);
    printf("Soustraction a-b : %i\n", a - b);
    printf("Multiplication a*b : %i\n", a * b);
    printf("Division a/b : %i\n", a / b);
    printf("Modulo a mod b : %i\n", a % b);

    printf("----Comparaisons (1 = true, 0 = false)----\n");
    printf("a == b ? : %i\n", a == b);
    printf("a > b ? : %i\n", a > b);

    return 0;
}