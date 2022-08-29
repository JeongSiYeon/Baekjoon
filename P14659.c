#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, max = 0;
    scanf("%d", &N);

    int *hight = (int *)calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d%*c", &hight[i]);
    
    for(int i = 0; i < N -1; i++)
    {
        int kill = 0, key = hight[i];
        for(int j = i+1; j < N; j++)
        {
            if(key < hight[j]) break;
            else kill++;
        }
        if(max < kill) max = kill;
    }

    printf("%d\n", max);
    return 0;
}