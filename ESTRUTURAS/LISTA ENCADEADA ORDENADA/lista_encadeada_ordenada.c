#include "lista_encadeada_ordenada.h"
#include <stdlib.h>
#include <stdio.h>

struct componente {
    Item conteudo;
    struct componente* proximo;
};
typedef struct componente componente;

struct lista_encadeada_ordenada {
    struct componente* primeiro;
    int quantidade;
};

Item 
le_buscar(lista_encadeada_ordenada* lista, const Item elemento){
    if(!lista || le_vazia(lista))
        return 0;
    int posicao_atual = 1;
    componente* item = lista->primeiro;
    while(item != NULL){
        if(item->conteudo == elemento)
            return posicao_atual;
        item = item->proximo;
        posicao_atual++;
    }
    return 0;
}

static componente* 
criar_componente(Item item){
    componente* novo_componente = (componente*) calloc(1, sizeof(componente));
    if(novo_componente)
        novo_componente->conteudo = item;
    return novo_componente;
}


void 
le_esvaziar(lista_encadeada_ordenada** lista){
    if(!lista || !(*lista))
        return;

    componente* componente_auxiliar = (*lista)->primeiro;
    while(componente_auxiliar != NULL){
        componente* componente_temporario = componente_auxiliar->proximo;
        free(componente_auxiliar);
        componente_auxiliar = componente_temporario;
    }

    (*lista)->primeiro = NULL;
    (*lista)->quantidade = 0;
}

void 
le_exibir(lista_encadeada_ordenada* lista){
    if(!lista)
        return;
    componente* item = lista->primeiro;
    while(item != NULL){
        printf("%d ", item->conteudo);
        item = item->proximo;
    }
}

lista_encadeada_ordenada* 
le_inicializar(void){
    lista_encadeada_ordenada* nova_lista = (lista_encadeada_ordenada*) calloc(1, sizeof(lista_encadeada_ordenada));
    return nova_lista;
}

bool
leo_inserir(lista_encadeada_ordenada* lista, Item item){
    if(!lista)
        return false;

    componente* novo_componente = criar_componente(item);
    if(!novo_componente)
        return false;

    if(le_vazia(lista) || lista->primeiro->conteudo >= item){
        novo_componente->proximo = lista->primeiro;
        lista->primeiro = novo_componente;
    } else {
        componente* componente_auxiliar = lista->primeiro;
        while(componente_auxiliar->proximo != NULL && componente_auxiliar->proximo->conteudo < item)
            componente_auxiliar = componente_auxiliar->proximo;
        novo_componente->proximo = componente_auxiliar->proximo;
        componente_auxiliar->proximo = novo_componente;
    }

    lista->quantidade++;
    
    return true;
}

void 
le_liberar(lista_encadeada_ordenada** lista){
    if(!lista || !(*lista))
        return;
    le_esvaziar(lista);
    free(*lista);
    *lista = NULL;
}

bool
le_remover_fim(lista_encadeada_ordenada* lista){
    if(!lista || le_vazia(lista))
        return false;

    componente* componente_anterior = lista->primeiro;
    if(le_tamanho(lista) == 1){
        free(componente_anterior);
        lista->primeiro = NULL;
        lista->quantidade--;
        return true;
    } else {
        componente* componente_final = componente_anterior->proximo;
        while(componente_final->proximo != NULL){
            componente_anterior = componente_final;
            componente_final = componente_final->proximo;
        }
        componente_anterior->proximo = NULL;
        free(componente_final);
    }

    lista->quantidade--;

    return true;
}

bool 
le_remover_inicio(lista_encadeada_ordenada* lista){
    if(!lista || le_vazia(lista))
        return false;

    componente* componente_temporario = lista->primeiro;
    
    lista->primeiro = componente_temporario->proximo;
    free(componente_temporario);
    lista->quantidade--;

    return true;
}

bool 
le_remover_meio(lista_encadeada_ordenada* lista, int posicao){
    if(!lista || le_vazia(lista) || posicao <= 0 || posicao > lista->quantidade)
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
le_tamanho(lista_encadeada_ordenada* lista){
    if(!lista)
        return 0;
    return lista->quantidade;
}

bool 
le_vazia(lista_encadeada_ordenada* lista){
    if(!lista)
        return true;
    return lista->quantidade == 0;
}