#include <stdio.h>

void array_copy_init(long long *dest, long long *arr);

int main(void)
{
    int i, j, N;
    long long before[10] = {0, }, after[10] = {0, }, result = 0;

    for(i = 0; i < 10; i++)
        after[i] = 1;
    after[0] = 0;

    scanf("%d%*c", &N);
    for(i = 1; i < N; i++)
    {
        array_copy_init(before, after);

        for(j = 0; j < 10; j++)
        {
            if(j == 0)
                after[1] += before[0] % 1000000000;
            else if(j == 9)
                after[8] += before[9] % 1000000000;
            else
            {
                after[j-1] += before[j] % 1000000000;
                after[j+1] += before[j] % 1000000000;
            }
        }
    }

    for(j = 0; j < 10; j++)
        result += after[j];


    printf("%lld\n", result % 1000000000);   
    return 0;
}

void array_copy_init(long long *dest, long long *arr)
{
    for(int i = 0; i < 10; i++)
    {
        dest[i] = arr[i];
        arr[i]  = 0; 
    }
}