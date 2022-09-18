#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(max, a, b) {if(a>b) max=a; else max=b;}

int LCS(char *str1, char *str2, int str1_len, int str2_len);

int main()
{   
    int lcs;
    char str1[1001];
    char str2[1001];

    scanf("%s", str1);
    scanf("%s", str2);

    lcs = LCS(str1, str2, strlen(str1), strlen(str2));
    printf("%d\n", lcs);

    return 0;
}

int LCS(char *str1, char *str2, int str1_len, int str2_len)
{
    int row, col, loc, max, result;
    int *matrix, matrix_size;

    matrix_size = (str1_len+1)*(str2_len+1);
    matrix = (int *)calloc(sizeof(int), matrix_size);    

    for(row=1; row<str2_len+1; row++) 
    {
        for(col=1; col<str1_len+1; col++)
        {
            loc = (str1_len+1)*row + col;
            if(str1[col-1]==str2[row-1])
            {
                matrix[loc] = matrix[(str1_len+1)*(row-1)+(col-1)]+1;
            }
            else
            {
                MAX(max, matrix[(str1_len+1)*(row)+(col-1)], matrix[(str1_len+1)
                *(row-1)+(col)]);
                matrix[loc] = max;
            }  
        }
    }

    result = matrix[matrix_size-1];
    free(matrix);
    return result;      
}