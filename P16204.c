#include <stdio.h>

int main(void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    if(M == K)
        printf("%d", N);
    else
        if(M > K)
            printf("%d", K + (N-M));
        else
            printf("%d", M + (N-K));

    return 0;
}