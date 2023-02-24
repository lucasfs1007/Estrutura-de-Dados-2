#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 
 
typedef struct no {
    int dado;
    struct no *esq, *dir;
}no;
 
typedef struct pilha{
    int tamanho;
    int topo;
    struct no* *array;
} pilha;
 

struct no* novono(int dado) {

    struct no* no = (struct no*) malloc(sizeof(struct no));
    no->dado = dado;
    no->esq = no->dir = NULL;
    return no;
}
 
struct pilha* criapilha(int tamanho) {
    struct pilha* pilha = (struct pilha*) malloc(sizeof(pilha));
    pilha->tamanho = tamanho;
    pilha->topo = -1;
    pilha->array = (struct no*) malloc(pilha->tamanho * sizeof(no));
    return pilha;
}
 

int picheio(struct pilha* pilha){
     return pilha->topo - 1 == pilha->tamanho;
}
 
int pivazio(struct pilha* pilha){

     return pilha->topo == -1; 
}
 
void empilha(struct pilha* pilha, struct no* no) {

    if (picheio(pilha))
        return;
    pilha->array[++pilha->topo] = no;
}
 
struct no* desempilha(struct pilha* pilha) {
    
    if (pivazio(pilha))
        return NULL;
    return pilha->array[pilha->topo--];
}
 
struct no* verifica(struct pilha* pilha) {

    if (pivazio(pilha))
        return NULL;
    return pilha->array[pilha->topo];
}
 

void pos_ordem (no *raiz) {
    if (raiz == NULL)
        return;
     
    struct pilha* pilha = criapilha(MAX_SIZE);

    do {
        
        while (raiz) {
            if (raiz->dir)
                empilha(pilha, raiz->dir);
                empilha(pilha, raiz);
                raiz = raiz->esq;
        }        
        raiz = desempilha(pilha);
 
        if (raiz->dir && verifica(pilha) == raiz->dir) {

            desempilha(pilha); 
            empilha(pilha, raiz);
            raiz = raiz->dir; 
        
        }else {
            printf("%d ", raiz->dado);
            raiz = NULL;
        }
    } while (!pivazio(pilha));
}