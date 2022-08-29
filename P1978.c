#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

int main(void)
{
    int i, N, primenC = 0; // 1 <= N <= 100
    
    scanf("%d%*c", &N);
    int *n = (int *)calloc(N, sizeof(int));

    for(i = 0; i < N; i++)
    {
        scanf("%d%*c", &n[i]);
        if(isPrime(n[i]) == 1)
            primenC++;
    }

    printf("%d\n", primenC);
    return 0;
}

// 주어진 자연수 n이 소수인지 확인한다.
int isPrime(int n)
{
    // special case: 1과 2는 예외 처리
    if(n <= 1) return 0;
    if(n == 2) return 1;
    // 2를 제외한 모든 짝수는 소수가 아니다.
    if(n % 2 == 0) return 0;

    int sqrtn = (int)round(sqrt((double)n));
    // 대칭 관계를 이용해서 3이상 sqrtn이하 홀수들만 판별해보자
    for(int div = 3; div <= sqrtn; div+= 2)
        if(n % div == 0) return 0;
    
    return 1;
}