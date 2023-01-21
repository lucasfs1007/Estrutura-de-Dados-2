#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int Item;
//similar ao trabalho de FSO
#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B)  \
    {               \
        Item T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

int separa(Item *v, int esquerda, int direita) {

    int i = esquerda - 1, j = direita;
    Item c = v[direita];

    for (;;) {

        while (less(v[++i], c))
            ;
        while (less(c, v[--j]))
            //quando o i e o j se encontrarem ja passamos o vetor todo então é condição de parada
            if (i == j)
                break;
            // Não podemos deixar a esquerda passar a direita
        if (i >= j)
            break;
        exch(v[i], v[j]);
    }

    exch(v[i], v[direita]);
    return i;
}

void quickSelect(Item *v, int esquerda, int direita, int p) {

    int j = separa(v, esquerda, direita);
    if (j == p)
        return;
    else if (j < p) {

        quickSelect(v, j + 1, direita, p);
    
    } else {
        quickSelect(v, esquerda, j - 1, p);
    }
}

void quickSort(Item *v, int esquerda, int direita) {
    //faremos ate a esquerda não passar a direita
    if (esquerda >= direita)
        return;
        //vamos fazendo essa divisão sucessiva para ir pegando o meio e ordenando no vetor auxiliar
    cmpexch(v[(esquerda + direita) / 2], v[direita]);
    cmpexch(v[esquerda], v[(esquerda + direita) / 2]);
    cmpexch(v[direita], v[(esquerda + direita) / 2]);

    int j = separa(v, esquerda, direita);
    quickSort(v, esquerda, j - 1);
    quickSort(v, j + 1, direita);
}

int main() {

    int n;
    int p;
    int x;
    //lendo n,p e x
    scanf("%d %d %d", &n, &p, &x);

    //alocando espaço na memoria para o vetor
    Item *v = malloc(sizeof(Item) * n);

    //preenchendo todas as posições do vetor
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int inicio = x * p, fim = inicio + x;

    if (fim >= n)
        fim = n - 1;

    quickSelect(v, 0, n - 1, inicio);
    quickSelect(v, inicio, n - 1, fim);
    quickSort(v, inicio, fim);

    int fimP = (fim + 1 == n) ? fim + 1 : fim;
    for (int i = inicio; i < fimP; i++) {

        printf("%d\n", v[i]);
    }
    //liberando de volta o espaço que não ta sendo mais usado

    free(v);
    return 0;
}