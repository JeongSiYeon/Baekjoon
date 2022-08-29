#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("address of sum: %d", sum);
}