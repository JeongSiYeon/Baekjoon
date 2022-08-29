#include <stdio.h>
#include <stdlib.h>

int f(int *dpp, int N);

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
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i = 3; i <= N; i++)
        dp[i] = (dp[i-1]%10007 + dp[i-2]%10007 + dp[i-2]%10007)%10007;
    
    return dp[N];
}