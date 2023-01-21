//utilizaremos essas 3 bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função para divivir os vetores
void merge(int *vetor, int inicio, int final, int meio) {
    int vetorAux[final - inicio + 1]; //+1 pq começamos do 0 e isso ia atrapalhar no cálculo do meio
    //variaveis para o vetor auxliar
    int menores = inicio;
    int maiores = meio + 1;
    int AUXi = 0;
    int p;

//o meio é pivo

    //vamos trabalhar com elementos maiores e menores que o pivo
    while (menores <= meio && maiores <= final) {
        //preenchendo o vetor auxiliar com elementos menores que o pivo
        if (vetor[menores] <= vetor[maiores]) {
            vetorAux[AUXi++] = vetor[menores++];
        //caso contrário ele vai preencher com os maiores
        } else {
            vetorAux[AUXi++] = vetor[maiores++];
        }
    }

    //nesses dois whiles vamos preencher o vetor auxiliar com elementos maiores e menores que o pivo
    while (menores <= meio) {

        vetorAux[AUXi++] = vetor[menores++];
    }
    while (maiores <= final) {
        vetorAux[AUXi++] = vetor[maiores++];
    }

    int v = 0; //zerando as posições para poder encher 

    //iremos passar por todo vetor e incrementaremos primeiro e inserimos depois para não ter problemas com posições
    for (p = inicio; p <= final; ++p) {
        vetor[p] = vetorAux[v++];
    }
}

//função para fazer ordenação por divisão e conquista
void mergeSort(int *vetor, int i, int j) {
    //enquanto a esquerda não passar a direita vamos dividindo
    if (i >= j)
        return;

    int meio = i + (j - i) / 2; //pegando o meio
    //fazendo as divisões com cada meio recursivamente
    mergeSort(vetor, i, meio);
    mergeSort(vetor, meio + 1, j);
    merge(vetor, i, j, meio);
}

int buscaBin(int *vetor, int inicio, int final, int busca) {
    //faremos a busca por todo vetor
    while (inicio + 1 < final) {

        int meio = (final + inicio) / 2; //calculando o pivo
        //vamos ver se o numero procurado é maior ou menor que o pivo para definirmos os limites da busca
        if (busca >= vetor[meio]) //nesse caso o numero buscado esta entre o meio e o final
            inicio = meio; //o inicio passa a ser o meio já que o buscado esta nessa faixa
        if (busca < vetor[meio]) //nesse caso o numero buscado está entre o meio e o inicio
            final = meio; //o meio passa a ser o limite da busca pq agt já sabe que é um número menor
    }
    //se acharmos o numero ele retorna a busca, senão fica como -1
    return vetor[inicio] == busca ? inicio : -1;
}

int main() {
   //variaveis
    int *vetor; 
    int nums; 
    int input;
    int i;
    //lendo os numeros
    scanf("%d", &nums);
    vetor = malloc(nums * sizeof(int)); //alocando memoria para o tanto de numeros digitados

    //passando por todo o vetor de numeros e preenchendo cada posição do mesmo
    for (i = 0; i < nums; i++)
        scanf("%d", &vetor[i]);
    //ordenando eles
    mergeSort(vetor, 0, nums - 1);

    //faremos isso até a saída de programa "EOF"
    while (scanf("%d", &input) != EOF)
        //printando se achou ou não
        buscaBin(vetor, 0, nums - 1, input) == -1 ? printf("nao\n") : printf("sim\n");

    return 0;
}