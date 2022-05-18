/*
CountingSort ou "Ordenação por contagem"
- Usa um array auxiliar de tamanho igual ao maior valor a ser ordenado, "K"
- Valor a ser ordenado é tratado como índice 
- O array auxiliar é usado para contar quantas vezes cada valor ocorre
- Percorre o array auxiliar verificando quais valores existem e os coloca no array ordenado

"Performance"
- Complexidade é O(N+K), onde K é o tamanho do array auxiliar
- Não recomendado para grandes conjuntos de dados(K muito grande)
- Ordena valores inteiros positivos
- Estável: não altera a ordem de dados iguais

*/
#include <stdio.h>

void countingSort(int *v, int n){
    int i, j, k, maior, menor,max;
    
    //Acha o maior valor para o max ser determinado
    maior = v[0];

    for(i = 1; i < n;i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    max = maior + 1;

    int baldes[max];

    //Zera o vetor baldes
    for(i = 0; i < max; i++){
        baldes[i] = 0;
    }

    //Valor a ser ordenado é tratado como índice do balde
    //O array auxiliar é usado para contar quantas vezes cada valor ocorre
    for(i = 0; i < n; i++){
         baldes[v[i]]++;
    }

    //Percorre o array auxiliar verificando quais valores existem e os coloca no array ordenado
    for(i = 0, j = 0; j < max; j++){
        for(k = baldes[j]; k > 0; k--){
            v[i] = j;
            i++;
        }
    }
 
}


int main(void){
    int v[7] = {5, 6, 100, 1, 3, 1, 7};
    countingSort(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}