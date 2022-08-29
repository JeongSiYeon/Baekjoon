#include <stdio.h>

int main(void)
{
    short count = 0, T, response[5];
    scanf("%hd%*c", &T);
    scanf("%hd %hd %hd %hd %hd", &response[0], &response[1], &response[2], &response[3], &response[4]);

    for(int i = 0; i < 5 ; i++)
    {
        if(T == response[i])
            count++;
    }

    printf("%hd", count);
    return 0;
}