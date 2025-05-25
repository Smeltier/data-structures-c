#ifndef PILHA_SEQUENCIAL_H
#define PILHA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct pilha_sequencial pilha_sequencial;
typedef int Item;

/*
 * Descrição:  Retorna a capacidade total da pilha.
 * Entrada:    Uma pilha.
 * Saída:      Capacidade máxima da pilha.
 */
int 
ps_capacidade(pilha_sequencial* pilha);

/*
 * Descrição:  Verifica se a pilha está cheia.
 * Entrada:    Uma pilha.
 * Saída:      true se a pilha estiver cheia; caso contrário, false.
 */
bool 
ps_cheia(pilha_sequencial* pilha);

/*
 * Descrição:  Inicializa a pilha com capacidade definida.
 * Entrada:    Um inteiro representando a capacidade.
 * Saída:      Ponteiro para a nova pilha inicializada.
 */
pilha_sequencial* 
ps_inicializar(const int tamanho);

/*
 * Descrição:  Libera a memória alocada para a pilha.
 * Entrada:    Endereço do ponteiro da pilha.
 * Saída:      Nenhuma.
 */
void 
ps_liberar(pilha_sequencial** pilha);

/*
 * Descrição:  Remove o item do topo da pilha.
 * Entrada:    Uma pilha.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
ps_pop(pilha_sequencial* pilha);

/*
 * Descrição:  Insere um item no topo da pilha.
 * Entrada:    Uma pilha e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool 
ps_push(pilha_sequencial* pilha, const Item item);

/*
 * Descrição:  Retorna o tamanho atual da pilha.
 * Entrada:    Uma pilha.
 * Saída:      Quantidade de itens atualmente na pilha.
 */
int 
ps_tamanho(pilha_sequencial* pilha);

/*
 * Descrição:  Retorna o item no topo da pilha.
 * Entrada:    Uma pilha.
 * Saída:      Item no topo da pilha.
 */
Item 
ps_top(pilha_sequencial* pilha);

/*
 * Descrição:  Verifica se a pilha está vazia.
 * Entrada:    Uma pilha.
 * Saída:      true se a pilha estiver vazia; caso contrário, false.
 */
bool 
ps_vazia(pilha_sequencial* pilha);

#endif // PILHA_SEQUENCIAL_H