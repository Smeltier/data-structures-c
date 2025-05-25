#ifndef FILA_SEQUENCIAL_H
#define FILA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct fila_sequencial fila_sequencial;
typedef int Item;

/*
 * Descrição:  Retorna o item no final da fila.
 * Entrada:    Uma fila.
 * Saída:      Item na última posição da fila.
 */
Item 
fs_back(fila_sequencial* fila);

/*
 * Descrição:  Retorna a capacidade total da fila.
 * Entrada:    Uma fila.
 * Saída:      Capacidade máxima da fila.
 */
int 
fs_capacidade(fila_sequencial* fila);

/*
 * Descrição:  Verifica se a fila está cheia.
 * Entrada:    Uma fila.
 * Saída:      true se a fila estiver cheia; caso contrário, false.
 */
bool 
fs_cheia(fila_sequencial* fila);

/*
 * Descrição:  Retorna o item no início da fila.
 * Entrada:    Uma fila.
 * Saída:      Item na primeira posição da fila.
 */
Item 
fs_frente(fila_sequencial* fila);

/*
 * Descrição:  Inicializa a fila com capacidade definida.
 * Entrada:    Um inteiro representando a capacidade.
 * Saída:      Ponteiro para a nova fila inicializada.
 */
fila_sequencial* 
fs_inicializar(const int tamanho);

/*
 * Descrição:  Libera a memória alocada para a fila.
 * Entrada:    Endereço do ponteiro da fila.
 * Saída:      Nenhuma.
 */
void 
fs_liberar(fila_sequencial** fila);

/*
 * Descrição:  Remove o item do início da fila.
 * Entrada:    Uma fila.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
fs_remover(fila_sequencial* fila);

/*
 * Descrição:  Insere um item no final da fila.
 * Entrada:    Uma fila e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool 
fs_inserir(fila_sequencial* fila, const Item item);

/*
 * Descrição:  Retorna o tamanho atual da fila.
 * Entrada:    Uma fila.
 * Saída:      Quantidade de itens atualmente na fila.
 */
int 
fs_tamanho(fila_sequencial* fila);

/*
 * Descrição:  Verifica se a fila está vazia.
 * Entrada:    Uma fila.
 * Saída:      true se a fila estiver vazia; caso contrário, false.
 */
bool 
fs_vazia(fila_sequencial* fila);

#endif // FILA_SEQUENCIAL_H