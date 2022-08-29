#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char N[100] = {0,};
    scanf("%s", N);

    for(int i = strlen(N)-1; i > 0; i--)
    {
        if(N[i] <= 51 && i > 0)
        {
            N[i] = '7';
            N[i-1] = N[i-1] -1;
        }

        else if('5' <= N[i] && N[i] <= '6')
            N[i] = '4';
      
        else if('8' <= N[i] && N[i] <= '9')
            N[i] = '7';
        printf("%d\n", atoi(N));
    }

    if(N[0] <= '3')
    {
        for(int i = 0; i < strlen(N)-1; i++)
            printf("7");
        return 0;
    }
    
    printf("%d", atoi(N));
    return 0;
}