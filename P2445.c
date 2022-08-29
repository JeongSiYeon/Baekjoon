#include <stdio.h>

int main(void)
{
    int i, j, k, l, N;
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < i+1; j++)
            printf("*");
        for(k = j; k <= (j + (2*N-2*j) -1); k++)
            printf(" ");
        for(l = k; l < k + i+1; l++)
            printf("*");
        printf("\n");
    }

    for(i = N-1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
            printf("*");
        for(k = j; k < (j + 2*(N - j)); k++)
            printf(" ");
        for(l = k; l < k + i; l++)
            printf("*");
        printf("\n");
    }

    return 0;
}