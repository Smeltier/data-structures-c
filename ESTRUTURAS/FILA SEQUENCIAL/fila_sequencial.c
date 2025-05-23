#include "fila_sequencial.h"
#include <stdlib.h>

struct fila_sequencial{
    Item* dados;
    int cap, qtde;
};

int fs_capacidade(fila_sequencial* fila){
    return fila->cap;
}

bool fs_cheia(fila_sequencial* fila){
    return fila->qtde == fila->cap;
}

Item fs_frente(fila_sequencial* fila){
    // Não trata o caso da fila ser NULL ou vazia.
    return fila->dados[fila->qtde - 1];
}

fila_sequencial* fs_inicializar(int tamanho){
    fila_sequencial* nova_fila = (fila_sequencial*) malloc(sizeof(fila_sequencial));
    if(!nova_fila)
        return NULL;
    
    nova_fila->dados = (Item*) malloc(tamanho * sizeof(Item));
    if(!nova_fila->dados){
        free(nova_fila);
        return NULL;
    }

    nova_fila->cap = tamanho;
    nova_fila->qtde = 0;

    return nova_fila;
}

fila_sequencial* liberar(fila_sequencial* fila){
    free(fila->dados);
    free(fila);
    return NULL;
}

bool fs_pop(fila_sequencial* fila){
    if(vazia(fila))
        return false;
    for(int i = 0; i < fila->qtde - 1; i++)
        fila->dados[i] = fila->dados[i + 1];
    fila->qtde--;
    return true;
}

bool fs_push(fila_sequencial* fila, Item item){
    if(fs_cheia(fila))
        return false;
    fila->dados[fila->qtde] = item;
    fila->qtde++;
    return true;
}

int fs_tamanho(fila_sequencial* fila){
    return fila->qtde;
}

bool fs_vazia(fila_sequencial* fila){
    return fila->qtde == 0;
}