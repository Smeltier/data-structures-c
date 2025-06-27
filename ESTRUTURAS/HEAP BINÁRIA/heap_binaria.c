#include "heap_binaria.h"
#include <stdlib.h>

struct heap_binaria{
    Item* dados;
    int tamanho;
    int capacidade;
};

heap_binaria* inicializar(int capacidade){
    heap_binaria* nova_heap = (heap_binaria*) malloc(sizeof(heap_binaria));
    if(!nova_heap) return NULL;

    nova_heap->dados = (Item*) malloc(sizeof(Item) * capacidade);
    if(!nova_heap->dados){
        free(nova_heap);
        return NULL;
    }

    nova_heap->capacidade = capacidade;

    return nova_heap;
}

