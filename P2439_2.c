#include <stdio.h>

int main(void)
{
    // input: N (1 <= N <= 100)
    int N, i = 0, j = 0, k = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {   
        for(j = 0; j < N-(i+1); j++)
            printf(" ");

        for(k = j; k < N; k++)
            printf("*");

        printf("\n");
    }

    return 0;
}