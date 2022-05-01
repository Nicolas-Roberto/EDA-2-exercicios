#include <stdio.h>
#include <stdlib.h>
//[0,262143]
//se o indice cabe na tabela da pra simplificar
#define HTSIZE 262144
#define HTNULL -1

typedef struct link{
    int Pi;
    struct link *prox;
} link;

typedef struct lista_st{
    link *head;
    int count;
} lista_st;

void LEinit(lista_st *lista){
    lista->head=NULL;
    lista->count=0;
}

void LEinsert(lista_st *lista, int Pi){
    link *l=malloc(sizeof(link));
    l->Pi=Pi;
    l->prox=lista->head;
    lista->head=l;
    lista->count++;
}

int LEsearch(lista_st *lista, int x){
    link *aux=lista->head;
    while(aux!=NULL){
        if(aux->Pi==x){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

typedef struct HT_st{
    lista_st *ht;
    int count;
} HT_st;

int hash(int Pi){
    return Pi%HTSIZE;
}

void HTinit(HT_st *HT){
    HT->ht = malloc(sizeof(lista_st)*HTSIZE);
    HT->count = 0;

    for(int i=0; i<HTSIZE; i++){
        LEinit(&HT->ht[i]);
    }
}

void HTinsert(HT_st *HT, int x){
    int hashv = hash(x);

    LEinsert(&HT->ht[hashv], x);
    HT->count++;
}

int HTsearch(HT_st *HT, int x){
    int hashv=hash(x);

    return LEsearch(&HT->ht[hashv], x);
}

int main()
{

    HT_st hashtable;
    HTinit(&hashtable);

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int Pi;
        scanf("%d", &Pi);
        HTinsert(&hashtable,Pi);
    }
    for(int i=0;i<HTSIZE;i++){
        if(hashtable.ht[i].count>=2){
            printf("colisão em %d, temos %d elementos\n", i, hashtable.ht[i].count);
        }
    }

    int pergunta;
    while(scanf("%d", &pergunta)==1){
        if(HTsearch(&hashtable, pergunta)){
            printf("sim\n");
        } else {
            printf("não\n");
        }
    }

    return 0;
}
