#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *th;

    int n, temp, bigger = 0, count = 0;
    scanf("%d", &n);

    while (n != 0)
    {
        th = (int *)calloc(1000001, sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            th[temp] += 1;

            if (th[temp] > count)
            {
                count = th[temp];
                bigger = temp;
            }
        }
        printf("%d\n", bigger);
        count = 0;
        bigger = 0;
        free(th);

        scanf("%d", &n);
    }
    return 0;
}
