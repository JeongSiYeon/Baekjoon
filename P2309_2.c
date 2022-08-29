#include <stdio.h>

void insertionSort(int arr[], int len);

int main(void)
{
    int i, j, sum = 0, find = 0, height[9] = {0,};
    
    for(i = 0; i < 9; i++)
    {
        scanf("%d%*c", &height[i]); 
        sum += height[i];
    }

    find = sum - 100;

    for(i = 0; i < 8; i++)
    {
        for(j = i+1; j < 9; j++)
            if(height[i]+height[j] == find)
            {
                height[i] = 0;
                height[j] = 0;
                break;
            }
        if(height[i]+height[j] == 0) break;
    }
    
    insertionSort(height, 9);
    for(i = 2; i < 9; i++) 
        printf("%d\n", height[i]);

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