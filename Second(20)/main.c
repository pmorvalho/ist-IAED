#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemCheque.h"
#include "ItemCliente.h"
#include "listas.h"
#include "avl.h"

/* Segundo projecto de IAED
  Grupo: al010
  81151 Pedro Orvalho
  81365 Ana Leitao
  81647 Manuel Galamba*/


static int n_cheques = 0; /*variavel que guarda o numero de cheques por processar*/
static int v_cheques = 0; /*variavel que guarda o valor dos cheques por processar*/


int main()
{
  long int ref;
  char command[12];
  Cheque cheque;
  link node;
  scanf("%s", command);
  while (1) { /*ciclo while que decorre ate ser executado o comando 'sair'*/
    if (strcmp(command, "cheque") == 0){
      /*cria um novo cheque e coloca-o na lista*/
      cheque=novo_cheque();
      insere_cauda(cheque);
      n_cheques++;             /*incremente o numero de cheques e o valor destes*/
      v_cheques += cheque_valor(cheque);
    }
    else if (strcmp(command, "processa") == 0){
      /*processa o cheque posto ha mais tempo na lista*/
      if (!(lista_vazia())){  /*se a lista nao estiver vazia, retira um cheque
                              ao numero deste e o seu respectivo valor*/
        cheque = (devolve_inicio()->item);
        n_cheques--;
        v_cheques -= cheque_valor(cheque);
        actualiza_info(cheque);
	      remove_node(devolve_inicio());
      }
      else
		    printf("Nothing to process\n");
    }
    else if (strcmp(command, "processaR") == 0) {
      /*processa o cheque de referencia 'ref'*/
      scanf(" %li", &ref);
      node = pesquisa_node(ref);
      if (node != NULL) {
        cheque = node->item;
        n_cheques--;
    	  v_cheques -= cheque_valor(cheque);
        actualiza_info(cheque);
        remove_node(node);
      }
      else
        printf("Cheque %li does not exist\n", ref);
    }
    else if (strcmp(command, "infocheque") == 0){
      /*imprime a informacao do cheque de referencia 'ref'*/
      scanf(" %li", &ref);
      info_cheque(devolve_item(ref));
    }
    else if (strcmp(command, "infocliente") == 0){
      /*imprime a informacao do cliente de referencia 'ref'*/
      scanf(" %li", &ref);
      printf("Cliente-info: ");
      info_cliente(verifica_cliente(ref));
    }
    else if (strcmp(command, "info") == 0) {
      /*imprime a informacao de todos os clientes ativos*/
      if (lista_vazia()) /*se a pool estiver vazia, nao havera clientes ativos*/
        printf("No active clients\n");
      else
        percorre_avl();
      }
    else if (strcmp(command, "sair") == 0) {
      /*apaga a lista de cheques e a arvore de clientes, imprime a informacao pedida e termina o programa*/
      printf("%d", apaga_arvore());
      apaga_lista();
      printf(" %d %d\n", n_cheques, v_cheques);
      return EXIT_SUCCESS;
    }
    getchar();
    scanf("%s", command);
  }
}
