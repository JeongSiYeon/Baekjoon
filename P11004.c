#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;} 

void insertionSort(int *arr, int p, int r);
void quickSort(int *arr, int p, int r, int K);
int partition(int *arr, int p, int r);

int main()
{
    int N, K, *num;      

    scanf("%d %d%*c", &N, &K);         
    num = (int *)malloc(N*sizeof(int));

    for(int i = 0; i < N; i++){
        scanf("%d%*c", &num[i]);              
    }

    quickSort(num, 0, N-1, K);   
    printf("%d\n", num[K-1]);    

    return 0;
}

void insertionSort(int *arr, int p, int r)
{
    int i, j, key;

    for(i = p+1; i <= r; i++) {
        key = arr[i];
        for(j = i-1; j >= 0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void quickSort(int *arr, int p, int r, int K)
{
    if(p <= r) {
        if(r-p+1 <= 200)
            insertionSort(arr, p, r);
        else {
            int q;
            q = partition(arr, p, r);
            if(q == K-1) 
                return;
            else if(q < K-1)
                quickSort(arr, q+1, r, K);
            else
                quickSort(arr, p, q-1, K); 
        }    
    }
}

int partition(int *arr, int p, int r)
{
    int i = p + 1;
    int j = r;         
    int pivot, randomi, tmp;             

    srand(time(NULL));
    randomi = rand() % (r-p+1) + p;
    SWAP(arr[p], arr[randomi], tmp);
    pivot = arr[p];   

    while(i <= j) {
        while(i <= r && pivot >= arr[i]) {
            i++;
        }
        while(j >= (p+1) && pivot <= arr[j]) {
            j--;
        }

        if(i <= j) {
            SWAP(arr[i], arr[j], tmp);
        }
    }
    SWAP(arr[p], arr[j], tmp);
    return j;
}