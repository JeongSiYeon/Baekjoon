#include <stdio.h>

int factorial(int N);

int main(void)
{
    int N;
    scanf("%d%*c", &N);

    printf("%d\n", factorial(N));
    return 0;
}

int factorial(int N)
{
    if(N == 0)
        return 1;
    return N * factorial(N-1);
}