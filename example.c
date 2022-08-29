#include <stdio.h>
#define SQR(X) ((X)*(X))
#define PRT(X) printf("계산 결과는 %d입니다.\n", X);

int main(void)
{
    int result;
    int x ;

    result = SQR(10);
    PRT(result);
    
    x=5;
    x+=3;
    result=SQR(x);
    printf("%d\n", x);
    PRT(result);

    x=10;
    result=SQR(x+3);
    PRT(result);
    

    return 0;
}