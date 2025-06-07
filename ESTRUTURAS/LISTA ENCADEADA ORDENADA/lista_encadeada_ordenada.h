#ifndef LISTA_ENCADEADA_ORDENADA_H
#define LISTA_ENCADEADA_ORDENADA_H

#include <stdbool.h>

typedef struct lista_encadeada_ordenada lista_encadeada_ordenada;
typedef int Item;

Item 
le_buscar(lista_encadeada_ordenada* lista, const Item elemento);

void 
le_esvaziar(lista_encadeada_ordenada** lista);

void 
le_exibir(lista_encadeada_ordenada* lista);

lista_encadeada_ordenada* 
le_inicializar(void);

bool
leo_inserir(lista_encadeada_ordenada* lista, Item item);

void 
le_liberar(lista_encadeada_ordenada** lista);

bool
le_remover_fim(lista_encadeada_ordenada* lista);

bool 
le_remover_inicio(lista_encadeada_ordenada* lista);

bool 
le_remover_meio(lista_encadeada_ordenada* lista, int posicao);

int
le_tamanho(lista_encadeada_ordenada* lista);

bool 
le_vazia(lista_encadeada_ordenada* lista);

#endif // LISTA_ENCADEADA_H