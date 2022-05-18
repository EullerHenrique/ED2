/*2)Faça uma comparação da análise de complexidade entre a busca sequencial ordenada
e a busca binária para o pior caso (sem considerar chaves repetidas).

A ordem de complexidade da busca sequencial no pior caso é O(n),
pois no pior caso o elemento será encontrado na ultima posição ou nem será encontrado.

A ordem de complexidade da busca binária no pior caso é O(log2 N),
pois no pior caso o elemento será encontrado na última posição ou nem será encontrado

COMPARAÇÃO????

3) Faça uma comparação entre todos os métodos de ordenação estudados em aula com
relação à estabilidade.

Não tenho a mínima ideia ??
*/

// 8) Dada a função ordena( ) descrita a seguir:
#include <stdio.h>
#define MAX 40
    struct individuo {
        char nome[30];
        int idade; 
    };
    typedef struct individuo Ind;
   
   Ind cadastro[MAX];
    int n_cad;

void ordena (Ind* cadastro, int n_cad){
    int i, j;
    Ind x;
    for(i = 1; i <= n_cad-1; i++){
        x = cadastro[i];
        j = i-1;
        while ((strcmp(x.nome,cadastro[j].nome) < 0) && j >= 0){ 
            cadastro[j+1] = cadastro[j];
            j--;;
        }
        cadastro[j+1]=x;
    }
}

/*Diga qual é o método de ordenação implementado neste algoritmo, descreva o seu funcionamento e narre sua complexidade.

R: O método de oredenação implementado neste algoritmo é o insertionSort
O metódo neste algoritmo funciona da seguinte forma:
1)

Daniel Claudio Bruna Ana
x = Daniel

Daniel Daniel Bruna Ana
Claudio Daniel Bruna Ana

2)
Claudio Daniel Bruna Ana
x = Bruna
Claudio Daniel Daniel Ana
Claudio Cladui Daniel Ana
Bruna Claudio Daniel Ana

3)

Bruna Claudio Daniel Ana
x = Ana
Bruna Claudio Daniel Daniel
Bruna Claudio Claudio Daniel
Bruna Bruna Claudio Daniel
Ana Bruna Claudio Daniel


Complexidade: 
O(n), melhor caso, o vetor já está ordenado.
O(n^2), pior caso, o maior elemento está no inicio do vetor

//Tá certo??


10)Qual método roda mais rápido em um vetor com chaves idênticas:
seleção ou inserção? Justifique sua resposta.

{1,1,1,1}

SelectionSort

1) 

*1 1* 1 1
1 *1 1* 1
1  1 *1  1*
menor = 0
    
{ 3 comparações

2) 
1 *1 1* 1
1 1 *1 1*
menor = 0

{ 2 comparações

3) 
1 1 *1 1*
menor = 0

{1 comparação

Total = 5 comparações

InsertionSort
1)
1 *1* 1 1

{ 1 comparação

2) 
1 1 *1* 1 

{ 1 comparação

3) 
1 1 1 *1*

{ 1 comparação

Total = 3 comparações

Logo, concluimos que quando todos os elementos do vetor são iguais, o melhor insertionSort é mais rápido.

//Tá certo??
*/


        

