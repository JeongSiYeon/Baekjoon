#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, T, A, B, add; // 1 <= A, B <= 45 000, NN)

    scanf("%d%*c", &T);
    int *LCM = (int *)calloc(T, sizeof(int));

    for(i = 0; i < T; i++)
    {
        scanf("%d %d%*c", &A, &B);

        if(A >= B) 
        {
            LCM[i] = B; 
            add = B;
        }
    
        else
        {
            LCM[i] = A;
            add = A;
        }

        // calculate LCM
        while(LCM[i] % A != 0 || LCM[i] % B != 0)
            LCM[i] += add;
    }

    for(i = 0; i < T; i++)
        printf("%d\n", LCM[i]);

    return 0;
}