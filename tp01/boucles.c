// Exercice 1.6

#include <stdio.h>

/**
 * Iterates and draws a filled rectangle, based on for loops.
 * @param nb expected amount of lines
 */
void loop(int nb)
{
    for (int i = 1; i < nb + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bool is_first = j == 0;
            bool is_last = j == i - 1;

            if (is_first || is_last || i == nb)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

/**
 * Iterates and draws a filled rectangle, based on while loops.
 * @param nb expected amount of lines
 */
void while_loop(int nb)
{
    int cntln = 0;
    while (cntln < nb)
    {
        int cntcl = 0;
        while (cntcl <= cntln)
        {
            bool is_first = cntcl == 0;
            bool is_last = cntcl == cntln;

            if (is_first || is_last || cntln == nb - 1)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
            cntcl++;
        }
        printf("\n");
        cntln++;
    }
}

int main()
{
    int nb = 0;
    printf("Entrez un nombre < 10 :\n");
    scanf("%i", &nb);

    if (nb >= 10)
    {
        printf("Valeur attendue < 10, réessayez.\n");
        return 1;
    }

    loop(nb);
    while_loop(nb);

    return 0;
}