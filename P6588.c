#include <stdio.h>
#include <stdlib.h>

void eratosthenes(int *primeN);

int main(void)
{
    // 6이상 1 000 000 이하의 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
    // 홀수 소수: 3, 5, 7, 11, 13, 17, ...

    // 각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다.
    // 6 <= n <= 1 000 000인 짝수 정수
    // 입력의 마지막 줄에는 0이 하나 주어진다.

    int i, testcaseN = 0;

    int *primeN = (int *)calloc(1000001, sizeof(int));
    int *evenN  = (int *)calloc(100000, sizeof(int));
    int *first  = (int *)calloc(100000, sizeof(int));
    int *second = (int *)calloc(100000, sizeof(int));

    // calculate primeN 
    eratosthenes(primeN);

    scanf("%d%*c", &evenN[testcaseN]);
    while(evenN[testcaseN] != 0)
    {
        // find first, fron 3
        i = 3;

        // 모든 경우의 수를 찾기 전까지 && 답 찾으면 break
        while(i <= 500000)
        {
            // 가장 최초의 홀수로 이루어진 골드파흐 파티션을 발견한다면
            if(primeN[i] == 0 && primeN[evenN[testcaseN] - i] == 0)
            {
                // 현재 조사하고 있는 i를 first라고 설정
                first[testcaseN] = i;
                // 입력받은 testcaseN에서 i를 뺀, 홀수인 소수라고 검증된 수를 second로 설정
                second[testcaseN] = evenN[testcaseN] - i;
                break;
            }

            // 홀수만 조사한다.
            i+=2;
        }
        
        // testcaseN++
        testcaseN++;

        // input next data
        scanf("%d%*c",  &evenN[testcaseN]);
    }

    for(i = 0; i < testcaseN; i++)
    {
        if(first[i] == 0)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n", evenN[i], first[i], second[i]); 
    }

    return 0;
}

void eratosthenes(int *primeN)
{
    int i, j;

    for(i = 2; i < 1000001; i++)
    {
        j = 2;
        // primeN[i]이 제외되지 않은채 남아있다먄
        if(primeN[i] == 0)
            // i의 배수인 primeN -1 할당
            while(i*j < 1000001)
            {
                primeN[i*j] = -1;
                j++;
            }
    }
    
    primeN[2] = 0;
}