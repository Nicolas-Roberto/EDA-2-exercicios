#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
static int pa[1001];
static int INT_MAX=9999999;

typedef struct node *link;
struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

struct node { 
   vertex w; 
   int p; 
   link next; 
};

static link NEWnode( vertex w, link next, int p) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next; 
   a->p = p;
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

void GRAPHinsertArc( Graph G, Edge e, int p) { 
   G->adj[e.v] = NEWnode( e.w, G->adj[e.v], p);
   G->adj[e.w] = NEWnode( e.v, G->adj[e.w], p);
   G->A++;
}

void GRAPHcptD1( Graph G, vertex s, int *dist){
   bool mature[1001];
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1, mature[v] = false, dist[v] = INT_MAX;
   pa[s] = s, dist[s] = 0;

   while (true) {
      // escolha de y:
      int min = INT_MAX;
      vertex y;
      for (vertex z = 0; z < G->V; ++z) {
         if (mature[z]) continue;
         if (dist[z] < min) 
            min = dist[z], y = z;
      }
      if (min == INT_MAX) break;
      // atualização de dist[] e pa[]:
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (mature[a->w]) continue;
         if (dist[y] + a->p < dist[a->w]) {
            dist[a->w] = dist[y] + a->p;
            pa[a->w] = y;
         }
      }
      mature[y] = true;
   }
}


int main(void) {
  int pilares, pontes;
  int pontoA, pontoB, buracos;
  Graph g;
  int *distancia = malloc(sizeof(int)*1001);
  int totalBuracos;
  
  scanf("%d %d", &pilares, &pontes);
  g = GRAPHinit(pilares+2);
  
  for(int i=0; i<pontes; i++){
    scanf("%d %d %d", &pontoA, &pontoB, &buracos);
    GRAPHinsertArc(g, EDGE(pontoA,pontoB), buracos);
  }

  GRAPHcptD1(g, 0, distancia);

  printf("%d", distancia[pilares+1]);
  
  return 0;
}