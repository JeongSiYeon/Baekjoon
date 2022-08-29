#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int approx  = 0, mushroon[10] = {0,}; // 1 <= mush <= 100

    for(int i = 0; i < 10; i++)
        scanf("%d%*c", &mushroon[i]);

    for(int i = 0; i < 10; i++)
    {
        if( abs(100-approx) >= abs(100-(approx+mushroon[i])) )
            approx += mushroon[i];
        else
            break;
    }

    printf("%d\n", approx);
    return 0;
}