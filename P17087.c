#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void in_prime_factor(int N, int *pf, int *len);

int main(void)
{
    int i, j = 0;
    int sisterN, subin_loc, sister_loc, len = 0, D;
    int *pf = (int *)calloc(1000, sizeof(int));

    scanf("%d %d%*c", &sisterN, &subin_loc); 
    scanf("%d%*c", &D);

    D = abs(D-subin_loc);

    in_prime_factor(D, pf, &len);

    for(j = len-1; j >= 0; j--)
        pf[len + abs(j-len) -1] = D/pf[j];

    j = 1;
    for(i = 1; i < sisterN; i++)
    {
        scanf("%d%*c", &sister_loc);

        sister_loc -= subin_loc;

        while(sister_loc % D != 0)
        {
            D = pf[2*len-1-j];
            j++;
        }
    }

    printf("%d\n", D);
    return 0;
}

void in_prime_factor(int N, int *pf, int *len)
{
    int number = 1;
    pf[0] = 1;
    *len = 1;

    for(number = 2; number <= (int)sqrt((double)N); number++)
    {
        if(N % number == 0)
        {
            pf[(*len)] = number;
            (*len)++;
        }     
    }      
}