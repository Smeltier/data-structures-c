#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include <stdbool.h>

typedef struct arvore_binaria_busca arvore_binaria_busca;
typedef int Item; 

bool abb_buscar(arvore_binaria_busca* arvore, Item item);

void abb_esvaziar(arvore_binaria_busca* arvore);

void abb_exibir(arvore_binaria_busca* arvore);

arvore_binaria_busca* abb_inicializar();

void abb_inserir(arvore_binaria_busca* arvore, Item item);

void abb_liberar(arvore_binaria_busca** arvore);

int abb_quantidade_nos(arvore_binaria_busca* arvore);

void abb_remover(arvore_binaria_busca* arvore, Item item);

bool abb_vazia(arvore_binaria_busca* arvore);

#endif // ARVORE_BINARIA_BUSCA_H