#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ZeraHash(int *hash, int tam){
    for(int i=0; i<=tam; i++){
      hash[i]=0;
    }
}

int main(void) {
  int *hash = malloc(sizeof(int)*101);
  int voos = 1, aeroportos = 1;
  int controle=1,max;

  int pontoA, pontoB;
  
  while(voos!=0 && aeroportos!=0){
    scanf("%d %d", &aeroportos, &voos);
    if(voos==0 && aeroportos==0) return 0;
    ZeraHash(hash, aeroportos);
    max=0;
    
    for(int i=1; i <= voos; i++){
      scanf("%d %d", &pontoA, &pontoB);
      hash[pontoA]++;
      hash[pontoB]++;
    }
    
    for(int i=1; i<=aeroportos; i++){
      if(hash[i]>max){
        max=hash[i];
      }
    }
  
    printf("Teste %d\n", controle);
    for(int i=1; i<=aeroportos; i++){
      if(hash[i]==max){
        printf("%d ", i);
      }
    }
    printf("\n\n");
    controle++;
  }

  

  
  return 0;
}