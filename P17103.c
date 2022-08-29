#include <stdio.h>
#include <stdlib.h>

int *Sieve_of_Eratosthene(int range);
int  Goldbach(int N, int *primeN);

int main(void)
{
    int i, T;
    scanf("%d%*c", &T);

    int *testcase = (int *)calloc(T, sizeof(int));
    int *result   = (int *)calloc(T, sizeof(int));
    int *primeN   = Sieve_of_Eratosthene(1000000);

    // 인덱스인가 실제 숫자인가가 관건이야
    for(i = 0; i < T; i++)
    {
        scanf("%d%*c", &testcase[i]);               // 2 <= testcase_i <= 1 000 000 인 짝수
        result[i] = Goldbach(testcase[i], primeN);
    }

    for(i = 0; i < T; i++)
        printf("%d\n", result[testcase[i]]);

    return 0;
}

// 인덱스의 요소값이 0이면 해당 인덱스는 소수
int *Sieve_of_Eratosthene(int range)
{
    int i, j;

    int *SOF = (int *)calloc(range+1, sizeof(int));
    SOF[0] = -1;
    SOF[1] = -1;

    for(i = 2; i <= range; i++)
    {
        j = 2;
        while(i*j <= range)
        {
            if(SOF[i*j] != -1) SOF[i*j] = -1;
            j++;
        }
    }

    return SOF;
}

// N - (2 ~ N보다 작은 primeN) = 소수이면 count++;
int Goldbach(int N, int *primeN)
{
    printf("GoldBach %d\n", N);
    
    int count = 0, i = 2;

    while(primeN[i] <= N/2)
    {
        if(primeN[N - primeN[i]] == 0)
            count++;

        while(primeN[i] != -1)
            i++;
    }

    return count;
}