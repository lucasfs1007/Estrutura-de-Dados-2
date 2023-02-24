#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct no {

  char *expressao;
  struct no *prox;

}no;

no *cria_pilha() {

 no *topo;
 topo = malloc (sizeof(no));
 topo->prox = NULL;
 return topo;
}

int empilha(no *topo, char *frase){
  no *novo = malloc(sizeof(no));

  if(novo == NULL) return 1;

  novo->expressao = frase;
  novo->prox = topo->prox;
  topo->prox = novo;

  return 0;
}


int desempilha(no *topo){
  no *lixo = topo->prox;

  if(lixo == NULL){
    printf("NULL\n");
    return 1;

  }
  printf("%s\n",lixo->expressao);
  topo->prox = lixo->prox;
  free(lixo);
  return 0;
}



int determina_operacao(char *a){
    char *inserir = "inserir";
    char *desfazer = "desfazer";

    int eh_inserir;
    int eh_desfazer;

    eh_inserir = strcmp(a,inserir);
    eh_desfazer = strcmp(a,desfazer);

    if(eh_inserir==0){
        return 1;
    }

    else if(eh_desfazer==0){
        return 2;
    }
    else{
        return 0;
    }

}



int main() {
  no *topo;
  topo = cria_pilha();
  char input[10]="";



  int funcao;
   while(scanf("%s",input)!=EOF){
        funcao = determina_operacao(input);
        if(funcao==1) {

            char *expressao = calloc(101,sizeof(char));

            scanf("%[^\n]s",expressao);
            empilha(topo,expressao);


        }
        else if(funcao == 2){
            desempilha(topo);

        }
        else{
            printf("entrada invalida\n");
        }

    }


  return 0;
}