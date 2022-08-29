#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int len);

int main(void)
{
    // 5명의 심판, 1~10 점수 줌, 총점: 최고점과 최저점 제외한 점수의 합
    // 만약 "남은" 3명의 최고점과 최저점 차이가 4점 이상 나면 KIN 출력

    int i, j, T;
    int score[5] = {0,};

    scanf("%d", &T); // 1 <= T <= 10
    int *total_score =  (int *)calloc(T, sizeof(int));

    for(i = 0; i < T; i++)
    {
        for(j = 0; j < 5; j++)
            scanf("%d%*c", &score[j]);

        insertionSort(score, 5);

        if(score[3] - score[1] >= 4) total_score[i] = 0;
        else total_score[i] = score[1] + score[2] + score[3];
    }

    for(i = 0; i < T; i++)
    {
        if(total_score[i] == 0) printf("KIN\n");
        else printf("%d\n", total_score[i]);
    }

    return 0;
}

void insertionSort(int arr[], int len)
{
    int i, j, key;
    for(i = 1; i < len; i++)
    {
        key = arr[i];
        for(j = i-1; j >= 0 && key < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}