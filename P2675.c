#include <stdio.h>
#include <malloc.h>

int main(void)
{
    // 역슬래시는 '\\'임
    // S의 가능 구성요소: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:

    int T, R[1000] = {0,} , i = 0, j = 0, k = 0;
    
    // 입력
    // 테스트 케이스 개수 T (1~1000)
    scanf("%d", &T);
    // 반복 횟수 R(1~8) 문자열 S(적어도 1글자존재, 20글자를 넘지 않는다.)
    char *S = (char *)malloc(sizeof(char) * T * 21); // 개수만큼 만들고

    for(i = 0; i < T; i++)
    {
        scanf("%d %s", &R[i], &S[21*i]);
    }
    
    for(i = 0; i < T; i++)
    {
        j = 0;
        while(S[21*i + j] != '\0')
        {
            for(k = 0; k < R[i]; k++)
            {
                printf("%c",S[21*i + j]);
            }
            j++;
        }
        printf("\n");
    }

    
    

    // 각 테스트 케이스에 대해 P 출력: // S의 문자를 R번 반복해 만든 새 문자열 P
    return 0;
}