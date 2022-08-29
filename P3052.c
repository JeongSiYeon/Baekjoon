#include <stdio.h>

void swap(int arr[], int idx1, int idx2);
void selectionSort(int arr[], int len);


int main(void)
{
    int num[10], mod[10], ret = 10;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
        mod[i] = num[i] % 42;
    }

    selectionSort(mod, 10);

    for(int j = 0; j < 9; j++)
    {
        if(mod[j] == mod[j+1])
        {
            ret--;
        }
    }

    printf("%d", ret);
    return 0;
}

void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void selectionSort(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < len; j++)
        {
            if(arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        swap(arr, i, min_idx);
    }
}