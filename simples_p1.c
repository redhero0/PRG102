#include <stdio.h>
#include <math.h>

int main()
{
    int lista[10], x = 11, y = 11;
    printf("Digite o vetor de 10 posições: ");
    // le o vetor de 10 posicoes
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &lista[i]);
    }
    // continua lendo x até que ele seja um valor válido de posição
    while (x > 9 || x < 0)
    {
        printf("\nDigite x: ");
        scanf("%d", &x);
    }
    // continua lendo y até que ele seja um valor válido de posição
    while (y > 9 || y < 0)
    {
        printf("\nDigite y: ");
        scanf("%d", &y);
    }
    printf("\nSoma = %d\n", lista[x] + lista[y]);
}