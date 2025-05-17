#ifndef FILA_SEQUENCIAL_H
#define FILA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct fila_sequencial fila_sequencial;
typedef int Item;

Item fs_back(fila_sequencial* fila);

int fs_capacidade(fila_sequencial* fila);

bool fs_cheia(fila_sequencial* fila);

Item fs_front(fila_sequencial* fila);

fila_sequencial* fs_inicializar(const int tamanho);

void fs_liberar(fila_sequencial** fila);

bool fs_pop(fila_sequencial* fila);

bool fs_push(fila_sequencial* fila, const Item item);

int fs_tamanho(fila_sequencial* fila);

bool fs_vazia(fila_sequencial* fila);

#endif