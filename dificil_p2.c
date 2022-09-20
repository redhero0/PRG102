#include <stdio.h>

/**
 * verificaLinhaOuColuna: percorre as posição a cima, abaixo, esquerda e direita do rei para avaliar
 * se uma rainha ou torre do outro time está colocando ele em cheque.
 * @param char tabuleiro[8][8]
 * @param int i
 * @param int j
 * @param char r
 */
char verificaLinhaOuColuna(char tabuleiro[8][8], int i, int j, char r)
{
    // flags para ja desconsiderar cheques em caso de outra peça no caminho ou só vazio
    // d_char criado para usar a diferença dos caracteres em ascii para avaliar o cheque caso o rei seja preto
    int f_baixo = 1, f_cima = 1, f_esquerda = 1, f_direita = 1, d_char = 'K' - r;
    for (int k = 1; k < 8; k++)
    {
        if ((i + k) < 8)
        {
            // verifica se encontra outra peça que não torre, rainha ou espaço vazio 
            // por primeiro e retira a possibilidade de cheque para aquela direção
            if ((tabuleiro[i + k][j] != ('q' + d_char) && tabuleiro[i + k][j] != ('t' + d_char) &&
                 tabuleiro[i + k][j] != '.')) 
                f_baixo = 0;
            // verifica se caso não tenha outra peça no meio do caminho, se no caso tem bispo ou rainha e retorna cheque
            else if (tabuleiro[i + k][j] != '.' && f_baixo)
                return r;
        }
        if ((i - k) >= 0)
        {
            if ((tabuleiro[i - k][j] != ('q' + d_char) && tabuleiro[i - k][j] != ('t' + d_char) &&
                 tabuleiro[i - k][j] != '.'))
                f_cima = 0;
            else if (tabuleiro[i - k][j] != '.' && f_cima)
                return r;
        }
        if ((j + k) < 8)
        {
            if ((tabuleiro[i][j + k] != ('q' + d_char) && tabuleiro[i][j + k] != ('t' + d_char) &&
                 tabuleiro[i][j + k] != '.'))
                f_direita = 0;
            else if (tabuleiro[i][j + k] != '.' && f_direita)
                return r;
        }
        if ((j - k) >= 0)
        {
            if ((tabuleiro[i][j - k] != ('q' + d_char) && tabuleiro[i][j - k] != ('t' + d_char) &&
                 tabuleiro[i][j - k] != '.'))
                f_esquerda = 0;
            else if (tabuleiro[i][j - k] != '.' && f_esquerda)
                return r;
        }
    }
    return 0;
}

/**
 * verificaDiagonal: percorre todas as posições das diagonais a partir do rei do rei para avaliar
 * se uma rainha ou bispo do outro time está colocando ele em cheque.
 * @param char tabuleiro[8][8]
 * @param int i
 * @param int j
 * @param char r
 */
char verificaDiagonal(char tabuleiro[8][8], int i, int j, char r)
{
    // flags para ja desconsiderar cheques em caso de outra peça no caminho ou só vazio
    // d_char criado para usar a diferença dos caracteres em ascii para avaliar o cheque caso o rei seja preto
    int f_be = 1, f_bd = 1, f_ce = 1, f_cd = 1, d_char = 'K' - r;
    for (int k = 1; k < 8; k++)
    {
        if ((i + k) < 8 && (j - k) >= 0)
        {
            // verifica se encontra outra peça que não bispo, rainha ou espaço vazio 
            // por primeiro e retira a possibilidade de cheque para aquela direção
            if ((tabuleiro[i + k][j - k] != ('q' + d_char) && tabuleiro[i + k][j - k] != ('b' + d_char) &&
                 tabuleiro[i + k][j - k] != '.'))
                f_be = 0;
            // verifica se caso não tenha outra peça no meio do caminho, se no caso tem bispo ou rainha e retorna cheque
            else if (tabuleiro[i + k][j - k] != '.' && f_be)
                return r;
        }
        if ((j + k) < 8 && (i - k) >= 0)
        {
            if ((tabuleiro[i - k][j + k] != ('q' + d_char) && tabuleiro[i - k][j + k] != ('b' + d_char) &&
                 tabuleiro[i - k][j + k] != '.'))
                f_cd = 0;
            else if (tabuleiro[i - k][j + k] != '.' && f_cd)
                return r;
        }
        if ((i + k) < 8 && (j + k) < 8)
        {
            if ((tabuleiro[i + k][j + k] != ('q' + d_char) && tabuleiro[i + k][j + k] != ('b' + d_char) && tabuleiro[i + k][j + k] != '.'))
                f_bd = 0;
            else if (tabuleiro[i + k][j + k] != '.' && f_bd)
                return r;
        }
        if ((j - k) >= 0 && (i - k) >= 0)
        {
            if ((tabuleiro[i - k][j - k] != ('q' + d_char) && tabuleiro[i - k][j - k] != ('b' + d_char) && tabuleiro[i - k][j - k] != '.'))
                f_ce = 0;
            else if (tabuleiro[i - k][j - k] != '.' && f_ce)
                return r;
        }
    }
    return 0;
}

