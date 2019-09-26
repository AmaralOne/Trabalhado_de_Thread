# Trabalhado_de_Thread

TANENBAUM_BOOK 
SISTEMAS OPERACIONAIS MODERNOS

63-(Número Primo) Um processo pode ser colocado em uma fila circular
mais de uma vez para dar a ele uma prioridade mais alta.
Executar instâncias múltiplas de um programa, cada uma
trabalhando em uma parte diferente de um pool de dados
pode ter o mesmo efeito. Primeiro escreva um programa
que teste uma lista de números para primalidade. Então
crie um método para permitir que múltiplas instâncias
do programa executem ao mesmo tempo de tal maneira
que duas instâncias do programa não trabalharão sobre
o mesmo número. Você consegue de fato repassar mais
rápido a lista executando múltiplas cópias do programa?
Observe que seus resultados dependerão do que mais seu
computador estiver fazendo; em um computador pessoal
executando apenas instâncias desse programa você não
esperaria uma melhora, mas em um sistema com outros
processos, deve conseguir ficar com uma porção maior
da CPU dessa maneira.


64-(NúmeroPerfeito) O objetivo desse exercício é implementar uma solução
com múltiplos threads para descobrir se um determinado
número é um número perfeito. N é um número perfeito
se a soma de todos os seus fatores, excluindo ele mes-
mo, for N; exemplos são 6 e 28. A entrada é um intei-
ro, N. A saída é verdadeira se o número for um número
perfeito e falsa de outra maneira. O programa principal
lerá os números N e P da linha de comando. O processo
principal gerará um conjunto de threads P. Os números
de 1 a N serão divididos entre esses threads de maneira
que dois threads não trabalhem sobre o mesmo número.
Para cada número nesse conjunto, o thread determinará
se o número é um fator de N; se for, ele acrescenta o
número a um buffer compartilhado que armazena fato-
res de N. O processo pai espera até que todos os threads
terminem. Use a primitiva de sincronização apropriada
aqui. O pai determinará então se o número de entrada é
perfeito, isto é, se N é uma soma de todos os seus fato-
res, então reportará em conformidade. (Nota: você pode
fazer a computação mais rápido restringindo os números
buscados de 1 até a raiz quadrada de N).

65- Implemente um programa para contar a frequência de
palavras em um arquivo de texto. O arquivo de texto é
dividido em N segmentos. Cada segmento é processado
por um thread em separado que produz a contagem de
frequência intermediária para esse segmento. O proces-
so principal espera até que todos os threads terminem;
então ele calcula os dados de frequência de palavras con-
solidados baseados na produção dos threads individuais.
