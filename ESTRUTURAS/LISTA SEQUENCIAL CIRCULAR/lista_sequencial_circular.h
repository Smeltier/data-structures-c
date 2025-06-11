#ifndef LISTA_SEQUENCIAL_CIRCULAR_H
#define LISTA_SEQUENCIAL_CIRCULAR_H

#include <stdbool.h>

typedef int Item;
typedef struct lista_sequencial_circular lista_sequencial_circular;

/*
 * Descrição:  Exibe os conteúdos da lista circular.
 * Entrada:    Uma lista circular.
 * Saída:      Nenhuma.
 */
void 
lsc_exibir(lista_sequencial_circular* lista);

/*
 * Descrição:  Inicializa a lista circular com capacidade definida.
 * Entrada:    Um inteiro representando a capacidade.
 * Saída:      Ponteiro para a nova lista circular inicializada.
 */
lista_sequencial_circular* 
lsc_inicializar(int tamanho);

/*
 * Descrição:  Insere um item no final da lista circular.
 * Entrada:    Uma lista circular e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool 
lsc_inserir(lista_sequencial_circular* lista, Item item);

/*
 * Descrição:  Remove o item do início da lista circular.
 * Entrada:    Uma lista circular.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
lsc_remover(lista_sequencial_circular* lista);

/*
 * Descrição:  Retorna o tamanho atual da lista circular.
 * Entrada:    Uma lista circular.
 * Saída:      Quantidade de itens atualmente na lista.
 */
int 
lsc_tamanho(lista_sequencial_circular* lista);

/*
 * Descrição:  Verifica se a lista circular está vazia.
 * Entrada:    Uma lista circular.
 * Saída:      true se a lista estiver vazia; caso contrário, false.
 */
bool 
lsc_vazia(lista_sequencial_circular* lista);

#endif // LISTA_SEQUENCIAL_CIRCULAR_H
