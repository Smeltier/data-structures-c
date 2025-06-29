#include "heap_binaria.h"
#include <stdlib.h>

enum TipoHeap{
    HEAP_MINIMA,
    HEAP_MAXIMA
};

struct heap_binaria{
    Item* dados;
    int tamanho;
    int capacidade;
    TipoHeap tipo;
};

heap_binaria* heap_inicializar(int capacidade, TipoHeap tipo){
    heap_binaria* nova_heap = (heap_binaria*) malloc(sizeof(heap_binaria));
    if(!nova_heap) return NULL;

    nova_heap->dados = (Item*) malloc(sizeof(Item) * capacidade);
    if(!nova_heap->dados){
        free(nova_heap);
        return NULL;
    }

    nova_heap->capacidade = capacidade;
    nova_heap->tipo = tipo;

    return nova_heap;
}

bool heap_vazia(heap_binaria* heap){
    return !heap || heap->tamanho == 0;
}

int heap_tamanho(heap_binaria* heap){
    if(!heap) return 0;
    return heap->tamanho;
}