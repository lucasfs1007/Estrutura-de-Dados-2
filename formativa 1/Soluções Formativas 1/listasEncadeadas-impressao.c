#include <stdio.h>

//criando o inicio da lista
typedef struct celula {

    //variaveis
	int dado;
	struct celula *prox;
} celula;

void imprime(celula *le) {

	for(celula *elemento = le -> prox; elemento != NULL; elemento = elemento -> prox) {

		printf("%d ->", elemento->dado);

	}

	printf(" NULL\n");
}

void imprime_rec (celula *le) {

    //apontando a proxima posição
	celula *elemento = le -> prox;

    //verificando se não estou no final da lista
	if(elemento != NULL) {

		printf("%d ->", elemento->dado);

		return imprime_rec(le -> prox);

	}

	printf(" NULL\n");

	return;
}