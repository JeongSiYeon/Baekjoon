#include <stdio.h>
#include <stdlib.h>

int asc (int N, int *series, int *memoA, int pointIDX);
int desc(int N, int *series, int *memoD, int pointIDX);

int main(void)
{
    int i, N, result, max = 0; 

    scanf("%d%*c", &N);                                 // 1 <= N <= 1000

    int *series = (int *)calloc(N, sizeof(int));
    int *memoA  = (int *)calloc(N, sizeof(int));      
    int *memoD  = (int *)calloc(N, sizeof(int));        

    for(i = 0; i < N; i ++)
        scanf("%d%*c", &series[i]);                     // 1 <= series[i] <= 1000

    for(i = N-1; i >= 0; i--)
    {
        result = asc(N, series, memoA, i) + desc(N, series, memoD, i) - 1;

        if(max < result) 
            max = result; 
    }        

    printf("%d\n", max);
    return 0;
}


// memoA[pointIDX]: pointIDX를 마지막 인덱스로 가지는 가장 긴 증가 수열의 길이를 구한다.
int asc (int N, int *series, int *memoA, int pointIDX)
{
    // dp
    if(memoA[pointIDX] != 0)
        return memoA[pointIDX];

    // logic
    for(int i = 0; i <= pointIDX; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(series[i] > series[j] && memoA[i] < 1 + memoA[j])
                memoA[i] = 1 + memoA[j];
        }
        
        if(memoA[i] == 0)
            memoA[i] = 1;
    }

    return memoA[pointIDX];
}

// memoA[pointIDX]: pointIDX를 시작 인덱스로 가지는 가장 긴 감소 수열의 길이를 구한다.
int desc(int N, int *series, int *memoD, int pointIDX)
{
    // dp
    if(memoD[pointIDX] != 0)
        return memoD[pointIDX];

    // logic
    for(int i = pointIDX; i >= 0; i--)
    {
        for(int j = i; j <= pointIDX; j++)
        {
            if(series[i] > series[j] && memoD[i] < 1 + memoD[j])
                memoD[i] = 1 + memoD[j];
        }
        
        if(memoD[i] == 0)
            memoD[i] = 1;
    }

    return memoD[pointIDX];
}