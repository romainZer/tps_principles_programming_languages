#include <stdio.h>
#include <string.h>

#define NOMBRE_ETUDIANTS 5
#define NOMBRE_NOTES 5

// Structure qui représente un étudiant
struct student
{
    char nom[50];
    char prenom[50];
    char adresse[100];
    int notes[NOMBRE_NOTES];
};

// Initialise le tableau d'étudiants
void init_students(struct student *etu, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        strcpy(etu[i].nom, "Inconnu");
        strcpy(etu[i].prenom, "Inconnu");
        strcpy(etu[i].adresse, "");
        for (int j = 0; j < NOMBRE_NOTES; j++)
        {
            etu[i].notes[j] = 0;
        }
    }
}

int main()
{
    struct student etu[NOMBRE_ETUDIANTS];
    init_students(etu, NOMBRE_ETUDIANTS);

    printf("=== Saisie des étudiants ===\n");
    printf("=== Veuillez saisir les informations des étudiants ===\n");
    for (int i = 0; i < NOMBRE_ETUDIANTS; i++)
    {
        struct student stud_infos;
        printf("\n--- Étudiant %d ---\n", i + 1);

        printf("Nom : ");
        scanf("%49s", stud_infos.nom);

        printf("Prénom : ");
        scanf("%49s", stud_infos.prenom);

        printf("Adresse : ");
        scanf(" %99[^\n]", stud_infos.adresse);

        for (int j = 0; j < NOMBRE_NOTES; j++)
        {
            printf("Saisissez la note n°%d : ", j + 1);
            scanf("%d", &stud_infos.notes[j]);
        }

        etu[i] = stud_infos;
    }

    printf("\n=== Récapitulatif des étudiants ===\n");
    for (int i = 0; i < NOMBRE_ETUDIANTS; i++)
    {
        printf("\nÉtudiant %d\n", i + 1);
        printf("  Nom     : %s\n", etu[i].nom);
        printf("  Prénom  : %s\n", etu[i].prenom);
        printf("  Adresse : %s\n", etu[i].adresse);
        printf("  Notes   : ");
        for (int j = 0; j < NOMBRE_NOTES; j++)
        {
            printf("%d ", etu[i].notes[j]);
        }
        printf("\n");
    }

    return 0;
}