#include <stdio.h>
#define PNUM 10

void insertionSort(int arr[], int n);

int main(void)
{
    int i, score_W[PNUM], score_K[PNUM];
    
    for(i = 0; i < PNUM; i++)
    {
        scanf("%d", &score_W[i]);
    }

    for(i = 0; i < PNUM; i++)
    {
        scanf("%d", &score_K[i]);
    }

    insertionSort(score_W, PNUM);
    insertionSort(score_K, PNUM);

    printf("%d %d", score_W[7]+score_W[8]+score_W[9], score_K[7]+score_K[8]+score_K[9]);

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