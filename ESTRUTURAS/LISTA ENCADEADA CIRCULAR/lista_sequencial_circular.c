#include "lista_sequencial_circular.h"
#include <stdlib.h>
#include <stdio.h>

struct lista_sequencial_circular{
    Item* dados;
    int inicio, fim;
    int capacidade;
};

void
lsc_exibir(lista_sequencial_circular* lista){
    if(!lista || lsc_vazia(lista))
        return;

    for (int i = lista->inicio; i <= lsc_tamanho(lista); i++){
        printf("%d ", lista->dados[i]);
        if(i == lista->capacidade)
            i = 0;
    }
}

lista_sequencial_circular*
lsc_inicializar(int tamanho){
    lista_sequencial_circular* nova_lista = (lista_sequencial_circular*) malloc(sizeof(lista_sequencial_circular));
    if(!nova_lista)
        return NULL;

    nova_lista->dados = (Item*) malloc(sizeof(lista_sequencial_circular));
    if(!nova_lista->dados){
        free(nova_lista);
        return NULL;
    }

    nova_lista->inicio = -1;
    nova_lista->fim = 0;
    nova_lista->capacidade = tamanho;

    return nova_lista;
}

bool
lsc_inserir(lista_sequencial_circular* lista, Item item){
    if(!lista)
        return false;

    lista->dados[lista->fim] = item;

    lista->fim++;
    if(lista->fim == lista->capacidade){
        lista->fim = 0;
    }

    return true;
}

bool
lsc_remover(lista_sequencial_circular* lista){
    if(!lista || lsc_vazia(lista))
        return false;

    lista->inicio++;
    if(lista->inicio == lista->capacidade)
        lista->inicio = 0;

    if(lista->inicio == lista->fim){
        lista->inicio = -1;
        lista->fim = 0;
    }

    return true;
}

int 
lsc_tamanho(lista_sequencial_circular* lista){
    if(!lista || lista->inicio == -1)
        return 0;

    if(lista->fim > lista->inicio)
        return lista->fim - lista->inicio;
    else
        return lista->fim - lista->inicio + lista->capacidade;
}

bool
lsc_vazia(lista_sequencial_circular* lista){
    return lsc_tamanho(lista) == 0;
}
