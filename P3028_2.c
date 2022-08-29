#include <stdio.h>

int main(void)
{
    // init location of ball: 1
    int i = 0, state = 1;

    // input: A,B,C로 구성된 최대 길이 50 문자열
    char mix[51];
    scanf("%s", mix);

    // solution
    while(mix[i] != '\0')
    {
        if(mix[i] == 'A' && (state == 1 || state == 2))
        {
            if(state == 1) state = 2;
            else           state = 1;
        }

        if(mix[i] == 'B' && (state == 2 || state == 3))
        {
            if(state == 2) state = 3;
            else           state = 2;
        }

        if(mix[i] == 'C' && (state == 1 || state == 3))
        {
            if(state == 1) state = 3;
            else           state = 1;
        }
        i++;
    }

    printf("%d", state);
    return 0;
}