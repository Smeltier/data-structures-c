#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdbool.h>

typedef struct lista_sequencial_ordenada lista_sequencial_ordenada;
typedef int Item;

/*
 * Descrição:  Busca um item dentro da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      Retorna a posição do item na lista; caso não encontre, retorna zero.
 */
int 
lso_busca_binaria(lista_sequencial_ordenada* lista, const Item item);

/*
 * Descrição:  Retorna a capacidade total da lista.
 * Entrada:    Uma lista.
 * Saída:      Capacidade máxima da lista.
 */
int 
lso_capacidade(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Verifica se a lista está cheia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver cheia; caso contrário, false.
 */
bool 
lso_cheia(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Exibe os conteúdos da lista.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void 
lso_exibir(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Insere um item de forma ordenada na lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item for inserido corretamente e false caso contrário.
 */
bool 
lso_inserir(lista_sequencial_ordenada* lista, const Item item);

/*
 * Descrição:  Inicializa a lista com capacidade definida.
 * Entrada:    Um inteiro representando a capacidade.
 * Saída:      Ponteiro para a nova lista inicializada.
 */
lista_sequencial_ordenada* 
lso_inicializar(const int capacidade);

/*
 * Descrição:  Libera a memória alocada para a lista.
 * Entrada:    Endereço do ponteiro da lista.
 * Saída:      Nenhuma.
 */
void 
lso_liberar(lista_sequencial_ordenada** lista);

/*
 * Descrição:  Remove todos os itens da lista sem liberar memória.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void 
lso_limpar(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Remove o item do final da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
lso_remover_fim(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Remove o item do início da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
lso_remover_inicio(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Remove o item de uma posição específica da lista.
 * Entrada:    Uma lista e a posição do item.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
lso_remover_meio(lista_sequencial_ordenada* lista, const int posicao);

/*
 * Descrição:  Retorna o tamanho atual da lista.
 * Entrada:    Uma lista.
 * Saída:      Quantidade de itens atualmente na lista.
 */
int 
lso_tamanho(lista_sequencial_ordenada* lista);

/*
 * Descrição:  Verifica se a lista está vazia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver vazia; caso contrário, false.
 */
bool 
lso_vazia(lista_sequencial_ordenada* lista);

#endif // LISTA_SEQUENCIAL_ORDENADA_H
