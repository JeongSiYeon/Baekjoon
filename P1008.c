#include <stdio.h>

int main(void)
{
    int A, B;
    double ret;

    scanf("%d %d", &A, &B);
    ret = (double)A / (double)B;

    printf("%.15lf\n", ret);
    
    return 0;
}