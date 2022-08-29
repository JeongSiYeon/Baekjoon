#include <stdio.h>
#include <stdlib.h>
// 와.. atoi의 배신 그리고 문제 안 읽는 나
int main(void)
{
    int i = 0, x_state = 0, y_state = 0;
    char x[7], y[7];


    // input
    scanf("%s %s", x,y); // alphbet or number(0~9)

    // is there any char?
    while(x[i] != '\0')
    {
        if(x[i] >= 65)
        {
            x_state = 1;
            break;
        }
        i++;
    }
    i = 0;

    while(y[i] != '\0')
    {
        if(y[i] >= 65)
        {
            y_state = 1;
            break;
        }
        i++;
    }

    if(x_state + y_state == 0)
        printf("%d", atoi(x)-atoi(y));
    else
        printf("NaN");

    return 0;
}