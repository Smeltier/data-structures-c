#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include <stdbool.h>

typedef struct arvore_binaria_busca arvore_binaria_busca;
typedef int Item; 

arvore_binaria_busca* aab_inicializar();

void aab_exibir(arvore_binaria_busca* arvore);

void aab_inserir(arvore_binaria_busca* arvore, Item item);

int aab_quantidade_nos(arvore_binaria_busca* arvore);

void aab_esvaziar(arvore_binaria_busca* arvore);

void aab_liberar(arvore_binaria_busca** arvore);

#endif // ARVORE_BINARIA_BUSCA_H