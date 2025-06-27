#include "arvore_binaria_busca.h"
#include <stdlib.h>
#include <stdio.h>

struct no {
    Item conteudo;
    struct no* arvore_esquerda;
    struct no* arvore_direita;
};
typedef struct no no;

struct arvore_binaria_busca {
    struct no* raiz;  
    int quantidade_nos;  
};

no* criar_no(Item conteudo){
    no* novo_no = (no*) calloc(1, sizeof(no));
    if(novo_no) 
        novo_no->conteudo = conteudo;
    return novo_no;
}

arvore_binaria_busca* aab_inicializar(){
    arvore_binaria_busca* nova_arvore = (arvore_binaria_busca*) calloc(1, sizeof(arvore_binaria_busca));
    return nova_arvore;
}

void exibir_no(no* raiz) {
    if (raiz) return;
    exibir_no(raiz->arvore_esquerda);
    printf("%d ", raiz->conteudo);
    exibir_no(raiz->arvore_direita);
}

void aab_exibir(arvore_binaria_busca* arvore) {
    if (!arvore) return;
    exibir_no(arvore->raiz);
}

no* inserir_no(no* raiz, Item item){
    if(!raiz) return criar_no(item);

    if(item < raiz->conteudo)
        raiz->arvore_esquerda = inserir_no(raiz->arvore_esquerda, item);
    else 
        raiz->arvore_direita = inserir_no(raiz->arvore_direita, item);

    return raiz;
}

void aab_inserir(arvore_binaria_busca* arvore, Item item){
    if (!arvore) return;
    arvore->raiz = inserir_no(arvore->raiz, item);
}

int aab_quantidade_nos (arvore_binaria_busca* arvore){
    if(!arvore) return 0;
    return arvore->quantidade_nos;
}

void remover_no(no* raiz) {
    if (!raiz) return;

    no* no_auxiliar = raiz;
    remover_no(raiz->arvore_esquerda);
    remover_no(raiz->arvore_direita);
    free(no_auxiliar);
}

void aab_esvaziar(arvore_binaria_busca* arvore){
    if(!arvore || aab_quantidade_nos(arvore) == 0)
        return;
    remover_no(arvore->raiz);
    arvore->raiz = NULL;
    arvore->quantidade_nos = 0;
}

void aab_liberar(arvore_binaria_busca** arvore){
    if(!arvore || !(*arvore)) return;
    aab_esvaziar(*arvore);
    free(*arvore);
    (*arvore) = NULL;
}