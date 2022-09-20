#include <stdio.h>
#include <math.h>

/* Esse define foi criado para que se definisse um tamanho para o vetor de entrada a ser inserido,
pois em C é necessario definir o tamanho de memória ocupado pelo vetor, tornando a programação mais 
complexa que em caso de C++ ou Python que o vetor ou listas funcionam mais como uma estrutura de dado lista
que permite push, pop e verificação do tamanho*/
#define N 10 // número de posições no vetor da entrada


/**
 * encontra_primo: recebe um ponteiro para a posição inicial de um vetor de inteiros de tamanho N (define)
 * e retorna um vetor de inteiros apenas com os primos do vetor de entrada.
 * @param int *arr
 * @return primos
 */
int *encontra_primo(int *arr)
{
    // Primeiro descobrir quantos primos tem para não criar um array de tamanho desnecessario
    int contador = 0, flag = 1;
    for (int i = 0; i < N; i++)
    {
        flag = 1;
        // para um número não ser primo ele tem que ser divisivel por números entre 2 e metade dele mesmo
        for (int j = 2; j <= arr[i]/2; j++)
        {
            if (arr[i] % j == 0)
            {
                flag = 0; // colocando a flag em 0 pois o numero é divisivel por outro que não 1 e ele mesmo
                arr[i] = 0; // zerando os valores não primos para fazer apenas um for posteriormente
                break;
            }
        }
        if (flag == 1) // flag que indica que o número é primo em 1
            contador++; // incrementa contador de primos
    }
    // Agora vamos criar o vetor do tamanho apenas necessário, para poupar espaço na memória. 
    if (contador != 0)
    {
        int *primos = (int*)malloc(sizeof(int) * (contador));
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            // como zeramos os não primos acima, colocamos em primos os valores diferentes de 0
            if (arr[i] != 0) 
            {
                primos[cnt] = arr[i];
                cnt++;
            }
        }
        for (int i = 0; i < contador; i++)
        {
            printf("%d ", primos[i]);
        }
        return primos;
    }
    else
        return NULL;
}

int main()
{
    int v[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    encontra_primo(v);
    return 0;
}