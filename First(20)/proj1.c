/*PROJETO 1 IAED
GRUPO 10:
  81151 PEDRO ORVALHO
  81365 ANA LEITAO
  81647 MANUEL GALAMBA*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define NAME 41 /*caso o compilador entenda isto como os 40 caracteres do nome mais o final*/
#define VAR 3

struct bank{
  char name[NAME];
  int class;
  int ref;
}; /*um banco e uma estrutura definida por um nome, uma referencia e uma classificacao*/

/*DECLARACAO DE VARIAVEIS*/

struct bank list[MAX];
int total_banks = 0, matrix[MAX][MAX], var[VAR];

/*DECLARACAO DE FUNCOES*/

void out_a();
void out_k();
void out_r();
void out_e();
void out_p();
void out_l();
void out_K();
void out_x();
void l_1(int);
void change_class(int);
void change_matrix();
int find_bank(int);

/*FUNCAO PRINCIPAL*/

int main() {
  char command;

  while (1) {
    command = getchar();
    switch  (command) { /*executa a funcao segundo o primeiro parametro da frase de input*/

      case 'a':
          out_a();
        break;

      case 'k':
          out_k();
        break;

      case 'r':
          out_r();
        break;

      case 'e':
          out_e();
        break;

      case 'p':
          out_p();
        break;

      case 'l':
          out_l();
        break;

      case 'K':
          out_K();
        break;

      case 'x':
          out_x();
          return EXIT_SUCCESS;

      default:
          printf("ERRO: Comando desconhecido\n");
        }
    getchar();
  }
  return EXIT_FAILURE;
}

/*FUNCOES DOS COMANDOS*/

void out_a() { /*cria um novo banco segundo a estrutura "bank"*/
  int i;
  /*cria uma nova linha e coluna da matrix a 0s*/
  for(i=0; i <= total_banks; i++) {
    matrix[i][total_banks] = 0;
    matrix[total_banks][i] = 0;
  }
  scanf(" %s %d %d", list[total_banks].name, &list[total_banks].class, &list[total_banks].ref);
  total_banks++;
}

void out_k() { /*despromove um banco bom a mau*/
  change_class(0);
}

void out_r() { /*promove um banco mau a bom*/
  change_class(1);
}

void out_e() { /*altera na "matrix" na posicao [i][j] o valor emprestado por i a j*/
  change_matrix();
  matrix[var[0]][var[1]] += var[2];
}

void out_p() { /*altera na "matrix" na posicao [j][i] o valor amortizado por i a j*/
  change_matrix();
  matrix[var[1]][var[0]] -= var[2];
}

void out_l() { /*funcao que imprime uma lista conforme o segundo parametro (0, 1 ou 2)*/
  int com, total[MAX], partners, i, j;
  scanf(" %d", &com);
  if (com == 0) { /*imprime a referencia, o nome e a classificacao de todos os bancos inseridos no programa*/
    for (i=0; i < total_banks; i++){
      printf("%d %s %d\n", list[i].ref, list[i].name, list[i].class);
    }
  }

  else if (com == 1) { /*imprime as informacoes de emprestimos e dividas de todos os bancos*/
    for (i=0; i < total_banks; i++) {
      l_1(i);
    }
  }

  else if (com == 2) { /*ve e imprime quantos bancos e que tem x parceiros, sendo que x<total_banks*/
    for(i=0; i < total_banks; i++) { /*poe o vetor "total" a 0s*/
      total[i] = 0;
    }
    for(i=0; i < total_banks; i++) {
      for(j=0, partners=0; j < total_banks; j++) {
        if (matrix[i][j] != 0 || matrix[j][i] != 0) { /*quando o banco "i" emprestou ou deve a outro "j"incrementa o "partners"*/
          partners++;
        }
      }
      total[partners]++; /*incrementa a posicao do vetor "total" correspondente ao numero de parceiros de "i"*/
    }
    for(i=0; i < total_banks; i++) {
      if (total[i] != 0)
        printf("%d %d\n", i, total[i]);
    }
  }
}

void out_K() {
  /*despromove o banco que tem o maior valor emprestado a bancos maus. percorre a "list"
  e quando encontra um banco bom adiciona o valor a variavel "value"*/
  int maximum = 1, worst=-1, value, i, j;
  for(i=0; i < total_banks; i++) {
    if (list[i].class == 1) {
      for(j=0, value=0; j < total_banks; j++) {
        if (list[j].class == 0) {
          value += matrix[i][j];
        }
      }
      if (value >= maximum) { /*se o "value" para esse banco for pior que o maximo,
      a variavel "worst" ficara com essa posicao*/
        maximum = value;
        worst = i;
      }
    }
  }
  if (worst != -1) { /*condicao para que so se efetue o seguinte caso exista um banco a ser despromovido*/
    list[worst].class = 0;
    printf("*");
    l_1(worst); /*imprime todas as informacoes para o banco que foi despromovido*/
  }
  out_x(); /*imprime o numero total de bancos e o numero de bancos bons*/
}

void out_x() {
  /*imprime o numero total de bancos e o numero de bancos bons, tem ciclo que percorre a "list" e incrementa o contador de bancos bons*/
  int class1, i;
  for(i=0, class1=0; i < total_banks; i++) {
    if (list[i].class == 1)
      class1++;
  }
  printf("%d %d\n", total_banks, class1);
}

/*FUNCOES AUXILIARES*/

void l_1(int i) {
  /*imprime o output pedido no enunciado para o banco na posicao i da "list", percorre a "matrix"
  para calcular todos os valores pedidos*/
  int pos, inP=0, outP=0, outV=0, outVM=0, inV=0, inVM=0;
  for(pos=0; pos < total_banks; pos++) { /*calcula os valores das dividas do banco e calcula os valores emprestados pelo banco*/
    if (matrix[pos][i] != 0) {
      inP++;
    }
    inV += matrix[pos][i];
    if(list[pos].class == 0) {
      inVM += matrix[pos][i];
      outVM += matrix[i][pos];
    }
    if (matrix[i][pos] != 0) {
      outP++;
    }
    outV += matrix[i][pos];
  }
  printf("%d %s %d %d %d %d %d %d %d\n", list[i].ref, list[i].name, list[i].class, inP, outP, outV, outVM, inV, inVM);
}

void change_class(int class) {
  /*muda a classificacao do banco dependendo do inteiro que recebe*/
  int ref, i;
  scanf(" %d", &ref);
  for(i=0; i < total_banks; i++) {
    if (list[i].ref == ref) {
      list[i].class = class;
      i = total_banks;
    }
  }
}

void change_matrix() {
  /*poe no vetor "var" as posicoes na "list" dos dois bancos e o valor que ira alterar a matriz*/
  int ref1, ref2;
  scanf(" %d %d %d", &ref1, &ref2, &var[2]);
  var[0] = find_bank(ref1);
  var[1] = find_bank(ref2);
}

int find_bank(int ref) {
  /*encontrar a posicao do banco de "ref" na list/matrix e po-la na variavel bank1*/
  int bank1=0, i;
  for(i=0; i < total_banks; i++)
    if (list[i].ref == ref) {
      bank1 = i;
      i = total_banks;
    }
  return bank1;
}
