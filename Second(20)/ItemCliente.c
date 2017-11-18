#include "ItemCliente.h"

Ref ref_cliente(link_cl cliente)
{
  /*recebe um apontador para um cliente e devolve a sua referencia*/
  return cliente->ref;
}


link_cl cria_cliente(Ref referencia)
{
  /*cria um cliente com a referencia dada e os outros valores a 0*/
  link_cl cliente = NULL;
  cliente = malloc(sizeof(Cliente));
  cliente->ref = referencia;
  cliente->num_e = 0;
  cliente->num_b = 0;
  cliente->valor_e = 0;
  cliente->valor_b = 0;
  return cliente;
}


link_cl actualiza_cliente(link_cl ap_cliente, char tipo, int valor, int sinal)
{
  /*recebe um apontador para um cliente, um caracter ('e'-emissor ou 'b'-beneficiario), o valor
  do cheque, e 1 (quando se adiciona um cheque) ou -1 (quando se processa um cheque) e atualiza
   a informacao do cliente*/
  if (tipo=='e') {
    ap_cliente->num_e += sinal*1;
    ap_cliente->valor_e += sinal*valor;
  }
  else if (tipo=='b') {
    ap_cliente->num_b += sinal*1;
    ap_cliente->valor_b += sinal*valor;
  }
  return ap_cliente;
}


int compara_clientes(link_cl item1, link_cl item2)
{
  /*compara a referencia de dois cheques*/
  return ref_cliente(item1) - ref_cliente(item2);
}


void info_cliente(link_cl item)
{
  /*recebe um apontador para um cliente e imprime a sua informacao*/
  printf("%li %d %d %d %d\n", item->ref, item->num_e, item->valor_e, item->num_b, item->valor_b);
}

void apaga_cliente(link_cl item)
{
  free(item);
}
