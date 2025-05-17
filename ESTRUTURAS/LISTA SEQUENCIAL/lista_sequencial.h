#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct lista_sequencial lista_sequencial;
typedef int Item;

/*
 * Descrição:  Busca um item dentro da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      Retorna a posição do item na lista; caso não encontre, retorna zero.
 */
int ls_buscar(lista_sequencial* lista, const Item item);

/*
 * Descrição:  Retorna a capacidade total da lista.
 * Entrada:    Uma lista.
 * Saída:      Capacidade máxima da lista.
 */
int ls_capacidade(lista_sequencial* lista);

/*
 * Descrição:  Verifica se a lista está cheia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver cheia; caso contrário, false.
 */
bool ls_cheia(lista_sequencial* lista);

/*
 * Descrição:  Exibe os conteúdos da lista.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void ls_exibir(lista_sequencial* lista);

/*
 * Descrição:  Inicializa a lista com capacidade definida.
 * Entrada:    Um inteiro representando a capacidade.
 * Saída:      Ponteiro para a nova lista inicializada.
 */
lista_sequencial* ls_inicializar(const int capacidade);

/*
 * Descrição:  Insere um item no final da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_fim(lista_sequencial* lista, const Item item);

/*
 * Descrição:  Insere um item no início da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_inicio(lista_sequencial* lista, const Item item);

/*
 * Descrição:  Insere um item em uma posição específica da lista.
 * Entrada:    Uma lista, o item e a posição desejada.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_meio(lista_sequencial* lista, const Item item, const int posicao);

/*
 * Descrição:  Libera a memória alocada para a lista.
 * Entrada:    Endereço do ponteiro da lista.
 * Saída:      Nenhuma.
 */
void ls_liberar(lista_sequencial** lista);

/*
 * Descrição:  Remove todos os itens da lista sem liberar memória.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void ls_limpar(lista_sequencial* lista);

/*
 * Descrição:  Remove o item do final da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_fim(lista_sequencial* lista);

/*
 * Descrição:  Remove o item do início da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_inicio(lista_sequencial* lista);

/*
 * Descrição:  Remove o item de uma posição específica da lista.
 * Entrada:    Uma lista e a posição do item.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool ls_remover_meio(lista_sequencial* lista, const int posicao);

/*
 * Descrição:  Retorna o tamanho atual da lista.
 * Entrada:    Uma lista.
 * Saída:      Quantidade de itens atualmente na lista.
 */
int ls_tamanho(lista_sequencial* lista);

/*
 * Descrição:  Verifica se a lista está vazia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver vazia; caso contrário, false.
 */
bool ls_vazia(lista_sequencial* lista);

#endif // LISTA_SEQUENCIAL_H
