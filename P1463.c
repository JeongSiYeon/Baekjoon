#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int *dp, int N);

int main(void)
{
    int N;
    
    scanf("%d%*c", &N);
    int *dp = (int *)calloc(N+1, sizeof(int));

    printf("%d\n", f(dp, N));
    return 0;
}

int f(int *dp, int N)
{
    dp[1] = 0;

    for(int i = 2; i <= N; i++)
    {
        int min = INT_MAX;

        if(i % 3 == 0 && min > (dp[i/3] + 1))
            min = dp[i/3] + 1;

        if(i % 2 == 0 && min > (dp[i/2] + 1))
            min = dp[i/2] + 1;
        
        if(min > (dp[i-1] + 1))
            min = dp[i-1] + 1;
        
        dp[i] = min;        
    }

    return dp[N];
}