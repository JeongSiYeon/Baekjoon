#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int N, F_count = 0;
    scanf("%d", &N);

    int *coin_state = (int*)malloc(sizeof(int)*N);    
    for(int i = 0; i < N; i++)
    {
        scanf("%d%*c", &coin_state[i]);
        if(coin_state[i] == 0)
            F_count++;
    }

    if(F_count < (N - F_count))
        printf("%d", F_count);
    else
        printf("%d\n", N - F_count);

    return 0;
}