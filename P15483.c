/* cost

     m o n k e y
   0
 m 
 o
 n
 e
 y

 \: copy,   0
 -: insert, 1
 |: delete, 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    int col, row, *dp;
    int source_len, dst_len;

    int source[1001];
    int dst[1001];

    scanf("%s", source);     // monkey
    scanf("%s", dst);     // mon ey

    source_len = strlen(source);
    dst_len = strlen(dst);

    dp = (int *)calloc(sizeof(int)*((source_len+1)*(dst_len+1)));

    // dp initialization
    for(col = 1; col<source_len+1; col++)
        dp[col] = col;
    
    for(row = 1; row<dst_len; row++)
        dp[row] = row;

    // complete dp
    for(row=1; row<dst_len+1; row++)
    {
        for(col=1; col<source_len+1; col++)
        {
            
        }
    }
 




    return 0;
}