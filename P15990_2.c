#include <stdio.h>
#include <stdlib.h>

int dp(int N, int *memo_tot, int *memo_1, int *memo_2, int *memo_3);

int main(void)
{
    int i, T;
    int result;

    int *memo_tot = (int *)calloc(100001, sizeof(int));
    int *memo_1   = (int *)calloc(100001, sizeof(int));
    int *memo_2   = (int *)calloc(100001, sizeof(int));
    int *memo_3   = (int *)calloc(100001, sizeof(int));

    memo_tot[0] = 0;
    memo_tot[1] = 1;
    memo_tot[2] = 1;
    memo_tot[3] = 3;

    memo_1[1] = 1;
    memo_2[2] = 1;

    memo_1[3] = 1;
    memo_2[3] = 1;
    memo_3[3] = 1;

    for(i = 4; i < 100000; i++)
        memo_tot[i] = -1;

    scanf("%d%*c", &T);
    int *num = (int *)calloc(T, sizeof(int));                      // 0 < n <= 100 000

    for(i = 0; i < T; i++)
        scanf("%d%*c", &num[i]);

    for(i = 0; i < T; i++)
        printf("%d\n", dp(num[i], memo_tot, memo_1, memo_2, memo_3));

    free(memo_1);
    free(memo_2);
    free(memo_3);
    free(memo_tot);

    return 0;
}

int dp(int N, int *memo_tot, int *memo_1, int *memo_2, int *memo_3)
{    
    printf("dp %d\n", N);

    if(memo_tot[N] != -1)
        return memo_tot[N];
        
    dp(N-1, memo_tot, memo_1, memo_2, memo_3);
    
    memo_1[N] = (memo_2[N-1] + memo_3[N-1])%1000000009;
    printf("memo_1[%d]: %d\n", N, memo_1[N]);

    memo_2[N] = (memo_1[N-2] + memo_3[N-2])%1000000009;
    printf("memo_2[%d]: %d\n", N, memo_2[N]);
    
    memo_3[N] = (memo_1[N-3] + memo_2[N-3])%1000000009;
    printf("memo_3[%d]: %d\n", N, memo_3[N]);
    
    return memo_tot[N] = ( (memo_1[N] + memo_2[N])%1000000009 + memo_3[N])%1000000009;
}