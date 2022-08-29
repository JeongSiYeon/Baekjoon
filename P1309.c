#include <stdio.h>

#define   LEFT      0
#define   RIGHT     1
#define   EMPTY     2

void array_copy(int arr_bef[3], int arr_aft[3]);

int main(void)
{
    int N;
    scanf("%d%*c", &N);

    int lion_before[3], lion_after [3];

    lion_before[LEFT]  = 1;
    lion_before[RIGHT] = 1;
    lion_before[EMPTY] = 1;

    for(int i = 1; i < N; i++)
    {
        lion_after[EMPTY] =  (lion_before[EMPTY] + lion_before[LEFT] + lion_before[RIGHT]) %9901;
        lion_after[LEFT]  =  (lion_before[EMPTY] + lion_before[RIGHT])%9901;
        lion_after[RIGHT] =  (lion_before[EMPTY] + lion_before[LEFT])%9901;

        array_copy(lion_before, lion_after);
    }

    printf("%d\n", (lion_before[EMPTY] + lion_before[LEFT] + lion_before[RIGHT])%9901);
    return 0;
}

void array_copy(int arr_bef[3], int arr_aft[3])
{
    for(int i = 0; i < 3; i++)
        arr_bef[i] = arr_aft[i];        
}