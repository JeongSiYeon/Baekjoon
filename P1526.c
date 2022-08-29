#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i, j, length;
    char N[15] = {0,};

    scanf("%s", N);
    length = strlen(N);

    for(i = 0; i < length; i++)
    {
        if('8' <= N[i] && N[i] <= '9')
        {
            for(j = i; j < length; j++)
                N[j] = '7';
            break;
        }
        else if('5' <= N[i] && N[i] <= '6')
        {
            N[i] = '4';
            for(j = i+1; j < length; j++)
                N[j] = '7';
            break;
        }
        else if('1' <= N[i] && N[i] <= '3')
        {
            N[i] = '0';
            for(int j = i+1; j < length; j++)
                N[j] = '7';
            break;
        }
        // 0의 경우를 생각 못했네..
        else if( N[i] == '0' && i > 0 )
        {
            N[i-1]--;
            for(int j = i; j < length; j++)
                N[j] = '7';
            i -= 2;
        }
    }

    for(i = 0; i < length; i++)
        if(N[i] != '0') printf("%c", N[i]);

    return 0;
}

