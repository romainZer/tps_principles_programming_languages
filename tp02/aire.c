#include <math.h>
#include <stdio.h>

float calculer_aire(float rayon)
{
    return M_PI * rayon * rayon;
}

int main()
{
    float rayon = 5.0;
    float aire = calculer_aire(rayon);
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}