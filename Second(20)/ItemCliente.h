#ifndef ITEMCLIENTE
#define ITEMCLIENTE
#include <stdlib.h>
#include <stdio.h>

/*Cliente - estrutura composta por uma referencia, numero de cheques no qual e beneficiario,
numero de cheques no qual e emissor, valor dos cheques no qual e beneficiario e valor dos
cheques no qual e emissor*/

typedef long int Ref;

typedef struct {
	Ref ref;
	int num_e, num_b;
	int valor_e, valor_b;
} Cliente;

typedef Cliente* link_cl;


Ref ref_cliente(link_cl);
link_cl cria_cliente(Ref);
link_cl actualiza_cliente(link_cl, char, int, int);
int compara_clientes(link_cl, link_cl);
void info_cliente(link_cl);
void apaga_cliente(link_cl);


#endif
