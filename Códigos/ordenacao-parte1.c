/*****************************************************************
IMPLEMENTAÇÃO DOS MÉTODOS BÁSICOS DE ORDENAÇÃO - GSI011(S)
Profa. Christiane R S Brasil
AULA DO DIA 17/09/2019
*****************************************************************/

void bubbleSort(int* v, int n)
{
    int i,fim,aux,troca;

    fim=n;

    do{
        troca = -1;
        for(i=0;i<fim-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = i;
            }
        }
        fim--;
    }while(troca!=-1);
}

void selectionSort(int* v, int n)
{
    int i,j,menor, aux;

    for(i=0;i<n-1;i++)
    {
        menor = i;
        for(j=i+1;j<n;j++)
        {
            if(v[j]<v[menor])
            {
                menor = j;
            }
        }
        if(i!=menor)
        {
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;
        }
    }
}

void insertionSort(int* v, int n)
{
    int i,j,aux;

    for(i=1;i<n;i++)
    {
        aux = v[i];
        j = i;
        while(j>0 && aux <v[j-1])
        {
            v[j] = v[j-1]; j--;
        }
        v[j] = aux;
    }
}
