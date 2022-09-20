#include <stdio.h>

/**
 * perfeito: recebe um inteiro e retorna se ele é perfeito
 * @param int x
 */
int perfeito(int x)
{
    int soma = 0;
    for (int i=1; i<x; i++) 
    {
        if(x%i == 0) // verifica se é divisivel por i
            soma +=i; // incrementa em soma os divisores
    }
    if(soma == x) // se soma é igual a x, ele é perfeito
        return 1;
    else    
        return 0;
}

int main()
{
   printf("%d\n", perfeito(28));
   return 0;
}