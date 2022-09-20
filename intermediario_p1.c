#include <stdio.h>
#include <math.h>

/**
 * encontra_angulo: recebe as coordenadas de 3 pontos e descobre o angulo entre eles,
 * descobrindo os lados formados pelos pontos e obtendo o angulo atraves da lei dos cossenos 
 * @param double a[2]
 * @param double b[2]
 * @param double c[2]
 * @return angulo
 */
double encontra_angulo(double a[2], double b[2], double c[2])
{
    double ab, bc, ca;
    ab = sqrt(pow(b[0]-a[0],2)+pow(b[1]-a[1],2));
    bc = sqrt(pow(b[0]-c[0],2)+pow(b[1]-c[1],2));
    ca = sqrt(pow(c[0]-a[0],2)+pow(c[1]-a[1],2));
    return acos((pow(ab,2)+pow(bc,2)-pow(ca,2))/(2*ab*bc));
}

int main()
{
    double a[2] = {0,0}, b[2] = {2,0}, c[2] = {0,2};
    printf("Angulo: %.4f\n", encontra_angulo(a, b, c));
    return 0;
}