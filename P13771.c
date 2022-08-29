#include <stdio.h>
#include <malloc.h>

void insertionSort(double * arr, int n);

int main(void)
{
    int N; 
    scanf("%d", &N); // 2 <= N <= 100

    double * price = (double *)malloc(sizeof(double)*N);

    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &price[i]);  
    }

    insertionSort(price, N);

    printf("%.2lf", price[1]);

    free(price);
    return 0;
}

void insertionSort(double * arr, int n)
{
    double key;
    int i = 0, j = 0;

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