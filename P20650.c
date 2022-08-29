#include <stdio.h>

void insertionSort(int arr[], int n);

int main(void)
{
    int B[7], max;
    
    for(int i = 0; i < 7; i++)
    {
        scanf("%d", &B[i]);
    }

    insertionSort(B, 7);
    
    max = B[6];
    for(int i = 0; i < 6; i++)
    {
        for(int j = i+1; j < 6; j++)
        {
            for(int k = j +1; k < 6; k++)
            {
                if((B[i] + B[j] + B[k]) == (max*2))
                {
                    for(int l = 0; l < 5; l++)
                    {
                        if(l != i && l != j && l != k)
                            printf("%d ", B[l]);
                    }
                    return 0;
                }
            }
        }
    }

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