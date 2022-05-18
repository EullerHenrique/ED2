#include <stdio.h>

int buscaBinaria(int* v, int in, int fim, int x){
    int meio;

   if(in <= fim){ 
        meio = (in + fim) / 2;

        if((meio - 1) < in || (meio + 1) > fim){
            return -2;// O elemento não está no vetor
        }else if(x < v[meio]){
            return buscaBinaria(v, in, (meio - 1), x);
        }
        else if(x > v[meio]){
            return buscaBinaria(v, (meio + 1), fim, x);
        }
        else if(v[meio] == x){
            return meio;
        }   
    }else{
        return -1;// O indice inicial não é menor do que o indice final 
    }
}// buscaBinaria

//**********************************************************************
//                          ANALISE DE COMPLEXIDADE
//                              BUSCA BINÁRIA
//**********************************************************************

//Melhor caso: O elemento foi encontrado no meio
//F(n) = 1 + 1 + 1 + 1
//F(n) = 4
//Ordem de complexidade: O(n)

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
//F(2^k) = F(2^(k-k) + 4k

//Sabendo que n = 2k, temos:
//log2 n = log2 2^k
//log2 n = k

//logo, temos:
//F(2^k) = F(2^(k-k)) + 4k
//F(2^k) = F(2^0) + 4log2 n
//F(2^k) = F(1) + 4log2 n
//F(2^k) = O(1) + 4log2 n

//Portanto, temos O(log2 n)



int main(void){
    int vetor[10] = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0}, n;
    int bin;

    printf("Qual elemento buscar: ");
    scanf("%d", &n);

    bin = buscaBinaria(vetor, 0, 10, n);
    printf("Busca Binária. ");

    if(bin == - 2){
        printf("O elemento %d não está no vetor \n", n);
    }
    else if(bin == -1){
        printf("O indice inicial não é menor do que o indice final \n");
    }
    else{
        printf(" O elemento %d está no indice (1ª vez apenas): %d \n", n, bin);
    }


}