/*********************************************************************
Códigos ensinados em sala de aula sobre Árvore de Busca Binária (ABB)
Profa. Christiane R S Brasil
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct No{
int info;
struct No* esq;
struct No* dir;
};

ArvBin* criaArvBin()
{
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz!=NULL) *raiz = NULL;
    return raiz;
}

void liberaNo(struct No* no)
{
    if(no==NULL) return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;
}

void liberaArvBin(ArvBin* raiz)
{
    if(raiz==NULL) return;
    liberaNo(*raiz);
    free(raiz);
}

int calculaAltura(ArvBin* raiz)
{
    if(raiz==NULL) return 0;//árvore não foi criada
    if(*raiz==NULL) return 0;//árvore vazia
    int altEsq = calculaAltura(&((*raiz)->esq));
    int altDir = calculaAltura(&((*raiz)->dir));
    if(altEsq > altDir) return (altEsq + 1);
    else return (altDir + 1);
}

int qtdeNos(ArvBin* raiz)
{    if(raiz==NULL) return 0;//árvore não foi criada
    if(*raiz==NULL) return 0;//árvore vazia
    int qtdeEsq = qtdeNos(&((*raiz)->esq));
    int qtdeDir = qtdeNos(&((*raiz)->dir));
    return (qtdeEsq + qtdeDir + 1);
}


void preOrdem(ArvBin* raiz)
{
    if(raiz==NULL) return;
    if(*raiz!=NULL){
        printf("%d ", (*raiz)->info);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}

void inOrdem(ArvBin* raiz)
{
    if(raiz==NULL) return;
    if(*raiz!=NULL){
        inOrdem(&((*raiz)->esq));
        printf("%d ", (*raiz)->info);
        inOrdem(&((*raiz)->dir));
    }
}

void posOrdem(ArvBin* raiz)
{
    if(raiz==NULL) return;
    if(*raiz!=NULL){
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%d ", (*raiz)->info);
    }
}

int buscaABB(ArvBin* raiz, int v)
{
    if(raiz == NULL) return 0;
    struct No* atual = *raiz;

    while(atual!=NULL)///não chegou a nenhum nó folha
    {
        if(v==atual->info) return 1;
        if(v<atual->info) atual = atual->esq;
        else              atual = atual->dir;
    }
    return 0;
}

int insereABB(ArvBin* raiz, int v){

    if(raiz == NULL) return 0;

    struct No* novo =(struct No*) malloc(sizeof(struct No));
    if(novo==NULL) return 0;
    novo->info = v;
    novo->esq = novo->dir = NULL;

    if(*raiz == NULL)///Árvore Vazia
    *raiz = novo;
    else{
        ///procurar a posição correta
        struct No* atual = *raiz, *ant = NULL;

        while(atual!=NULL)
        {
            ant = atual;
            if(v==atual->info)///elemento já existe
            {
                free(novo);
                return 0;
            }
            if(v < atual->info)
                atual = atual->esq;
            else
                atual = atual->dir;
        }///fimwhile

        if(v<ant->info)///inserindo pela esquerda
            ant->esq = novo;
        else
            ant->dir = novo;
    }
    return 1;///inserido
}

int removeABB(ArvBin* raiz, int v)
{
    if(raiz == NULL) return 0;
    struct No* ant = NULL, *atual = *raiz;

    while(atual!=NULL)
    {
        if(v==atual->info)///elemento encontrado
        {
            if(atual == *raiz) *raiz = removeAtual(atual);
            else
            {
                if(ant->esq == atual)///veio pela esquerda
                ant->esq = removeAtual(atual);
                else
                ant->dir = removeAtual(atual);
            }
            return 1;///removido
        }///continua procurando
        ant = atual;
        if(v<atual->info) atual = atual->esq;
        else              atual = atual->dir;
    }
    return 0;///não removido
}

struct No* removeAtual(struct No* atual)
{
    struct No* p, *q;

    if(atual->esq == NULL)///não tem filho esquerdo (Caso 1)
    {
        q = atual->dir;
        free(atual);
        return q;
    }

    p = atual;
    q = atual->esq;

    while(q->dir!=NULL)///procura filho mais a direita da subárvore da esquerda
    {
        p = q;
        q = q->dir;
    }

    if(p!=atual)/// testa se tem o filho mais a direita da subarvore da esquerda (Caso 2)
    {           /// ou se não tem o filho mais a direita (Caso 3)
        p->dir = q->esq;///INSTRUÇÃO 1
        q->esq = atual->esq;///INSTRUÇÃO 2
    }

    q->dir = atual->dir;///INSTRUÇÃO 3
    free(atual);
    return q;
};

int fatorBalanceamento(ArvBin* raiz)
{
    return (calculaAltura(&(*raiz)->esq) - calculaAltura(&(*raiz)->dir));
}
