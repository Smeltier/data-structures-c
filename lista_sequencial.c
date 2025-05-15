#include "lista_sequencial.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista_sequencial {
    Item* dados;
    int cap, qtde;
};

int buscar(lista_sequencial* lista, Item item){
    if(vazia(lista))
        return 0;
    for(int i = 0; i < lista->qtde; i++)
        if(lista->dados[i] == item)
            return i + 1;
    return 0;
}

int capacidade(lista_sequencial* lista){
    return lista->cap;
}

bool cheia(lista_sequencial* lista){
    return lista->qtde == lista->cap;
}

void exibir(lista_sequencial* lista){
    for(int i = 0; i < lista->qtde; i++)
        printf("%d ", lista->dados[i]);
}

lista_sequencial* inicializar(int capacidade){
    lista_sequencial* lista = (lista_sequencial*) malloc(sizeof(lista_sequencial));
    if(!lista){
        return NULL;
    }
    lista->dados = (Item*) malloc(sizeof(Item) * capacidade);
    if(!lista->dados){
        return NULL;
    }
    lista->cap = capacidade;
    lista->qtde = 0;
    return lista;
}

bool inserir_fim(lista_sequencial* lista, Item item){
    if(cheia(lista))
        return false;
    lista->dados[lista->qtde++] = item;
    return true;
}

bool inserir_inicio(lista_sequencial* lista, Item item){
    if(cheia(lista))
        return false;
    for(int i = lista->qtde; i > 0; i--)
        lista->dados[i] = lista->dados[i - 1];
    lista->dados[0] = item;
    (lista->qtde)++;
    return true;
}

bool inserir_meio(lista_sequencial* lista, Item item, int posicao){
    if(cheia(lista))
        return false;
    for(int i = lista->qtde; i >= posicao; i--)
        lista->dados[i] = lista->dados[i - 1];
    lista->dados[posicao - 1] = item;
    (lista->qtde)++;
    return true;
}

void liberar(lista_sequencial** lista){
    if(!lista)
        return;
    free((*lista)->dados);
    free(*lista);
    *lista = NULL;
}

void limpar(lista_sequencial* lista){
    lista->qtde = 0;
}

bool remover_fim(lista_sequencial* lista){
    if(vazia(lista))
        return false;
    lista->qtde--;
    return true;
}

bool remover_inicio(lista_sequencial* lista){
    if(vazia(lista))
        return false;
    for(int i = 0; i < lista->qtde - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->qtde--;
    return true;
}

bool remover_meio(lista_sequencial* lista, int posicao){
    if(vazia(lista) || posicao < 1 || posicao > lista->qtde)
        return false;
    for(int i = posicao - 1; i < lista->qtde - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->qtde--;
    return true;
}

int tamanho(lista_sequencial* lista){
    return lista->qtde;
}

bool vazia(lista_sequencial* lista){
    return lista->qtde == 0;
}
