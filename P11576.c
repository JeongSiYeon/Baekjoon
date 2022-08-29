#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    // A진법 -> B진법
    int i, A, B, m, num, nof = 0, digitN = 0;
    int *result = (int *)calloc(20, sizeof(int));

    scanf("%d %d%*c", &A, &B);                          // 2 <= A, B <= 30
    scanf("%d%*c", &m);                                 // 1 <= m <= 25

    // A -> 10(50)
    for(i = m-1; i >= 0; i--)
    {
        scanf("%d%*c", &num);                           
        digitN += num * (int)pow(A, i);
    }

    // 10 -> B(8)
    while(digitN > 0)
    {
        result[nof] = digitN % B;
        digitN /= B;
        nof++;
    }

    for(i = nof-1; i >= 0; i--)
        printf("%d ", result[i]);

    return 0;
}