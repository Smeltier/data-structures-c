#include "lista_sequencial.h"
#include <stdio.h>
#include <stdlib.h>

struct lista_sequencial {
    Item* dados;
    int capacidade, quantidade;
};

int 
ls_buscar(lista_sequencial* lista, const Item item){
    if(vazia(lista))
        return 0;
    for(int i = 0; i < lista->quantidade; i++)
        if(lista->dados[i] == item)
            return i + 1;
    return 0;
}

int 
ls_capacidade(lista_sequencial* lista){
    return lista->capacidade;
}

bool 
ls_cheia(lista_sequencial* lista){
    return lista->quantidade == lista->capacidade;
}

void 
ls_exibir(lista_sequencial* lista){
    for(int i = 0; i < lista->quantidade; i++)
        printf("%d ", lista->dados[i]);
}

lista_sequencial* 
ls_inicializar(const int capacidade){
    lista_sequencial* lista = (lista_sequencial*) malloc(sizeof(lista_sequencial));
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

bool 
ls_inserir_fim(lista_sequencial* lista, const Item item){
    if(cheia(lista))
        return false;
    lista->dados[lista->quantidade++] = item;
    return true;
}

bool 
ls_inserir_inicio(lista_sequencial* lista, const Item item){
    if(cheia(lista))
        return false;
    for(int i = lista->quantidade; i > 0; i--)
        lista->dados[i] = lista->dados[i - 1];
    lista->dados[0] = item;
    (lista->quantidade)++;
    return true;
}

bool 
ls_inserir_meio(lista_sequencial* lista, const Item item, const int posicao){
    if(cheia(lista))
        return false;
    for(int i = lista->quantidade; i >= posicao; i--)
        lista->dados[i] = lista->dados[i - 1];
    lista->dados[posicao - 1] = item;
    (lista->quantidade)++;
    return true;
}

void 
ls_liberar(lista_sequencial** lista){
    if(!lista || !*lista)
        return;
    free((*lista)->dados);
    free(*lista);
    *lista = NULL;
}

void 
ls_limpar(lista_sequencial* lista){
    lista->quantidade = 0;
}

bool 
ls_remover_fim(lista_sequencial* lista){
    if(vazia(lista))
        return false;
    lista->quantidade--;
    return true;
}

bool 
ls_remover_inicio(lista_sequencial* lista){
    if(vazia(lista))
        return false;
    for(int i = 0; i < lista->quantidade - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->quantidade--;
    return true;
}

bool 
ls_remover_meio(lista_sequencial* lista, const int posicao){
    if(vazia(lista) || posicao < 1 || posicao > lista->quantidade)
        return false;
    for(int i = posicao - 1; i < lista->quantidade - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->quantidade--;
    return true;
}

int 
ls_tamanho(lista_sequencial* lista){
    return lista->quantidade;
}

bool 
ls_vazia(lista_sequencial* lista){
    return lista->quantidade == 0;
}