#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int dp(int n, int *row_0, int *row_1);

int main(void)
{
    int i, j, T, n;

    scanf("%d%*c", &T);
    
    int *result = calloc(T, sizeof(int));
    int *row_0  = calloc(100001, sizeof(int));     // 0 <= score <= 100 인 정수
    int *row_1  = calloc(100001, sizeof(int));     // 0 <= score <= 100 인 정수

    for(i = 0; i < T; i++)
    {
        scanf("%d%*c", &n);

        for(j = 1; j < n+1; j++)
            scanf("%d%*c", &row_0[j]);
        
        for(j = 1; j < n+1; j++)
            scanf("%d%*c", &row_1[j]);
        
        result[i] = dp(n, row_0, row_1);  
    }

    for(i = 0; i < T; i++)
        printf("%d\n", result[i]);

    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int dp(int n, int *row_0, int *row_1)
{
    int ret;

    int *memo_0 = (int *)calloc(n+1, sizeof(int));
    int *memo_1 = (int *)calloc(n+1, sizeof(int));

    memo_0[1] = row_0[1];
    memo_1[1] = row_1[1];

    for(int i = 2; i < n+1; i++)
    {
        memo_0[i] = row_0[i] + max(memo_1[i-2], memo_1[i-1]);
        memo_1[i] = row_1[i] + max(memo_0[i-2], memo_0[i-1]);
    }

    ret = max(memo_0[n], memo_1[n]);

    free(memo_0);
    free(memo_1);

    return ret;
}