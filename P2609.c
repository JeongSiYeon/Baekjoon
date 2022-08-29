#include <stdio.h>

int main(void)
{
    /// input two natural number a, b (1 <= a, b <= 10 000)
    int a, b, GCD, LCM, add;
    scanf("%d %d%*c", &a, &b);

    if(a == b)
    {
        printf("%d\n%d", a, a);
        return 0;
    }

    else if(a > b) // a: 24. b: 18
    {
        GCD = b; // GCD: 18 17 16 15 14 .... 6
        LCM = b; // LCM: 18 36 54 72
        add = b;
    }
    
    else
    {
        GCD = a;
        LCM = a;
        add = a;
    }

    // calculate GCD
    while(a % GCD != 0 || b % GCD != 0)
        GCD--;

    // calculate LCM
    while(LCM % a != 0 || LCM % b != 0)
        LCM += add;

    // output: Greatest common divisor, least common multiple
    printf("%d\n%d", GCD, LCM);
    return 0;
}