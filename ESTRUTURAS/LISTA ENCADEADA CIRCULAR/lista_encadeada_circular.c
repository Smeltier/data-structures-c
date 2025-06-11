#include "lista_encadeada_circular.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct componente{
    Item conteudo;
    struct componente* proximo;
} componente;

struct lista_encadeada_circular{
    struct componente* primeiro;
    int quantidade;
};

componente*
criar_componente(Item item){
    componente* novo_componente = (lista_encadeada_circular*) calloc(1, sizeof(lista_encadeada_circular));
    if(novo_componente) novo_componente->conteudo = item;
    return novo_componente;
}

lista_encadeada_circular*
lsc_inicializar(){
    lista_encadeada_circular* nova_lista = (lista_encadeada_circular*) calloc(1, sizeof(lista_encadeada_circular));
    return nova_lista;
}

bool
lsc_inserir(lista_encadeada_circular* lista, Item item){
    if(!lista) return false;

    componente* novo_componente = criar_componente(item);
    if(!novo_componente) return false;

    componente* componente_auxiliar = lista->primeiro;
    while(componente_auxiliar->proximo != lista->primeiro)
        componente_auxiliar = componente_auxiliar->proximo;

    componente_auxiliar->proximo = novo_componente;
    novo_componente->proximo = lista->primeiro;
    lista->quantidade++;

    return true;
}

bool
lsc_remover(lista_encadeada_circular* lista){
    if(!lista || lsc_vazia(lista)) return false;

    componente* componente_remover = lista->primeiro;
    componente* componente_auxiliar = NULL;
    while(componente_remover->proximo != lista->primeiro){
        componente_auxiliar = componente_remover;
        componente_remover = componente_remover->proximo;
    }

    if(componente_auxiliar == NULL){
        lista->primeiro = NULL;
        free(componente_remover);
    }

    lista->quantidade--;

    return true;
}

bool 
lsc_vazia(lista_encadeada_circular* lista){
    return lista->quantidade == 0;
}

bool 
lsc_tamanho(lista_encadeada_circular* lista){
    return lista->quantidade;
}