#include <stdio.h>

int main(void)
{
    int N, i = 0;
    scanf("%d", &N); // (1 <= N <= 9)

    for(i = 1; i < 10; i++)
    {
        printf("%d * %d = %d\n", N, i, N*i);
    }

    return 0;
}