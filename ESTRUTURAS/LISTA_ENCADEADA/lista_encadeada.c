#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

struct componente {
    int conteudo;
    struct componente* proximo;
};

struct lista_encadeada {
    struct componente* primeiro;
    int quantidade;
};

Item 
le_buscar(lista_encadeada* lista, const Item elemento){
    if(le_vazia(lista))
        return 0;
    int posicao_atual = 1;
    componente* item;
    for(item = lista->primeiro; item != NULL; item = item->proximo, posicao_atual++)
        if(item->conteudo == elemento)
            return posicao_atual;
    return 0;
}

void 
le_exibir(lista_encadeada* lista){
    componente* item;
    for(item = lista->primeiro; item != NULL; item = item->proximo)
        printf("%d ", item->conteudo);
}

lista_encadeada* 
le_inicializar(void){
    lista_encadeada* nova_lista = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    nova_lista->primeiro = NULL;
    nova_lista->quantidade = 0;
    return nova_lista;
}

bool 
le_inserir_fim(lista_encadeada* lista, const Item item){
    if(!lista)
        return false;

    componente* novo_componente = (componente*) malloc(sizeof(componente));
    if(!novo_componente)
        return false;

    novo_componente->conteudo = item;
    novo_componente->proximo = NULL;

    if(lista->primeiro == NULL){
        lista->primeiro = novo_componente;
    } else {
        componente* componente_auxiliar = lista->primeiro;
        while(componente_auxiliar->proximo != NULL)
            componente_auxiliar = componente_auxiliar->proximo;
        componente_auxiliar->proximo = novo_componente;
    }
    lista->quantidade++;

    return true;
}

bool 
le_inserir_inicio(lista_encadeada* lista, const Item elemento){
    if(!lista)
        return false;

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
le_inserir_meio(lista_encadeada* lista, const Item item, const int posicao){
    if(!lista || posicao <= 0 || posicao > lista->quantidade + 1)
        return false;
        
    componente* novo_componente = (componente*) malloc(sizeof(componente));
    if(!novo_componente)
        return false;

    novo_componente->conteudo = item;

    int posicao_atual = 1;
    componente* componente_anterior = NULL;
    componente* componente_posicao = lista->primeiro;
    while(posicao_atual < posicao){
        componente_anterior = componente_posicao;
        componente_posicao = componente_posicao->proximo;
        posicao_atual++;
    }

    if(componente_anterior == NULL){
        novo_componente->proximo = lista->primeiro;
        lista->primeiro = novo_componente;
    }   
    else{
        novo_componente->proximo = componente_posicao;
        componente_anterior->proximo = novo_componente;
    }

    lista->quantidade++;
    return true;
}

void 
le_liberar(lista_encadeada** lista){
    if(lista == NULL || *lista == NULL)
        return;

    componente* componente_auxiliar = (*lista)->primeiro;
    while(componente_auxiliar != NULL){
        componente* componente_temporario = componente_auxiliar->proximo;
        free(componente_auxiliar);
        componente_auxiliar = componente_temporario;
    }

    free(*lista);
    *lista = NULL;
}

bool
le_remover_fim(lista_encadeada* lista){
    if(le_vazia(lista) || !lista)
        return false;

    componente* componente_anterior = NULL;
    componente* componente_final = lista->primeiro;
    while(componente_final!= NULL && componente_final->proximo != NULL){
        componente_anterior = componente_final;
        componente_final = componente_final->proximo;
    }

    if(componente_anterior == NULL)
        lista->primeiro = NULL;
    else
        componente_anterior->proximo = NULL;

    free(componente_final);
    lista->quantidade--;

    return true;
}

bool 
le_remover_inicio(lista_encadeada* lista){
    if(!lista || le_vazia(lista))
        return false;

    componente* componente_auxiliar = lista->primeiro;

    lista->primeiro = componente_auxiliar->proximo;
    free(componente_auxiliar);
    lista->quantidade--;

    return true;
}

bool 
le_remover_meio(lista_encadeada* lista, int posicao){
    if(le_vazia(lista) || !lista || posicao <= 0 || posicao > lista->quantidade)
        return false;

    int posicao_atual = 1;
    componente* componente_anterior = NULL;
    componente* componente_posicao = lista->primeiro;
    while(posicao_atual < posicao){
        componente_anterior = componente_posicao;
        componente_posicao = componente_posicao->proximo;
        posicao_atual++;
    }

    if(componente_anterior == NULL){
        lista->primeiro = componente_posicao->proximo;
    }
    else{
        componente_anterior->proximo = componente_posicao->proximo;
    }

    free(componente_posicao);
    lista->quantidade--;
    return true;
}

int
le_tamanho(lista_encadeada* lista){
    return lista->quantidade;
}

bool 
le_vazia(lista_encadeada* lista){
    return lista->quantidade == 0;
}