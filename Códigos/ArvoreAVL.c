 /*********************************************************************
C�digos ensinados em sala de aula sobre �rvore AVL
Profa. Christiane R S Brasil
**********************************************************************/

/**---Rota��o Simples � Direita---**/
void RotacaoLL(ArvAVL* raiz)
{
    struct No* no;
    no = (*raiz)->esq;///INSTRU��O 1
    (*raiz)->esq = no->dir;///INSTRU��O 2
    no->dir = *raiz;///INSTRU��O 3
    ///Recalculando altura
    (*raiz)->alt = maior(calculaAltura(&(*raiz)->esq), calculaAltura(&(*raiz)->dir)+1);
    no->alt = maior(calculaAltura(no->esq), (*raiz)->alt)+1);

    *raiz = no;
}

/**---Rota��o Simples � Esquerda---**/
void RotacaoRR(ArvAVL* raiz)
{
    struct No* no;
    no = (*raiz)->dir;///INSTRU��O 1
    (*raiz)->dir = no->esq;///INSTRU��O 2
    no->esq = *raiz;///INSTRU��O 3
    ///Recalculando altura
    (*raiz)->alt = maior(calculaAltura(&(*raiz)->esq), calculaAltura(&(*raiz)->dir)+1);
    no->alt = maior(calculaAltura(no->dir), (*raiz)->alt)+1);

    *raiz = no;
}

/**---Rota��o Dupla � Direita---**/
void RotacaoLR(ArvAVL* raiz)
{
    RotacaoRR(&(*raiz)->esq);///simples � esquerda
    RotacaoLL(raiz);///simples � direita
}

/**---Rota��o Dupla � Esquerda---**/
void RotacaoRL(ArvAVL* raiz)
{
    RotacaoLL(&(*raiz)->dir);///simples � direita
    RotacaoRR(raiz);///simples � esquerda
}
