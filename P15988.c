#include <stdio.h>
#include <stdlib.h>

long long dp(int N, int *memo);

int main(void)
{
    int i, T;
    int *memo = (int *)calloc(1000001, sizeof(int));

    scanf("%d%*c", &T);
    int *num = (int *)calloc(T, sizeof(int));                      // 0 < n <= 1 000 000

    for(i = 0; i < T; i++)
        scanf("%d%*c", &num[i]);

    for(i = 0; i < T; i++)
        printf("%lld\n", dp(num[i], memo));

    return 0;
}

long long dp(int N, int *memo)
{
    if(memo[N] != 0)
        return memo[N];
    
    if(N <= 2)
        return memo[N] = N;
    
    if(N == 3)
        return memo[3] = 4;

    return memo[N] = (dp(N-1, memo)%1000000009 + dp(N-2, memo)%1000000009 + dp(N-3, memo)%1000000009)%1000000009;
}