#include <stdio.h>

#define vertex int

struct graph {
   int V; 
   int A; 
   int **adj; 
};

typedef struct graph *Graph;

static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

Graph GRAPHinit( int V ) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->adj[w][v] = 1;
      G->A++;
   }
}

void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->adj[w][v] = 0;
      G->A--;
   }
}

void GRAPHshow( Graph G) { 
   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

void Lugares(Graph g, int *lugares, int estive){
  for(int i=0; i<g->A; i++){
    if(g->adj[estive][i] == 1){
      lugares[i]=1;
    }
    lugares[estive]=1;
  }
}

int main(void) {
  int n, m, j;
  int a, k;
  
  scanf("%d ", &n);
  scanf("%d ", &m);
  scanf("%d", &j);

  Graph g = GRAPHinit(n);
  

  for(int i=0; i<n; i++){
    scanf("%d", &a);
    for(int l=0; l<a; l++){
      scanf("%d", &k);
      GRAPHinsertArc(g, i, k);
    }
  }

  int *lugares = calloc(n, sizeof(int));
  while(m--){
    scanf("%d", &k);
    Lugares(g, lugares, k);
  }

  int w;
  while(j--){
    scanf("%d", &k);
    
    if(lugares[k] == 1){
      printf("Eu vou estar la\n");
    }else{
      printf("Nao vou estar la\n");
    }
  }
  
  return 0;
}
