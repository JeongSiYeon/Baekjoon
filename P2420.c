#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long N, M, sub;

    scanf("%lld %lld", &N, &M);
    sub = N - M; 

    if(sub < 0) 
        printf("%lld", -sub);
    else 
        printf("%lld", sub);

    return 0;
}