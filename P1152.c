#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int i = 0, bCount = 0;
    char *S = (char *)malloc(sizeof(char) * 1000010);
    gets(S);

    while (S[i] == ' ') 
    {
        i++;
    }

    while(S[i] != '\0')
    {
        if(S[i+1] == '\0')
        {
            bCount++;
            break;
        }
        if(S[i] == ' ') bCount++;
        i++;
    }

    printf("%d", bCount);  
    return 0;
}