/**
 * verificaPeao: verifica qual o rei para então definir o movimento do peão e então verifica
 * se o peão inimigo está colocando ele em cheque
 * @param char tabuleiro[8][8]
 * @param int i
 * @param int j
 * @param char r
 */
char verificaPeao(char tabuleiro[8][8], int i, int j, char r)
{
    if (r == 'K')
    {
        // caso seja o rei branco, os peões descem a coluna em diagonal
        if ((i - 1) >= 0 && (j + 1) < 8)
        {
            if (tabuleiro[i - 1][j + 1] == 'p')
                return r;
        }
        if ((j - 1) >= 0 && (i - 1) >= 0)
        {
            if (tabuleiro[i - 1][j - 1] != 'p')
                return r;
        }
    }
    if (r == 'k')
    {
        // caso seja o rei preto, os peões sobem a coluna em diagonal
        if ((i + 1) >= 0 && (j + 1) < 8)
        {
            if (tabuleiro[i + 1][j + 1] == 'P')
                return r;
        }
        if ((j - 1) >= 0 && (i + 1) >= 0)
        {
            if (tabuleiro[i + 1][j - 1] != 'P')
                return r;
        }
    }
    return 0;
}

/**
 * verificaCavalo: verifica se tem um cavalo inimigo em alguma posição que coloque o rei em cheque
 * @param char tabuleiro[8][8]
 * @param int i
 * @param int j
 * @param char r
 */
char verificaCavalo(char tabuleiro[8][8], int i, int j, char r)
{
    // d_char criado avaliar cheque para qualquer um dos reis com a diferença de char r na tabela ascii
    int d_char = 'K' - r;
    //verifica todas as oito posições possíveis de um cavalo por um rei em cheque
    if ((i + 1) < 8 && (j + 2) < 8)
    {
        if (tabuleiro[i + 1][j + 2] == ('n' + d_char))
            return r;
    }
    if ((j + 1) < 8 && (i + 2) < 8)
    {
        if (tabuleiro[i + 2][j + 1] == ('n' + d_char))
            return r;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0)
    {
        if (tabuleiro[i - 1][j - 2] != ('n' + d_char))
            return r;
    }
    if ((j - 1) >= 0 && (i - 2) >= 0)
    {
        if (tabuleiro[i - 2][j - 1] != ('n' + d_char))
            return r;
    }
    if ((i + 1) < 8 && (j - 2) >= 0)
    {
        if (tabuleiro[i + 1][j - 2] == ('n' + d_char))
            return r;
    }
    if ((j + 1) < 8 && (i - 2) >= 0)
    {
        if (tabuleiro[i - 2][j + 1] == ('n' + d_char))
            return r;
    }
    if ((i + 2) < 8 && (j - 1) >= 0)
    {
        if (tabuleiro[i + 2][j - 1] == ('n' + d_char))
            return r;
    }
    if ((j + 2) < 8 && (i - 1) >= 0)
    {
        if (tabuleiro[i - 1][j + 2] == ('n' + d_char))
            return r;
    }
    return 0;
}

/**
 * verificaCheque: percorre o tabuleiro até encontrar um rei e chama outras funções
 * para verificar todas as possibilidades que colocam o rei em cheque
 * retornando qual rei está em cheque ou nenum
 * @param char tabuleiro[8][8]
 */
char verificaCheque(char tabuleiro[8][8])
{
    char rei_cheque = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tabuleiro[i][j] == 'K' || tabuleiro[i][j] == 'k')
            {
                // verifica todas as possibilidades de cheques para cada rei e retorna se está 
                // em cheque ou não
                if ((verificaLinhaOuColuna(tabuleiro, i, j, tabuleiro[i][j]) != 0) || (verificaDiagonal(tabuleiro, i, j, tabuleiro[i][j]) != 0) || (verificaPeao(tabuleiro, i, j, tabuleiro[i][j]) != 0) || (verificaCavalo(tabuleiro, i, j, tabuleiro[i][j]) != 0))
                {
                    rei_cheque = tabuleiro[i][j];
                }
            }
        }
    }
    return rei_cheque;
}

int main()
{
    int conta_ponto = 0, jogo = 0;
    char rei_cheque = 0;
    do
    {
        conta_ponto = 0;
        char tabuleiro[8][8], c;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                scanf("%c", &tabuleiro[i][j]);
                if (tabuleiro[i][j] == '.')
                {
                    conta_ponto++;
                }
                // Para evitar problemas de leitura da matriz/tabuleiro
                if (tabuleiro[i][j] == '\n')
                {
                    j--;
                    if (j == 0 && i > 0)
                    {
                        i--;
                        j = 7;
                    }
                }
            }
        }
        if (conta_ponto != 64)
        {
            jogo++;
            rei_cheque = verificaCheque(tabuleiro);
            if (rei_cheque != 0)
            {
                if (rei_cheque == 'K')
                {
                    printf("Jogo #%d: rei branco esta em cheque.\n", jogo);
                }
                if (rei_cheque == 'k')
                {
                    printf("Jogo #%d: rei preto esta em cheque.\n", jogo);
                }
            }
            else
            {
                printf("Jogo #%d: nenhum rei esta em cheque.\n", jogo);
            }
        }

    } while (conta_ponto != 64);
    return 0;
}