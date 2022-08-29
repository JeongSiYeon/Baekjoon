#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int *left, int *mid, int *right);

int main(void)
{
    int i = 0, j = 0;
    
    char *temp  = (char *)calloc(50000, sizeof(int));
    int  *left  = (int *)calloc(10000, sizeof(int));
    int  *mid   = (int *)calloc(10000, sizeof(int));
    int  *right = (int *)calloc(10000, sizeof(int));
    int  *count = (int *)calloc(10000, sizeof(int));

    while(gets(temp))  
    {
        if(temp[0] == '\0')
            break;

        char *token;
        left[i]  = atoi(strtok(temp, " "));
        mid[i]   = atoi(strtok(NULL, " "));
        right[i] = atoi(strtok(NULL, " "));

        i++;
    }     

    for(j = 0; j < i; j++)
    {
        count[j] = 0;
        while(left[j] + 1 != mid[j] || mid[j] + 1 != right[j])
        {
            move(&left[j], &mid[j], &right[j]);
            count[j]++;
        }
    }
    
    for(int j = 0; j < i; j++)
        printf("%d\n", count[j]);
    
    return 0;
}

void move(int *left, int *mid, int *right)
{
    if((*mid - *left) < (*right - *mid))
    {
        *left  = *mid;
        *mid = *left+1;      
    }
    else
    {
        *right = *mid;
        *mid = *right - 1;
    }
}