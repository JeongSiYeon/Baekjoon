#include <stdio.h>
#include <stdlib.h>

int main(void)
{    
    int iter, jiter, N, M, K, i, j, x, y;

    // input: N(행) M(열) (1 <= N, M <= 300)
    scanf("%d %d%*c", &N, &M);
    printf("N: %d, M: %d\n", N, M);
    
    // N*M 배열
    int *arr = (int *)calloc(N*M, sizeof(int));
    
    // N*M 배열에 정수 저장 (-10 000 <= num <= 10 000)
    for(iter = 0; iter < N*M; iter++)
    {
        scanf("%d%*c", &arr[iter]);
        printf("[%d] num: %d\n", iter, arr[iter]);
    }
    
    // 합을 구할 부분의 개수(1 <= K <= 10 000)
    scanf("%d%*c", &K);
    printf("K: %d\n", K);

    // 합을 구하고 저장할 배열
    int *sum = (int *)calloc(K, sizeof(int));

    // 시작 위치(i: 행, j: 열)와 종료 위치(x: 행, y: 열)가 K개 들어온다.
    for(iter = 0; iter < K; iter++)
    {
        scanf("%d %d %d %d%*c", &i, &j, &x, &y);
        // 합을 구해서 sum에 저장한다
        
        printf("i: %d j: %d x: %d y: %d\n", i, j, x, y);
        printf("%d ~ %d\n", M*(i-1) + (j-1), M*(x-1) + (y-1));

        for(jiter = M*(i-1) + (j-1); jiter <= M*(x-1) + (y-1); jiter++)
        {
            printf("iter: %d, + %d\n", iter, arr[jiter]);
            sum[iter] += arr[jiter];
        }
    }

    printf("sum end\n");

    for(iter = 0; iter < K; iter++)
        printf("%d\n", sum[iter]);

    return 0;
}