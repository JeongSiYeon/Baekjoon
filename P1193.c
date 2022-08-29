#include <stdio.h>

int main(void)
{
    int lineN = 1, X, from = 0, to = 1;
    scanf("%d", &X);

    while(!(from < X && X <= to))
    {
        lineN++;
        from = to;
        to = from + lineN;
    }

    if(lineN % 2 == 0)
        printf("%d/%d\n", lineN-(to-X), 1+(to-X));
    else
        printf("%d/%d\n", 1+(to-X), lineN-(to-X));

    return 0;
}