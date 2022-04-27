#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int headIndex, int halfIndex, int nailIndex)
{
    int size = nailIndex - headIndex + 1;
    int *copyV, flag1 = 0, flag2 = 0, p1 = headIndex, p2 = halfIndex + 1;

    copyV = (int *)malloc(size * sizeof(int));

    if (copyV != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            if (!flag1 && !flag2)
            {
                if (V[p1] < V[p2])
                {
                    copyV[i] = V[p1++];
                }
                else
                    copyV[i] = V[p2++];

                if (p1 > halfIndex)
                {
                    flag1 = 1;
                }
                if (p2 > nailIndex)
                {
                    flag2 = 1;
                }
            }
            else
            {
                if (!flag1)
                {
                    copyV[i] = V[p1++];
                }
                else
                    copyV[i] = V[p2++];
            }
        }
        for (int i = 0, j = headIndex; i < size; i++, j++)
        {
            V[j] = copyV[i];
        }
    }
    free(copyV);
}

void mergeSort(int *V, int headIndex, int nailIndex)
{
    int halfIndex;

    if (headIndex < nailIndex)
    {
        halfIndex = ((headIndex + nailIndex) / 2);

        mergeSort(V, headIndex, halfIndex);
        mergeSort(V, halfIndex + 1, nailIndex);
        merge(V, headIndex, halfIndex, nailIndex);
    }
}

//A e B estão ordenados
int *intercala( int *vetA, int lA, int rA,
                int *vetB, int lB, int rB)
{
    int tamA = lA+rA+1;
    int tamB = lB+rB+1;
    int *vetC = (int *) malloc(sizeof(int) * (tamA+tamB));

    int lC = 0;
    //int rC = tamA+tamB-1;

    int iA = lA, iB = lB ,iC = lC;

    while(iA <= rA && iB <= rB){
        if(vetA[iA] < vetB[iB]){
            vetC[iC] = vetA[iA];
            iA++;
        } else {
            vetC[iC] = vetB[iB];
            iB++;
        }
        iC++;
    }
    while(iA <= rA){
        vetC[iC] = vetA[iA];
        iC++;
        iA++;
    }
    while(iB <= rB){
        vetC[iC] = vetB[iB];
        iC++;
        iB++;
    }
    realloc(vetA, sizeof(int)*(tamA+tamB));
    return vetC;
}

int main()
{
    int *vetA, *vetB;
    int tam = 0,tamFinal = 0, iA = 0, iB = 0;
    int start=0;
    //int x=0;

    while(scanf("%d", &tam)== 1){
        tamFinal += tam;
        if(!start){
            start++;
            vetA = (int *) malloc(sizeof(int) * tam);
            while(iA<tamFinal){
                scanf("%d", &vetA[iA]);
                iA++;
            };
        } else {
            vetB = (int *) malloc(sizeof(int) * tam);
            while(iB<tam){
                scanf("%d", &vetB[iB]);
                iB++;
            };


            vetA = intercala(vetA, 0, (tamFinal-tam-1),
                             vetB, 0, iB-1);

            iB=0;
        }
        //x++;

        //if(x==3) break;
    }

    for(int i=0; i<tamFinal; i++){
        printf("%d ", vetA[i]);
    }


    return 0;
}
