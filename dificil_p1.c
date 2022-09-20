#include <stdio.h>

/**
 * encontraDiamante: percorre uma string e avalia quantos "diamantes" tem, nesse caso, ao 
 * encontrar a parte debaixo do diamante e ao encontrar, volta as posições da string e procura 
 * uma parte de cima, quando encontrar, substitui ambas as partes do diamante por "_" para elas não 
 * serem consideradas e conta os diamantes.
 * @param char *s
 * @return cnt_diamante
 */
int encontraDiamante (char *s)
{
    int i = 0, cnt_diamante = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '>')
        {
            for (int j = (i - 1); j >= 0; j--)
            {
                if (s[j] == '<')
                {
                    cnt_diamante++;
                    s[i] = '_'; // espaço vazio
                    s[j] = '_'; // espaço vazio
                    break;
                }
            }
        }
        i++;
    }
    return cnt_diamante;
}
/**
 * encontraDiamante: percorre a string e conta quantas partes de cima de diamanete tem, então ao encontrar
 * partes de baixo, diminui da quantidade das partes de cima e conta diamante
 * @param char *s
 * @return cnt_diamante
 */
int encontraDiamante2 (char *s)
{
    int i = 0, cnt_diamante = 0, cnt_cima = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '<')
        {
            cnt_cima++;
        }
        else if(s[i] == '>' && cnt_cima>0)
        {
            cnt_diamante++;
            cnt_cima--;
        }
        i++;
    }
    return cnt_diamante;
}

int main()
{
    int N;
    char s[1001];
    scanf ("%d", &N); // lê a quantidade de testes que deseja que sejam feitas
    for (int i = 0; i < N; i++) // chama ambas as funções criadas pelo número de testes que tem
    {
        scanf("%s", s);
        printf("%d\n", encontraDiamante2 (s)); // chama a primeira funcao antes pois esta não modifica o vetor
        printf("%d\n", encontraDiamante (s));
    }
    return 0;
}