#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

struct componente{
    int conteudo;
    lista_encadeada* proximo;
};

struct lista_encadeada{
    struct componente* primeiro;
    int quantidade;
};

lista_encadeada* 
le_inicializar(void){
    lista_encadeada* nova_lista = (lista_encadeada*) (sizeof(lista_encadeada));
    if(!nova_lista)
        return NULL;

    nova_lista->primeiro = NULL;
    nova_lista->quantidade = 0;

    return nova_lista;
}

bool 
le_inserir_inicio(lista_encadeada* lista, Item elemento){
    componente* novo_componente = (componente*) malloc(sizeof(componente));
    if(!novo_componente)
        return false;

    novo_componente->conteudo = elemento;
    novo_componente->proximo = lista->primeiro;
    lista->primeiro = novo_componente;
    lista->quantidade++;
    
    return true;
}

bool
le_inserir_fim(lista_encadeada* lista, Item item){
    componente* componente_auxiliar = lista->primeiro;
    while(componente_auxiliar->proximo != NULL)
        componente_auxiliar = componente_auxiliar->proximo;

    componente* novo_componente = (componente*) malloc(sizeof(componente));
    if(!novo_componente)
        return false;

    novo_componente->conteudo = item;
    novo_componente->proximo = NULL;
    componente_auxiliar->proximo = novo_componente;
    lista->quantidade++;

    return true;
}

bool
le_inserir_meio(lista_encadeada* lista, Item item, int posicao){
    if(posicao <= 0 || posicao > lista->quantidade)
        return false;
        
    componente* novo_componente = (componente*) malloc(sizeof(componente));
    if(!novo_componente)
        return false;

    


    return true;
}

void 
le_exibir(lista_encadeada* lista){
    componente* item;
    for(item = lista->primeiro; item != NULL; item = item->proximo)
        printf("%d ", item->conteudo);
}

bool 
le_vazia(lista_encadeada* lista){
    return lista->quantidade == 0;
}

lista_encadeada* 
le_buscar(lista_encadeada* lista, Item elemento){
    componente* item;
    for(item = lista->primeiro; item != NULL; item = item->proximo)
        if(item->conteudo == elemento)
            return item;
    return NULL;
}

lista_encadeada* 
le_remover_elemento(lista_encadeada* lista, Item elemento){
    componente* componente_anterior = NULL;
    componente* componente_auxiliar = lista->primeiro;

    while(componente_auxiliar != NULL && componente_auxiliar->conteudo != elemento){
        componente_anterior = componente_auxiliar;
        componente_auxiliar = componente_auxiliar->proximo;
    }

    if(componente_auxiliar == NULL)
        return lista;

    if(componente_anterior == NULL)
        lista = lista->primeiro->proximo;
    else
        componente_anterior->proximo = componente_auxiliar->proximo;

    free(componente_auxiliar);

    return lista;
}

void 
le_liberar(lista_encadeada* lista){
    if(vazia(lista))
        return;

    componente* componente_auxiliar = lista;
    while(componente_auxiliar != NULL){
        componente* componente_temporario = componente_auxiliar->proximo;
        free(componente_auxiliar);
        componente_auxiliar = componente_temporario;
    }
}
