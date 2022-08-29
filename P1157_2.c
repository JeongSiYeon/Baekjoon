#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0, alphabetN[26] = {0,}, maxidx = 0, tie = 0;
    char *word = (char *)calloc(1000001, sizeof(char));

    while(1)
    {
        scanf("%c", &word[i]);
        if(word[i] == 10) break;

        if(word[i] >= 97) word[i] -= 32;
        alphabetN[word[i]-65]++;
        i++;
    } 

    for(i = 1; i < 26; i++)
    {
        if(alphabetN[maxidx] < alphabetN[i])
        {
            maxidx = i;
            tie = 0;
        }
        else if(alphabetN[maxidx] == alphabetN[i])
            tie = 1;
    }

    if(tie == 0)
        printf("%c", maxidx+65);
    else
        printf("?");

    return 0;
}