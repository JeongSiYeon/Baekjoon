#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, M, N;
    scanf("%d %d%*c", &M, &N);                             // 1 <= M <= N <= 1 000 000

    int *primeN = (int *)calloc(N+1, sizeof(int));

    primeN[0] = -1;
    primeN[1] = -1;

    for(i = 2; i <= N; i++)
        for(j = 2; i*j <= N; j++)
            primeN[i*j] = -1;
    
    for(i = M; i <= N; i++)
        if(primeN[i] == 0)
            printf("%d\n", i);

    return 0;
}