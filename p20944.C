#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{    
    // 입력
    // N (1 <= N <= 1,000,000 인 정수)
    int N, i = 0;
    scanf("%d", &N);

    char *string = (char *)malloc(sizeof(char)*500005);
    for(i = 0; i < N; i++)
    {
        printf("%c", 'a');
    }

    return 0;
}