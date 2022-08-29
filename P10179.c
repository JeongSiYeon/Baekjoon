#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main(void)
{
    int N;
    double *price = (double *)malloc(sizeof(double)*N);
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf%*c", &price[i]);
    }
    
    for(int i = 0; i < N; i++)
        printf("$%.2lf\n", round((price[i]*0.8) * 100) / 100);

    free(price);
    return 0;
}