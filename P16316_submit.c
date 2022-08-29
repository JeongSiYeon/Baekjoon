#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 0, j = 0, n = 0, blankN = 0;
    char counting[7000];
    char temp[10001];

    scanf("%d%*c", &n);
    gets(counting);

    while(counting[i] != '\0')
    {
        if(counting[i] == ' ')
            i++;

        j = 0;
        strcpy(temp, &counting[i]);

        while(temp[j] != ' ' && temp[j] != '\0')
            j++;
        
        temp[j] = '\0';
        blankN++;
        
        if(temp[0] == '0')
        {
            printf("something is fishy\n");
            return 0;
        }

        else if(atoi(temp) != 0)
        {
            if(atoi(temp) != blankN)
            {
                printf("something is fishy\n");
                return 0;
            } 
            if(counting[i+j] == '\0')
            {
                if(atoi(temp) != n)
                {
                    printf("something is fishy\n");
                    return 0;
                }
            }
        }
        i = i + j;
    }
    if(blankN == n)
        printf("makes sense");
    else
        printf("something is fishy\n");

    return 0;
}