#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long one, two, sum;

    char A[8], B[8], C[8], D[8];
    char first[16], second[16];
    scanf("%s %s %s %s%*c", A, B, C, D);

    strcpy(first, A);
    strcpy(&first[strlen(A)], B);

    strcpy(second, C);
    strcpy(&second[strlen(C)], D);

    one = atoll(first);
    two = atoll(second);
    sum = one + two;

    printf("%lld\n", sum);
    return 0;
}