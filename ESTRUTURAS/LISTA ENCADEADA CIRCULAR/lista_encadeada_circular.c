#include "lista_encadeada_circular.h"
#include <stdio.h>
#include <stdlib.h>

struct componente{
    Item conteudo;
    struct componente* proximo;
};
typedef struct componente componente;

struct lista_encadeada_circular{
    struct componente* primeiro;
    int quantidade;
};

componente*
criar_componente(Item item){
    componente* novo_componente = (componente*) calloc(1, sizeof(componente));
    if(novo_componente) 
        novo_componente->conteudo = item;
    return novo_componente;
}

lista_encadeada_circular*
lsc_inicializar(){
    lista_encadeada_circular* nova_lista = (lista_encadeada_circular*) calloc(1, sizeof(lista_encadeada_circular));
    return nova_lista;
}

bool 
lsc_inserir(lista_encadeada_circular* lista, Item item) {
    if (!lista) 
        return false;

    componente* novo_componente = criar_componente(item);
    if (!novo_componente) 
        return false;

    if (lista->primeiro == NULL) {
        novo_componente->proximo = novo_componente;
        lista->primeiro = novo_componente;
    } else {
        componente* aux = lista->primeiro;
        while (aux->proximo != lista->primeiro)
            aux = aux->proximo;
        aux->proximo = novo_componente;
        novo_componente->proximo = lista->primeiro;
    }

    lista->quantidade++;

    return true;
}

bool lsc_remover(lista_encadeada_circular* lista) {
    if (!lista || lista->primeiro == NULL) 
        return false;

    componente* atual = lista->primeiro;
    if (atual->proximo == atual) {
        free(atual);
        lista->primeiro = NULL;
    } else {
        componente* anterior = atual;
        while (anterior->proximo != lista->primeiro)
            anterior = anterior->proximo;
        anterior->proximo = atual->proximo;
        lista->primeiro = atual->proximo;
        free(atual);
    }

    lista->quantidade--;

    return true;
}

bool 
lsc_vazia(lista_encadeada_circular* lista){
    return !lista || lista->quantidade == 0;
}

int 
lsc_tamanho(lista_encadeada_circular* lista){
    if(!lista)
        return 0;
    return lista->quantidade;
}