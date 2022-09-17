/*
P11004_K번째 수
시간제한: 2초
메모리 제한: 512MB
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);
void swap(int *arr, int i1, int i2);

int main()
{
    int N, K;                                  
    scanf("%d %d%*c", &N, &K);                 // 1 <= K <= N <= 5 000 000

    int *num = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d%*c", &num[i]);               // -10^9 <= num <= 10^9
    }

    // sort num
    quickSort(num, 0, N-1);

    // print loc: K
    printf("%d\n", num[K-1]);                   

    return 0;
}

void quickSort(int *arr, int p, int r)
{
    if(p < r) {
        int q;

        q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int partition(int *arr, int p, int r)
{
    int i = p-1, j = p;                    
    int pivot = arr[r];

    for(j = p; j < r; j++) {                
        if(arr[j] <= pivot) {
            swap(arr, ++i, j);
        }
    }
    swap(arr, ++i, j);

    return i;
}

void swap(int *arr, int i1, int i2)
{
    int temp;
    
    temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}