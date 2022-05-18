#include "ArvBinaria.h";

struct No{
    int info;
    struct No*esq;
    struct No*dir;
}

ArvBin *criaArvBin(){
    ArvBin *raiz = malloc(sizeof(ArvBin));
    if(raiz!= NULL){
        *raiz = NULL;
    }
    return raiz;
}

void preOrdem(ArvBin*raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem(&(*raiz)->esq);
        preOrdem(&(*raiz)->dir);
    }
}

int main(void){
    preOrdem(criaArvBin());
}