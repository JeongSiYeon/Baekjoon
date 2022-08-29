#include <stdio.h>
#include <limits.h>

int  min             (int a, int b);
void update_min_cost (int precost[3]);

int main(void)
{    
    int i, N, newcost, mincost = INT_MAX;
    int cost[3];

    scanf("%d%*c", &N);                       // 2 <= N <= 1000
    
    // initilization
    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &newcost);
        cost[i] = newcost;
    }

    // find min cost...process
    for(i = 1; i < N; i++)
        update_min_cost(cost);

    // find min cost...result
    for(i = 0; i < 3; i++)
        if(mincost > cost[i])
            mincost = cost[i];
    
    printf("%d", mincost);
    return 0;    
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

void update_min_cost (int precost[3])
{
    int i, cost, poscost[3];

    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &cost);
        poscost[i] = cost + min(precost[(i+1)%3], precost[(i+2)%3]);
    }

    for(i = 0; i < 3; i++)
        precost[i] = poscost[i];
}   