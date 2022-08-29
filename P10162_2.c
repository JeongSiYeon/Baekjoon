#include <stdio.h>

int main(void)
{
    int T = 0, push[3] = {0,};
    scanf("%d", &T);

    if(T / 300 > 0)
    {
        push[0] = T / 300;
        T = T - push[0]*300;
    }
    if(T / 60 > 0)
    {
        push[1] = T / 60;
        T = T - push[1]*60;
    }
    if(T / 10 > 0)
    {
        push[2] = T / 10;
        T = T - push[2]*10;
    }

    if(T != 0)
    {
        printf("-1");
        return 0;
    }

    for(int i = 0; i < 3; i++)
        printf("%d ",push[i]);

    return 0;
}