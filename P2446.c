#include <stdio.h>

int main(void)
{
    int i, j, k, N;
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < i; j++)
            printf(" ");
        for(k = j; k < j + (2*(N-i) -1); k++)
            printf("*");
        printf("\n");
    }

    for(i = 1; i < N; i++)
    {
        for(j = 0; j < N-(i+1); j++)
            printf(" ");
        for(k = j; k < j + (2*i+ 1); k++)
            printf("*");
        printf("\n");
    }

    return 0;
}