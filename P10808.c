#include <stdio.h>

int main(void)
{
    // 알파벳 소문자로만 이루어진 단어 S
    // 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하시오

    char alphabet;
    int  i, alphaCount[26] = {0,};

    scanf("%c", &alphabet);
    while(alphabet != '\n')
    {
        alphaCount[alphabet-97]++;
        scanf("%c", &alphabet);
    }

    for(i = 0; i < 26; i++)
        printf("%d ", alphaCount[i]);

    return 0;
}