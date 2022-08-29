#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N); // (1 <= N <= 100)
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}