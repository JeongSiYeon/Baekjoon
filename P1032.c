#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i, j, N;
    scanf("%d%*c", &N); // 1 <= N <= 50 인 자연수
    // 파일 이름의 길이는 모두 같고 길이는 최대 50이다.
    // 파일 이름은 알파벳 소문자와 '.'로만 이루어져 있다.
    char *file_name = (char *)calloc(51*N, sizeof(char));
    char *pattern   = (char *)calloc(51,   sizeof(char));

    for(i = 0; i < N; i++)
        scanf("%s", &file_name[i*51]);

    // sol: 같은 문자인 부분은 그대로 출력, 다르면 ? 저장 in pattern, 처음거 pattern에 복사하고 나머지를 계속 비교하며 다르면 바로 ?로 변경
    strcpy(pattern, &file_name[0]);
    for(i = 1; i < N; i++)
    {
        for(j = 0; j < strlen(pattern); j++)
        {
            if(pattern[j] == '?') 
                continue;
            if(pattern[j] != file_name[51*i+j]) 
                pattern[j] = '?';
        }
    }

    printf("%s\n", pattern);
    return 0;
}