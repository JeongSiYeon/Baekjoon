#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int n, max = 0, sum = 0;

    scanf("%d", &n);
    int *cost = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cost[i]);
        sum += cost[i];
        if(max < cost[i]) max = cost[i];
    }

    printf("%d\n", sum-max);
    return 0;
}

