#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdbool.h>

typedef struct lista_encadeada lista_encadeada;
typedef int Item;

/*
* Descrição: Busca um elemento na lista encadeada.
* Entrada:   Ponteiro para a lista e o elemento a buscar.
* Saída:     Posição do elemento na lista, ou 0 se não encontrado.
*/
Item 
le_buscar(lista_encadeada* lista, const Item elemento);

/*
* Descrição: Exibe todos os elementos da lista.
* Entrada:   Ponteiro para a lista.
* Saída:     Nenhuma.
*/
void 
le_exibir(lista_encadeada* lista);

/*
* Descrição: Inicializa uma nova lista encadeada vazia.
* Entrada:   Nenhuma.
* Saída:     Ponteiro para a nova lista.
*/
lista_encadeada* 
le_inicializar(void);

/*
* Descrição: Insere um elemento no final da lista.
* Entrada:   Ponteiro para a lista e o elemento a inserir.
* Saída:     true se a inserção for bem sucedida, false caso contrário.
*/
bool 
le_inserir_fim(lista_encadeada* lista, const Item item);

/*
* Descrição: Insere um elemento no início da lista.
* Entrada:   Ponteiro para a lista e o elemento a inserir.
* Saída:     true se a inserção for bem sucedida, false caso contrário.
*/
bool 
le_inserir_inicio(lista_encadeada* lista, const Item elemento);

/*
* Descrição: Insere um elemento em uma posição específica da lista.
* Entrada:   Ponteiro para a lista, elemento e posição desejada (1-based).
* Saída:     true se a inserção for bem sucedida, false caso contrário.
*/
bool 
le_inserir_meio(lista_encadeada* lista, const Item item, const int posicao);

/*
* Descrição: Libera toda a memória ocupada pela lista e seus componentes.
* Entrada:   Endereço do ponteiro para a lista.
* Saída:     Nenhuma.
*/
void 
le_liberar(lista_encadeada** lista);

void
le_ordenar(lista_encadeada* lista);

/*
* Descrição: Remove o elemento do final da lista.
* Entrada:   Ponteiro para a lista.
* Saída:     true se a remoção for bem sucedida, false caso contrário.
*/
bool 
le_remover_fim(lista_encadeada* lista);

/*
* Descrição: Remove o elemento do início da lista.
* Entrada:   Ponteiro para a lista.
* Saída:     true se a remoção for bem sucedida, false caso contrário.
*/
bool 
le_remover_inicio(lista_encadeada* lista);

/*
* Descrição: Remove o elemento de uma posição específica da lista.
* Entrada:   Ponteiro para a lista e a posição do elemento (1-based).
* Saída:     true se a remoção for bem sucedida, false caso contrário.
*/
bool 
le_remover_meio(lista_encadeada* lista, int posicao);

/*
* Descrição: Retorna a quantidade de elementos na lista.
* Entrada:   Ponteiro para a lista.
* Saída:     Número de elementos presentes na lista.
*/
int 
le_tamanho(lista_encadeada* lista);

/*
* Descrição: Verifica se a lista está vazia.
* Entrada:   Ponteiro para a lista.
* Saída:     true se estiver vazia, false caso contrário.
*/
bool 
le_vazia(lista_encadeada* lista);

#endif // LISTA_ENCADEADA_H