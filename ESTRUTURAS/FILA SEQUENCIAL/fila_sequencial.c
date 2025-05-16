#include "fila_sequencial.h"
#include <stdlib.h>

struct fila_sequencial{
    Item* dados;
    int cap, qtde;
};

Item fs_back(fila_sequencial* fila){
    return fila->dados[0];
}

int fs_capacidade(fila_sequencial* fila){
    return fila->cap;
}

bool fs_cheia(fila_sequencial* fila){
    return fila->qtde == fila->cap;
}

Item fs_front(fila_sequencial* fila){
    if(fs_vazia(fila))
        return NULL; // ??
    return fila->dados[fila->qtde - 1];
}

fila_sequencial* fs_inicializar(const int tamanho){
    fila_sequencial* nova_fila = (fila_sequencial*) malloc(sizeof(fila_sequencial));
    if(!nova_fila)
        return NULL;
    
    nova_fila->dados = (Item*) malloc(tamanho * sizeof(Item));
    if(!nova_fila->dados){
        nova_fila->dados = NULL;
        return NULL;
    }

    nova_fila->cap = tamanho;
    nova_fila->qtde = 0;

    return nova_fila;
}

bool fs_pop(fila_sequencial* fila){
    if(!fila || fs_vazia(fila))
        return false;
    fila->qtde--;
    return true;
}

bool fs_push(fila_sequencial* fila, const Item item){
    if(!fila || fs_cheia(fila))
        return false;
    
    for(int i = fila->qtde; i > 0; i--)
        fila->dados[i] = fila->dados[i - 1];
    
    fila->dados[0] = item;
    fila->qtde++;

    return true;
}

int fs_tamanho(fila_sequencial* fila){
    return fila->qtde;
}

bool fs_vazia(fila_sequencial* fila){
    return fila->qtde == 0;
}