#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

static Item *pq;
static int N;

// inicia a Fila de Prioridade
void PQinit(int maxN)
{
  pq = malloc(sizeof(Item)*maxN);
  N=0;
}

// deixa a fila vazia
int PQempty()
{
  return N==0;
}


// conserta fila de baixo pra cima
void fixUp(Item *pq, int k)
{
  while(k>1 && less(pq[k/2], pq[k]))
    {
      exch(pq[k], pq[k/2]);
      k = k/2;
    }
}

// conserta fila de cima pra baixo
void fixDown(Item *pq, int k, int N)
{
  int j;
  while(2*k <= N)
    {
      j=2*k;
      if(j<N && less(pq[j], pq[j+1])) j++;
      if(!less(pq[k], pq[j])) break;
      exch(pq[k],pq[j]);
      k=j;
    }
}

// remove ultimo elemento da fila
Item PQdelmax()
{
  exch(pq[1], pq[N]);
  fixDown(pq, 1, N-1);
  return pq[N--];
}

// insere valor na fila
void PQinsert(Item v)
{
  pq[++N]=v;
  fixUp(pq, N);
}

// ordena fila
void PQsortsimple(Item *v, int l, int r)
{
  int k;
  PQinit((r-l+1));
  for(k=l; k<=r; k++) PQinsert(v[k]);
  for(k=r; k>=l; k--) v[k] = PQdelmax();
}

// Print the array
void printArray(Item *pq, int tam) {

  for(int i=0; i<tam; i++){
    printf("%d ", pq[i]);
  }
  printf("\n");

}


int main() {
  int control, inputNum, outputSize;

  while(scanf("%d ", &control) != EOF)
  {
    if(control == 1)
    {
      scanf("%d", &inputNum);
      if(N<100)
      {
        PQinsert(inputNum);
      } else if(pq[N]>inputNum)
        {
          PQdelmax();
          PQinsert(inputNum);
        }
    }
    if(control == 2)
    {
      scanf("%d", &outputSize);
      printArray(pq, outputSize);
    }
  }

  return 0;
}
