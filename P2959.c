#include <stdio.h>

void insertionSort(int arr[], int n);

int main(void)
{
    int num[4]; // (0 < A, B, C, D < 100)
    scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

    insertionSort(num, 4);
    printf("%d %d %d %d\n", num[0], num[1],num[2], num[3]);
    printf("%d", num[0]*num[2]);

    return 0;
}

void insertionSort(int arr[], int n)
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