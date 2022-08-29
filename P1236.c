#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 직사각형 모양의 성 1층은 몇 명의 경비원에 의해서 보호되고 있다.
    // 영식이는 모든 행과 모든 열에 한 명 이상의 경비원리 있으며 좋겠다고 생각
    // 성의 크기, 경비원이 어디 있는지 주어졌을 때, 몇 명의 경비원을 최소로 추가해야 영식이를 만족시키는지 구하는 프로그램?
    // 첫째 줄에 성의 세로 크기 N, 가로 크기 M (N과 M은 50보다 작거나 같은 자연수)

    // 둘째 줄부터 N개의 줄에는 성의 상태가 주어진다.
    // 첫 째 줄에 추가해야 하는 경비원의 최솟값을 출력한다.

    int N, M, length_0 = 0, width_0 = 0;
    scanf("%d %d%*c", &N, &M);

    int *length = (int *)calloc(N, sizeof(int));
    int *width = (int *)calloc(M, sizeof(int));
    char *security_loc = (char *)calloc(M+1, sizeof(char));

    for(int i = 0; i < N; i++)
    {
        scanf("%s%*c", security_loc);
        for(int j = 0; j < M; j++)
            if(security_loc[j] == 'X')
            {
                width[j] = 1;
                length[i] = 1;
            }
    }

    for(int i = 0; i < M; i++)
        if(width[i] == 0)
            width_0++;
    
     for(int i = 0; i < N; i++)
        if(length[i] == 0)
            length_0++;
    
    if(width_0 >= length_0)
        printf("%d\n", width_0);
    else
        printf("%d\n", length_0);

    return 0;
}