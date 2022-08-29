#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int gcd(int a, int b);

int main(void)
{
    int i, j, k, testcaseN, nof;
    scanf("%d%*c", &testcaseN);

    long long *result = (long long *)calloc(testcaseN, sizeof(long long));

    for(i = 0; i < testcaseN; i++)
    {
        scanf("%d%*c", &nof);
        int *number = (int *)calloc(nof, sizeof(int));

        for(j = 0; j < nof; j++)
            scanf("%d%*c", &number[j]);
        
        for(j = 0; j < nof-1; j++)
            for(k = j+1; k < nof; k++)
                result[i] += gcd(number[j], number[k]);
        
        free(number);
    }

    for(i = 0; i < testcaseN; i++)
        printf("%lld\n", result[i]);

    free(result);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;

    if(*a < *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }    
}

int gcd(int a, int b)
{
    swap(&a, &b);
    if(b == 0) return a;
    return gcd(b, a%b);
}