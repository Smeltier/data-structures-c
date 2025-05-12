#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

struct lista_encadeada{
    int valor;
    lista_encadeada* proximo_no;
};

lista_encadeada* inicializar(void){
    return NULL;
}

lista_encadeada* inserir(lista_encadeada* lista, int elemento){
    lista_encadeada* novo_no = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    novo_no->valor = elemento;
    novo_no->proximo_no = lista;
    return novo_no;
}

void mostrar(lista_encadeada* lista){
    lista_encadeada* item;
    for(item = lista; item != NULL; item = item->proximo_no)
        printf(" %d", item->valor);
}

bool vazia(lista_encadeada* lista){
    return lista == NULL;
}

lista_encadeada* buscar(lista_encadeada* lista, int elemento){
    lista_encadeada* item;
    for(item = lista; item != NULL; item = item->proximo_no)
        if(item->valor == elemento)
            return item;
    return NULL;
}

lista_encadeada* remover(lista_encadeada* lista, int elemento){
    lista_encadeada* no_anterior = NULL;
    lista_encadeada* no_auxiliar = lista;

    while(no_auxiliar != NULL && no_auxiliar->valor != elemento){
        no_anterior = no_auxiliar;
        no_auxiliar = no_auxiliar->proximo_no;
    }

    if(no_auxiliar == NULL)
        return lista;

    if(no_anterior == NULL)
        lista = lista->proximo_no;
    else
        no_anterior->proximo_no = no_auxiliar->proximo_no;

    free(no_auxiliar);

    return lista;
}

void liberar(lista_encadeada* lista){
    if(vazia(lista))
        return;
    lista_encadeada* no_auxiliar = lista;
    while(no_auxiliar != NULL){
        lista_encadeada* no_temporario = no_auxiliar->proximo_no;
        free(no_auxiliar);
        no_auxiliar = no_temporario;
    }
}
