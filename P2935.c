#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int lenA = 0, lenB = 0;
    char operator[2];
    char A[101] = {0,}, B[101] = {0,};

    scanf("%s", A);
    scanf("%s", operator);
    scanf("%s", B);

    // calculate the length of A and B
    while(A[lenA] != '\0')
        lenA++;
    while(B[lenB] != '\0')
        lenB++;

    if (strcmp(operator, "+") == 0)
    {
        if(lenA > lenB)
        {
            printf("%d",1);
            for(int i = 0; i < lenA-1; i++)
            {
                if(i == lenA-lenB-1)
                {
                    printf("%d",1);
                    continue;
                }
                printf("%d", 0);
            }
        }
        else if (lenA < lenB)
        {
            printf("%d",1);
            for(int i = 0; i < lenB-1; i++)
            {
                if(i == lenB-lenA-1)
                {
                    printf("%d",1);
                    continue;
                }
                printf("%d", 0);
            }
        }
        else 
        {
            printf("%d",2);
            for(int i = 0; i < lenA-1; i++)
                printf("%d", 0);
        }
    }

    else if (strcmp(operator, "*") == 0) 
    {
        printf("%d",1);
        for(int i = 0; i < lenA+lenB-2; i++)
            printf("%d", 0);
    }

    return 0;
}