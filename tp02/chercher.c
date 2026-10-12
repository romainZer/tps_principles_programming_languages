#include <stdio.h>
#include <string.h>

int main()
{
    char *tableau_exemple[] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."};

    printf("Entrez une phrase à rechercher : ");
    char phrase[100];
    scanf("%s", phrase);
    printf("\n");

    printf("=== Résultats de la recherche ===\n");
    for (unsigned long int i = 0; i < sizeof(tableau_exemple) / sizeof(tableau_exemple[0]); i++)
    {
        char *foundvalptr = strstr(tableau_exemple[i], phrase);
        if (foundvalptr != NULL)
        {
            printf("%s\n", foundvalptr);
        }
    }
}