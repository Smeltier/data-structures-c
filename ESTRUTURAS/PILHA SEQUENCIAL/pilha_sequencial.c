#include "pilha_sequencial.h"
#include <stdlib.h>

struct pilha_sequencial{
    Item* dados;
    int cap, qtde;
};

int ps_capacidade(pilha_sequencial* pilha){
    return pilha->cap;
}

bool ps_cheia(pilha_sequencial* pilha){
    return pilha->qtde == pilha->cap;
}

pilha_sequencial* ps_inicializar(int tamanho){
    pilha_sequencial* nova_pilha = (pilha_sequencial*) malloc(sizeof(pilha_sequencial));
    if(!nova_pilha)
        return NULL;
    
    nova_pilha->dados = (Item*) malloc(tamanho* sizeof(Item));
    if(!nova_pilha->dados){
        nova_pilha->dados = NULL;
        return NULL;
    }

    nova_pilha->cap = tamanho;
    nova_pilha->qtde = 0;

    return nova_pilha;
}

bool ps_pop(pilha_sequencial* pilha){
    if(!pilha || ps_vazia(pilha))
        return false;
    pilha->qtde--;
    return true;
}

bool ps_push(pilha_sequencial* pilha, Item item){
    if(!pilha || ps_cheia(pilha))
        return false;
    pilha->dados[pilha->qtde++] = item;
    return true;
}

int ps_tamanho(pilha_sequencial* pilha){
    return pilha->qtde;
}

Item ps_top(pilha_sequencial* pilha){
    return pilha->dados[pilha->qtde - 1];
}

bool ps_vazia(pilha_sequencial* pilha){
    return pilha->qtde == 0;
}