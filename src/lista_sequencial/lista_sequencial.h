#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>
#include <stddef.h>  // para size_t

typedef struct LISTA_SEQUENCIAL LISTA_SEQUENCIAL;

/*
 * Descrição:  Busca um item dentro da lista usando função de comparação.
 * Entrada:    Uma lista, o item e uma função de comparação.
 * Saída:      Retorna a posição do item na lista (1-based); caso não encontre, retorna zero.
 */
int ls_buscar(LISTA_SEQUENCIAL* lista, const void* item, int (*cmp)(const void*, const void*));

/*
 * Descrição:  Retorna a capacidade total da lista.
 * Entrada:    Uma lista.
 * Saída:      Capacidade máxima da lista.
 */
int ls_capacidade(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Verifica se a lista está cheia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver cheia; caso contrário, false.
 */
bool ls_cheia(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Exibe os conteúdos da lista usando função de callback.
 * Entrada:    Uma lista e uma função para exibir cada elemento.
 * Saída:      Nenhuma.
 */
void ls_exibir(LISTA_SEQUENCIAL* lista, void (*exb)(const void*));

/*
 * Descrição:  Inicializa a lista genérica com capacidade e tamanho de cada elemento.
 * Entrada:    Um inteiro representando a capacidade e o tamanho em bytes de cada elemento.
 * Saída:      Ponteiro para a nova lista inicializada.
 */
LISTA_SEQUENCIAL* ls_inicializar(const int capacidade, const size_t tamanho_item);

/*
 * Descrição:  Insere um item no final da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_fim(LISTA_SEQUENCIAL* lista, const void* item);

/*
 * Descrição:  Insere um item no início da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_inicio(LISTA_SEQUENCIAL* lista, const void* item);

/*
 * Descrição:  Insere um item em uma posição específica da lista.
 * Entrada:    Uma lista, o item e a posição desejada.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_meio(LISTA_SEQUENCIAL* lista, const void* item, const int posicao);

/*
 * Descrição:  Libera a memória alocada para a lista.
 * Entrada:    Endereço do ponteiro da lista.
 * Saída:      Nenhuma.
 */
void ls_liberar(LISTA_SEQUENCIAL** lista);

/*
 * Descrição:  Remove todos os itens da lista sem liberar memória.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void ls_limpar(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Remove o item do final da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_fim(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Remove o item do início da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_inicio(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Remove o item de uma posição específica da lista.
 * Entrada:    Uma lista e a posição do item.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_meio(LISTA_SEQUENCIAL* lista, const int posicao);

/*
 * Descrição:  Retorna o tamanho atual da lista.
 * Entrada:    Uma lista.
 * Saída:      Quantidade de itens atualmente na lista.
 */
int ls_tamanho(LISTA_SEQUENCIAL* lista);

/*
 * Descrição:  Verifica se a lista está vazia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver vazia; caso contrário, false.
 */
bool ls_vazia(LISTA_SEQUENCIAL* lista);

#endif // LISTA_SEQUENCIAL_H