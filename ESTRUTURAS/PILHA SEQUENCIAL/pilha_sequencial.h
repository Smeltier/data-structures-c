#ifndef PILHA_SEQUENCIAL_H
#define PILHA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct pilha_sequencial pilha_sequencial;
typedef int Item;

int ps_capacidade(pilha_sequencial* pilha);

bool ps_cheia(pilha_sequencial* pilha);

pilha_sequencial* ps_inicializar(const int tamanho);

bool ps_pop(pilha_sequencial* pilha);

bool ps_push(pilha_sequencial* pilha, const Item item);

int ps_tamanho(pilha_sequencial* pilha);

Item ps_top(pilha_sequencial* pilha);

bool ps_vazia(pilha_sequencial* pilha);

#endif