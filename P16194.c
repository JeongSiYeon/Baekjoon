#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, N;
    scanf("%d%*c", &N); // 1 <= N <= 1000
    int *minprice = (int *)calloc(N+1, sizeof(int));

    for(i = 1; i <= N; i++)
    {
        scanf("%d%*c", &minprice[i]);
        for(j = 1; j <= i/2; j++)
        {
            if(minprice[j]+minprice[i-j] < minprice[i])
                minprice[i] = minprice[j]+minprice[i-j];
        }
    }

    printf("%d\n", minprice[N]);
    return 0;
}