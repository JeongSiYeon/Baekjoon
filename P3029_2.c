#include <stdio.h>

typedef struct _time
{
    short hour; // 0 <= hour <= 23
    short min;  // 0 <=  min <= 59
    short sec;  // 0 <=  sec <= 59
} TIME;

int main(void)
{
    TIME now, throw, waiting;

    scanf("%hd:%hd:%hd%*c", &now.hour, &now.min, &now.sec);
    scanf("%hd:%hd:%hd%*c", &throw.hour, &throw.min, &throw.sec);

    // special case: waiting time == (24:00:00)
    if(now.hour == throw.hour && now.min == throw.min && now.sec == throw.sec)
        printf("24:00:00");
    else
    {
        waiting.sec = throw.sec - now.sec;
        if(waiting.sec < 0)
        {
            waiting.sec += 60;
            throw.min--;
        }

        waiting.min = throw.min - now.min;
        if(waiting.min < 0)
        {
            waiting.min += 60;
            throw.hour--;
        }

        waiting.hour = throw.hour - now.hour;
        if(waiting.hour < 0)
            waiting.hour += 24;
        
        printf("%02hd:%02hd:%02hd\n", waiting.hour, waiting.min, waiting.sec);        
    }
    return 0;
}