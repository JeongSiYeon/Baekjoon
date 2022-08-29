#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    if(N / 10000 == 555)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}