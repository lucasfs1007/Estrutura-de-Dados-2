#include <stdio.h>
#include <stdlib.h>

// utilizaremos essa lista encadeada
typedef struct No{
    char letra;
    int indice;
} No; 
//caso for um item vazio deixaremos com espaço em branco ou -1
No NULLitem = {' ', -1};


static int tamanhoHash, elementos;
static No *hashTable;

#define key(index)(((unsigned)index)%tamanhoHash)
#define index(x)(x.indice)

void InitHashTable(int max){
    elementos = 0;
    tamanhoHash = max;
    //alocando o espaço necessario para preencher ela
    hashTable = malloc(tamanhoHash*sizeof(No));
    //passando por toda tabela hash e deixando ela como -1 em tudo para depois preencher
    for(int i = 0; i < tamanhoHash; i++){
        hashTable[i] = NULLitem;
    }
}

//utilizaremos essa função para preencher a tabela
void insereHash(No caractere){
    int v = index(caractere);
    int i = key(v);
    //validando os caracteres
    if  (hashTable[i].letra != caractere.letra){
        hashTable[i] = caractere;
        elementos++;
    } else {
        return;
    }
}

int main(){
    InitHashTable(1048583);
    No item;
    int menor;
    int j;

    //vamos receber até o fim da entrada, ou seja o EOF
    while (scanf("%d %c", &item.indice, &item.letra)!=EOF){
        //lógica para pegarmos o menor indice
        if(elementos==0){
            menor = item.indice;
        } else {
            if(item.indice < menor){
                menor = item.indice;
            }
        }
        insereHash(item);
    }
    //preenchendo as tabelas com cada elemento
    for(int i = menor; i < menor+elementos ; i++){
        j = key(i);
        printf("%c", hashTable[j].letra);
    }
    printf("\n");
    return 0;
}