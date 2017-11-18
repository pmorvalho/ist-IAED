#ifndef ITEMCHEQUE
#define ITEMCHEQUE
#include "ItemCliente.h"
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

/*Cheque - estrutura composta por um inteiro que corresponde ao valor do cheque, a
referencia e dois apontadores para clientes, um para o emissor e outro para o beneficiario*/

typedef struct {
  int valor;
  Ref referencia;
  Cliente *emissor, *beneficiario;
} Cheque;

typedef Cheque Item;

Ref cheque_ref(Cheque);
Ref cheque_valor(Cheque);
int compara_cheques(Cheque, Cheque);
Cheque novo_cheque();
void info_cheque(Cheque);
void actualiza_info(Cheque);

#endif
