#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main()
{
    char filename[MAX_LENGTH];
    char phrase[MAX_LENGTH];
    char ligne[MAX_LENGTH];
    int compteur = 0;

    printf("Entrez le nom du fichier (avec l'extension) : ");
    scanf("%s", filename);

    printf("Entrez le début d'une phrase : ");
    scanf(" %s", phrase);

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Le fichier n'a pas pu être ouvert et/ou n'existe pas.\n");
        return 1;
    }

    while (fgets(ligne, MAX_LENGTH, fptr) != NULL)
    {
        char *position = ligne;

        while ((position = strstr(position, phrase)) != NULL)
        {
            compteur++;
            position += strlen(phrase);
        }
    }

    fclose(fptr);

    printf("\"%s\" apparaît %d fois dans le fichier.\n", phrase, compteur);

    return 0;
}