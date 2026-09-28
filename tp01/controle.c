#include <stdio.h>

int main()
{
    for (int n = 1; n <= 1000; n++)
    {
        // Divisible par 4 mais pas par 6
        if (n % 4 == 0 && n % 6 != 0)
        {
            printf("%i\n", n);
        }

        // Pair et divisible par 8
        if (n % 2 == 0 && n % 8 == 0)
        {
            printf("%i\n", n);
        }

        // Divisible par 5 ou 7 mais pas par 10
        if ((n % 5 == 0 || n % 7 == 0) && n % 10 != 0)
        {
            printf("%i\n", n);
        }
    }
}