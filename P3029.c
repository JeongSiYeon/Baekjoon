#include <stdio.h>

typedef struct time
{
    int hour;
    int min;
    int sec;
} TIME;

int main(void)
{
    // 현재시간
    // hh:mm:ss (00 <= hh <= 23, 00<= mm, ss <= 59)
    TIME nowT;
    scanf("%d:%d:%d", &nowT.hour, &nowT.min, &nowT.sec);

    // 나트륨을 던질 시간
    // hh:mm:ss (00 <= hh <= 23, 00<= mm, ss <= 59)
    TIME naT;
    scanf("%d:%d:%d", &naT.hour, &naT.min, &naT.sec);

    // 출력
    // 적어도 1초는 기다리고 (현재 시간 < 나트륨 던질 시간)
    // 많아야 24시간 기다린다.
    TIME waiting = {naT.hour-nowT.hour, naT.min-nowT.min, naT.sec-nowT.sec};

    if(waiting.sec == 0 && waiting.min == 0 && waiting.hour == 0)
    {
        printf("24:00:00");
        return 0;
    }

    if(waiting.sec < 0)
    {
        waiting.min--;
        waiting.sec = 60 + waiting.sec;
    }

    if(waiting.min < 0)
    {
        waiting.hour--;
        waiting.min = 60 + waiting.min;
    }

    if(waiting.hour < 0)
    {
        waiting.hour = 24 + waiting.hour;
    }
    
    printf("%02d:%02d:%02d",waiting.hour, waiting.min, waiting.sec);
    return 0;
}