#include <stdio.h>
#include <math.h>

/* Esse define foi criado para que se definisse um tamanho para o vetor de entrada a ser inserido,
pois em C é necessario definir o tamanho de memória ocupado pelo vetor, tornando a programação mais 
complexa que em caso de C++ ou Python que o vetor ou listas funcionam mais como uma estrutura de dado lista
que permite push, pop e verificação do tamanho*/
#define N 10 // número de posições no vetor da entrada


/**
 * tira_repetido: percorre um vetor, avaliando se a valores repetidos em cada posição e caso tenha, 
 * desloca o vetor de modo a retirar números repetidos, mas ao fim, aloca memória para retornar um 
 * vetor apenas com os números sem repetir
 * @param int *arr
 * @return ret
 */
int *tira_repetido(int *arr)
{
    int cnt = 0;
    // for para percorrer o vetor que ainda sobra
    for (int i = 0; i < N - cnt ; i++)
    {
        // verifica todas as posições do vetor a frente da atual
        for (int j = i + 1; j < N - cnt; j++)
        {
            // verifica a igualdade
            if (arr[i] == arr[j])
            {
                // move todo o vetor para uma posição a menos
                for (int k = j; k < (N - cnt - 1); k++)
                {
                    arr[k] = arr[k+1];
                }
                cnt++; // conta que um número estava repetido
                j--; // volta uma posição para avaliar a posição seguinte que ainda não foi considerada
            }
        }
    }
    // Aloca memória para retornar um vetor sem numeros repetidos, ou seja, do tamalho 
    // apenas necessário para incluir apenas vetor de números não repetidos
    int *ret = (int*)malloc(sizeof(int) * (N-cnt));
    // Coloca apenas os valores não repetidos do vetor original
    for (int l = 0; l < (N-cnt); l++)
    {
        ret[l] = arr[l];
        printf("%d ", ret[l]);
    }
    return ret;
}

int main()
{
    int v[N] = {2, 2, 2, 4, 5, 5, 7, 9, 9, 2};
    tira_repetido(v);
    return 0;
}