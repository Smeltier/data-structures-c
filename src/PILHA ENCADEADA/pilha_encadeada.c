#include "pilha_encadeada.h"
#include <stdlib.h>
#include <limits.h>

struct componente {
    Item conteudo;
    struct componente* proximo;
};
typedef struct componente componente;

struct pilha_encadeada {
    struct componente* primeiro;
    int quantidade;
};

static componente* criar_componente(Item item){
    componente* novo_componente = (componente*) calloc(1, sizeof(componente));
    if(novo_componente)
        novo_componente->conteudo = item;
    return novo_componente;
}

void pe_esvaziar(pilha_encadeada** pilha){
    if(!pilha || !(*pilha))
        return;

    componente* componente_auxiliar = (*pilha)->primeiro;
    while(componente_auxiliar){
        componente* componente_temporario = componente_auxiliar->proximo;
        free(componente_auxiliar);
        componente_auxiliar = componente_temporario;
    }

    (*pilha)->primeiro = NULL;
    (*pilha)->quantidade = 0;
}

pilha_encadeada* pe_inicializar(void){
    pilha_encadeada* nova_pilha = (pilha_encadeada*) calloc(1, sizeof(pilha_encadeada));
    return nova_pilha;   
}

bool pe_inserir(pilha_encadeada* pilha, const Item item){
    if(!pilha)
        return;

    componente* novo_componente = criar_componente(item);
    if(!novo_componente)
        return false;

    novo_componente->proximo = pilha->primeiro;
    pilha->primeiro = novo_componente;
    pilha->quantidade++;

    return true;
}

void pe_liberar(pilha_encadeada** pilha){
    if(!pilha || !(*pilha))
        return;
    pe_esvaziar(pilha);
    free(*pilha);
    *pilha = NULL;
}

bool pe_remover(pilha_encadeada* pilha){
    if(!pilha || pe_vazia(pilha))
        return false;
    
    componente* componente_temporario = pilha->primeiro;

    pilha->primeiro = componente_temporario->proximo;
    pilha->quantidade--;

    free(componente_temporario);

    return true;
}

int pe_tamanho(pilha_encadeada* pilha){
    if(!pilha)
        return 0;
    return pilha->quantidade;
}

Item pe_topo(pilha_encadeada* pilha){
    if(!pilha || pe_vazia(pilha))
        return INT_MIN;
    return pilha->primeiro->conteudo;
}

bool pe_vazia(pilha_encadeada* pilha){
    if(!pilha)
        return true;
    return pilha->quantidade == 0;
}