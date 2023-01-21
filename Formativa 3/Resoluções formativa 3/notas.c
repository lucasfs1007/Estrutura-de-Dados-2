#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A.count)

struct cont_st{
    int nota;
    int count;
};

typedef struct cont_st Item;

int big(Item A,Item B){
    if(key(A)==key(B)){
        return (A.nota>B.nota);
    }else{
        return (key(A)>=key(B));
    }
}

void merge(Item *V, int l, int m, int r) {

  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r) {

    if(big(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r) {
    
  if (l>=r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

void contaNotas(){
    int n,b,conta=0;
    int d;
        
    struct cont_st TH[1000];
    memset(TH, 0, sizeof(struct cont_st)*1000);
    scanf("%d",&n);
    while (conta<n){
        scanf("%d",&b);
        TH[b].nota=b;
        TH[b].count++;
        conta++;
    }
    mergesort(TH,0,1000);
          
    printf("%d\n",TH[0].nota);
    
}

int main(void){

    contaNotas();
    
    return 0;
}