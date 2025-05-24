#include "pilha_sequencial.h"
#include <stdlib.h>

struct pilha_sequencial{
    Item* dados;
    int capacidade, quantidade;
};

int 
ps_capacidade(pilha_sequencial* pilha){
    return pilha->capacidade;
}

bool 
ps_cheia(pilha_sequencial* pilha){
    return pilha->quantidade == pilha->capacidade;
}

pilha_sequencial* 
ps_inicializar(const int tamanho){
    pilha_sequencial* nova_pilha = (pilha_sequencial*) malloc(sizeof(pilha_sequencial));
    if(!nova_pilha)
        return NULL;
    
    nova_pilha->dados = (Item*) malloc(tamanho * sizeof(Item));
    if(!nova_pilha->dados)
        return NULL;

    nova_pilha->capacidade = tamanho;
    nova_pilha->quantidade = 0;

    return nova_pilha;
}

void 
ps_liberar(pilha_sequencial** pilha){
    if(!pilha || !*pilha)
        return;
    free((*pilha)->dados);
    free(*pilha);
    *pilha = NULL;
}

bool 
ps_pop(pilha_sequencial* pilha){
    if(!pilha || ps_vazia(pilha))
        return false;
    pilha->quantidade--;
    return true;
}

bool 
ps_push(pilha_sequencial* pilha, const Item item){
    if(!pilha || ps_cheia(pilha))
        return false;
    pilha->dados[pilha->quantidade++] = item;
    return true;
}

int 
ps_tamanho(pilha_sequencial* pilha){
    return pilha->quantidade;
}

Item 
ps_top(pilha_sequencial* pilha){
    return pilha->dados[pilha->quantidade - 1];
}

bool 
ps_vazia(pilha_sequencial* pilha){
    return pilha->quantidade == 0;
}