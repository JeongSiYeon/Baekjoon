#include <stdio.h>
#include <stdlib.h>

long long dp(long long *memo, int N);

int main(void)
{
    int N;
    scanf("%d%*c", &N);

    if(N % 2 == 1)
    {
        printf("0\n");
        return 0;
    }

    long long *memo = (long long *)calloc(N+1, sizeof(long long));

    printf("%lld\n", dp(memo, N));
    return 0;
}

long long dp(long long *memo, int N)
{
    if(memo[N] != 0)
        return memo[N];

    if(N == 2) 
        return memo[N] = 3;

    for(int i = 2; i < N; i+=2)
        memo[N] += (dp(memo, i) * dp(memo, N-i));
    
    return memo[N] = memo[N] + 2;
}