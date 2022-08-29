#include <stdio.h>
#include <malloc.h>

void swap(int * arr, int idx1, int idx2);
void selectionSort(int * arr, int startIDX, int n);

int main(void)
{
    // 5명의 심판이 score (1 <= score <= 10인 정수) 를 매김
    // fScore = 시그마 score - 최고점 - 최저점
    // printf("%d", fScore);
    // 단, 남은 3명의 점수의 최고점과 최저점의 차이가 4점 이상 -> print("KIN");

    // test case 1 ~ 10
    int i, T;
    scanf("%d", &T); 

    // test case 개수에 맞게 심사위원의 답을 담을 container를 동적할당한다.
    int *score = (int *)malloc(sizeof(int)*T*5);

    // 다섯 심판이 준 점수 다섯 개의 정수가 하나의 공백을 사이에 두고 주어진다.
    for(i = 0; i < T; i++)
    {
        scanf("%d %d %d %d %d", &score[5*i+0], &score[5*i+1], &score[5*i+2], &score[5*i+3], &score[5*i+4]);
        // 정렬
        selectionSort(score, 5*i, 5);
    }

    for(i = 0; i < T; i++)
    {
        if(score[5*i+3] - score[5*i+1] < 4)
        {
            printf("%d\n", score[5*i+1] + score[5*i+2] + score[5*i+3]);
        }
        else
        {
            printf("KIN\n");
        }
    }
    free(score);
    return 0;
}


void swap(int * arr, int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void selectionSort(int * arr, int startIDX, int n)
{
    int minidx;

    for(int i = startIDX; i < startIDX + 4; i++)
    {
        minidx = i;
        for(int j = i + 1; j < startIDX + 5; j++)
        {
            if(arr[minidx] > arr[j])
            {
                minidx = j;
            }
        }
        if(i != minidx)
        {
            swap(arr, i, minidx);
        }
    }
}