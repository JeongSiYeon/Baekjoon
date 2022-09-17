#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;} 
#define MAXI(arr, a, b, c, maxi) {maxi = (*(arr+a)>*(arr+b)) ? a:b; if(*(arr+c)>maxi) maxi=c;}    // 인덱스비교가 아니라 값비교로 바꿈
#define MINI(arr, a, b, c, mini) {mini = (*(arr+a)<*(arr+b)) ? a:b; if(*(arr+c)<mini) mini=c;}
  
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
    int i = p-1, j;         
    int pivot, tmp;                 
    int maxi, mini, mediani, s=(p+r)/2;
    
    MAXI(arr, p, r, s, maxi);
    MINI(arr, p, r, s, mini);
    mediani = (p+r+s) - maxi - mini;

    SWAP(arr[mediani], arr[r], tmp);
    pivot = arr[r];               

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