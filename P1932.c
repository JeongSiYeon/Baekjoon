#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
void dp(int nof, int *memo);

int main(void)
{
    int i, n, maxN = 0;

    scanf("%d%*c", &n);                          // 1 <= n <= 500 

    int *memo = (int *)calloc(n, sizeof(n));
    
    scanf("%d%*c", &memo[0]);
    
    for(i = 1; i < n; i++)
        dp(i+1, memo);
    
    for(i = 0; i < n; i++)
    {
        if(maxN < memo[i])
            maxN = memo[i];
    }

    printf("%d\n", maxN);
    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

void dp(int nof, int *memo)
{
    int i;
    int *input = (int *)calloc(nof, sizeof(int));

    for(i = 0; i < nof; i++)
        scanf("%d%*c", &input[i]);

    memo[nof-1] = memo[nof-2];

    for(i = nof-2; i >= 1; i--)
        memo[i] = max(memo[i-1], memo[i]);

    for(i = 0; i < nof; i++)
        memo[i] += input[i];

    free(input);
}