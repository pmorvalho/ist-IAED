#include "ItemCheque.h"

Ref cheque_ref(Cheque item)
{
	/*recebe um cheque e devolve a sua referencia*/
	return item.referencia;
}


Ref cheque_valor(Cheque item)
{
	/*recebe um cheque e devolve o seu valor*/
	return item.valor;
}


int compara_cheques(Cheque item1, Cheque item2)
{
	/*compara a referencia de dois cheques*/
	return cheque_ref(item1) - cheque_ref(item2);
}


Cheque novo_cheque()
{
	/*cria um novo cheque com a informacao obtida pelo standard input*/
	Cheque novo;
	Ref e,b;
	scanf(" %d %li %li %li", &novo.valor, &e, &b, &novo.referencia);
	/*obtem um apontador para os clientes atraves da funcao verifica_cliente e atualiza a informacao destes*/
	novo.emissor = actualiza_cliente(verifica_cliente(e), 'e', novo.valor, 1);
	novo.beneficiario = actualiza_cliente(verifica_cliente(b), 'b', novo.valor, 1);
	return novo;
}


void info_cheque(Cheque item)
{
	/*recebe um cheque e imprime a sua informacao*/
	printf("Cheque-info: %li %d %li --> %li\n", item.referencia, item.valor, item.emissor->ref, item.beneficiario->ref);
}


void actualiza_info(Cheque cheque)
{
	/*recebe um cheque e chama a atualiza_cliente para o emissor e para o beneficiario*/
	actualiza_cliente(cheque.emissor, 'e', cheque.valor, -1);
	actualiza_cliente(cheque.beneficiario, 'b', cheque.valor, -1);
}
