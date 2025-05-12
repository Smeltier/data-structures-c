#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>

// INTERFACE DA ESTRUTURA DE DADOS

// DECLARACAO TIPO:

typedef struct lista_sequencial lista_sequencial;
typedef int Item;

// PROTOTIPO DAS OPERAÇÕES:

/*
 * Descrição:  Busca um item dentro da lista
 * Entrada:    Uma lista e o item.
 * Saída:      Retorna a posição do item na lista, caso não encontre, retorna zero.
 */
int buscar(lista_sequencial* lista, Item item);

/*
 * Descrição:  Retorna a capacidade da lista, ou seja, o número máximo de items.
 * Entrada:    Uma lista.
 * Saída:      Capacidade da lista.
 */
int capacidade(lista_sequencial* lista);

/*
 * Descrição:  Se a lista está cheia
 * Entrada:    Uma lista.
 * Saída:      true se a lista está cheia ou false se ela não estiver cheia.
 */
bool cheia(lista_sequencial* lista);

/*
 * Descrição:  Exibe os conteúdos da lista
 * Entrada:    Uma lista.
 * Saída:      Nenhuma.
 */
void exibir(lista_sequencial* lista);

/*
 * Descrição:  Inicializa os items da lista.
 * Entrada:    Uma lisra.
 * Saída:      Nenhuma.
 */
lista_sequencial* inicializar(int capacidade);

/*
 * Descrição:  Se a lista está cheia
 * Entrada:    Uma lista.
 * Saída:      true se item foi inserido corretamente ou false se não foi inserido corretamente.
 */
bool inserir_inicio(lista_sequencial* lista, Item item);

bool inserir_fim(lista_sequencial* lista, Item item);

bool inserir_meio(lista_sequencial* lista, Item item, int posicao);

/*
 * Descrição:  Se a lista está cheia
 * Entrada:    Uma lista.
 * Saída:      true se item foi inserido corretamente ou false se não foi inserido corretamente.
 */
bool remover_inicio(lista_sequencial* lista);

/*
 * Descrição:  Se a lista está cheia
 * Entrada:    Uma lista.
 * Saída:      true se item foi inserido corretamente ou false se não foi inserido corretamente.
 */
bool remover_fim(lista_sequencial* lista);

bool remover_meio(lista_sequencial* lista, int posicao);

/*
 * Descrição:  O tamanho da lista
 * Entrada:    Uma lista.
 * Saída:      O tamanho da lista.
 */
int tamanho(lista_sequencial* lista);

/*
 * Descrição:  Se a lista está vazia
 * Entrada:    Uma lista.
 * Saída:      true se a lista está vazia ou false se ela não estiver vazia.
 */
bool vazia(lista_sequencial* lista);



#endif // Lista Sequencial