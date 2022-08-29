#include <stdio.h>

int main(void)
{
    int pay, count = 0;
    scanf("%d", &pay);

    pay = 1000-pay;

    if(pay / 500 > 0)
    {
        count += pay / 500;
        pay -= 500 * (pay / 500);
    }
    if(pay / 100 > 0)
    {
        count += pay / 100;
        pay -= 100 * (pay / 100);
    }
    if(pay / 50 > 0)
    {
        count += pay / 50;
        pay -= 50 * (pay / 50);
    }
    if(pay / 10 > 0)
    {
        count += pay / 10;
        pay -= 10 * (pay / 10);
    }
    if(pay / 5 > 0)
    {
        count += pay / 5;
        pay -= 5 * (pay / 5);
    }
    
    count += pay;

    printf("%d", count);
    return 0;
}