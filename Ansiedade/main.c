#include <stdio.h>
#include <stdlib.h>

int main()
{
    int triagem=0,countSim=0, vars = 0;
    char c[4];

    while(scanf(" %s",c) != EOF) {
        vars++;
        if(c[0] == 's'){
            countSim++;
        }
        if(vars == 10) {
            if(countSim >= 2) {
                triagem++;
            }
            countSim=0;
            vars = 0;
        }

    }

    printf("%d", triagem);
    return 0;
}
