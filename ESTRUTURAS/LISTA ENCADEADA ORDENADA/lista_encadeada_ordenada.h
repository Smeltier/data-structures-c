#ifndef LISTA_ENCADEADA_ORDENADA_H
#define LISTA_ENCADEADA_ORDENADA_H

#include <stdbool.h>

typedef struct lista_encadeada_ordenada lista_encadeada_ordenada;
typedef int Item;

/*
 * Descrição:  Busca um item dentro da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      Retorna a posição do item na lista; caso não encontre, retorna zero.
 */
Item 
le_buscar(lista_encadeada_ordenada* lista, const Item elemento);

/*
 * Descrição:  Esvazia a lista.
 * Entrada:    A referência para o ponteiro da lista.
 * Saída:      Nenhuma.
 */
void 
le_esvaziar(lista_encadeada_ordenada** lista);

/*
 * Descrição:  Exibe os itens presente na lista.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void 
le_exibir(lista_encadeada_ordenada* lista);

/*
 * Descrição:  Inicializa uma lista.
 * Entrada:    Nenhuma.
 * Saída:      Um ponteiro para a nova lista.
 */
lista_encadeada_ordenada* 
le_inicializar(void);

/*
 * Descrição:  Insere um novo item de forma ordenada na lista.
 * Entrada:    Uma lista e um item.
 * Saída:      True caso consiga inserir corretamente; False caso contrário.
 */
bool
leo_inserir(lista_encadeada_ordenada* lista, Item item);

/*
 * Descrição:  Libera a memoria alocada para a lista.
 * Entrada:    A referência para o ponteiro da lista.
 * Saída:      Nenhuma.
 */
void 
le_liberar(lista_encadeada_ordenada** lista);

/*
 * Descrição:  Remove o item do final da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool
le_remover_fim(lista_encadeada_ordenada* lista);

/*
 * Descrição:  Remove o item do início da lista.
 * Entrada:    Uma lista.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
le_remover_inicio(lista_encadeada_ordenada* lista);

/*
 * Descrição:  Remove o item de uma posição específica da lista.
 * Entrada:    Uma lista e a posição do item.
 * Saída:      true se o item foi removido corretamente; caso contrário, false.
 */
bool 
le_remover_meio(lista_encadeada_ordenada* lista, int posicao);

/*
 * Descrição:  Retorna o tamanho atual da lista.
 * Entrada:    Uma lista.
 * Saída:      Quantidade de itens atualmente na lista.
 */
int
le_tamanho(lista_encadeada_ordenada* lista);

/*
 * Descrição:  Verifica se a lista está vazia.
 * Entrada:    Uma lista.
 * Saída:      true se a lista estiver vazia; caso contrário, false.
 */
bool 
le_vazia(lista_encadeada_ordenada* lista);

#endif // LISTA_ENCADEADA_H