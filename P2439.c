#include <stdio.h>

int main(void)
{
    int N, i = 0, j = 0;
    char star[101];
    scanf("%d", &N); // (1 <= N <= 100)

    for(i = 0; i < N; i++)
    {
        star[i] = ' ';
    }

    star[i] = '\0';
    
    for(j = N-1; j >= 0; j--)
    {
        star[j] = '*';
        printf("%s\n", star);
    }
    return 0;
}