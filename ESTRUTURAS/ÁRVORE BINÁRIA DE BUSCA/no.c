#include "no.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    Item conteudo;
    struct no* arvore_esquerda;
    struct no* arvore_direita;
};

bool buscar_no(no* raiz, Item item){
    if(!raiz) return false;
    if(raiz->conteudo == item) return true;
    if(item < raiz->conteudo) return buscar_no(raiz->arvore_esquerda, item);
    else return buscar_no(raiz->arvore_direita, item);
}

no* criar_no(Item conteudo){
    no* novo_no = (no*) calloc(1, sizeof(no));
    if(novo_no) 
        novo_no->conteudo = conteudo;
    return novo_no;
}

void exibir_no(no* raiz) {
    if (!raiz) return;
    exibir_no(raiz->arvore_esquerda);
    printf("%d ", raiz->conteudo);
    exibir_no(raiz->arvore_direita);
}

no* inserir_no(no* raiz, Item item){
    if(!raiz) return criar_no(item);
    if(item < raiz->conteudo) 
        raiz->arvore_esquerda = inserir_no(raiz->arvore_esquerda, item);
    else 
        raiz->arvore_direita = inserir_no(raiz->arvore_direita, item);
    return raiz;
}

void liberar_nos(no* raiz) {
    if (!raiz) return;
    no* no_auxiliar = raiz;
    liberar_nos(raiz->arvore_esquerda);
    liberar_nos(raiz->arvore_direita);
    free(no_auxiliar);
}

no* melhor_no(no* raiz){
    if(!raiz) return NULL;
    if(raiz->arvore_esquerda)
        return melhor_no(raiz->arvore_esquerda);
    return raiz;
}

no* remover_no(no* raiz, Item item){
    if(!raiz) return NULL;

    if(item < raiz->conteudo)
        raiz->arvore_esquerda = remover_no(raiz->arvore_esquerda, item);
    else if(item > raiz->conteudo)
        raiz->arvore_direita = remover_no(raiz->arvore_direita, item);
    else{
        no* no_auxiliar = NULL;

        if(!raiz->arvore_esquerda && !raiz->arvore_direita){
            free(raiz);
            return NULL;
        }
        else if(!raiz->arvore_esquerda){
            no_auxiliar = raiz->arvore_direita;
            free(raiz);
            return no_auxiliar;
        }
        else if(!raiz->arvore_direita){
            no_auxiliar = raiz->arvore_esquerda;
            free(raiz);
            return no_auxiliar;
        }
        else{
            no_auxiliar = melhor_no(raiz->arvore_direita);
            raiz->conteudo = no_auxiliar->conteudo;
            raiz->arvore_direita = remover_no(raiz->arvore_direita, no_auxiliar->conteudo);
        }
    }
    
    return raiz;
}