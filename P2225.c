#include <stdio.h>
#include <stdlib.h>

long long decomposition(long long dp[], int target, int into, int K);

int main(void)
{
    int N, K;

    scanf("%d %d%*c", &N, &K);
    if(K == 1)
    {
        printf("1\n");
        return 0;
    }

    long long *dp = (long long *)calloc((N+1)*(K-1), sizeof(long long));

    decomposition(dp, N, K, K);

    printf("%lld", dp[(K-1)*N + K-2]);
    return 0;
}


long long decomposition(long long dp[], int target, int into, int K)
{
    // 1) de(6, 4, 4)
    long long ret = 0;

    if(into == 2)
        return dp[(K-1)*target] = (target + 1);

    if(dp[(K-1)*target + into-2] != 0)
        return dp[(K-1)*target + into-2];

    for(int i = 0; i <= target; i++)
    {
        // 1) 0+ de(6, 3)
        //      0+ de(6, 2) --- return 7
        //      1+ de(5, 2) --- return 6
        //      2+ de(4, 2) --- return 5
        //      3+ de(3, 2) --- return 4
        //      4+ de(2, 2) --- return 3
        //      5+ de(1, 2) --- return 2
        //      6+ de(0, 2) --- return 1

        // 1) de(5, 3) --- 
        // 1) de(4, 3) --- 
        // 1) de(3, 3) --- 
        // 1) de(2, 3) --- 
        // 1) de(1, 3) --- 
        // 1) de(0, 3)

        // 내 예상 K 가 1인 경우에서 뻑난듯
                 

        ret += decomposition(dp, target-i, into-1, K) % 1000000000;
    }

    // printf("%d into %d: %d\n", target, into, ret);
    return dp[(K-1)*target + into-2] = ret % 1000000000;
}