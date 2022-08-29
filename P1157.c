#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int i = 0;
    int count[26] = {0,}, max_count = 0;
    char *word = (char *)malloc(sizeof(char) * 1000001);
    char retC = '\0';
  
    scanf("%s", word);

    while(word[i] != '\0')
    {
        if(word[i] >= 97) 
        {
            word[i] = word[i] -32;
        }
        count[word[i++] - 65]++;
    }

    max_count = count[0];
    retC = 65;
    for(i = 1; i < 26; i++)
    {
        if(max_count < count[i]) {
            max_count = count[i];
            retC = i + 65;
        }
        else if(max_count == count[i]) {
            retC = '?';
        }
    }
    printf("%c", retC);
    return 0;
}