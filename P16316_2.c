#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // input1: n (1 <= n <= 1000)
    int n, i = 0, j = 0, Bcount = 1; 

    scanf("%d%*c", &n);
    // input2: spokem (0 <= a(character!) <= 10 000 or "mumble")
    char *temp = (char *)malloc(sizeof(char)*n*6*2); 
    char *spoken = (char *)malloc(sizeof(char)*n*6*2); 
    gets(spoken);

    // solve
    while(spoken[i] != '\0')
    {
        // special case: 0
        if(spoken[i] == '0')
        {
            printf("something is fishy\n");
            return 0;
        }

        if(spoken[i] == ' ')
        {
            Bcount++;
            i++;
        }
            
        else
        {
            j = 0;
            strcpy(temp, &spoken[i]);
            while(temp[j] != ' ' && temp[j] != '\0')
                j++;
            temp[j] = '\0';

            if(atoi(temp) != 0)
            {
                if(Bcount != atoi(temp))
                {
                    printf("something is fishy\n");
                    return 0;
                }
            }
            
            i = i + j;
        }
    }
    
    if(Bcount == n)
        printf("makes sense\n");
    else
        printf("something is fishy\n");

    return 0;
}