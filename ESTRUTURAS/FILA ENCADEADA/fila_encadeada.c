#include "fila_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct componente componente;

struct componente {
    Item conteudo;
    struct componente* proximo;
};

struct fila_encadeada {
    struct componente* primeiro;
    int quantidade;
};

static componente* 
criar_componente(Item item){
    componente* novo_componente = (componente*) calloc(1, sizeof(componente));
    if(novo_componente)
        novo_componente->conteudo = item;
    return novo_componente;
}

void 
fe_esvaziar(fila_encadeada** fila){
    if(!fila || !(*fila))
        return;

    componente* componente_auxiliar = (*fila)->primeiro;
    while(componente_auxiliar != NULL){
        componente* componente_temporario = componente_auxiliar->proximo;
        free(componente_auxiliar);
        componente_auxiliar = componente_temporario;
    }

    (*fila)->primeiro = NULL;
    (*fila)->quantidade = 0;
}

fila_encadeada* 
fe_inicializar(void){
    fila_encadeada* nova_fila = (fila_encadeada*) calloc(1, sizeof(fila_encadeada));
    return nova_fila;
}

bool 
fe_inserir(fila_encadeada* fila, const Item item){
    if(!fila)
        return false;

    componente* novo_componente = criar_componente(item);
    if(!novo_componente)
        return false;

    if(fe_vazia(fila)){
        fila->primeiro = novo_componente;
    } else {
        componente* componente_auxiliar = fila->primeiro;
        while(componente_auxiliar->proximo != NULL)
            componente_auxiliar = componente_auxiliar->proximo;
        componente_auxiliar->proximo = novo_componente;
    }
    fila->quantidade++;

    return true;
}

void 
fe_liberar(fila_encadeada** fila){
    if(!fila || !(*fila))
        return;
    fe_esvaziar(fila);
    free(*fila);
    *fila = NULL;
}

bool 
fe_remover(fila_encadeada* fila){
    if(!fila || fe_vazia(fila))
        return false;

    componente* componente_temporario = fila->primeiro;
    
    fila->primeiro = componente_temporario->proximo;
    free(componente_temporario);
    fila->quantidade--;

    return true;
}

int
fe_tamanho(fila_encadeada* fila){
    if(!fila)
        return 0;
    return fila->quantidade;
}

bool 
fe_vazia(fila_encadeada* fila){
    if(!fila)
        return true;
    return fila->quantidade == 0;
}