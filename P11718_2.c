#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0, j = 0;
    // input: 최대 100줄 100글자, 빈 줄 x, 공백으로 시작하거나 끝나지 않는다.
    char string[100][101] = {0, };

    while(i != 100)
    {
        gets(string[i]);
        if(strlen(string[i]) == 0)
            break;
        i++;
    }

    for(j = 0; j < i; j++)
        printf("%s\n", string[j]);
    
    return 0;
}