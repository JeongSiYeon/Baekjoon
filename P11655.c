#include <stdio.h>

int main(void)
{
    // ROT13: 영어 알파벳을 13글자씩 밀어서 만든다.
    int i = 0;
    char string[101];

    gets(string);

    while(string[i] != '\0')
    {

        if(65 <= string[i] && string[i] <= 90)
        {
            if(string[i] + 13 > 90) 
                string[i] = 64 + (string[i] + 13) % 90;
            else
                string[i] = string[i] + 13;
        }

        else if (97 <= string[i] && string[i] <= 122)
        {
            if(string[i] + 13 > 122) 
                string[i] = 96 + (string[i] + 13) % 122;
            else
                string[i] = string[i] + 13;
        }

        i++;
    }

    printf("%s\n", string);
    
    return 0;
}