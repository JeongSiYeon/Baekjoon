#include <stdio.h>

int main(void)
{
    // A: 300sec, B: 60sec, C: 10sec

    int T;
    int count[3] = {0,}; // count[0]: count_A, count[1]: count_B, count[2]: count_C

    scanf("%d", &T); // 1 <= T(sec) <= 10,000인 정수
    // sol
    if(T / 300 != 0)
    {
        count[0] += T/300;
        T = T - 300 * (T/300);
    }
    if(T / 60 != 0)
    {
        count[1] += T/60;
        T = T - 60 * (T/60);
    }
    if(T / 10 != 0)
    {
        count[2] += T/10;
        T = T - 10 * (T/10);
    }
    if(T == 0)
        printf("%d %d %d", count[0], count[1], count[2]);
    else
        printf("-1");

    return 0;
}