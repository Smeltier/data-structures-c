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

static bool buscar_no(no* raiz, Item item){
    if(!raiz) return false;
    if(raiz->conteudo == item) return true;
    if(item < raiz->conteudo) return buscar_no(raiz->arvore_esquerda, item);
    else return buscar_no(raiz->arvore_direita, item);
}

static no* criar_no(Item conteudo){
    no* novo_no = (no*) calloc(1, sizeof(no));
    if(novo_no) 
        novo_no->conteudo = conteudo;
    return novo_no;
}

static void exibir_no(no* raiz) {
    if (!raiz) return;
    exibir_no(raiz->arvore_esquerda);
    printf("%d ", raiz->conteudo);
    exibir_no(raiz->arvore_direita);
}

static no* inserir_no(no* raiz, Item item){
    if(!raiz) return criar_no(item);
    if(item < raiz->conteudo) 
        raiz->arvore_esquerda = inserir_no(raiz->arvore_esquerda, item);
    else 
        raiz->arvore_direita = inserir_no(raiz->arvore_direita, item);
    return raiz;
}

static void liberar_nos(no* raiz) {
    if (!raiz) return;
    no* no_auxiliar = raiz;
    liberar_nos(raiz->arvore_esquerda);
    liberar_nos(raiz->arvore_direita);
    free(no_auxiliar);
}

static no* melhor_no(no* raiz){
    if(!raiz) return NULL;
    if(raiz->arvore_esquerda)
        return melhor_no(raiz->arvore_esquerda);
    return raiz;
}

static no* remover_no(no* raiz, Item item){
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

bool abb_buscar(arvore_binaria_busca* arvore, Item item){
    if(!arvore || abb_vazia(arvore))
        return false;
    return buscar_no(arvore->raiz, item);
}

void abb_esvaziar(arvore_binaria_busca* arvore){
    if(!arvore || aab_vazia(arvore)) return;
    liberar_nos(arvore->raiz);
    arvore->raiz = NULL;
    arvore->quantidade_nos = 0;
}

void abb_exibir(arvore_binaria_busca* arvore) {
    if (!arvore || abb_vazia(arvore)) return;
    exibir_no(arvore->raiz);
}

arvore_binaria_busca* abb_inicializar(){
    arvore_binaria_busca* nova_arvore = (arvore_binaria_busca*) 
                                        calloc(1, sizeof(arvore_binaria_busca));
    return nova_arvore;
}

void abb_inserir(arvore_binaria_busca* arvore, Item item){
    if (!arvore) return;
    arvore->raiz = inserir_no(arvore->raiz, item);
    arvore->quantidade_nos++;
}

void abb_liberar(arvore_binaria_busca** arvore){
    if(!arvore || !(*arvore)) return;
    aab_esvaziar(*arvore);
    free(*arvore);
    (*arvore) = NULL;
}

int abb_quantidade_nos(arvore_binaria_busca* arvore){
    if(!arvore) return 0;
    return arvore->quantidade_nos;
}

void abb_remover(arvore_binaria_busca* arvore, Item item){
    if(!arvore || aab_vazia(arvore)) return;
    if(abb_buscar(arvore, item)){
        arvore->raiz = remover_no(arvore->raiz, item);
        arvore->quantidade_nos--;
    }
}

bool abb_vazia(arvore_binaria_busca* arvore){
    return !arvore || arvore->quantidade_nos == 0;
}