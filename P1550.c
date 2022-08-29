#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i = 0, j = 0;
    double dec = 0; 
    char hexa[10], temp[3];    /
    gets(hexa);  

    for(i = strlen(hexa)-1; i >= 0; i--)
    {
        // 숫자 1부터 9인 경우
        if (atoi(&hexa[i]) != 0)    
        {
            dec += (atoi(&hexa[i]) * pow(16, j)); 
        }
        // atoi 결과 0 중 숫자 0인 경우
        else if(hexa[i] == 48) 
        {
            hexa[i] = '\0';
        }
        // atoi 결과 0 중문자인 경우
        else 
        {
            dec += ((hexa[i]-55)* pow(16, j)); // 'A' == 41 / 'B' == 42 / ...
        }

        hexa[i] = '\0';
        j++;
    }
    printf("%.0lf", dec);
    return 0;
}