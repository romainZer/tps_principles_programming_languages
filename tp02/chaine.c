#include <stdio.h>
#include <string.h>
int main()
{
    char input[128];
    printf("Entrez une chaîne de caractères : ");
    scanf("%s", input);

    int inp_size = strlen(input);
    printf("Taille de la chaîne : %i\n", inp_size);

    char copied_str[inp_size];
    strcpy(copied_str, input);
    printf("Chaîne originale : %s\nChaîne copiée : %s\n", input, copied_str);

    char concat_str[inp_size * 2];
    strcpy(concat_str, input);
    strcat(concat_str, input);
    printf("Chaîne doublée : %s\n", concat_str);
    return 0;
}