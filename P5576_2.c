#include <stdio.h>

void insertionSort(int arr[], int len);

int main(void)
{
    int i;
    // w대학 참가자: 10명, k대학 참가자: 10명
    // 득점이 높은 3명의 점수가 각 대학의 점수이다.
    // 각 대학의 점수를 구하여라

    // input: 0 <= score <= 100
    int WScore[10] = {0,}, KScore[10] = {0,};
    for(i = 0; i < 10; i++)
        scanf("%d%*c", &WScore[i]);
    for(i = 0; i < 10; i++)
        scanf("%d%*c", &KScore[i]);

    insertionSort(WScore, 10);
    insertionSort(KScore, 10);

    printf("%d %d", WScore[9] + WScore[8] + WScore[7], KScore[9] + KScore[8] + KScore[7]);

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