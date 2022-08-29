#include <stdio.h>
#include <limits.h>

int  minidx          (int arr[], int idx1, int idx2);
int  maxidx          (int arr[], int idx1, int idx2);
void update_min_cost (int ith, int precost[3], int firstSelect[3]);

int main(void)
{    
    int i, N, newcost, mincost = INT_MAX;
    int cost[3], firstSelect[3];

    scanf("%d%*c", &N);                       // 2 <= N <= 1000
    
    // initilization
    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &newcost);
        cost[i]      = newcost;
    }

    // find min cost...process1
    for(i = 1; i < N-1; i++)
        update_min_cost(i, cost, firstSelect);
    
    // find min cost...process2: first != last
    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &newcost); // 
        cost[i] = newcost + cost[maxidx(firstcost, (i+1)%3, (i+2)%3)];
    }

    // find min cost...result
    for(i = 0; i < 3; i++)
        if(mincost > cost[i])
            mincost = cost[i];
    
    printf("%d", mincost);
    return 0;    
}

int minidx(int arr[], int idx1, int idx2);
{
    if(arr[idx1] < arr[idx2])
        return idx1;
    else
        return idx2;
}

int  maxidx(int arr[], int idx1, int idx2)
{
    if(arr[idx1] > arr[idx2])
        return idx1;
    else
        return idx2;
}


void update_min_cost (int ith, int precost[3], int firstSelct[3])
{
    int i, cost, minIDX[3], select[3], poscost[3];

    for(i = 0; i < 3; i++)
    {
        scanf("%d%*c", &cost);
        minIDX[i] = minidx(precost, (i+1)%3, (i+2)%3);
        poscost[i] = cost + precost[minIDX[i]];
    }

    for(i = 0; i < 3; i++)
    {
        if(ith == 1)
            firstSelct[i] = minIDX[i];
        else
            select[i] = firstSelect[minIDX[i]];
    }

    for(i = 0; i < 3; i++)
    {
        precost[i] = poscost[i];
        firstSelct[i] = select[i];
    } 
}   