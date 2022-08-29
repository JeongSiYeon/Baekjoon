#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0, selection = 0, N;
    scanf("%d", &N); 

    char firstN[31];
    int *count = (int *)calloc(26, sizeof(int)); 

    for(i = 0; i < N; i++)
    {
        scanf("%s", firstN); 
        count[firstN[0]-97]++;
    }

    for(i = 0; i < 26; i++)
    {
        if(count[i] >= 5) 
        {
            printf("%c", i+97);
            selection++;
        }
    }
    if(selection == 0) printf("PREDAJA\n");    
    return 0;
}

