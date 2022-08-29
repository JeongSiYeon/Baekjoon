#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    int i = 0, min = 0, max = 0;
    char *A = (char *)malloc(sizeof(char)*8);
    char *B = (char *)malloc(sizeof(char)*8);

    scanf("%s %s", A, B);   // 1 <= A, B <= 1,000,000 

    while(A[i] != '\0')
    {
        if(A[i] == '6')
            A[i] = '5';
        i++;
    }
    i = 0;
    
    while(B[i] != '\0')
    {
        if(B[i] == '6')
            B[i] = '5';
        i++;
    }
    i = 0;

    min = atoi(A) + atoi(B);

    while(A[i] != '\0')
    {
        if(A[i] == '5')
            A[i] = '6';
        i++;
    }
    i = 0;
    
    while(B[i] != '\0')
    {
        if(B[i] == '5')
            B[i] = '6';
        i++;
    }
    i = 0;

    max = atoi(A) + atoi(B);

    printf("%d %d\n", min, max);
    return 0;
}