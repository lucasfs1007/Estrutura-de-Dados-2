#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    //variaveis
    int entradaA;
    int entradaB;
    int Xa;
    int Xb; 
    int Ya;
    int Yb;
    int contador;
    int trocaA;
    int trocaB;
    int passadas;
 
    //lendo as entradas
    scanf("%d %d", &entradaA, &entradaB);
    scanf("%d", &passadas);

    Xa = 1;
    Ya = 1;
    Xb = entradaA;
    Yb = entradaB;

    for(contador = 0; contador < passadas; contador++) {

        scanf("%d %d", &trocaA, &trocaB);
        if(trocaA ==1){
            Ya++;
        }else if(trocaA == 2){
            Ya--;
        }else if(trocaA == 3){
            Xa++;
        }else {
            Xa--;
        }if(trocaB == 1){
            Yb++;
        }else if(trocaB == 2){
            Yb--;
        }else if(trocaB == 3){
            Xb++;
        }else{
            Xb--;
        }if(Xa == Xb && Ya == Yb){
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", Xa, Ya, contador+1);
            break;
        }else if(Xa > entradaA || Xa < 1 || Ya > entradaB|| Ya < 1){
            printf("PA saiu na posicao (%d,%d) no passo %d\n", Xa, Ya, contador+1);
            break;
        }else if (Xb > entradaA || Xb < 1 || Yb > entradaB || Yb < 1){
            printf("PB saiu na posicao (%d,%d) no passo %d\n", Xb, Yb, contador+1);
            break;
        }
    } if(contador == passadas)
        printf("Nao se encontraram\n");
    return 0;
}