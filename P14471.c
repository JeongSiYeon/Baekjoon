#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _pointCard
{
    int winN;
    int bangN;     
} POINTCARD;

void swap(int arr[], int idx1, int idx2);
void selectionSort(int arr[], int len);

int main(void)
{
    // input1: N, M (1 <= N, M <= 1000, integer)
    int N, M, i = 0, j = 0, givewayN = 0, cost = 0;
    scanf("%d %d", &N, &M);  // PC 칸 수 : 2N, 가지고 있는 PC 개수: M
    int *for_giveway = (int *)calloc(M, sizeof(int)); // stampN needed to win

    // input2: 당첨 도장 개수: Ai, 꽝 도장 개수: Bi (0 <= Ai, Bi <= Bi, Ai + Bi = 2N)
    POINTCARD *P = (POINTCARD *)malloc(sizeof(POINTCARD)*M);
    for(i = 0; i < M; i++)
    {   
        scanf("%d %d", &P[i].winN, &P[i].bangN);
        if(P[i].winN >= N) givewayN++;
        else
        {
            for_giveway[j] = N - P[i].winN;
            j++;
        }
    }            

    // sort <for_giveway> -> sum(M-1-C minimum for_givewayN value(s))
    if(givewayN < M-1)
    {
        selectionSort(for_giveway, j);
        for(i = 0; i < M-1-givewayN; i++)
            cost += for_giveway[i];
    }
    
    printf("%d\n", cost);
    return 0;
}

void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void selectionSort(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int minidx = i;
        for(int j = i+1; j < len; j++)
            if(arr[minidx] > arr[j]) minidx = j;
        swap(arr, i, minidx);
    }
}