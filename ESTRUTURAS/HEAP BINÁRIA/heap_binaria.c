#include "heap_binaria.h"
#include <stdlib.h>
#include <stdio.h>

struct heap_binaria{
    Item* dados;
    unsigned tamanho;
    unsigned capacidade;
    tipo_heap tipo;
};

static int indice_filho_direito(heap_binaria* heap, int indice_pai);
static int indice_filho_esquerdo(heap_binaria* heap, int indice_pai);
static int indice_pai(heap_binaria* heap, int indice);
static void inserir_fim(heap_binaria* heap, Item item);
static void inserir_max(heap_binaria* heap);
static void inserir_min(heap_binaria* heap);
static void max_heapfy(heap_binaria* heap, int indice_pai);
static void min_heapfy(heap_binaria* heap, int indice_pai);
static void trocar_valores(heap_binaria* heap, int valor_1, int valor_2);

static int indice_filho_direito(heap_binaria* heap, int indice_pai){
    int indice_filho = 2 * indice_pai + 2;
    if(indice_filho >= heap->tamanho)
        return ERRO;
    return indice_filho;
}

static int indice_filho_esquerdo(heap_binaria* heap, int indice_pai){
    int indice_filho = 2 * indice_pai + 1;
    if(indice_filho >= heap->tamanho)
        return ERRO;
    return indice_filho;
}

static int indice_pai(heap_binaria* heap, int indice){
    if(indice <= 0) 
        return ERRO;
    return (indice - 1) / 2;
}

static void inserir_fim(heap_binaria* heap, Item item){
    heap->dados[heap->tamanho] = item;
    heap->tamanho++;
}

static void inserir_max(heap_binaria* heap){
    int filho = heap->tamanho - 1,
        pai = indice_pai(heap, filho);

    while(pai >= 0 && heap->dados[filho] > heap->dados[pai]){
        trocar_valores(heap, filho, pai);
        filho = pai;
        pai = indice_pai(heap, filho);
    }
}

static void inserir_min(heap_binaria* heap){
    int filho = heap->tamanho - 1,
        pai = indice_pai(heap, filho);

    while(pai >= 0 && heap->dados[filho] < heap->dados[pai]){
        trocar_valores(heap, filho, pai);
        filho = pai;
        pai = indice_pai(heap, filho);
    }
}

static void max_heapfy(heap_binaria* heap, int pai){
    if(!heap || pai < 0 || pai >= heap->tamanho)
        return;
    
    int filho_esquerdo = indice_filho_esquerdo(heap, pai),
        filho_direito = indice_filho_direito(heap, pai);
    
    if(filho_esquerdo == ERRO)
        return;

    while((filho_esquerdo != ERRO && heap->dados[pai] < heap->dados[filho_esquerdo]) || 
          (filho_direito != ERRO && heap->dados[pai] < heap->dados[filho_direito])) {

        if(filho_direito == ERRO){
            trocar_valores(heap, pai, filho_esquerdo);
            return;
        }
        else if(heap->dados[filho_esquerdo] >= heap->dados[filho_direito]){
            trocar_valores(heap, pai, filho_esquerdo);
            pai = filho_esquerdo;
        }
        else{
            trocar_valores(heap, pai, filho_direito);
            pai = filho_direito;
        }

        filho_esquerdo = indice_filho_esquerdo(heap, pai);
        filho_direito = indice_filho_direito(heap, pai);
    }
}

static void min_heapfy(heap_binaria* heap, int pai){
    if(!heap || pai < 0 || pai >= heap->tamanho)
        return;
    
    int filho_esquerdo = indice_filho_esquerdo(heap, pai),
        filho_direito = indice_filho_direito(heap, pai);
    
    if(filho_esquerdo == ERRO)
        return;

    while((filho_esquerdo != ERRO && heap->dados[pai] > heap->dados[filho_esquerdo]) || 
          (filho_direito != ERRO && heap->dados[pai] > heap->dados[filho_direito])) {

        if(filho_direito == ERRO){
            trocar_valores(heap, pai, filho_esquerdo);
            return;
        }
        else if(heap->dados[filho_esquerdo] <= heap->dados[filho_direito]){
            trocar_valores(heap, pai, filho_esquerdo);
            pai = filho_esquerdo;
        }
        else{
            trocar_valores(heap, pai, filho_direito);
            pai = filho_direito;
        }

        filho_esquerdo = indice_filho_esquerdo(heap, pai);
        filho_direito = indice_filho_direito(heap, pai);
    }
}

static void trocar_valores(heap_binaria* heap, int valor_1, int valor_2){
    int auxiliar = heap->dados[valor_1];
    heap->dados[valor_1] = heap->dados[valor_2];
    heap->dados[valor_2] = auxiliar;
}

bool heap_cheia(heap_binaria* heap){
    if(!heap) return false;
    return heap->tamanho == heap->capacidade;
}

bool heap_esvaziar(heap_binaria* heap){
    if(!heap)
        return false;

    heap->tamanho = 0;

    return true;
}

void heap_exibir(heap_binaria* heap){
    if(!heap || heap_vazia(heap))
        return;

    int idx = 0, 
        quantidade_elementos = 1;

    while(idx < heap->tamanho){
        for(int j = 0; j < quantidade_elementos && idx < heap->tamanho; ++j, ++idx)
            printf("%d ", heap->dados[idx]);
        printf("\n");
        quantidade_elementos *= 2;
    }
}

heap_binaria* heap_inicializar(int capacidade, tipo_heap tipo){
    heap_binaria* nova_heap = (heap_binaria*) malloc(sizeof(heap_binaria));
    if(!nova_heap) return NULL;

    nova_heap->dados = (Item*) malloc(sizeof(Item) * capacidade);
    if(!nova_heap->dados){
        free(nova_heap);
        return NULL;
    }

    nova_heap->capacidade = capacidade;
    nova_heap->tipo = tipo;
    nova_heap->tamanho = 0;

    return nova_heap;
}

bool heap_inserir(heap_binaria* heap, Item item){
    if(heap_cheia(heap))
        return false;
    
    inserir_fim(heap, item);

    if(heap->tipo == HEAP_MAXIMA)
        inserir_max(heap);
    else 
        inserir_min(heap);

    return true;
}

void heap_liberar(heap_binaria** heap){
    if(!heap) return;
    free((*heap)->dados);
    free(*heap);
    *heap = NULL;
}

int heap_capacidade(heap_binaria* heap){
    if(!heap) return 0;
    return heap->capacidade;
}

Item heap_remover(heap_binaria* heap){
    if(!heap || heap_vazia(heap))
        return ERRO;

    int valor_retorno = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;

    if(heap->tipo == HEAP_MAXIMA)
        max_heapfy(heap, 0);
    else
        min_heapfy(heap, 0);

    return valor_retorno;
}

int heap_tamanho(heap_binaria* heap){
    if(!heap) return 0;
    return heap->tamanho;
}

Item heap_topo(heap_binaria* heap){
    if(!heap || heap_vazia(heap))
        return ERRO;
    return heap->dados[0];
}

bool heap_vazia(heap_binaria* heap){
    return !heap || heap->tamanho == 0;
}