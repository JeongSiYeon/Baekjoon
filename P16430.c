#include <stdio.h>

void abbreviation(int *n1, int *n2, int div);

int main(void)
{
    int A, B, numer, denomin;

    scanf("%d %d", &A, &B);
    numer   = B-A;
    denomin = B;
    
    abbreviation(&numer, &denomin, 2);
    abbreviation(&numer, &denomin, 3);

    printf("%d %d", numer, denomin);
    return 0;
}

void abbreviation(int *n1, int *n2, int div)
{
    while(*n1%div == 0 && *n2%div == 0)
    {
        (*n1) = (*n1) / div;
        (*n2) = (*n2) / div;
    }
}