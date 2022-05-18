#include <stdio.h>

int buscaBinaria(int *v, int n, int x){
    int in, fim, meio;
    in = 0;
    fim = n - 1;
    
    
    while(in <= fim){
        meio = (in + fim)/2;
        if(x < v[meio]){
            fim = meio - 1;
        }
        else if(x > v[meio]){
            in = meio + 1;
        }else if(x == v[meio]){
            return meio;
        }
    }
    return -1;
}

int buscaLinear(int *v, int n, int x){
    int i;
    for(i = 0; i < n; i++){
        if(x == v[i]){
            return i;
        }
    }
    return -1;
}
 
int buscaOrdenada(int *v, int n, int x){
    int i = 0;
    while(i < n && v[i] < x){
        i++;
    }

    if(x == v[i]){
        return i;
    }
    else{
        return -1;
    }
}


int main(void){
    int vetor[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, n;
    
    int bin;
    int linear;
    int ordenada;
    int x;

    printf("Qual elemento buscar: ");
    scanf("%d", &x);

    bin = buscaBinaria(vetor, 10, x);
    printf("Busca Binária. \n");
    if(bin == -1){
        printf("O elemento %d não está no vetor\n",x);
    }
    else{
          printf("O elemento %d está no indice: %d \n", x, bin);
    }

    linear = buscaLinear(vetor, 10, x);
    printf("Busca Binária. \n");
    if(linear == -1){
        printf("O elemento %d não está no vetor\n", x);
    }
    else{
          printf("O elemento %d está no indice: %d \n", x, linear);
    }
 
    ordenada = buscaOrdenada(vetor,10,x);
    printf("Busca Ordenada Normal.\n ");

    if(ordenada == - 1){
        printf("O elemento %d não está no vetor \n", x);
    }
    else{
        printf("O elemento %d está no indice: %d \n", x, ordenada);
    }


}