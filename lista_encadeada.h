#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdbool.h>

typedef struct lista_encadeada lista_encadeada;

/*
 * Descrição:  Busca um elemento na lista.
 * Entrada:    Uma lista e o elemento a ser buscado.
 * Saída:      Retorna um ponteiro para o nó com o elemento ou NULL se não for encontrado.
 */
lista_encadeada* buscar(lista_encadeada* lista, int elemento);

/*
 * Descrição:  Inicializa uma nova lista encadeada.
 * Entrada:    Nenhuma.
 * Saída:      Retorna NULL, indicando uma lista vazia.
 */
lista_encadeada* inicializar(void);

/*
 * Descrição:  Insere um novo elemento no início da lista.
 * Entrada:    Uma lista e o elemento a ser inserido.
 * Saída:      Retorna a nova lista com o elemento inserido.
 */
lista_encadeada* inserir(lista_encadeada* lista, int elemento);

/*
 * Descrição:  Libera todos os nós da lista.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void liberar(lista_encadeada* lista);

/*
 * Descrição:  Mostra os elementos da lista no terminal.
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void mostrar(lista_encadeada* lista);

/*
 * Descrição:  Remove um elemento da lista.
 * Entrada:    Uma lista e o elemento a ser removido.
 * Saída:      Retorna a nova lista com o elemento removido.
 */
lista_encadeada* remover(lista_encadeada* lista, int elemento);

/*
 * Descrição:  Verifica se a lista está vazia.
 * Entrada:    Uma lista.
 * Saída:      Retorna true se a lista estiver vazia, false caso contrário.
 */
bool vazia(lista_encadeada* lista);

#endif // LISTA_ENCADEADA_H
