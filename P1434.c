#include <stdio.h>
#include <malloc.h>

int main(void)
{
    // input
    int N, M, i = 0, j = 0, waste = 0;
    int *A = (int *)malloc(sizeof(int)*N);
    int *B = (int *)malloc(sizeof(int)*M);

    scanf("%d %d%*c", &N, &M);

    for(i = 0; i < N; i++)
        scanf("%d%*c", &A[i]);

    for(i = 0; i < M; i++)
        scanf("%d%*c", &B[i]);
    
    // i loop B, j loop A
    for(i = 0; i < M; i++)
    {
        while(B[i] != 0)
        {
            if(A[j] >= B[i])
            {
                A[j] -= B[i];
                B[i] = 0;
            }
            else
                j++;
        }
    }

    for(i = 0; i < N; i++)
        waste += A[i];    

    printf("%d\n", waste);
    return 0;
}