#include <stdio.h>
#include <stdlib.h>

int count_vowels(char *string);

int main(void)
{
    // 입력: 문장(알파벳 대소문자, .,!? 공백), 여러 개, 최대 255글자, 입력 끝은 #
    // 출력: 모음의 개수 세기 

    int i = 0;
    char *string = (char *)calloc(256,sizeof(char));
    int  *count = (int *)calloc(1000000, sizeof(int));

    while(string[0] != '#')
    {
        gets(string);
        count[i++] = count_vowels(string);      
    }

    for(int j = 0; j < i-1; j++)
        printf("%d\n", count[j]);
    return 0;
}

int count_vowels(char *string)
{
    int i = 0, vowelN = 0;
    while(string[i] != '\0')
    {
        if(string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U' || 
           string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            vowelN++;
        i++;
    }
    return vowelN;
}