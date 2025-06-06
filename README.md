# Estruturas de Dados em C

Este repositório contém implementações completas de algumas estruturas de dados em C. Cada estrutura possui uma interface (arquivo `.h`) bem documentada, padronizada e pronta para uso em aplicações de sistemas, algoritmos ou estudos acadêmicos.

## Estrutura do Projeto

```
.
├── ESTRUTURAS
   ├── FILA SEQUENCIAL
       ├── fila_sequencial.c
       └── fila_sequencial.h
   ├── LISTA ENCADEADA
       ├── lista_encadeada.c
       └── lista_encadeada.h
   ├── LISTA SEQUENCIAL ORDENADA
       ├── lista_sequencial_ordenada.c
       └── lista_sequencial_ordenada.h
   ├── LISTA SEQUENCIAL
       ├── lista_sequencial.c
       └── lista_sequencial.h
   ├── PILHA ENCADEADA
       ├── pilha_encadeada.c
       └── pilha_encadeada.h
   └── PILHA SEQUNCIAL
       ├── pilha_sequencial.c
       └── pilha_sequencial.h
├── LICENSE
└── README.md
```

## Compilação

Compile usando `gcc` ou outro compilador C. Exemplo:

```bash
gcc main.c lista_sequencial.c fila_sequencial.c pilha_sequencial.c -o programa
```

> Certifique-se de incluir os arquivos `.h` no seu código com `#include "lista_sequencial.h"` etc.

## Padrão dos Cabeçalhos

Todos os headers seguem um padrão de documentação com:
- **Descrição** da função
- **Entradas**
- **Saídas**
- Tipos bem definidos (`Item`, ponteiros opacos para as estruturas)

Exemplo:

```c
/*
 * Descrição:  Insere um item no final da lista.
 * Entrada:    Uma lista e o item.
 * Saída:      true se o item foi inserido corretamente; caso contrário, false.
 */
bool ls_inserir_fim(lista_sequencial* lista, const Item item);
```

## Requisitos

- Conhecimento básico de C
- Entendimento de alocação dinâmica
- `gcc` ou outro compilador compatível com C99 ou superior

## Autor

Gabriel Gonçalves de Castro  
Estudante de Engenharia de Computação - CEFET-MG  

- [LinkedIn](https://www.linkedin.com/in/gabriel-gon%C3%A7alves-534598321/)
- [Lattes](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?metodo=apresentar&id=K1547984P6)
- [YouTube](https://www.youtube.com/@GabrielSmeltier)

## Licença

Este projeto está licenciado sob a Licença MIT. Sinta-se livre para usar, modificar e distribuir com os devidos créditos.

---
