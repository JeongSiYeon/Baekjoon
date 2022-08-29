#include <stdio.h>

int main(void)
{
    char S[101];
    int i = 0, j = 0, k = 0, ret[26];

    for(i = 0; i < 26; i++)
    {
        ret[i] = -1;
    }
    
    scanf("%s", S); 
    
    while(S[j] != '\0')
    {
        if(ret[S[j] - 97] == -1)
        {
            ret[S[j] - 97] = j;
        }
        j++;
    }
    
    for(k = 0; k < 26; k++)
    {
        printf("%d ", ret[k]);
    }
    
    return 0;
}