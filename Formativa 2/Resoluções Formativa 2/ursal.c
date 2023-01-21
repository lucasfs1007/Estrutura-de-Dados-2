#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define completo unsigned long long
#define menor(a, b) (a.valor == b.valor ? a.chave > b.chave : a.valor > b.valor)
#define troca(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmptroca(a, b) \
    if (menor(b, a))   \
    troca(a, b)

typedef struct
{
    int chave;
    int valor;
} Item;

//vamos dividir o vetor em menores que o pivo e maiores que o pivo
int particiona(Item *v, int esquerda, int direita) {
    Item pivo = v[direita];
    int j = esquerda;
    for (int k = esquerda; k < direita; k++)
        if (menor(v[k], pivo)){

            troca(v[k], v[j]);
            j++;
        }
    troca(v[j], v[direita]);
    return j;
}

//algoritmo que joga os menores a esquerda e maiores a direita
void quicksort(Item *v, int esquerda, int direita) {
    if (direita <= esquerda)
        return;

    cmptroca(v[(esquerda + direita) / 2], v[direita]);
    cmptroca(v[esquerda], v[(esquerda + direita) / 2]);
    cmptroca(v[direita], v[(esquerda + direita) / 2]);

    int meio = particiona(v, esquerda, direita);

    quicksort(v, esquerda, meio - 1);
    quicksort(v, meio + 1, direita);
}

Item presidente[91], senador[901], federal[9001], estadual[90001];
int pn = 0, sn = 0, dfn = 0, den = 0;

void eleicao() {
    long long s, f, e;
    scanf(" %lld %lld %lld", &s, &f, &e);

    long long validos = 0, invalidos = 0, total = 0;
    for (int x, esquerda; scanf("%d%n", &x, &esquerda) == 1;) {
        if (x < 0) {

            invalidos++;
            continue;
        }

        switch (esquerda) {

        case 3:
            presidente[x - 10].chave = x;
            presidente[x - 10].valor++;
            total++;
            break;
        case 4:
            senador[x - 100].chave = x;
            senador[x - 100].valor++;
            break;
        case 5:
            federal[x - 1000].chave = x;
            federal[x - 1000].valor++;
            break;
        default:
            estadual[x - 10000].chave = x;
            estadual[x - 10000].valor++;
        }
        validos++;
    }

    for (int i = 0; i < 91; i++)
        if (presidente[i].valor)
            presidente[pn++] = presidente[i];
    for (int i = 0; i < 901; i++)
        if (senador[i].valor)
            senador[sn++] = senador[i];
    for (int i = 0; i < 9001; i++)
        if (federal[i].valor)
            federal[dfn++] = federal[i];
    for (int i = 0; i < 90001; i++)
        if (estadual[i].valor)
            estadual[den++] = estadual[i];

    printf("%lld %lld\n", validos, invalidos);

    quicksort(presidente, 0, pn - 1);
    quicksort(senador, 0, sn - 1);
    quicksort(federal, 0, dfn - 1);
    quicksort(estadual, 0, den - 1);

    if ((double)presidente[0].valor / total >= .51)
        printf("%d\n", presidente[0].chave);
    else
        printf("Segundo turno\n");

    for (int i = 0; i < s; i++)
        printf("%d%c", senador[i].chave, " \n"[i == s - 1]);
    for (int i = 0; i < f; i++)
        printf("%d%c", federal[i].chave, " \n"[i == f - 1]);
    for (int i = 0; i < e; i++)
        printf("%d%c", estadual[i].chave, " \n"[i == e - 1]);
}

int main() {
    
    eleicao();

    return 0;
}