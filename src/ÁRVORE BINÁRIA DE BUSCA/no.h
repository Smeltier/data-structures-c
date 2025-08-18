#ifndef NO_H
#define NO_H

#include <stdbool.h>

typedef int Item;
typedef struct no no;

/*
* Descrição: Busca um item na subárvore com raiz no nó fornecido.
* Entrada:   Ponteiro para o nó raiz e o item a ser buscado.
* Saída:     true se o item for encontrado, false caso contrário.
*/
bool buscar_no(no* raiz, Item item);

/*
* Descrição: Cria um novo nó com o item fornecido.
* Entrada:   Item a ser armazenado.
* Saída:     Ponteiro para o novo nó criado.
*/
no* criar_no(Item conteudo);

/*
* Descrição: Exibe em ordem os conteúdos da subárvore com raiz no nó fornecido.
* Entrada:   Ponteiro para o nó raiz.
* Saída:     Nenhuma.
*/
void exibir_no(no* raiz);

/*
* Descrição: Insere um item na subárvore com raiz no nó fornecido.
* Entrada:   Ponteiro para o nó raiz e o item a ser inserido.
* Saída:     Ponteiro para a nova raiz da subárvore.
*/
no* inserir_no(no* raiz, Item item);

/*
* Descrição: Libera recursivamente todos os nós a partir do nó fornecido.
* Entrada:   Ponteiro para o nó raiz da subárvore a ser liberada.
* Saída:     Nenhuma.
*/
void liberar_nos(no* raiz);

/*
* Descrição: Retorna o nó com o menor valor na subárvore fornecida.
* Entrada:   Ponteiro para o nó raiz da subárvore.
* Saída:     Ponteiro para o nó com o menor valor.
*/
no* melhor_no(no* raiz);

/*
* Descrição: Remove um item da subárvore com raiz no nó fornecido.
* Entrada:   Ponteiro para o nó raiz e o item a ser removido.
* Saída:     Ponteiro para a nova raiz da subárvore.
*/
no* remover_no(no* raiz, Item item);

#endif // NO_H