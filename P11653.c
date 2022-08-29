#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, N, primeN;
    int *primeNs  = (int *)calloc(10000001, sizeof(int));
    primeNs[0] = -1;
    primeNs[1] = -1;

    scanf("%d%*c", &N);
    if(N == 1)
        return 0;

    // factorization in prime factors
    primeN = 2;
    while(N > 1)
    {
        if(primeNs[primeN] != -1)
        {
            while(N % primeN == 0)
            {
                printf("%d\n", primeN);
                N /= primeN;
            }
            
            i = 2;
            
            while(primeN*i < 10000001)
            {
                primeNs[primeN*i] = -1;
                i++;
            }
        }
        
        primeN++;
    }

    return 0;
}