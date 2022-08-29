#include <stdio.h>

int main(void)
{
    short A, B, C, D;

    scanf_s("%hd %hd%*c", &A, &B);           // 0 <= A, B <= 1,000
    scanf_s("%hd %hd", &C, &D);       // 0 <= C, D <= 1,000

    printf("%hd %hd %hd %hd\n", A, B, C, D);

    if (A + D >= B + C)
        printf("%hd", B + C);
    else
        printf("%hd", A + D);

    return 0;
}