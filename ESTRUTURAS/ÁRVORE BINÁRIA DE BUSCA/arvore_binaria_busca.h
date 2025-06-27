#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include <stdbool.h>

typedef struct arvore_binaria_busca arvore_binaria_busca;
typedef int Item;

/*
* Descrição: Verifica se um item está presente na Árvore Binária de Busca.
* Entrada:   Ponteiro para a árvore e o item a ser buscado.
* Saída:     true se o item for encontrado, false caso contrário.
*/
bool abb_buscar(arvore_binaria_busca* arvore, Item item);

/*
* Descrição: Esvazia a árvore, removendo todos os elementos.
* Entrada:   Ponteiro para a árvore.
* Saída:     Nenhuma.
*/
void abb_esvaziar(arvore_binaria_busca* arvore);

/*
* Descrição: Exibe os elementos da árvore em ordem crescente (ordem simétrica).
* Entrada:   Ponteiro para a árvore.
* Saída:     Nenhuma (os elementos são impressos na saída padrão).
*/
void abb_exibir(arvore_binaria_busca* arvore);

/*
* Descrição: Inicializa uma nova Árvore Binária de Busca vazia.
* Entrada:   Nenhuma.
* Saída:     Ponteiro para a nova árvore.
*/
arvore_binaria_busca* abb_inicializar(void);

/*
* Descrição: Insere um item na Árvore Binária de Busca.
* Entrada:   Ponteiro para a árvore e o item a ser inserido.
* Saída:     Nenhuma.
*/
void abb_inserir(arvore_binaria_busca* arvore, Item item);

/*
* Descrição: Libera toda a memória ocupada pela árvore e seus nós.
* Entrada:   Endereço do ponteiro para a árvore.
* Saída:     Nenhuma.
*/
void abb_liberar(arvore_binaria_busca** arvore);

/*
* Descrição: Remove um item da Árvore Binária de Busca, caso ele exista.
* Entrada:   Ponteiro para a árvore e o item a ser removido.
* Saída:     Nenhuma.
*/
void abb_remover(arvore_binaria_busca* arvore, Item item);

/*
* Descrição: Retorna a quantidade de elementos na árvore.
* Entrada:   Ponteiro para a árvore.
* Saída:     Número de elementos presentes na árvore.
*/
int abb_quantidade_nos(arvore_binaria_busca* arvore);

/*
* Descrição: Verifica se a árvore está vazia.
* Entrada:   Ponteiro para a árvore.
* Saída:     true se estiver vazia, false caso contrário.
*/
bool abb_vazia(arvore_binaria_busca* arvore);

#endif // ARVORE_BINARIA_BUSCA_H