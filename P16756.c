#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int N;
    long long min = LLONG_MAX;
    scanf("%d", &N); // (2 <= N <= 100 000)

    long long *num = (long long *)calloc(N, sizeof(long long)); // -1 000 000 000 <= num <= 1 000 000 000
    long long *differ = (long long *)calloc(N-1, sizeof(long long));  // 0으로 초기화함

    for(int i = 0; i < N; i++)
    {
        scanf("%lld%*c", &num[i]);
        if(i != 0) differ[i-1] = abs(num[i]-num[i-1]);
    }

    for(int i = 0; i < N-1; i++)
    {
        if(differ[i] == 0)
        {
            printf("0");
            return 0;
        }
        else
            if(min > differ[i]) min = differ[i];
    }

    printf("%d\n", min);

    // 2
    // num을 받으면서 2개 원소 사이의 값도 저장 그 중 가장 작은 부분으로 정하자
    // special case: 한 바퀴 싹 돌면서 0이 나오는 순간 printf("0"); return 0; 종료
    // general case: 사이 값 중 가장 최소인 값이 해이다.
    // 정당성 증명
    // 0) 사이값이 나올 경우: interval을 확장하는 의미가 없어짐. interval에서 핵심사항은 max와 min임
    // 1) 큰 수 또는 작은 수가 나올 경우: 차이가 더 커지거나 작아짐
    // 2) 같은 수가 나올 경우: 의미 없음. 최대 최소 변하지 않음.

    // output: the minimum value of an interval.

    return 0;
}