#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int len);

int main(void)
{
    int i, N;
    scanf("%d", &N);
    int *num = (int *)calloc(N, sizeof(int));

    for(i = 0; i < N; i++)
        scanf("%d%*c", &num[i]);
    
    insertionSort(num, N);

    for(i = 0; i < N; i++)
        printf("%d\n", num[i]);

    return 0;
}

void insertionSort(int *arr, int len)
{
    int i, j, key;
    for(i = 1; i < len; i++)
    {
        key = arr[i];
        for(j = i -1; j >= 0 && key < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}