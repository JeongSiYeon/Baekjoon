#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned short A, B, C, D, min, absolute[3];
    scanf("%hu %hu %hu %hu", &A, &B, &C, &D);

    absolute[0] = abs((A+B)-(C+D));
    absolute[1] = abs((A+C)-(B+D));
    absolute[2] = abs((A+D)-(B+C));

    min = absolute[0];
    for(int i = 1; i < 3; i++)
    {
        if(min > absolute[i])
            min = absolute[i];
    }
    
    printf("%d", min);
    
    return 0;
}