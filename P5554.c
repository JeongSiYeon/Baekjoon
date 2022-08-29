#include <stdio.h>

int main(void)
{   
    int HS, SP, PA, AH, hour, min;
    scanf("%d", &HS);
    scanf("%d", &SP);
    scanf("%d", &PA);
    scanf("%d", &AH);

    hour = (HS + SP + PA + AH) / 60;
    min = (HS + SP + PA + AH) % 60;

    printf("%d\n", hour);
    printf("%d\n", min);

    return 0;
}