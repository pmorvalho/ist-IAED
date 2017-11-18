#include "listas.h"static link head=NULL;static link tail=NULL;void insere_cauda(Item item){	/*cria um novo node com um novo cheque como item, inserindo-o no fim da lista	(na 'tail')*/	link node;	node = malloc(sizeof(Node));	node->item = item;	node->next = NULL;	if (tail != NULL) /*quando a lista nao esta vazia, o 'tail->next' aponta para										o novo no, para o conectar ao resto da lista*/		tail->next = node;	tail=node;	if (head == NULL) /*quando a lista esta vazia, a 'head' aponta para o mesmo no que a 'tail'*/		head=tail;	return;}link pesquisa_node(Ref ref){	/*percorre a lista, devolvendo, se existir, o no com o cheque que tem como referencia 'ref'*/	link i = NULL;	for (i = head; i != NULL; i = i->next)		if (ref == cheque_ref(i->item))			return i;	return NULL;}Cheque devolve_item(Ref ref){	/*devolve o cheque que tem referencia 'ref', recorrendo a funcao pesquisa_node*/	link i = NULL;	i = pesquisa_node(ref);	return i->item;}void remove_node(link i){	/*recebe um apontador para um no da lista, quando o apontador e NULL, significa que	nao existe o no que se pretende remover, se nao for NULL, percorre a lista para remover o no*/	link aux = NULL;	link prev = NULL;	if (compara_cheques(i->item, head->item) == 0) {	/*remove o no quando o cheque que se pretende remover corresponde a head*/		head = i->next;		if (head == NULL) 															/*caso em que a lista fica vazia*/			tail = head;		free(i);		return;	}	for (aux=head->next, prev = head; aux != tail; prev = aux, aux = aux->next) {		/*percorre a lista e remove o no que se pretende, quando/se o encontra*/		if (compara_cheques(aux->item, i->item) == 0) {			prev->next = i->next;			free(i);			return;		}	}	if (compara_cheques(tail->item, i->item) == 0) {		/*remove o no quando o cheque que se pretende remover corresponde a tail*/		tail = prev;		tail->next = NULL;		free(i);		return;	}}void apaga_lista(){	/*apaga todos os nos que estao na lista e os respectivos cheques*/	link aux = NULL;	while (head != tail) {		aux = head;		head = head->next;		free(aux);	}	head = NULL;	free(tail);}int lista_vazia(){	/*devolve sim se a head aponta para NULL, e nao caso contrario*/	return head == NULL;}link devolve_inicio(){	/*devolve a head*/	return head;}