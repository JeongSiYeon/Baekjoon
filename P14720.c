#include <stdio.h>
#include <malloc.h>

int main(void)
{
    // 딸 -> 초 -> 바 -> 딸 ->..
    // 딸이 나올 때까지 기다렸다가 초나 나올 때 까지 ㅇ린ㅇ
    
    // input1: N (the number of store, 1 <= N <= 1000)
    int i = 0, state = 0, count = 0, N; 
    scanf("%d%*c", &N);

    // input2: kinds (0: str, 1: cho, 2: bana)
    int *kind = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++)
        scanf("%d%*c", &kind[i]);
    
    for(i = 0; i < N; i++)
    {
        if(state == kind[i])
        {
            if(state == 2)
                state = 0;
            else
                state++;
            count++;
        }
    }

    printf("%d", count);
    return 0;
}