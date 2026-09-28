// Exercice 1.2

#include <stdio.h>

float PI = 3.14159;

/**
 * Calculates a radius (of a circle)
 */
float calculateRadius(float r)
{
    float radius = PI * r * r;
    return radius;
}

/**
 * Calculates a perimeter (of a circle)
 */
float calculatePerimeter(float r)
{
    float perimeter = PI * 2 * r;
    return perimeter;
}

int main()
{
    float radius;
    printf("Veuillez entrer le rayon du cercle : ");
    scanf("%f", &radius);
    printf("\n");

    float area = calculateRadius(radius);
    float perimeter = calculatePerimeter(radius);

    printf("Area : %f\n", area);
    printf("Perimeter : %f\n", perimeter);

    return 0;
}
