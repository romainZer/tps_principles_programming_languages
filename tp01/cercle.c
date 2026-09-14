// Exercice 1.2

#include <stdio.h>

float PI = 3.14159;

float calculateArea(float r)
{
    float rayon = PI * r * r;
    return rayon;
}

float calculatePerimeter(float r)
{
    float perimeter = PI * 2 * r;
    return perimeter;
}

int main()
{
    float rayon;
    printf("Veuillez entrer le rayon du cercle : ");
    scanf("%f", &rayon);
    printf("\n");

    float area = calculateArea(rayon);
    float perimeter = calculatePerimeter(rayon);

    printf("Area : %f\n", area);
    printf("Perimeter : %f\n", perimeter);

    return 0;
}
