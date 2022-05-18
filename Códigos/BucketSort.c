/*
BucketSort ou "Ordenação usando Baldes"
-Distribui os valores a serem ordenados em um conjunto de baldes.
 Cada balde guarda uma faixa de valores.
-Ordena os valores de cada balde. Isso é feito usando outro algoritmo de ordenação ou ele mesmo.
-Percorre os baldes e coloca os valores de cada balde de volta no array ordenado.

-"Performance"
- Melhor caso: O(n+k), onde k é o número de baldes
- Pior caso: O(n^2), todos são colocados no mesmo balde

- Ordena valores inteiros positivos
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5
typedef struct{
    int qtd;
    int valores[TAM];
}balde;


void bubbleSort(int *V, int N){
    int i, aux, troca;
    do{
        troca = -1;
        for(i = 0; i < N - 1; i++){
            if(V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                troca = i;
            }
        }
        N--;
    }while (troca != -1);
}

void bucketSort(int *v, int n){
    int i, j, maior, menor, nrobaldes, pos;
    balde *bd;
    //Acha maior e menor valor
    maior = v[0];
    menor = v[0];

    for(i = 1; i < n;i++){
        if(v[i] > maior){
            maior = v[i];
        }
        if(v[i]< menor){
            menor= v[i];
        }
    }
    
    //Inicializa baldes
    nrobaldes = (maior - menor) / TAM + 1;
    printf("Maior = %d\n",maior);
    printf("Menor = %d\n",menor);

    printf("Num baldes= %d\n", nrobaldes);
    bd = malloc(nrobaldes*sizeof(balde));
    for(i = 0; i < nrobaldes;i++){
        bd[i].qtd = 0;
    }

    //Distriubui os valores nos baldes
    for(i = 0; i < n; i++){
        pos = (v[i]-menor)/TAM;
        printf("bd[%d] = v[%d] = %d\n",pos,bd[pos].qtd, v[i]);
        bd[pos].valores[bd[pos].qtd] = v[i];
        bd[pos].qtd++;
    }

    //Ordena baldes e coloca no array
    pos = 0;
    for(i = 0; i < nrobaldes;i++){
        bubbleSort(bd[i].valores, bd[i].qtd);
        for(j = 0; j < bd[i].qtd; j++){
            v[pos] = bd[i].valores[j];
            pos++;
        }         
    }
    free(bd);
}

int main(void){
    int v[6] = {18,5,30,13,22,4};
    bucketSort(v,6);
    for(int i=0; i < 6; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}