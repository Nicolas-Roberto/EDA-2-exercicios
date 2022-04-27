#include <stdio.h>
#include <stdlib.h>

void selectionBubble(int *v, int l, int r) {
    int aux;
    int troca;
    for(int j=l; j<r; j++) {
        troca=0;
        for(int i=0; i<r ; i++) {
            if(v[i+1] < v[i]) {
                aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
                troca++;
            }
        }
        if(troca == 0) return;
    }
}

int main()
{

    int i=0;
    int vet[1000];
    while(scanf("%d", &vet[i++]) == 1);
    /*
    for(int j=0; j<i; j++) {
        vet[j] = rand();
    }

    for(int j=0; j<i; j++){
        printf("%d ", vet[j]);
    }
    */


    selectionBubble(vet, 0, i-1);
    //printf("\n");
    for(int j=0; j<i; j++){
        if(j==i-1) {
            printf("%d", vet[j]);
            break;
            }
        printf("%d ", vet[j]);
    }

    return 0;
}
