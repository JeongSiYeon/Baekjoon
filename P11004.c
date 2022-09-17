#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}   //swap을 define으로 함

void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main()
{
    int N, K;                                  
    scanf("%d %d%*c", &N, &K);                 // 1 <= K <= N <= 5 000 000

    int *num = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d%*c", &num[i]);                // -10^9 <= num <= 10^9
    }

    quickSort(num, 0, N-1);                    // sort num
    printf("%d\n", num[K-1]);                  // print loc: K               
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
    int i = p-1, j = p;                          // p랑 j랑 재귀적으로 들어오는거 생각 안하고 첫 번째 입력에 한해서만 함
    int random, pivot, tmp = 0;  
    
    srand(time(NULL));
    if(p-r+1 == 0)                                // zero division생각안함
        random = p;
    else
        random = rand()%(p-r+1)+p;   

    pivot = arr[random];                           // 고정 피벗은 최악의 경우로 갈 확률 높음 -> random하게
    SWAP(arr[random], arr[r], tmp);                // 밑에 알고리즘 바꾸기 귀찮아서 그냥 swap함

    for(j = p; j < r; j++) {                
        if(arr[j] <= pivot) {
            i++;
            SWAP(arr[i], arr[j], tmp);
        }
    }
    i++;
    SWAP(arr[i], arr[j], tmp);
    return i;
}