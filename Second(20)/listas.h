#ifndef LISTAS
#define LISTAS
#include <stdio.h>
#include <stdlib.h>
#include "ItemCheque.h"

/*Node - estrutura composta por um cliente e um apontador para o Node seguinte*/

struct Node {
	Cheque item;
	struct Node *next;
};

typedef struct Node Node;
typedef Node *link;

void insere_cauda();
link pesquisa_node(Ref);
Item devolve_item(Ref);
void remove_node(link);
void apaga_lista();
int lista_vazia();
link devolve_inicio();

#endif
