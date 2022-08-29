#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
    int i, glassN;
    scanf("%d%*c", &glassN);                               // 1 <= glassN <= 10 000

    int *amount = (int *)calloc(glassN+3, sizeof(int));    // 0 <= amount <= 1000
    int *result = (int *)calloc(glassN+3, sizeof(int)); 

    for(i = 3; i < glassN+3; i++)
        scanf("%d%*c", &amount[i]);
    
    result[3] = amount[3];

    for(i = 4; i < glassN+3; i++)
        result[i] = amount[i] + max(result[i-3], max(result[i-2], amount[i-1] + max(result[i-3], result[i-4])));
    
    printf("%d\n", max(result[glassN+1], result[glassN+2]));
    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}