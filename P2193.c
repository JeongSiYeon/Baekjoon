#include <stdio.h>

void array_copy_init(unsigned long long *dest, unsigned long long *arr);

int main(void)
{

    int i, j, N;
    scanf("%d%*c", &N); // 1 <= N <= 90

    unsigned long long before[2], after[2], result = 0;

    after[0] = 0;
    after[1] = 1;

    for(i = 1; i < N; i++)
    {
        array_copy_init(before, after);

        for(j = 0; j < 2; j++)
        {
            if(j == 0)
            {
                after[0] += before[0];
                after[1] += before[0];
            }

            else
                after[0] += before[1];
        }
    }

    printf("%lld\n", after[0]+after[1]);
    return 0;
}

void array_copy_init(unsigned long long *dest, unsigned long long *arr)
{
    dest[0] = arr[0];
    dest[1] = arr[1];
    arr[0] = 0;
    arr[1] = 0;
}