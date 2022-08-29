#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    char N[100];
    int i, system, len = 0, digitN = 0;

    // N(system)
    scanf("%s%*c", N);
    // system
    scanf("%d%*c", &system);

    len = strlen(N);
    for(i = 0; i < len; i++)
    {
        if(48 <= N[i] && N[i] <= 57)
            N[i] = N[i] - 48;
        else
            N[i] = N[i] - 55;
            
        digitN += N[i] * (int)pow(system, len-i-1);
    }

    printf("%d\n", digitN);
    return 0;
}