#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vertex int

typedef struct {
  int v;
  int w;
}Edge;
Edge EDGE(int v, int w){
  Edge e;
  e.v=v;
  e.w=w;
  return e;
};

static int count;
static int pre[7000];

typedef struct node *link;
struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

struct node { 
   vertex w; 
   link next; 
};

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V ) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHdestroy(Graph G){
  free(G->adj);
  free(G);
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->adj[w] = NEWnode( v, G->adj[w]);
   G->A++;
}

void DepthSearch(Graph g, Edge e){
  int t, w=e.w;
  pre[w] = count++;
  for(link l=g->adj[w]; l!=NULL; l=l->next){
    t=l->w;
    if(pre[t] == -1) DepthSearch(g, EDGE(w,t));
  }
}

int GraphSearch(Graph g){
  int v, conexo=0;
  count = 0;
  for(v=0; v<g->V; v++) pre[v] = -1;
  for(v=1; v<g->V; v++){
    if(pre[v] == -1){
      conexo++;
      DepthSearch(g, EDGE(v,v));
    }
  }
  return conexo;
}

int main(void) {
  int estacoes = 1, linhas = 1;
  int controle=1, falha=0;

  int pontoA, pontoB;

  while(estacoes!=0 && linhas!=0){
    scanf("%d %d", &estacoes, &linhas);
    if(estacoes==0 && linhas==0) return 0;
    
    Graph g = GRAPHinit(estacoes+1);
    
    for(int i=1; i <= linhas; i++){
          scanf("%d %d", &pontoA, &pontoB);
          GRAPHinsertArc(g, pontoA, pontoB);
    }

    falha = GraphSearch(g);

    printf("Teste %d\n", controle);
    if(falha==1){
      printf("normal\n");
    }else{
      printf("falha\n");
    }
    printf("\n");
    controle++;
    GRAPHdestroy(g);
  }
  
  return 0;
}