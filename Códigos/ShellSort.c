/*
Shell sort 
-Faz trocas a uma certa distância(que diminui a cada iteração)
-Primeiro compara elementos separados por "h" posições e ordena.
-Depois, diminui progressivamnte a distância de comparação ate h ser igual a 1.

-Complexidade: ?????


*/

#include <stdio.h>

void shellSort(int *v, int n) {
    int i , j , aux, h;
    h = n/2;

    while(h > 0) {
        i = h;
        while (i < n) {
            aux = v[i];
            j = i;
                //Testa se aux < v[j-h]
                while(j >= h && aux < v[j-h]){
                    //V[j-h] se torna o v[j] 
                    v[j] = v[j-h];
                    j = j - h;
                }
            // O aux se torna o v[j]    
            v[j] = aux;
            i++;
        }
        h = h/2;
    }
}

int main(void){
    int v[7] = {5, 6, 2, 1, 3, 1, 7};
    shellSort(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

