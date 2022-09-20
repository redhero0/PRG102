#include <stdio.h>

/**
 * encontra_letra: recebe um caracter e uma string e retorna quantas vezes aquele 
 * caracter aparece na string
 * @param char c
 * @param char *s
 * @return cnt
 */
int encontra_letra(char c, char *s)
{
    int cnt = 0, i = 0;
    while (s[i] != '\0') // percorre a string até o seu fim
    {
        if (s[i] == c)
            cnt++; // incrementa contador quando posicao da string é igual ao caracter
        i++; // vai para a proxima posição da string
    }
    return cnt;
}
int main()
{
    char c, s[100];
    scanf("%c", &c); // le o caracter que se deseja contar na string
    getchar(); // limpar buffer
    scanf("%[^\n]s", s); //le string até o barra n
    printf("\n%d\n", encontra_letra(c, s)); // imprime o retorno da funcao encontra letra
}