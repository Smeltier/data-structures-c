#include "fila_sequencial.h"
#include <stdlib.h>
#include <limits.h>

struct fila_sequencial{
    Item* dados;
    int capacidade, quantidade;
};

Item 
fs_back(fila_sequencial* fila){
    return fila->dados[0];
}

int 
fs_capacidade(fila_sequencial* fila){
    return fila->capacidade;
}

bool 
fs_cheia(fila_sequencial* fila){
    return fila->quantidade == fila->capacidade;
}

Item 
fs_frente(fila_sequencial* fila){
    if(fs_vazia(fila))
        return INT_MIN;
    return fila->dados[fila->quantidade - 1];
}

fila_sequencial* 
fs_inicializar(const int tamanho){
    fila_sequencial* nova_fila = (fila_sequencial*) malloc(sizeof(fila_sequencial));
    if(!nova_fila)
        return NULL;
    
    nova_fila->dados = (Item*) malloc(tamanho * sizeof(Item));
    if(!nova_fila->dados){
        nova_fila->dados = NULL;
        return NULL;
    }

    nova_fila->capacidade = tamanho;
    nova_fila->quantidade = 0;

    return nova_fila;
}

void 
fs_liberar(fila_sequencial** fila){
    if(!fila || !*fila)
        return;
    free((*fila)->dados);
    free(*fila);
    *fila = NULL;
}

bool 
fs_remover(fila_sequencial* fila){
    if(!fila || fs_vazia(fila))
        return false;
    fila->quantidade--;
    return true;
}

bool 
fs_inserir(fila_sequencial* fila, const Item item){
    if(!fila || fs_cheia(fila))
        return false;
    
    for(int i = fila->quantidade; i > 0; i--)
        fila->dados[i] = fila->dados[i - 1];
    
    fila->dados[0] = item;
    fila->quantidade++;

    return true;
}

int
fs_tamanho(fila_sequencial* fila){
    return fila->quantidade;
}

bool 
fs_vazia(fila_sequencial* fila){
    return fila->quantidade == 0;
}