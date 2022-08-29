#include <stdio.h>
#include <stdlib.h>

int dp(int series[], int memo[], int start, int N);

int main(void)
{
    int i, N, result, max_length = 1;

    scanf("%d%*c", &N);                              // 1 <= N <= 1000

    int *series = (int *)calloc(N, sizeof(int));
    int *memo   = (int *)calloc(N, sizeof(int));

    for(i = 0; i < N; i++)                           // 1 <= ai <= 1000
    {
        memo[i] = -1;
        scanf("%d%*c", &series[i]);
    }    
    
    for(i = 0; i < N; i++)
        dp(series, memo, i, N);

    for(i = 0; i < N; i++)
        if(max_length < memo[i])
            max_length = memo[i];

    printf("%d\n", max_length);
    return 0;
}

int dp(int series[], int memo[], int start, int N)
{
    int i, j, max_length = 1;

    // dp
    if(memo[start] != -1)
        return memo[start];

    // finish condition
    if(start == N-1)
        return memo[N-1] = 1;

    i = start+1;

    while(max_length <= N-i)
    {
        if(series[start] < series[i])
        {
            memo[i] = dp(series, memo, i, N);

            if(max_length < 1 + memo[i])
                max_length = 1 + memo[i];
        }

        i++;
    }

    return memo[start] = max_length;
}
