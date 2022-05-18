#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int*v, int n, int x){
    int in, fim, meio;
    in = 0;
    fim = n -1;

    while(in <= fim){
        meio = (in + fim)/2;
        if(x <  v[meio]){
            fim = meio -1;
        }
        else if( x > v[meio]){
            fim = meio + 1;
        }
        else if(x == v[in]){
            return meio;
        }
    }
    return -1;
}

int buscaLinear(int *v, int n, int x){
    for(int i = 0; i < n; i++){
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


int buscaBinariaV2(int *v, int in, int fim, int x){
    int meio;
    
    if(in <= fim){
        meio = (in + fim)/2;

        if(x < v[in]){
            return buscaBinariaV2(v,in, (meio -1), x);
        }
        else if(x > v[in]){
            return buscaBinariaV2(v, (meio + 1), fim, x);
        }else if(x == v[in]){
            return meio;
        }
    }
    else{
        return  -1;
    }
}

int *buscaLinearV2(int*v, int n, int x){
    int *vet = malloc(sizeof(int));
    if(vet == NULL){
        return NULL;
    }

    vet[0] = -1;
    for(int i = 0, j = 1; i < n; i++){
        if(x == v[i]){
         //   vet = realloc(sizeof(int) * (j+1));
            vet[j++] = i; // indice
            vet[0] = j;// tamanho
        }
    }

    if(vet[0] < 0){
        free(vet);
        return NULL;
    }else{
        return vet;
    }
}


int *buscaOrdenadaV2(int *v, int n, int x){
    int *vet = malloc(sizeof(int));
    if(vet == NULL){
        return NULL;
    }

    vet[0] = -1;

    for(int i = 0, j = 1; i < n && v[i] <= x; i++){
        if(v[i] == x){
            vet = realloc(vet, sizeof(int) * (j+1));
            vet[j++] = i;
            vet[0] = j;    
        }
    }
    
    if(vet[0] < 0){
        free(vet);
        return NULL;
    }else{
        return vet;
    }
}

int BublleSort(int *v, int n){
    int aux, troca;

    do{
      troca = -1;
     
      for(int i = 0; i < n - 1; i++){
           if(v[i] > v[i+1]){
              aux = v[i]; 
              v[i] = v[i+1];
              v[i+1] = aux;
              troca = i;
           }
      }
      n--;
    }while(troca!=-1);
}

int SelectionSort(int *v, int n){
    int i, j,menor, aux;
    
    for(i = 0; i < n-1; i++){
        menor= i;
        for(j = j + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        
        if(i != menor){
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;
        }
    }
}

int insertionSort(int *v, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        j = i;
        while(j > 0 && aux < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
}
