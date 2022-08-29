#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, N;
    scanf("%d%*c", &N); // 1 <= N <= 1000
    int *maxPrice = (int *)calloc(N+1, sizeof(int));

    for(i = 1; i <= N; i++)
    {
        scanf("%d%*c", &maxPrice[i]);
        for(j = 1; j <= i/2; j++)
        {
            if(maxPrice[j]+maxPrice[i-j] > maxPrice[i])
                maxPrice[i] = maxPrice[j]+maxPrice[i-j];
        }
    }

    printf("%d\n", maxPrice[N]);
    return 0;
}