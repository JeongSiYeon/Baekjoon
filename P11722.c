#include <stdio.h>
#include <stdlib.h>

int dp(int N, int *series, int *memo, int targetIDX);

int main(void)
{
    int i, N, result, max = 0; 
    scanf("%d%*c", &N);                                 // 1 <= N <= 1000

    int *series = (int *)calloc(N, sizeof(int));
    int *memo   = (int *)calloc(N, sizeof(int));

    for(i = 0; i < N; i ++)
        scanf("%d%*c", &series[i]);                    // 1 <= series[i] <= 1000

    for(i = N-1 ; i >= 0; i--)
    {
        result = dp(N, series, memo, i);
        if(max < result) 
            max = result; 
    }        

    printf("%d\n", max);
    return 0;
}

int dp(int N, int *series, int *memo, int targetIDX)
{
    for(int i = targetIDX+1; i < N; i++)
        if(series[targetIDX] > series[i] && memo[targetIDX] < 1 + memo[i])
            memo[targetIDX] = 1 + memo[i];
    
    if(memo[targetIDX] == 0)
        memo[targetIDX] = 1;
    
    return memo[targetIDX];
}