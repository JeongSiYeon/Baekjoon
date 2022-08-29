#include <stdio.h>

int main(void)
{
    short N, M;
    scanf("%hd %hd", &N, &M);

    if(M <= 2)
        printf("NEWBIE!\n");
    else if(M <= N)
        printf("OLDBIE!\n");
    else
        printf("TLE!\n");
    return 0;
}