#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(max, a, b) {if(a>b) max=a; else max=b;}

int LCS(char *str1, char *str2, int str1_len, int str2_len);

int main()
{   
    int lcs;                    // lcs: 결과값
    char str1[1001];            // str1: 첫 번째 문자열 col이 순회
    char str2[1001];            // str2: 두 번째 문자열 row가 순회

    scanf("%s", str1);
    scanf("%s", str2);

    lcs = LCS(str1, str2, strlen(str1), strlen(str2));
    printf("%d\n", lcs);

    return 0;
}

int LCS(char *str1, char *str2, int str1_len, int str2_len)
{
    int row, col, loc, max, result;                    // loc: matrix에서 채워야 하는 칸 위치
    int *matrix, matrix_size;                          // matrix: memoization용 matrix 
                                                       
    matrix_size = (str1_len+1)*(str2_len+1);           // matrix: (str1_len+1) by (str2_len+1)
    matrix = (int *)calloc(sizeof(int), matrix_size);  // matrix를 기본적으로 0으로 초기화한다.

    for(row=1; row<str2_len+1; row++)                  // (1,1)부터 시작하여 행마다 -> 방향으로 순차적으로 값을 채운다. 
    {
        for(col=1; col<str1_len+1; col++)
        {
            loc = (str1_len+1)*row + col;              // matrix[(str1_len+1)*row + col]는 str1의 col번째(위치: col-1) 글자까지와 str2의 row번째(위치: row-1) 글자까지의 LCS를 의미한다.
            if(str1[col-1]==str2[row-1])               // str1의 col번째 글자와 str2의 row번째 글자가 같은 경우 
            {
                matrix[loc] = matrix[(str1_len+1)*(row-1)+(col-1)]+1;  // str1의 col-1번째 글자와 str2의 row-1번째 글자까지의 LCS에 1을 더하여 loc칸의 LCS를 구할 수 있다.
            }
            else                                        // str1의 col번째 글자와 str2의 row번째 글자가 다를 경우
            {
                MAX(max, matrix[(str1_len+1)*(row)+(col-1)], matrix[(str1_len+1)
                *(row-1)+(col)]);                      // str1의 col-1번째 글자와 str2의 row번째 글자까지의 LCS와 str1의 col번째 글자와 str2의 row-1번째 글자까지의 LCS 중 큰 값을 가져오면 된다.
                matrix[loc] = max;
            }  
        }
    }

    result = matrix[matrix_size-1];
    free(matrix);
    return result;      
}