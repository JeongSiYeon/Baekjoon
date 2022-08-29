#include <stdio.h>

#define PNUM 9

void insertionSort(int arr[], int n);

int main(void)
{
    int i, j, spyI_1 = -1, spyI_2 = -1; 
    int hight[9] = {0,}, sum = 0;

    for(i = 0; i < PNUM; i++)
    {
        scanf("%d", &hight[i]);
        sum += hight[i];
    }

    insertionSort(hight, 9);

    for(i= 0; i < PNUM-1; i++)
    {
        if(spyI_2 != -1) 
            break;

        for(j = i+1; j < PNUM; j++)
        {
            if((sum - 100) == hight[i] + hight[j])
            {
                spyI_1 = i;
                spyI_2 = j;
                break;
            }
        }
    }

    for(i= 0; i < 9; i++)
    {
        if(i == spyI_1 || i == spyI_2) 
            continue;
        printf("%d\n", hight[i]);
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