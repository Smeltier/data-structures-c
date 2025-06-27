#include "arvore_binaria_busca.h"
#include "no.h"
#include <stdlib.h>
#include <stdio.h>

struct arvore_binaria_busca {
    struct no* raiz;  
    int quantidade_nos;  
};

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