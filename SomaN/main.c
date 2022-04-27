#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x, soma = 0, i = 0;
    scanf("%d",&n);

    while( i < n ) {
        scanf("%d",&x);
        soma += x;
        i++;
    }

    printf("%d",soma);
    return 0;
}
