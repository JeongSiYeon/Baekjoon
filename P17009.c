#include <stdio.h>

int main(void)
{
    int i, A[3], B[3], tot_A = 0, tot_B = 0;

    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &A[i]);  // 0 ~ 100
        tot_A += (3-i)*A[i];
    }

    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &B[i]);
        tot_B += (3-i)*B[i];
    }

    if(tot_A > tot_B)
        printf("A\n");
    else if(tot_A < tot_B)
        printf("B\n");
    else
        printf("T\n");

    return 0;
}