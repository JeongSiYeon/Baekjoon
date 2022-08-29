#include <stdio.h>

int main(void)
{
    int i, j, T, N, M, tie = 0; 
    int power, max = 0, result[100] = {0, };

    scanf("%d%*c", &T); // 1 <= T <= 100

    for(i = 0; i < T; i++)
    {      
        scanf("%*c%d %d%*c", &N, &M);
       for(j = 0; j < N; j++)
        {
            scanf("%d%*c", &power);
            if(max < power) max = power;
        }
        
        for(j = 0; j < M; j++)
        {
            scanf("%d%*c", &power);
            if(max < power) 
                result[i] = 1;
        }   
    }

    for(i = 0; i < T; i++)
    {
        if(result[i] == 0) printf("S\n");
        else               printf("B\n");
    }

    return 0;
}