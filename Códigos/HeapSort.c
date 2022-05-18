/*
HeapSOrt ou "Ordenação usando heap"
- Heap: vetor que simula uma arvore binária completa(exceção do último nivel)
- Todo elemento "pai" do vetor possui dois elementos "filhos"
- FilhoESq(Pai) = 2 * Pai + 1
- FilhoDIr(Pai) = 2 * Pai + 2

*/
#include <stdio.h>

void criarHeap(int *v, int in, int fim){
    //v[in] = pai original
    //in = indice do pai original

    //Aux = pai original
    int aux = v[in];
    //j = indice do primeiro filho do pai
    int j = 2* in + 1;
    //Se o indice do filho for menor ou igual ao fim, o vetor ainda existe
    while(j <= fim){
        //Se o indice do filho for menor que o fim...
        if(j < fim){
            //Se v[j] < v[j+1], então o segundo filho pode ser maior que o pai
            if(v[j] <  v[j+1]){
                //j  = indice do segundo filho do pai
                j = j + 1;
            }
        }
        //Se o filho for maior que o pai, então o filho se torna o pai
        if(aux < v[j]){
            //O filho se torna o pai
            v[in] = v[j];
            //O indice do filho se torna o indice do pai
            in = j;
            //O indice do novo primeiro filho é calculado
            j = 2*in+1;
        }
        else{
            //Se o pai for maior que o(s) filho, então o while se encerra
            j = fim + 1;
        }
    }
    //O antigo pai se torna o filho
    v[in] = aux;
}

void heapSort(int *v, int n){
    int i, aux;
    
    //Criar heap a partir dos dados
    //i = divisao do vetor 
    //Percorre o vetor do meio para o inicio
    for(i = (n-1)/2; i >= 0; i--){
        criarHeap(v,i,n-1);
    }

    //i = final do vetor
    //Percorre o vetor do fim para o segundo elemento
    for(i = n-1; i >= 1; i--){
        //Pegar o maior elemento(maior = pai) da heap e colocar na sua
        //no final do array
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        //Reconstruir heap
        criarHeap(v, 0, i-1);
    }
}

int main(void){
    int v[7] = {5, 600, 2, 1, 3, 1, 7};
    heapSort(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
