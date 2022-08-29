#include <stdio.h>

int main(void)
{
    int date, car[5], count = 0;
    scanf("%d%*c", &date);
    scanf("%d %d %d %d %d", &car[0], &car[1], &car[2], &car[3], &car[4]);

    for(int i = 0; i < 5; i++)
    {
        if(date == car[i])
            count++;
    }
    printf("%d", count);
}