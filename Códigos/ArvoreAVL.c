 /*********************************************************************
Códigos ensinados em sala de aula sobre Árvore AVL
Profa. Christiane R S Brasil
**********************************************************************/

/**---Rotação Simples à Direita---**/
void RotacaoLL(ArvAVL* raiz)
{
    struct No* no;
    no = (*raiz)->esq;///INSTRUÇÃO 1
    (*raiz)->esq = no->dir;///INSTRUÇÃO 2
    no->dir = *raiz;///INSTRUÇÃO 3
    ///Recalculando altura
    (*raiz)->alt = maior(calculaAltura(&(*raiz)->esq), calculaAltura(&(*raiz)->dir)+1);
    no->alt = maior(calculaAltura(no->esq), (*raiz)->alt)+1);

    *raiz = no;
}

/**---Rotação Simples à Esquerda---**/
void RotacaoRR(ArvAVL* raiz)
{
    struct No* no;
    no = (*raiz)->dir;///INSTRUÇÃO 1
    (*raiz)->dir = no->esq;///INSTRUÇÃO 2
    no->esq = *raiz;///INSTRUÇÃO 3
    ///Recalculando altura
    (*raiz)->alt = maior(calculaAltura(&(*raiz)->esq), calculaAltura(&(*raiz)->dir)+1);
    no->alt = maior(calculaAltura(no->dir), (*raiz)->alt)+1);

    *raiz = no;
}

/**---Rotação Dupla à Direita---**/
void RotacaoLR(ArvAVL* raiz)
{
    RotacaoRR(&(*raiz)->esq);///simples à esquerda
    RotacaoLL(raiz);///simples à direita
}

/**---Rotação Dupla à Esquerda---**/
void RotacaoRL(ArvAVL* raiz)
{
    RotacaoLL(&(*raiz)->dir);///simples à direita
    RotacaoRR(raiz);///simples à esquerda
}
