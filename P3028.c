#include <stdio.h>

#define left   1
#define middle 2
#define right  3

int main(void)
{
    int i = 0, state = 1;
    char mix[51];
    scanf("%s", mix);

    while(mix[i] != '\0')
    {
        if(mix[i] == 'A')
        {
            if(state == 1) state = 2;
            else if(state == 2) state = 1;
        }
        else if(mix[i] == 'B')
        {
            if(state == 2) state = 3;
            else if(state == 3) state = 2;
        }
        else 
        {
            if(state == 1) state = 3;
            else if(state == 3) state = 1;
        }
        i++;
    }
    printf("%d", state);

    return 0;
}