#include <stdio.h>

int main(void)
{
    int N, guest_pick, refuseN = 0;
    int seat[100] = {0,};

    scanf("%d", &N); // N <= 100

    for(int i = 0; i < N; i++)
    {
        scanf("%d%*c", &guest_pick);

        if(seat[guest_pick-1] == 1)
            refuseN++;
        else
            seat[guest_pick-1] = 1;
    }

    printf("%d\n", refuseN);
    return 0;
}