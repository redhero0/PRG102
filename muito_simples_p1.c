#include <stdio.h>
#include <math.h>

/**
 * distancia: calcula a distancia entre dois pontos de coordenadas x e y recebidos em vetores de 2 posicoes
 * @param double v1[2]
 * @param double v2[2]
 * @return sqrt(pow((v1[0]-v2[0]),2) + pow((v1[1]-v2[1]),2))
 */
double distancia(double v1[2], double v2[2])
{
    return sqrt(pow((v1[0]-v2[0]),2) + pow((v1[1]-v2[1]),2)); // raiz((v1x - v2x)^2 + (v1y-v2y)^2)
}

int main()
{
    double v1[2] = {1, 2};
    double v2[2] = {5, 6};
    printf("%.5f\n", distancia(v1, v2));
}