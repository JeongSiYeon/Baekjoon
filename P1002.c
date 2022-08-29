#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    double distance_x1_x2 = 0;
    int T;
    scanf("%d", &T);

    int *x1 = (int *)malloc(sizeof(int)*T);
    int *x2 = (int *)malloc(sizeof(int)*T);
    int *y1 = (int *)malloc(sizeof(int)*T);
    int *y2 = (int *)malloc(sizeof(int)*T);
    int *r1 = (int *)malloc(sizeof(int)*T);
    int *r2 = (int *)malloc(sizeof(int)*T); 

    // 10,000 <= x1, y1, x2, y2 <= 10,000 인 정수
    // 1 <= r1, r2 <= 10,000인 정수
    for(int i = 0; i < T; i++)     
        scanf("%d %d %d %d %d %d", &x1[i], &y1[i], &r1[i], &x2[i], &y2[i], &r2[i]);  
    
    for(int i = 0; i < T; i++)
    {
        distance_x1_x2 = sqrt( pow(x1[i]-x2[i], 2) + pow(y1[i]-y2[i], 2) );

        if(x1[i] == x2[i] && y1[i] == y2[i] && r1[i] == r2[i])
            printf("-1\n");

        else if( distance_x1_x2 < abs(r1[i]-r2[i]) || distance_x1_x2 > r1[i] + r2[i])
            printf("0\n");

        else if(distance_x1_x2 == abs(r1[i]-r2[i]) || distance_x1_x2 == r1[i] + r2[i])
            printf("1\n");

        else
            printf("2\n");
    }

    return 0;
}