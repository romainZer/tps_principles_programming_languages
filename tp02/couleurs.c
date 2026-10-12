#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COULEURS 100

typedef struct
{
    unsigned char r, g, b, a;
} Couleur;

int sont_egales(Couleur c1, Couleur c2)
{
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

Couleur couleur_aleatoire(void)
{
    static const unsigned char valeurs[] = {0, 128, 255};
    Couleur c;
    c.r = valeurs[rand() % 3];
    c.g = valeurs[rand() % 3];
    c.b = valeurs[rand() % 3];
    c.a = valeurs[rand() % 3];
    return c;
}

int main(void)
{
    Couleur tab[NB_COULEURS];
    int deja_compte[NB_COULEURS] = {0};

    // Génère une valeur aléatoire (se base sur l'horloge)
    srand((unsigned)time(NULL));

    for (int i = 0; i < NB_COULEURS; i++)
    {
        tab[i] = couleur_aleatoire();
    }

    printf("Couleurs distinctes et occurrences :\n");

    for (int i = 0; i < NB_COULEURS; i++)
    {
        if (!deja_compte[i])
        {
            int compteur = 1;
            for (int j = i + 1; j < NB_COULEURS; j++)
            {
                if (sont_egales(tab[i], tab[j]))
                {
                    compteur++;
                    deja_compte[j] = 1;
                }
            }
            printf("(R=%d, G=%d, B=%d, A=%d) : %d\n",
                   tab[i].r, tab[i].g, tab[i].b, tab[i].a, compteur);
        }
    }

    return 0;
}