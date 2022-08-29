#include <stdio.h>

int main(void)
{
    short A, B, C, D;

    scanf("%hd %hd", &A, &B);           // 0 <= A, B <= 1,000
    scanf("%*c %hd %hd", &C, &D);       // 0 <= C, D <= 1,000

    if(A+D >= B+C)
        printf("%hd", B+C);
    else
        printf("%hd", A+D);

    return 0;
}