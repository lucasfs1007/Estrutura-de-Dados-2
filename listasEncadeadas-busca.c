#include <stdio.h>

//inicio da lista encadeada
typedef struct celula {
	int dado;
	struct celula *prox;
} celula;

//função busca
celula *busca (celula *le, int x) {

	celula *elemento = le->prox;

	for(elemento = elemento; elemento != NULL; elemento = elemento -> prox) {

		if(elemento->dado == x) {

		  return elemento;

		}
	}

	return NULL;

}

celula *busca_rec (celula *le, int x) {

	celula *elemento = le->prox;

	if(elemento != NULL) {

		if(elemento->dado == x) {

			return elemento;

		} 
		return busca_rec(elemento, x);

	} 
    
	return NULL;
}