#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int* v, int in, int fim, int x){
    int meio;

    if(in <= fim){
        meio = (in + fim) / 2;

        if(x < v[meio]){
            return buscaBinaria(v, in, (meio - 1), x);
        }
        else if(x > v[meio]){
            return buscaBinaria(v, (meio + 1), fim, x);
        }
        else if(v[meio] == x){
            return meio;
        }
        
    }else{
        return -1;// // O indice inicial não é menor do que o indice final 
    }
}// buscaBinaria

//**********************************************************************
//                          ANALISE DE COMPLEXIDADE
//                              BUSCA BINÁRIA
//**********************************************************************

//Melhor caso: O elemento foi encontrado no meio
//F(n) = 6
//Ordem de complexidade: O(1)

//Pior caso: O elemento não existe ou foi encontrado na última posição
//F(n) = F(n/2) + 4

//n pertence ao conjunto dos números pares
//Logo, podemos escrever, deste modo, considerando n = 2^k

//F(2^k) = F(2^k/2) + 4
//F(2^k) = F(2^(k-1)) + 4

//Expansão

// F(2^k) = (F(2^(k-2) + 4 ) + 4)
// F(2^k) = (F(2^(k-3) + 4) + 4) + 4)

//Podemos resumir para:
//F(2^k) = F(2^(k-k) + 5k

//Sabendo que n = 2k, temos:
//log2 n = log2 2^k
//log2 n = k

//logo, temos:
//F(2^k) = F(2^(k-k)) + 4k
//F(2^k) = F(2^0) + 4log2 n
//F(2^k) = F(1) + 4log2 n
//F(2^k) = O(1) + 4log2 n

//Portanto, temos O(log2 n)

// Vetor precisa ser destruido fora da função
int* buscaLinear(int* v, int n, int x){
    int i, j;
    int* inds = malloc(sizeof(int));

    if(inds == NULL){
        return NULL;
    }

    inds[0] = -1;
    for(i = 0, j = 1; i < n; i++){
        if(v[i] == x){
            inds = realloc(inds, sizeof(int) * (j + 1));
            inds[j++] = i;
            inds[0] = j;
        }// if
    }// for

    if(inds[0] < 0){
        free(inds);
        return NULL;
    }else{
        return inds;
    }
}// buscaLinear

//                             ANÁLISE DE COMPLEXIDADE
//******************************************************************************************************
//                                 BUSCA LINEAR
//******************************************************************************************************

//Caso geral: É um caso geral porque mesmo se tiver somente um elemento o algorimtmo continuará procurando
// F(n) =  1 + 1 + 1 + 1 + 1 + 1 + n + n + n + n + n + n + 1 + 1 
// F(n) = 6n + 8 
//Ordem de complexidade: O(n)


int* buscaOrdenada(int* v, int n, int x){
    int* inds = malloc(sizeof(int));
    int i, j;

    if(inds == NULL){
        return NULL;
    }
    
    inds[0] = -1;    
    for(i = 0, j = 1; i < n && v[i] <= x; i++){
        if(v[i] == x){
            inds = realloc(inds, sizeof(int) * (j + 1));
            inds[j++] = i;
            inds[0] = j; //Armazena o tamanho do vetor
        }
    }// for

    if(inds[0] < 0){ //Se nenhum elemento tiver sido encontrado
        free(inds);
        return NULL;
    }else{
        return inds;
    }
}// buscaOrdenada
//*******************************************************************************
//                             ANÁLISE DE COMPLEXIDADE
//                                 BUSCA LINEAR
//*******************************************************************************

//Melhor caso: O elemento foi encontrado na primeira posição
//F(n) = 6n + 8
//Como o elemento foi encontrado na primeira posiçao, i = 1, então n = 1;
//F(1) = 6(1) + 8
//F(1) = 15
//Ordem de complexidade: O(1)

//Pior caso: O elemento foi encontrado na última posição ou não foi encontrado
// F(n) =  1 + 1 + 1 + 1 + 1 + 1 + n + n + n + n + n + n + n + 1 + 1 
// F(n) = 6n + 8 
//Ordem de complexidade: O(n)


int main(void){
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n;
    int bin;
    int*lin;
    int*ord;
    int i;
    


    printf("Qual elemento buscar: ");
    scanf("%d", &n);

    
    bin = buscaBinaria(vetor, 0, 9, n);
    printf("Busca Binária. \n");

    if(bin == - 1){
        printf("O elemento %d não está no vetor!! \n", n);
    }
    else{
        printf(" O elemento %d está no indice (1ª vez apenas): %d \n", n, bin);
    }


    lin = buscaLinear(vetor, 10, n);
    ord = buscaOrdenada(vetor, 10, n);

    printf("Busca Linear. \n");
    if(lin == NULL){
        printf("O elemento %d não está no vetor!! \n",n);
    }
    else{
        printf(" %d está nas seguintes posições: ",n);
        for(i = 1; i < lin[0]; i++){
             printf("%d ", lin[i]);
        }
        printf("\n");
    }

    printf("Busca Ordenada. \n");
    if(ord == NULL){
        printf("O elemento %d não está no vetor!! \n",n);
    }
    else{
        printf(" %d está nas seguintes posições: ",n);
        for(i = 1; i < ord[0]; i++){
             printf("%d ", ord[i]);
        }
        printf("\n");
    }

    free(lin);
    return 0;
}// main