#include "lista_sequencial.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct LISTA_SEQUENCIAL {
    void* dados;
    int capacidade, tamanho;
    size_t tamanho_dados;
};

int ls_buscar(LISTA_SEQUENCIAL* lista, const void* item, int (*cmp)(const void*, const void*)){
    if(!lista) return 0;

    for(int it = 0; it < lista->tamanho; ++it){
        void* elemento = (char*)lista->dados + it * lista->tamanho_dados;
        if(cmp(elemento, item) == 0)
            return it + 1;
    }
    return 0;
}

int ls_capacidade(LISTA_SEQUENCIAL* lista){
    if(!lista) return INT_MIN;
    return lista->capacidade;
}

bool ls_cheia(LISTA_SEQUENCIAL* lista){
    if(!lista) return true;
    return lista->tamanho == lista->capacidade;
}

void ls_exibir(LISTA_SEQUENCIAL* lista, void (*exb)(const void*)){
    if(!lista || !exb) return;
    for(int it = 0; it < lista->tamanho; ++it){
        void* elemento = (char*)lista->dados + it * lista->tamanho_dados;
        exb(elemento);
    }
}

LISTA_SEQUENCIAL* ls_inicializar(const int capacidade, const size_t tamanho_dados){
    LISTA_SEQUENCIAL* nova_lista = (LISTA_SEQUENCIAL*) malloc(sizeof(LISTA_SEQUENCIAL));
    if(!nova_lista){
        return NULL;
    }
    nova_lista->dados = malloc(capacidade * tamanho_dados);
    if(!nova_lista->dados){
        free(nova_lista);
        return NULL;
    }

    nova_lista->capacidade = capacidade;
    nova_lista->tamanho = 0;
    nova_lista->tamanho_dados = tamanho_dados;

    return nova_lista;
}

bool ls_inserir_fim(LISTA_SEQUENCIAL* lista, const void* item){
    if(!lista || ls_cheia(lista))
        return false;

    void* destino = (char*)lista->dados + lista->tamanho * lista->tamanho_dados;
    memcpy(destino, item, lista->tamanho_dados);
    lista->tamanho++;
    
    return true;
}

bool ls_inserir_inicio(LISTA_SEQUENCIAL* lista, const void* item){
    if(!lista || ls_cheia(lista))
        return false;

    memmove((char*)lista->dados + lista->tamanho_dados, lista->dados, lista->tamanho * lista->tamanho_dados);
    memcpy(lista->dados, item, lista->tamanho_dados);
    lista->tamanho++;

    return true;
}

bool ls_inserir_meio(LISTA_SEQUENCIAL* lista, const void* item, const int posicao){
    if(!lista || ls_cheia(lista)) return false;
    if(posicao < 1 || posicao > lista->tamanho + 1) return false;

    void* destino = (char*)lista->dados + (posicao - 1) * lista->tamanho_dados;

    memmove((char*)destino + lista->tamanho_dados, destino, (lista->tamanho - (posicao - 1)) * lista->tamanho_dados);

    memcpy(destino, item, lista->tamanho_dados);

    lista->tamanho++;

    return true;
}

void ls_liberar(LISTA_SEQUENCIAL** lista) {
    if (!lista || !*lista) return;
    free((*lista)->dados);
    free(*lista);
    *lista = NULL;
}

void ls_limpar(LISTA_SEQUENCIAL* lista){
    if(!lista) return;
    lista->tamanho = 0;
}

bool ls_remover_fim(LISTA_SEQUENCIAL* lista){
    if(!lista || ls_vazia(lista)) return false;
    lista->tamanho--;
    return true;
}

bool ls_remover_inicio(LISTA_SEQUENCIAL* lista){
    if(!lista || ls_vazia(lista)) return false;

    memmove(lista->dados, (char*)lista->dados + lista->tamanho_dados, (lista->tamanho - 1) * lista->tamanho_dados);
    lista->tamanho--;

    return true;
}

bool ls_remover_meio(LISTA_SEQUENCIAL* lista, const int posicao){
    if(!lista || ls_vazia(lista)) return false;
    if(posicao < 1 || posicao > lista->tamanho) return false;

    void* origem = (char*)lista->dados + posicao * lista->tamanho_dados;
    void* destino = (char*)lista->dados + (posicao - 1) * lista->tamanho_dados;

    memmove(destino, origem, (lista->tamanho - posicao) * lista->tamanho_dados);

    lista->tamanho--;

    return true;
}

int ls_tamanho(LISTA_SEQUENCIAL* lista){
    if(!lista) return INT_MIN;
    return lista->tamanho;
}

bool ls_vazia(LISTA_SEQUENCIAL* lista){
    if(!lista) return false;
    return lista->tamanho == 0;
}