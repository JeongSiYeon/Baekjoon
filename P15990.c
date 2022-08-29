#include <stdio.h>
#include <stdlib.h>

long long dp(int N, int before, int *memo);

int main(void)
{
    int i, T;
    int *memo = (int *)calloc(1000001, sizeof(int));

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 3;

    scanf("%d%*c", &T);
    int *num = (int *)calloc(T, sizeof(int));                      // 0 < n <= 1 000 000

    for(i = 0; i < T; i++)
        scanf("%d%*c", &num[i]);

    for(i = 0; i < T; i++)
        printf("%lld\n", dp(num[i], 0, memo));

    return 0;
}

long long dp(int N, int before, int *memo)
{    
    if(N == 0)
        return memo[0];

    if(memo[N] != 0)
        return memo[N];

    if(before != 0)
        memo[N] -= dp(N-before, 0, memo);
    
    if(N <= 2)
        return memo[N] = 1;
    
    if(N == 3)
        return memo[3] = 3;
    

    memo[N] = (dp(N-1, 1, memo)%1000000009 + dp(N-2, 2, memo)%1000000009 + dp(N-3, 3, memo)%1000000009)%1000000009;
    printf("memo[%d]: %d\n", N, memo[N]);
    return memo[N];
}