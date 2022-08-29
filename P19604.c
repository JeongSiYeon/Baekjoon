#include <stdio.h>
#include <malloc.h>

void insertionSort(int * arr, int n);

int main(void)
{
    int N;
    scanf("%d", &N); // 2 <= N <= 100

    int *x = (int *)malloc(sizeof(int)*N);
    int *y = (int *)malloc(sizeof(int)*N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d,%d", &x[i], &y[i]);
    }
    insertionSort(x, N);
    insertionSort(y, N);

    printf("%d,%d\n", x[0]-1, y[0]-1);
    printf("%d,%d\n", x[N-1]+1, y[N-1]+1);

    return 0;
}

void insertionSort(int * arr, int n)
{
    int key, i = 0, j = 0;

    for(i = 1; i < n ; i++)
    {
        key = arr[i];
        for(j = i-1; j>= 0 && key < arr[j] ;j--)
        {
            arr[j+1] = arr[j];
        }  
        arr[j+1] = key;      
    }
}