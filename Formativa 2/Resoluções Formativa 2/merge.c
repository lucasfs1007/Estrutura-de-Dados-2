#include <stdio.h>
#include <stdlib.h>

//função para dividirmos o vetor para ordena-lo em um vetor auxiliar
void merge(int *vetor, int inicio, int final, int metade) {
    //mais um pq inciamos em 0 o vetor
    int vetorAux[final - inicio + 1];
    //auxiliares
    int Ai = inicio;
    int Bi = metade + 1;
    int AUXi = 0;
    int p;

    while (Ai <= metade && Bi <= final) {

        //caso a direita não avance a esquerda vamos incrementando o vetor auxiliar
        if (vetor[Ai] <= vetor[Bi]) {

            vetorAux[AUXi++] = vetor[Ai++];
        //caso eles se ultrapassem --> condição de parada
         }else {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    //iremos incrementar o vetor auxiliar usando a equerda e direita
    while (Ai <= metade) {

        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= final) {

        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;

    //passaremos por todo o vetor e vamos incrementar o auxiliar
    for (p = inicio; p <= final; ++p) {

        vetor[p] = vetorAux[v++];
    }
}

void mergeSort(int *vetor, int i, int j) {

    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(vetor, i, meio);
    mergeSort(vetor, meio + 1, j);
    merge(vetor, i, j, meio);
}

int main() {

    int vetor[100000 + 66], i = 0, k;

    //vamos ler até condição de parada
    while (scanf("%d", &vetor[i++]) != EOF){
    }

    --i;

    mergeSort(&vetor[0], 0, i - 1);

    printf("%d", vetor[0]);
    for (k = 1; k < i; ++k) {
        
        printf(" %d", vetor[k]);
    }
    printf("\n");
    return 0;
}