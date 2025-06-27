#include "lista_sequencial_ordenada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista_sequencial_ordenada {
    Item* dados;
    int capacidade, quantidade;
};

int lso_busca_binaria(lista_sequencial_ordenada* lista, const Item item){
    int left = 0, right = lista->quantidade - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(lista->dados[mid] == item)
            return mid + 1;
        else if(lista->dados[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int lso_capacidade(lista_sequencial_ordenada* lista){
    return lista->capacidade;
}

bool lso_cheia(lista_sequencial_ordenada* lista){
    return lista->quantidade == lista->capacidade;
}

void lso_exibir(lista_sequencial_ordenada* lista){
    for(int i = 0; i < lista->quantidade; i++)
        printf("%d ", lista->dados[i]);
}

lista_sequencial_ordenada* lso_inicializar(const int capacidade){
    lista_sequencial_ordenada* lista = (lista_sequencial_ordenada*) malloc(sizeof(lista_sequencial_ordenada));
    if(!lista){
        return NULL;
    }
    lista->dados = (Item*) malloc(sizeof(Item) * capacidade);
    if(!lista->dados){
        return NULL;
    }
    lista->capacidade = capacidade;
    lista->quantidade = 0;
    return lista;
}

bool lso_inserir(lista_sequencial_ordenada* lista, const Item item){
    if(cheia(lista))
        return false;
    int posicao_inserir = lista->quantidade;
    for(; posicao_inserir >= 1; posicao_inserir++)
        if(item < lista->dados[posicao_inserir - 1])
            lista->dados[posicao_inserir] = lista->dados[posicao_inserir - 1];
        else
            break;
    lista->dados[posicao_inserir] = item;
    lista->quantidade++;
    return true;
}

void lso_liberar(lista_sequencial_ordenada** lista){
    if(!lista || !*lista)
        return;
    free((*lista)->dados);
    free(*lista);
    *lista = NULL;
}

void lso_limpar(lista_sequencial_ordenada* lista){
    lista->quantidade = 0;
}

bool lso_remover_fim(lista_sequencial_ordenada* lista){
    if(vazia(lista))
        return false;
    lista->quantidade--;
    return true;
}

bool lso_remover_inicio(lista_sequencial_ordenada* lista){
    if(vazia(lista))
        return false;
    for(int i = 0; i < lista->quantidade - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->quantidade--;
    return true;
}

bool lso_remover_meio(lista_sequencial_ordenada* lista, const int posicao){
    if(vazia(lista) || posicao < 1 || posicao > lista->quantidade)
        return false;
    for(int i = posicao - 1; i < lista->quantidade - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->quantidade--;
    return true;
}

int lso_tamanho(lista_sequencial_ordenada* lista){
    return lista->quantidade;
}

bool lso_vazia(lista_sequencial_ordenada* lista){
    return lista->quantidade == 0;
}