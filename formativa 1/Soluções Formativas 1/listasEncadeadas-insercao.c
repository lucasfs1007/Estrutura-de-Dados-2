#include <stdio.h>
#include <stdlib.h>

typedef struct celula {

	//variaveis
	int dado;
	struct celula *prox;
} celula;

celula *busca_lista_posicao (celula *le, int x) {

	//estrutura nó
	celula *elemento = le;

  for(elemento=elemento; elemento->prox != NULL; elemento = elemento -> prox) {
    
	if(elemento->prox->dado==x) {

      return elemento;

    }
  }
	return elemento;
}

void insere_antes (celula *le, int x, int y) {

	//variaveis
	int i = 0;
	celula *elemento;

	//realocação de memória...criação do nó
	celula *novo = malloc (sizeof (celula));
	//percorrendo a lista encadeada até chegar na posição desejada

	elemento = busca_lista_posicao(le, y);
	novo -> dado = x;	
	novo -> prox = elemento -> prox;
	elemento -> prox = novo;

}


void insere_inicio (celula *le, int x) {

	//criação do nó
	celula *novo = malloc(sizeof(celula));
	novo -> dado = x;
	novo->prox = le->prox;
	le->prox = novo;
}