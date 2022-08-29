#include <stdio.h>

int main(void)
{
    short A,B,C,D,E;

    scanf("%hd%*c", &A);
    scanf("%hd%*c", &B);
    scanf("%hd%*c", &C);
    scanf("%hd%*c", &D);
    scanf("%hd%*c", &E);
    
    if(A < 0)
        printf("%hd", (-A)*C + D + (B*E));
    else
        printf("%hd", (B-A)*E);

    return 0;
}