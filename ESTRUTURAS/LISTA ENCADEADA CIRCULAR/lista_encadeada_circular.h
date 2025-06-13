#ifndef LISTA_ENCADEADA_CIRCULAR_H
#define LISTA_ENCADEADA_CIRCULAR_H

#include <stdbool.h>

typedef struct lista_encadeada_circular lista_encadeada_circular;
typedef int Item;

/*
* Descrição: Inicializa uma nova lista encadeada circular vazia.
* Entrada:   Nenhuma.
* Saída:     Ponteiro para a nova lista.
*/
lista_encadeada_circular*
lsc_inicializar();

/*
* Descrição: Insere um elemento no final da lista circular.
* Entrada:   Ponteiro para a lista e o elemento a inserir.
* Saída:     true se a inserção for bem sucedida, false caso contrário.
*/
bool
lsc_inserir(lista_encadeada_circular* lista, Item item);

/*
* Descrição: Remove o elemento do início da lista circular.
* Entrada:   Ponteiro para a lista.
* Saída:     true se a remoção for bem sucedida, false caso contrário.
*/
bool
lsc_remover(lista_encadeada_circular* lista);

/*
* Descrição: Verifica se a lista circular está vazia.
* Entrada:   Ponteiro para a lista.
* Saída:     true se estiver vazia, false caso contrário.
*/
bool 
lsc_vazia(lista_encadeada_circular* lista);

/*
* Descrição: Retorna a quantidade de elementos na lista circular.
* Entrada:   Ponteiro para a lista.
* Saída:     Número de elementos presentes na lista.
*/
int 
lsc_tamanho(lista_encadeada_circular* lista);

#endif // LISTA_ENCADEADA_CIRCULAR_H
