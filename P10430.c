#include <stdio.h>

int main(void)
{
    int A, B, C; // 2 <= A, B, C <= 10 000
    scanf("%d %d %d%*c", &A, &B, &C);

    printf("%d\n", (A+B)%C);
    printf("%d\n", ((A%C) + (B%C))%C);
    printf("%d\n", (A*B)%C);
    printf("%d\n", ((A%C) * (B%C))%C);

    return 0;
}