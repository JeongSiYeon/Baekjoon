#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Quarter: $0.25), Dime: $0.10, Nickel: $0.05, Penny: $0.01
    int i = 0;

    // input1: T
    int T;                // 3
    scanf("%d", &T);

    // input2: change (0 <= c <= 500)
    int *C = (int *)calloc(T, sizeof(int));            // 124 25 194
    int *q = (int *)calloc(T, sizeof(int));
    int *d = (int *)calloc(T, sizeof(int));  
    int *n = (int *)calloc(T, sizeof(int));   
    int *p = (int *)calloc(T, sizeof(int));      

    for(i = 0; i < T; i++)
    {
        scanf("%d", &C[i]); 

        if(C[i] / 25 > 0) 
        {
            q[i] = C[i] / 25;                // 124 / 25 => q[0]: 4
            C[i] = C[i] - 25*q[i];           // C[0]: 24
        }

        if(C[i] / 10 > 0) 
        {
            d[i] = C[i] / 10;                
            C[i] = C[i] - 10*d[i];          
        }

        if(C[i] / 5 > 0) 
        {
            n[i] = C[i] / 5;               
            C[i] = C[i] - 5*n[i];         
        }

        p[i] = C[i]; 
    }

    for(i = 0; i < T; i++)
        printf("%d %d %d %d\n", q[i], d[i], n[i], p[i]);

    return 0;
}