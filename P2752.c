#include <stdio.h>

void insertionSort(int arr[], int n);

int main(void)
{
    int n[3]; 

    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    insertionSort(n, 3);
    
    printf("%d %d %d", n[0], n[1], n[2]);
    return 0;
}

void insertionSort(int arr[], int n)
{
    int key, i = 0, j = 0;

    for(i = 1; i < 3 ; i++)
    {
        key = arr[i];
        for(j = i-1; j>= 0 && key < arr[j] ;j--)
        {
            arr[j+1] = arr[j];
        }  
        arr[j+1] = key;      
    }
}