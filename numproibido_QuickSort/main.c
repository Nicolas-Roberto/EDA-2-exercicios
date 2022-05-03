#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

int partition (Item *v, int l, int r) {
    Item c = v[r];
    int j = l;

    for(int k = l; k < r; k++)
        if(less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }

    exch(v[j], v[r]);

    return j;
}

void quickSelect(int *v, int l, int r, int k) {

    if(r <= l)  return;

    int m = partition(v, l, r);

    if(m > k)   quickSelect(v, l, m - 1, k);
    if(m < k)   quickSelect(v, m + 1, r, k);
}


void quickSort(Item *v, int l, int r) {
    if (l < r) {
        int m = partition(v, l, r);

        quickSort(v, l, m - 1);
        quickSort(v, m + 1, r);
    }
}

void sort(Item *v, int index, int end, int N) {
    quickSelect(v, 0, N - 1, index);
    quickSelect(v, index + 1, N - 1, end);
    quickSort(v, index + 1, end - 1);
}


int main(){
    int N, P, X, index, end, aux;

    scanf("%d %d %d", &N, &P, &X);

    int * v = (int *)calloc(N, sizeof(int));

    index = P * X;
    end = index+ X - 1;

    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    sort(v, index, end, N);

    aux = N;

    for(int i = 0; i < X; i++){
        if(index < aux){
            printf("%d\n", v[index]);
            index += 1;
        }
    }

    free(v);

    return 0;
}
