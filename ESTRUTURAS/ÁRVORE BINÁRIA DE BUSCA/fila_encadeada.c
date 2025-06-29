#include "fila_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

struct componente {
    no* conteudo;
    struct componente* proximo;
};
typedef struct componente componente;

struct fila_encadeada {
    componente* primeiro;
    int quantidade;
};

static componente* criar_componente(no* ponteiro_no){
    componente* novo_componente = (componente*) calloc(1, sizeof(componente));
    if(novo_componente)
        novo_componente->conteudo = ponteiro_no;
    return novo_componente;
}

no* fe_frente(fila_encadeada* fila){
    if(!fila || fe_vazia(fila))
        return NULL;
    return fila->primeiro->conteudo;
}

fila_encadeada* fe_inicializar(){
    return (fila_encadeada*) calloc(1, sizeof(fila_encadeada));
}

bool fe_inserir(fila_encadeada* fila, no* ponteiro_no){
    if(!fila || !ponteiro_no) return false;

    componente* novo_componente = criar_componente(ponteiro_no);
    if(!novo_componente) return false;

    if(fe_vazia(fila)) {
        fila->primeiro = novo_componente;
    } else {
        componente* atual = fila->primeiro;
        while(atual->proximo)
            atual = atual->proximo;
        atual->proximo = novo_componente;
    }

    fila->quantidade++;
    return true;
}

bool fe_remover(fila_encadeada* fila){
    if(!fila || fe_vazia(fila))
        return false;

    componente* temp = fila->primeiro;
    fila->primeiro = temp->proximo;

    free(temp);  

    fila->quantidade--;
    return true;
}

void fe_esvaziar(fila_encadeada** fila){
    if(!fila || !(*fila)) return;

    componente* atual = (*fila)->primeiro;
    while(atual){
        componente* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    (*fila)->primeiro = NULL;
    (*fila)->quantidade = 0;
}

void fe_liberar(fila_encadeada** fila){
    if(!fila || !(*fila)) return;
    fe_esvaziar(fila);
    free(*fila);
    *fila = NULL;
}

int fe_tamanho(fila_encadeada* fila){
    if(!fila) return 0;
    return fila->quantidade;
}

bool fe_vazia(fila_encadeada* fila){
    if(!fila) return true;
    return fila->quantidade == 0;
}