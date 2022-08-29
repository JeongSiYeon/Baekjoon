#include <stdio.h>

int main(void)
{
    long long N, M;
    scanf("%lld %lld", &N, &M);
    if(N == M) printf("1");
    else       printf("0");

    return 0;
}
