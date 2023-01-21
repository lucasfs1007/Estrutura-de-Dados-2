
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 101

char *hasht[M];

int hash(char *key, int tamanho){
    int r = 0;
    for(int i = 0; i < tamanho; ++i){
        r = r+(key[i] * (i+1))%M;
    }

    return (19*r)%M;
}

int main() {
    int t;
    scanf("%d", &t);

    int n;
    char palavra[30], comando, *key;
    int pos, c, tamanho, cont;
    while(t--){

        cont = 0;
        for(int i = 0; i < n; ++i)
            hasht[i] = NULL;

        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", palavra);
            key = &palavra[4];
            comando = palavra[0];
            tamanho = strlen(key);

            if(comando == 'A'){
                c = 1;
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, tamanho) + j*j + 23*j) % M;
                    if(hasht[pos] != NULL && strcmp(key, hasht[pos])==0){
                        c = 0;
                        break;
                    }
                }

                if(c){
                    for(int j = 0; j < 20; ++j){
                        pos = (hash(key,tamanho) + j*j + 23*j)%M;

                        if(hasht[pos]==NULL){
                            hasht[pos] = malloc(sizeof(char)*(tamanho+1));
                            strcpy(hasht[pos], key);
                            cont++;
                            break;
                        }
                    }
                }

            }else if(comando == 'D'){
                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, tamanho) + j*j + 23*j)%M;
                    if(hasht[pos] != NULL && strcmp(hasht[pos], key) == 0){
                        free(hasht[pos]);
                        hasht[pos] = NULL;
                        cont--;
                        break;
                    }
                }
            }
        }
        printf("%d\n", cont);
            for(int i = 0; i < M; ++i){
                if(hasht[i] != NULL){
                    printf("%d:%s\n", i, hasht[i]);
                }
            }
    }
    return 0;
}