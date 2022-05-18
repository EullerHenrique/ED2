#include <stdio.h>
#include <stdlib.h>

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

void stoneSort(int *V, int N){
    int i,aux, in, troca;
    in = 0;
    do{
        troca = -1;
        for(i = N-1; i > in; i--){
            if(V[i] < V[i-1]){
                aux = V[i];
                V[i] = V[i-1];
                V[i-1] = aux;
                troca = i;
            }
        } 
        in++;
    }while(troca != -1);
}

void selectionSort(int *V, int N){
    int i, j, menor, aux;
    for(i = 0; i < N - 1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(V[j] < V[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = V[menor];
            V[menor] = V[i];
            V[i] = aux;
        }
    }
}

void insertionSort(int *V, int N){
    int i, j, aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        j = i;
        while(j > 0 && aux < V[j-1]){
            V[j] = V[j-1];
            j--;
        }
        V[j] = aux; 
    }
}

int main(void){
    int vet1[10] = {100,99,123,70,330,50,40,30,20,10};
    int vet2[10] = {10,2,3,4,1,3,333,44,12,44};
    int vet3[5] = {50,40,30,20,10};
    

    printf("Vetor 1 : \n");
    for(int i = 0; i < 10; i++){
        printf("%d ",vet1[i]);
    }
    printf("\n\n");

    printf("StoneSort do vetor 1: \n");
    stoneSort(vet1, 10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vet1[i]);
    }
    printf("\n\n");

    printf("Vetor 2: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ",vet2[i]);
    }
    printf("\n\n");

    printf("SelectionSort do vetor 2: \n");
    selectionSort(vet2,10);
    for(int i = 0; i < 10; i++){
        printf("%d ",vet2[i]);
    }
    printf("\n\n");

    
    printf("Vetor 3: \n");
    for(int i = 0; i < 5; i++){
        printf("%d ",vet3[i]);
    }
    printf("\n\n");

    printf("InsertionSort do vetor 3: \n");
    insertionSort(vet3,5);
    for(int i = 0; i < 5; i++){
        printf("%d ", vet3[i]);
    }
    printf("\n\n");



}