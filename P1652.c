#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 영식이가 누울 자리: 똑바로 연속해서 2칸이 존재하는 곳
    // 심지어 중간에 어정쩡하게 누울 수 없다.
    int i, j, N, widthC = 0, lengthC = 0; 
    scanf("%d", &N); // N <= 100인 정수

    char *space = (char *)calloc(N*N+1, sizeof(char));

    for(i = 0; i < N; i++)
        scanf("%s%*c", &space[N*i]);

    // sol
    // 가로 줄마다(5*i) 연속으로 .이 존재하는 순간(state == 2가 되는 순간) count하고 다음으로 넘어간다.

    // 줄 넘어갈 때 예외상황 생각안했다
    for(i = 0; i < N*N; i += N) // 0 5 10 15 20 
    {
        for(j = i; j < i + (N-1); j++) // 0123 
            if(space[j] == '.' && space[j+1] == '.')
            {
                widthC++;
                
                // 한 줄에 더 누울 수 있는 경우를 위해서
                while(space[j] != 'X' && j < i + (N-2))
                    j++;
            }  
    }

    // 세로 줄마다(0,5,10,15,20/ 1,6,11,16,21,26 => 0부터 시작해서 5전까지 loop를 돌면서 초항의 역할을 하고
    // N의 등차수열로 검사하기) 연속으로 .이 존재하는 순간 count하고 다음으로 넘어간다.
    for(i = 0; i < N; i++) // 01234
    {
        for(j = i; j < N*(N-1); j+=N) // 1 6 11 16 21
            if(space[j] == '.' && space[j+N] == '.')
            {
                lengthC++;

                // 한 줄(세로)에 더 누울 수 있는 경우를 위해서
                while(space[j] != 'X' && j < N*(N-2))
                    j+=N;
            }
    }
    
    // output: 가로로 누울 수 있는 자리 세로로 누울 수 있는 자리
    printf("%d %d\n", widthC, lengthC);
    return 0;
}