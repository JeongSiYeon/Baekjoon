#include <stdio.h>
#include <string.h>

int main(void)
{
    // 입력 수가 주어지지 않았을 때 연속 입력 받고 출력하기
    int i = 0;
    char string[100][101] = {0, };
    while(i != 100)
    {
        gets(string[i]);
        if(strlen(string[i]) == 0)
            break;
        i++;
    }

    i = 0;
    while(string[i][0] != 0)
    {
        printf("%s\n", string[i]);
        i++;
    }

    return 0;
}