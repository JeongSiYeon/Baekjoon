#include <stdio.h>
#include <stdlib.h>

void insertionSort(double *arr, int len);

int main(void)
{
    // 주의 w, xi, yi는 10진법 소숫점 7째 자리까지 주어진다.
    // 잔디를 깎을 때, 깎이는 범위에 가장자리도 포함된다.

    int T = 0, i, nx = -1, ny = -1;    // 0 < nx < 1000, 0 < ny < 1000
    int *state = (int *)calloc(100000, sizeof(int)); // 1: YES, 0: NO
    double w = -1;         // 0 < w < 50
    
    while(1)
    {
        scanf("%d %d %lf%*c", &nx, &ny, &w);
        if(nx == 0 && ny == 0 && w == 0.0) 
            break;
        
        double x_boundary = 0, y_boundary = 0;

        double *x = (double *)calloc(nx, sizeof(double)); // 0 <= xi <= 75
        double *y = (double *)calloc(ny, sizeof(double)); // 0 <= yi <= 100

        for(i = 0; i < nx; i++)
            scanf("%lf%*c", &x[i]);
        for(i = 0; i < ny; i++)
            scanf("%lf%*c", &y[i]);
        
        // sorting
        insertionSort(x, nx);
        insertionSort(y, ny);

        // x checking
        for(i = 0; i < nx; i++)
        {
            if(x[i]-w/2.0 <= x_boundary) 
            {
                x_boundary = x[i] + w/2;
                continue;
            }
            else break; 
        }

        if(i == nx && x[--i] + w/2.0 >= 75) 
            state[T]++;            

        // x에서 다 채워지지 않았다면, y checking
        if(state[T] == 1)
        {
            for(i = 0; i < ny; i++)
            {
                if(y[i]-w/2.0 <= y_boundary) 
                {
                    y_boundary = y[i] + w/2;
                    continue;
                }
                else break; 
            }

            if(i == ny && y[--i] + w/2.0 >= 100) 
                state[T]++;
        }

        // next case
        T++;
    }

    for(i = 0; i < T; i++)
    {
        if(state[i] == 2) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

void insertionSort(double *arr, int len)
{
    int i, j;
    double key;
    for(i = 1; i < len; i++)
    {
        key = arr[i];
        for(j = i-1; j >= 0 && key < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}