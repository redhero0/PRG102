# PRG102

Repositório criado para os códigos do Processo Seletivo da Crossbots 2022 para a área de programação. 

## Implementação

Todos os códigos foram implementados em linguagem C. 

## Exercícios Muito Simples

1 - Consiste em uma função para o cálculo da distância entre dois pontos (x, y) recebidos por meio de dois vetores de duas posições, utiliza a biblioteca math.h para utilizar as funções sqrt() e pow() aplicando a fórmula 
```
sqrt(pow((v1[0]-v2[0]),2) + pow((v1[1]-v2[1]),2));
```

2 - Consiste na função converte_temperatura que converte uma temperatura de Fahrenheit para Celsius como abaixo
```
((temp_f-32)*5)/9;
```

### Exercícios Simples

1 - Faz a leitura de um vetor de 10 posições e de um inteiro x e um inteiro y, retornando a soma dos valores nas posições x e y do vetor.

2 - Consiste da função perfeito que verifica se um número inteiro é perfeito, verificando se ele é a soma de todos os seus divisores utilizando um loop.

3 - Consiste na função encontra_primos que recebe um vetor de inteiros e retorna um vetor somente com os primos, para isso, descobre quantos primos há no vetor e o modifica para o deixar somente com seus primos, então aloca um vetor somente com a memória necessária para um vetor que possua somente os primos, colocando os primos do vetor de entrada nesse vetor de retorno.

4 - Consiste da função encontra_letra que recebe um carácter e uma string e verifica quantas vezes aquele carácter se repete na string.

### Exercícios Intermediários

1 - Consiste na função encontra_angulo que recebe três pontos (x,y), três vetores de 2 posições, calculando o ângulo entre eles. Utiliza a biblioteca math.h para descobrir o ângulo por meio da aplicação da lei dos cossenos após descobrir as três retas formadas pelos três pontos.

2 - Consiste na função tira_repetido que recebe um vetor de números e retorna um vetor apenas com os números sem repetições.

## Exercícios Difíceis

1 - Consiste da função encontraDiamante que recebe uma string com carácteres do tipo >, <, . e conta quantos "diamantes" é possível formar a partir daquela string. Os diamantes são formados pela junção de <> e . são grãos de areia que podem ser retirados. 

2 - O programa é formado por diversas funções que percorrem um tabuleiro de xadrez e avaliam se algum dos reis está em cheque, retornando se algum está e qual deles está.
