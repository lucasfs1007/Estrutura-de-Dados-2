#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct No {
    int inicio;
    int pista;
    int proximoNo;
    struct No* ponteiro;
} No;

struct No* cabeca;

void imprimirLista(struct No* cabeca) {

    if(cabeca == NULL) {
        return;

    }
    imprimirLista(cabeca->ponteiro);
    printf("%d\n", cabeca->pista);
}

void inserir(int dados, int inicio, int prox) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->pista = dados; 
    novoNo->inicio = inicio;
    novoNo->proximoNo = prox;

    if(cabeca == NULL) {
        cabeca = novoNo;
        return;
    }

    novoNo->ponteiro = cabeca;
    cabeca = novoNo;
    return;
}

int main() {
    int numeroDeLinhas = 0;
    int inicio;
    int pista;
    int proximoNo;
    int listaCabeca = 0;
    int valida = 1;

    scanf("%d", &numeroDeLinhas);

    struct No* array = (struct No*)malloc(sizeof(struct No) * numeroDeLinhas);


    for(int i = 0; i < numeroDeLinhas; i++) {
        scanf("%d %d %d", &inicio, &pista, &proximoNo);
        array[i].inicio = inicio;
        array[i].pista = pista;
        array[i].proximoNo = proximoNo;
    }

  

    for(int i = 0; i < numeroDeLinhas; i++) {
       
        for(int j = 0; j < numeroDeLinhas; j++) {
            if(array[i].inicio == array[j].proximoNo) {
                valida = 0;
            }
        }
        if(valida == 1) {
            inserir(
                array[i].pista,
                array[i].inicio,
                array[i].proximoNo
            );
            listaCabeca = i;
            break;
        }
    }
    
    for(int j = 0; j < numeroDeLinhas; j++) {
        for(int i = 0; i < numeroDeLinhas; i++) {
            if(array[listaCabeca].proximoNo == array[i].inicio) {
                inserir(
                    array[i].pista,
                    array[i].inicio,
                    array[i].proximoNo
                );
                listaCabeca = i;
            }
        }
    }

    imprimirLista(cabeca);
    return 0;
}