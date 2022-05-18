int bubbleSort(int*v, int n){
    int troca, aux;
    
    do{
        troca = -1;
        for(int i = 0; i < n-1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = i;
            }
            n--;
        }
    }while(troca!=-1);
}

int selectionSort(int *v, int n){
    int i, j, meio, menor, aux;

    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = j + 1; j < n; j++){
          if(v[j] < menor){
              menor = j;
          }
        }

        if( i!= menor){
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;
        }
    }
}


int insertionSort(int *v, int n){
    int i, j, aux; 

    for(i = 1; i < n ; i++){
        aux = v[i];
        i = j;

        while(j>0 && aux < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
}



























