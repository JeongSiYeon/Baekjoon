#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0, j = 0, maxidx = 0, stringCount = 0, alphaCount[26] = {0,}, tie = 0;
    char c, *string = (char*)calloc(51, sizeof(char));
    
    while(stringCount < 50)
    {
        c = getchar();
        if(c == EOF) break;
        alphaCount[c-97]++;
    
        gets(string);

        i = 0;
        stringCount++;
        while(string[i] != '\0')
        {
            if(string[i] != ' ') 
                alphaCount[string[i]-97]++;
            i++;
        }
    }
    
    for(i = 1; i < 26; i++)
    {
        if(alphaCount[maxidx] < alphaCount[i]) 
        {
            maxidx = i;
            tie = 0;
        }
        else if(alphaCount[maxidx] == alphaCount[i]) 
            tie = 1;
    }

    if(stringCount == 0)  
        return 0;

    if (tie == 0) 
        printf("%c", maxidx+97);
    else
        for(i = 0; i < 26; i++)
            if(alphaCount[maxidx] == alphaCount[i])
                printf("%c", i+97);

    return 0;
}