#include <stdio.h>
#include <stdlib.h>

void calculate(int *dp, int N);

int main(void)
{
    int i, T;
    int dp[11] = {0,};

    scanf("%d%*c", &T);
    int *testcase = (int *)calloc(T+1, sizeof(int));
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(i = 1; i <= T; i++)
    {
        scanf("%d%*c", &testcase[i]);
        if(dp[testcase[i]] == 0)
            calculate(dp, testcase[i]);
    }

    for(i = 1; i <= T; i++)
        printf("%d\n", dp[testcase[i]]);

    return 0;
}

void calculate(int *dp, int N)
{
    if(dp[N-1] == 0)
        calculate(dp, N-1);
    if(dp[N-2] == 0)
        calculate(dp, N-2);
    if(dp[N-3] == 0)
        calculate(dp, N-3);
    
    dp[N] = dp[N-1] + dp[N-2] + dp[N-3];
}