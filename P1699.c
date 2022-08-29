#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxroot(int target);
int squareN(int dp[], int target);

int main(void)
{
    int N, result;
    scanf("%d%*c", &N); // (1 ≤ N ≤ 100,000)

    int *dp = (int *)calloc(N+1, sizeof(int));
    
    result = squareN(dp, N);
    printf("%d\n", result);

    return 0;
}

int maxroot(int target)
{
    int ret = 1;

    while((ret+1) * (ret+1) <= target)
        ret++;

    return ret;
}

int squareN(int dp[], int target)
{
    int i, Q, min = INT_MAX, root = maxroot(target);

    if(target == 0) return 0;

    // 메모이제이션이 되어 있는 경우
    if(dp[target] != 0)
        return dp[target];

    // 메모이제이션이 안되어 있는 제곱수인 경우 
    if(root * root == target)
        return dp[target] = 1;

    // max root 부터 1까지 가능한 경우 모두 판단하기
    for(i = root; i > 0; i--)
    {
        int num = 0;

        Q = target / (i*i);
        num += (Q + squareN(dp, target-Q*i*i));

        if(min > num)
            min = num;
    }

    return dp[target] = min;  
}