#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}                

void insertionSort(int *arr, int p, int r);
void quickSort(int *arr, int p, int r, int K);
void partition(int *arr, int p, int r, int *q, int *s);

int main()
{
    int N, K, *num;                           // N: 입력값의 개수(1 <= N <= 5 000 000), 
                                              // K: 오름차순 정렬했을 때 구할 수의 번째 수
    scanf("%d %d%*c", &N, &K);                
    num = (int *)malloc(N*sizeof(int));       // num: 입력값를 받는 배열

    for(int i = 0; i < N; i++){                                 
        scanf("%d%*c", &num[i]);              
    }

    quickSort(num, 0, N-1, K);                
    printf("%d\n", num[K-1]);    
    
    free(num);
    return 0;
}

// arr배열의 p~r범위에서 오름차순 퀵정렬
void quickSort(int *arr, int p, int r, int K)
{    
    int q, s;                                      // q는 pivot의 위치이고 q~s는 pivot과 동일한 값을 가진 range이다.      

    if(p < r) {                                    
        partition(arr, p, r, &q, &s);              // pivot보다 작은 범위, 같은 범위, 큰 범위를 나눈다.

        if(q <= K-1 && K-1 <= s)                   // 모든 값을 정렬하지 않는다. 구하고자 하는 위치인 K번째의 수의 자리가 결정되는 순간 정렬을 멈춘다.
            return;
        else if(q < K-1)                           // 남아있는 정렬되지 않은 두 부분 중 K번째의 수가 속한 부분만 정렬한다. 
            quickSort(arr, s+1, r, K);             // K번째의 수가 pivot보다 큰 부분에 위치해 있는 경우 해당 위치만 정렬한다.
        else
            quickSort(arr, p, q-1, K);             // K번째의 수가 pivot보다 작은 부분에 위치해 있는 경우 해당 위치만 정렬한다.
    }    
}

void partition(int *arr, int p, int r, int *q, int *s)
{
    int i = p + 1;                                        // p위치는 이후 pivot이 될 예정이므로 p+1부터 + 방향으로 순회한다.
    int j = r;                                            // r위치부터 -방향으로 순회한다.
    int pivot, randomi, tmp;             

    srand(time(NULL));                                    // 퀵소트의 경우 정렬되어 있을 때나 역정렬되어 있을 때 최악의 성능을 보이는 것을 방지하기 위해
    randomi = rand() % (r-p+1) + p;                       // 정렬해야 하는 범위인 p~r까지 랜덤으로 pivot index를 뽑고            
    SWAP(arr[p], arr[randomi], tmp);                      // 그 값과 p index의 값을 SWAP한다. 이로써 분할이 한쪽으로만 쏠리게 될 확률이 낮아진다.
    pivot = arr[p];                                       // p위치의 수가 pivot이 된다.

    while(i <= j) {                                       // i가 j를 넘어가는 순간 i와 j는 모든 수를 검사완료했으므로 j는 pivot 위치가 되어 반복문을 빠져나가도록 한다. 
        while(i <= r && pivot >= arr[i]) {                // i는 왼쪽부터 pivot보다 큰 수가 있으면 머물러 있으며 pivot보다 작은 수와의 SWAP을 기다린다.
            i++;                                          // i <= r을 조건으로 추가하여 j가 r인 경우 i가 r이 아니라 최대 r+1까지 가도록하여 반복문을 빠져나갈 수 있도록 한다. 1만큼 더 가는 이유는 s를 i-1로 결정하기 때문이다.
        }
        while(j >= (p+1) && pivot <= arr[j]) {            // j는 오른쪽부터 pivot보다 작은 수가 있으면 머물러 있으며 pivot보다 큰 수와의 SWAP을 기다린다.
            j--;                                          // j의 최종위치와 pivot을 교환하므로 j가 최대 pivot위치인 p까지 갈 수 있도록 j >= (p+1)을 조건으로 추가한다.
        }
        if(i <= j) {                                      // i가 j를 넘어가지 않았을 경우
            SWAP(arr[i], arr[j], tmp);                    // i와 j에 알맞은 수가 위치하도록 SWAP을 한다. 
        }
    }
    SWAP(arr[p], arr[j], tmp);                            // j위치에 있는 수와 p위치의 pivot을 바꾸므로써 피벗의 위치를 j로 결정한다. 

    *q = j;                                               // i와 j 모두 해당 위치의 수와 pivot값이 같은 경우에도 이동했다.
    *s = i-1;                                             // 따라서 pivot과 동일한 값을 가진 수가 여러 개 였다면 j+1~i-1위치에는 pivot과 동일한 수가 위치하게 된다.
                                                          // 그런데 바로 위에서 SWAP을 진행했으므로 j~i-1위치에 pivot과 동일한 값의 수가 위치하게 된다. 
}