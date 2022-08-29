#include <stdio.h>

int main(void)
{
    // input: N (1 <= N <= 100)
    int N, i = 0, j = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        for(j = N; j > i; j--)
            printf("*");
        printf("\n");
    }

    return 0;
}