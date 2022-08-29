#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void del_move(int arr[], int remove_idx);
int findMin(int arr[], int start, int end);

int main(void)
{
    // input
    int n, k, i = 0, tot_st = 0, par_st = 0, minidx = 0;
    scanf("%d  %d", &n, &k); // 1 <= k <= n <= 300
    int t[300] = {0,}; 

    for(i = 0; i < n; i++)
        scanf("%d", &t[i]); // 1 <= t[i] <= 1,000,000

    while(1)
    {
        if(t[1] == 0)
        {
            par_st = par_st + t[0];
            tot_st = tot_st + par_st;
            break;
        }
        else if(t[2] == 0)
        {
            minidx = findMin(t, 0, 1);
            par_st = par_st + t[minidx];
            tot_st = tot_st + par_st;
            del_move(t, minidx);
        }
        else 
        {
            minidx = findMin(t, 0, 2);
            par_st = par_st + t[minidx];
            tot_st = tot_st + par_st;
            del_move(t, minidx);
        }
    }

    // output
    printf("%d", tot_st);
    return 0;
}

void del_move(int arr[], int remove_idx)
{
    int i = remove_idx;
    while(arr[i] != '\0')
    {
        arr[i] = arr[i + 1];
        i++;
    }
}

int findMin(int arr[], int start, int end)
{
    int minidx = start;
    for(int i = start + 1; i <= end; i++)
    {
        if(arr[minidx] > arr[i])
            minidx = i;
    }
    return minidx;
}