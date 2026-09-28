#include <stdio.h>

/**
 * Converts to bin and displays the result
 */
void convert_to_bin(int usr_inp)
{
    // Initialisation
    char res[128];
    int count = 0;

    if (usr_inp == 0)
    {
        printf("0\n");
        return;
    }

    // Calcul
    while (usr_inp > 0)
    {
        res[count] = usr_inp % 2;
        usr_inp = usr_inp / 2;
        count++;
    }

    // Affichage
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    printf("\n");
}

int main()
{
    int usr_input;
    printf("Veuillez entrer la valeur a convertir en binaire :\n");
    scanf("%i", &usr_input);
    convert_to_bin(usr_input);
    return 0;
}