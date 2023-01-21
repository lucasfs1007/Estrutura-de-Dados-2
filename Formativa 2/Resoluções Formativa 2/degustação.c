//utilizaremos essas 3 bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct com os dados da bebida a ser feita
typedef struct {
    int tamanho;
     int posicao;
    char caracteres;
   
} Bebida;

//função para dividir os vetores para ordena-los
void merge(Bebida *drinks, int inicio, int final, int meio) {

    Bebida vetorAux[final - inicio + 1]; //porque começa da posição 0
    //variaveis do vetor auxiliar
    int Ai = inicio;
    int Bi = meio + 1;
    int AUXi = 0;
    int p;

    //pegando os elementos maiores e menores que o meio para ordena-los em um vetor auxiliar
    while (Ai <= meio && Bi <= final) {

        //caso a direita passe a esquerda é pq ordenamos tudo, então o vetor auxiliar recebe esse vetor já ordenado
        if (drinks[Ai].tamanho >= drinks[Bi].tamanho) {
            vetorAux[AUXi++] = drinks[Ai++];
        //caso contrario ele recebe a outra parte
        } else {
            vetorAux[AUXi++] = drinks[Bi++];
        }
    }

    //ordenando os elementos menores que o meio
    while (Ai <= meio) {
        vetorAux[AUXi++] = drinks[Ai++];
    }
    //Ordenando elementos maiores que o meio
    while (Bi <= final) {
        vetorAux[AUXi++] = drinks[Bi++];
    }
    //zerando as posições do vetor auxiliar para inserirmos
    int v = 0;
    //passando por todo o vetor, preenchendo e depois incrementarmos...para garantir que vamos pegar a posição 0 também
    for (p = inicio; p <= final; ++p) {

        drinks[p] = vetorAux[v++];
    }
}

//função para ordenar por divisão e conquista
void mergeSort(Bebida *drinks, int i, int j) {
    //enquanto a esquerda não passar a direita vamos ordernar pegando cada metade até chegar em um
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(drinks, i, meio);
    mergeSort(drinks, meio + 1, j);
    merge(drinks, i, j, meio);
}

//função main
int main() {
    Bebida drinks[100000]; //tamanho definido no exercicio
    int i = 0;
    int sent = 0;
    int j;
    char input[100001];
    //lendo a entrada
    scanf("%s", input);

    //vamos guardar o tamanho da entrada aqui
    int z = strlen(input);
    //passando por todos os caracteres da entrada
    for (i = 0; i < z; i++) {

        drinks[sent].caracteres = input[i];
        drinks[sent].posicao = i;

        while (input[i] == drinks[sent].caracteres) {
            drinks[sent].tamanho++;
            i++;
        }
        i--;
        sent++;
    }

    mergeSort(&drinks[0], 0, sent);

    for (j = 0; j < sent; j++) {

        printf("%d %c %d\n", drinks[j].tamanho, drinks[j].caracteres, drinks[j].posicao);
    }

    return 0;
}