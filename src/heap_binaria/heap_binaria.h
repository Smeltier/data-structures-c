#ifndef HEAP_BINARIA_H
#define HEAP_BINARIA_H

#include <stdbool.h>
#include <limits.h>

#define ERRO INT_MIN

typedef int Item;
typedef struct heap_binaria heap_binaria;

typedef enum {
    HEAP_MINIMA,
    HEAP_MAXIMA
} tipo_heap;

/*
 * Descrição: Verifica se a heap está cheia.
 * Entrada:   Uma heap.
 * Saída:     true se cheia; caso contrário, false.
 */
bool heap_cheia(heap_binaria* heap);

/*
 * Descrição: Esvazia a heap, mantendo sua capacidade.
 * Entrada:   Uma heap.
 * Saída:     true se a heap foi esvaziada corretamente; caso contrário, false.
 */
bool heap_esvaziar(heap_binaria* heap);

/*
 * Descrição: Exibe os elementos da heap por nível.
 * Entrada:   Uma heap.
 * Saída:     Nenhuma.
 */
void heap_exibir(heap_binaria* heap);

/*
 * Descrição: Retorna a capacidade total da heap.
 * Entrada:   Uma heap.
 * Saída:     Capacidade da heap.
 */
int heap_capacidade(heap_binaria* heap);

/*
 * Descrição: Inicializa uma heap com capacidade e tipo definidos.
 * Entrada:   Capacidade da heap e tipo (min ou max).
 * Saída:     Ponteiro para a nova heap.
 */
heap_binaria* heap_inicializar(int capacidade, tipo_heap tipo);

/*
 * Descrição: Insere um item na heap, mantendo a propriedade da heap.
 * Entrada:   Uma heap e o item.
 * Saída:     true se inserido com sucesso; caso contrário, false.
 */
bool heap_inserir(heap_binaria* heap, Item item);

/*
 * Descrição: Libera a memória alocada para a heap.
 * Entrada:   Endereço do ponteiro da heap.
 * Saída:     Nenhuma.
 */
void heap_liberar(heap_binaria** heap);

/*
 * Descrição: Remove o item do topo da heap.
 * Entrada:   Uma heap.
 * Saída:     O item removido, ou ERRO se falhar.
 */
Item heap_remover(heap_binaria* heap);

/*
 * Descrição: Retorna o número de elementos na heap.
 * Entrada:   Uma heap.
 * Saída:     Tamanho atual da heap.
 */
int heap_tamanho(heap_binaria* heap);

/*
 * Descrição: Retorna o item no topo da heap.
 * Entrada:   Uma heap.
 * Saída:     O item do topo, ou ERRO se vazia.
 */
Item heap_topo(heap_binaria* heap);

/*
 * Descrição: Verifica se a heap está vazia.
 * Entrada:   Uma heap.
 * Saída:     true se vazia; caso contrário, false.
 */
bool heap_vazia(heap_binaria* heap);

#endif // HEAP_BINARIA_H