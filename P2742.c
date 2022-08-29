#include <stdio.h>

int main(void)
{
    int N;  // 자연수
    scanf("%d", &N);
    for(int i = N; i >= 1; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}