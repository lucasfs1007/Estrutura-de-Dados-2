#include <stdio.h>
#include <stdlib.h>

//inicio da lista
typedef struct celula {
    //variaveis
   int dado;

   struct celula *prox;
} celula;

//função de divisão
void divide_lista(celula *l, celula *l1, celula *l2) {

    l = l -> prox;

    //enquanto não chegar no final continuarei.
    while(l != NULL) {

        //olhando o resto da divsão e vendo se é par
        if(l -> dado % 2 == 0) {

            l2 -> prox = l;
            l2 = l2 -> prox;
        
        //é impar
        }else{

            l1 -> prox =l;
            l1 = l1 -> prox;

        }
        l = l -> prox;
    }

    //final da lista.
    l1 -> prox = NULL;
    l2 -> prox = NULL;
}