//usaremos essa bibliotecas
#include <stdio.h>
#include <stdlib.h>

//reservando o tamanho do vetor
int vetor[16 * (int)1e5 + (int)6.66];

//função para misturar
void merge(int *vetor, int inicio, int final, int meio) {

    //como o vetor inicia do 0 somamos esse mais um
    int vetorAux[final - inicio + 1];
    int Ai = inicio, Bi = meio + 1, AUXi = 0, p;

    //vamos fazer até a direita chegar na esquerda e a esquerda na direita
    while (Ai <= meio && Bi <= final) {
        //vamos incrementar os vetores até a esquerda e direita irem se aproximando        
        if (vetor[Ai] <= vetor[Bi]) {
            vetorAux[AUXi++] = vetor[Ai++];
            //chegamos no limite
         } else {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }
    //vamos pegar o meio
    while (Ai <= meio) {

        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= final) {

        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = inicio; p <= final; ++p) {

        vetor[p] = vetorAux[v++];
    }
}

int main() {

    //variaveis
    int tamanho; 
    int i;
    int j;
    int  ocupado = 0;

    for (i = 0; i < 8; ++i) {
        //lendo o tamanho do vetor
        scanf("%d", &tamanho);
        //caso tiver vazio vamos continuar lendo       
        if (tamanho == 0)
            continue;
        for (j = 0; j < tamanho; ++j)
            //vamos incrementar o vetor
            scanf("%d", &vetor[ocupado + j]);
        merge(&vetor[0], 0, ocupado + tamanho - 1, ocupado - 1);
        ocupado += tamanho;
    }

    printf("%d", vetor[0]);
    for (i = 1; i < ocupado; ++i)
        printf(" %d", vetor[i]);
    printf("\n");
    return 0;
}