#include <stdio.h>
#include <stdlib.h>

//funcao que vai trabalhar com as trocas de posição mediante a ordenação
void troca(int* xp, int* yp) {

    //Trabalhando com os vetores
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}
 
// Função para realizar a ordenação
void ordenacao(int posicao[], int n) {

    int i;
    int j;
    int menorIndice;
 
    for (i = 0; i < n - 1; i++) {
 
        // Pegando o menor indice do vetor 
        menorIndice = i;
        for (j = i + 1; j < n; j++)
            if (posicao[j] < posicao[menorIndice])
                menorIndice = j;
 
    
        troca(&posicao[menorIndice], &posicao[i]);
    }
}
 
// Função para imprimir a posicao
void imprimePosicao(int posicao[], int tamanho) {

    for (int i = 0; i < tamanho; i++)
        printf("%d ", posicao[i]);
        printf("\n");
}
 

//função main
int main() {

   int numero;
   int posicao[1000];
   int contador = 0;
   while (scanf("%d",&numero) != EOF){
     
     posicao[contador]= numero;

     contador++;

   }

   int n = contador;
  
 
    ordenacao(posicao, n);
    imprimePosicao(posicao, n);
 
    return 0;
}