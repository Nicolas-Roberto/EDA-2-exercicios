#include <stdio.h>
#include <string.h>
int main()
{

    char string[101];
    int saidas[100];
    int n,contSaidas=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", string);
        int j=0,soma=0;
        while(string[j] != '\0') {
            if(string[j]>=48 && string[j]<=57){
                soma += string[j] - '0';
            }
            j++;
        }
        saidas[i] = soma;
    }
    for(int i=0; i<n; i++) {
        printf("%d\n", saidas[i]);
    }

    return 0;
}
