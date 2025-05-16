#ifndef FILA_SEQUENCIAL_H
#define FILA_SEQUENCIAL_H

#include <stdbool.h>

typedef struct fila_sequencial fila_sequencial;
typedef int Item;

int fs_capacidade(fila_sequencial* fila);

fila_sequencial* fs_inicializar(int tamanho);

#endif